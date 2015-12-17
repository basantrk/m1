/*
 * Main algorithm that references code for Leibiniz and BBP calculations that is * avaliable in pi_funs.c
 * Algorithm that calculates the time for Leibniz and BBP  
 */


#include<stdio.h>
#include<math.h>
#include "pi_funs.c"
#include "timer.h"
#include "adjust.c"
#include "timer.c"



double pi_leibiniz (int n);
double pi_bbp (int n);
int adjust_rep_count (int count, double time, double tmin, double tmax);

int main ( )
 {
    
    int i;
    int ileibniz, ibbp;
    double tot = 0.000001;
    double abserr;
    double pi;
    
    i = 1;
    do
         // Calculates Leibniz series until the approximation of Pi converges within M_PI.
         // Prints number of terms, approximation ,and relative error at each at each stage.
         // At the end, the number of itterations necessary is returned.
    {
        pi = pi_leibniz(i);
        abserr = fabs(pi - M_PI);
        printf("%8d   %20.15f   %20.15f\n", i, pi, abserr);
        i *= 2;
    } 
    while (abserr > tot);
    ileibniz = i / 2; //Since itterations is doubled above,we have to divide by 2
    printf ("ileibniz = %8d/n", ileibniz);
    
    i = 1;
    do
         // Calculates BBP series until the approximation of Pi converges within M_PI.
         // Prints number of terms, approximation ,and relative error at each at each stage.
         // At the end, the number of itterations necessary is returned.
    {
        pi = pi_bbp (i);
        abserr = fabs(pi - M_PI);
        printf("%8d   %20.15f   %20.15f\n", i, pi, abserr);
        i *=2;
    } 
    while (abserr > tot);
    ibbp = i / 2;
    printf("ibbp = %8d\n \n \n", ibbp);

double time;
double time1;
double time2;
int t;
double tmax = 2.;
double tmin = 1.;
int count = 1000;

    //Measures the time of the Bbp series calcualtions. Then number of counts is adjusted until the total time is between 1 and 2 seconds. 
    printf ("Bbp series timing:\n\n");
    printf ("    Time/Iteration            Total Time            Iterations\n");
  
    do 
    {

        timer_start ();

        for (t = 0; t < count; t++)
        {
            pi_bbp (ibbp);
        }

        time = timer_stop ();
        time1 = time / count;
        printf (" %10.2f usec         %10.6f sec      %10d\n", time1 * 1.e6,
            time, count);
        count = adjust_rep_count (count, time, tmin, tmax);

    }
    while ((time > tmax) || (time < tmin));
    printf ("\n\n");

    count = 1000;

//Measures the time of the Leibniz series calcualtions. Then number of counts is      adjusted until the total time is between 1 and 2 seconds. 
    printf ("Leibniz series timing:\n\n");
    printf ("    Time/Iteration           Total Time           Iterations\n");
    do
    {

        timer_start ();

        for (t = 0; t < count; t++)
        {
            pi_leibniz (ileibniz);
        }

        time = timer_stop ();

        time2 = time / count;
        printf (" %10.2f usec         %10.6f sec      %10d\n", time2 * 1.e6,
            time, count);
        count = adjust_rep_count (count, time, tmin, tmax);

    }
    while ((time > tmax) || (time < tmin));
    printf ("\n\n");
     
    double e = time2 / time1;
// Prints the ratio between the time for BBP and Leibniz calculations.
    printf ("Ratio t_Lei/ t_BBP:%10.2f\n\n", e);

    return 0;
}




