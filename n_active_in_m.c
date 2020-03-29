/*
 * Probability Caculation
 *  for n active user within m in total with the active probability p.
 * Copyright (C) 2020 Shaun <zhangx@uestc.edu.cn>   
*/

#include <stdio.h>
#include <math.h>

double comb(double m, double n)
{
    double v1=1, v2=1;
    for(double tmpi=m; tmpi>=m-n+1; tmpi--) 
        v1 *= tmpi;
    for(double tmpj=2; tmpj<=n; tmpj++)   
        v2 *= tmpj;
    return v1/v2;
}

double bino(double m, double n, double p)
{
    return comb(m,n)*pow(p,n)*pow((1-p),(m-n));
}

int main()
{
    double tmpm, tmpn, tmpp;
    printf("Please Enter m n p with blank space:\n");
    scanf("%lf %lf %lf", &tmpm, &tmpn, &tmpp);

    double p_sum = 0;
    /*
    for(double  i=tmpn+1; i<tmpm+1; i++)
        p_sum += bino(tmpm,i,0.1);
    */
    for(double  i=0; i<=tmpn; i++)
        p_sum += bino(tmpm,i,0.1);

    printf("p_sum is %.12lf\n", 1-p_sum);

    return 0;
}