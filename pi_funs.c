double pi_bbp (int n);
double pi_leibniz (int n);

// Calculates the Leibniz series.

double pi_leibniz (int n)
{
    double sum = 0.0;
    int i;

    for(i = 0; i <= n; i++)               
    {

        if (i%2 == 0)               
            sum += 4./(2.*i + 1);  
        else
            sum -= 4./(2.*i + 1);
    }
    return sum;
}

//Calculates the bbp series. 
double pi_bbp (int n)
{
    
    double a = 1.;
    double pi = 0.;

    for (int k = 0; k < n; k++)
    {
        int k8 = 8 * k;                     
        double b = 4. / (k8 + 1);
        double c = 2. / (k8 + 4);
        double d = 1. / (k8 + 5);
        double e = 1. / (k8 + 6);

        pi += a * (b - c - d - e);
        a /= 16.;
     }
     return pi;
}

 

