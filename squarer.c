//Chris Conklin
//Squaring Function Example
#include <stdio.h> //we need this for printf

/* Remember the format for function declaration is
   output_type function_name (input_type variable_name, input_type variable_name, ...)
   in this case my function name is squarer, it takes in one double input called
   to_be_square (which is the name the FUNCTION will use for the variable), and the
   output is also a double
*/

double squarer (double to_be_squared)
{

    double squared; //I create a new variable that only exists within this function
    squared = to_be_squared*to_be_squared;

    return squared; //This number will be placed wherever the function is called

}


int main()
{

    double x = 5;

    printf ("%.2f squared is %.2f! \n", x, squarer(x));
    // In this case we call squarer with 5 as the input. When squarer runs, it will
    // use 5 as the value of its variable to_be_squared. Then the value of the
    // variable squared (25) will be returned and will appear where the second
    // placeholder is


    return 0;



}
