/*
milestone-#2 (header file)
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
#ifndef _milestone_2
#define _milestone_2

#include<stdio.h>

double Pow(double x,int n);
int gcd(int a,int b);
int is_prime(unsigned int x);
double FV(double rate,unsigned int nperiods,double PV);
double PV(double rate,unsigned int nperiods,double FV);
void print_all_factors(unsigned int x);
void print_all_primes(unsigned int x);
int odd_even(int x);
int LCM_of_3(int a,int b,int c);
unsigned int fact(unsigned int n);
unsigned int nPr(unsigned int n,unsigned int r);
unsigned int nCr(unsigned int n,unsigned int r);
void fibonacci(unsigned int n); //will print a minimum of 2 numbers

#endif