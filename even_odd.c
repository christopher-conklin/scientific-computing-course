//Chris Conklin
//Examples of using if/else, switch, and for statements 
#include <stdio.h> //we will use printf

//This function uses an if statement to print whether the input number is even or odd
void even_or_odd (int num)
{
    if (num%2 == 0) //the statement in parentheses is what is evaluated as true or false
        printf("%d is even!\n",num); //Because there is only one statement here, I don't need
    				     //brackets. I would need brackets if I wanted the code
    				     //to do more than one thing if num was even
    else
        printf("%d is odd!\n", num);
}

//This function uses the switch statment to print what the remainder is when
//the input number is divided by 5
void division5 (int num)
{
    switch (num%5) //the number in parentheses is what is being checked in each case
    {
    case 0: //note the syntax. There is a colon after the 0.If num%5==0, then the computer will evaluate all the code after the colon until it reaches the next case (or a break statement) 
        printf("%d is divisible by 5",num);
        break; //This statement stops the switch statement
    case 1:
        printf("%d/5 has remainder one",num);
        break;
    case 2:
        printf("%d/5 has remainder two", num);
        break;
    case 3:
        printf("%d/5 has remainder three", num);
        break;
    case 4:
        printf("%d/5 has remainder four", num);
        break;
    default: // This is the code that will be run if none of the cases are true
        printf("Error with switch statement");


    }
}


//Ths function will print both if the input number is even and if it is positive or negative.
//Becasue we already defined a function to determine whether a number is even or odd, we can
//use it by calling it within this function after we print out whether the number is positive
//or negative
void eopn(int num)
{
  if(num >0) //Note that switch would not work here because we are not evaluating whether num is a specific value
    printf("%d is positive and ",num);
  else if(num <0)
    printf("%d is negative and ",num);
  even_or_odd(num);
	  //The rest of these sentences will be completed by even_or_odd
}

int main()
{
	//Here I use a for loop to print x and y data for the function y=x^2 from x=0 to x=10
   for(float j=0; j<10; j=j+0.01)
   {
       printf("%f \t %f\n",j, j*j);
   }
	//Here I use a while loop to print whether the integers from -10 to 10 are even/odd
   	//and positive/negative
   int k = -10;
   while(k<11)
   {
	   eopn(k++); //after evaluating eopn, k is increased by 1 using the ++ operator
	   //Take a look in the output at what happens when k = 0. Does that make sense?
   }
    return 0;
}
