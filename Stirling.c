//Chris Conklin
//Stirling's approximation
#include <stdio.h>
#include <math.h>

long factorial(long n)
{
    long answer = 1;
    for(int i=2; i<=n; i++)
        answer*=i;
    return answer;
}

double stirling(long n)
{
    return sqrt(2*3.1416*n)*pow(n,n)/exp(n);
}


int main()
{

    for(long i = 1; i<=50; i+=1)
    {
        printf("This is change2");
        printf("%li \t %lf \n",i,(factorial(i)-stirling(i))/factorial(i));
    }

    return 0;
}
