/*
milestone-#2
author:-manthan shah

functions:
1.power
2.gcd
3.check prime number
4.future value based on compund interest
5.present value from investment based on compound interest
6.print all factors of a number
7.check even/odd
8.LCM of 3 numbers
9.factorial
10.nCr
11.nPr
12.fibonacci
*/
#include"milestone-2.h"

double Pow(double x,int n)
{
	//if(n<0) return -1; //error case 
	if(!x) return 0;
	int count;
	double power=1;
	for(count=0;count<n;count++) power*=x;
	return power;
}

int gcd(int a,int b)
{
	if(a==1 || b==1) return 1;
	if(a<=0 || b<=0) return -1; //-1: error case for this function
	unsigned int remainder,dividend,divisor;
	if(a>b)
	{
		divisor = a;
		remainder= b;
	}else
	{
		divisor = b;
		remainder = a;
	}
	do
	{
		dividend = divisor;
		divisor = remainder;
		remainder = dividend%divisor;
	}while(remainder!=0);
	return divisor;	
}

int is_prime(unsigned int x)
{
	if(x<=1) return -1; //'out of bounds' case for the function definition
	int i=1,num=x;
	do
	{
		if((num%i)==0) num=num/i;
		i++;
	}
	while((i*i)<=x);
	if(num==x) return 1;
	else return 0;
}

double FV(double rate,unsigned int nperiods,double PV)
{
	rate++;
	rate = Pow(rate,nperiods);
	return PV*rate;
}

double PV(double rate,unsigned int nperiods,double FV)
{
	rate++;
	rate*=Pow(rate,nperiods);
	return FV/rate;
}

void print_all_factors(unsigned int x)
{
	int i=1,num=x;
	do
	{
		if((num%i)==0)
		{
			printf(" %d",i);
			
		}
	}while((i++)<=x);
	return;
}

void print_all_primes(unsigned int x)
{
	int i=2;
	do
	{
		if(is_prime(i)&&x%i==0)
		{
			printf(" %d",i);
			
		}
	}while((i++)<=x);
	return;
}

int odd_even(int x) //1 if odd
{
	return (x&1);
}

int LCM_of_3(int a,int b,int c)
{
	a = a/gcd(a,b);
	b = b/gcd(b,c);
	c = c/gcd(a,c);
	return a*b*c;
}

unsigned int fact(unsigned int n)
{
	if(!n)return 1;
	int num=n;
	while(n!=1)
	{
		num*=(--n);
	}
	return num;
}

unsigned int nPr(unsigned int n,unsigned int r)
{
	if(n<r) return -1; //error case
	return fact(n)/fact(r);
}

unsigned int nCr(unsigned int n,unsigned int r)
{
	if(n<r) return -1; //error case
	return fact(n)/(fact(r)*fact(n-r));
}

void fibonacci(unsigned int n) //will print a minimum of 2 numbers
{
	if(!n) return;
	unsigned int a=0,b=1,c=1,i=n;
	printf("0 1");
	do
	{
		printf(" %d",c);
		a=b;
		b=c;
		c=a+b;
	}while(--i>=3);
	return;
}
