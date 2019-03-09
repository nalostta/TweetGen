/*------------------------------
milestone 1
author : manthan shah

functions :
1.pounds to kg
2.kg to pounds
3.inch to cm
4.cm to inch
5.Farenheit to C
6.C to farenheit
7.area of circle
8.area of rectangle
9.area of triangle
------------------------------*/
#include"milestone-1.h"

double lbs_to_kg(double pounds)
{
	return pounds*0.453592;
}

double kg_to_lbs(double kilogram)
{
	return kilogram*2.204623;
}

double inch_to_cm(double inch)
{
	return inch*2.54;
}

double cm_to_inch(double cm)
{
	return cm*0.393701;
}

double Farenheit_to_C(double Fah)
{
	return (Fah-32)/1.8;
}

double C_to_Farenheit(double Celcius)
{
	return (Celcius*1.8)+32;
}

double AreaOfCircle(double radius)
{
	return pi*radius*radius;
}

double AreaOfRectangle(double length,double breadth)
{
	return length*breadth;
}

double AreaOfTriangle(double base,double height)
{
	return 0.5*base*height;
}
