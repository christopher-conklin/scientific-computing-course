//Chris Conklin
//This program has a function that finds the volume of a cylinder
//and another function that prints the answer
#include <stdio.h> //we need for the printf function


const float pi=3.1416;
/* This variable is global, so in can be accessed in any function. Unless we have a number
   like pi that we expect to be in multiple functions, it is best to avoid using global
   variables, since their memory is never freed until the program ends. Also, you don't
   want to try to use pi and discover that a different function has changed its value.
   Therefore I use the const specifier to make it impossible for any part of the program
   to change it*/


/*These next two lines tell the computer that these two functions exist but will be 
  defined later. Note that each has a semicolon at the end*/

float volume_cylinder (float radius, float height);
void print_volume (float r, float h, float vol);

int main()
{
	//here I test both functions by finding and printing the volume of a cylinder
	//with radius 2 and height 5
	float r =2, h=5;
	float v = volume_cylinder(r,h); //the value returned by volume_cylinder is stored in v
	print_volume(r,h,v);

	return 0;
}

//Now I will define each function that I declared at the beginning
//Note that these DON'T have a semicolon after the parentheses
float volume_cylinder (float radius, float height)
{
	float volume = pi*radius*radius*height;
	return volume;
}


void print_volume (float r, float h, float vol)
{
	printf("A cylinder with a radius of %.2f and a height of %.2f has a volume of %.2f\n",r,h,vol);
	//Note that this is a void function, so it has no return value
}
