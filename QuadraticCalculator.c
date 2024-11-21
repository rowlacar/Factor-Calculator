#include <stdlib.h>
#include <math.h>
#include <stdio.h>

//generate the prototypes
double calc_the_discriminant(double value_a, double value_b, double value_c);
int get_choice();
void do_fun_math();


int main()
{
    int choice = 1;
    //do fun math, and then ask if they want to try again.
    do {

        do_fun_math();
        //I tried using booleans but 1 and 2 are so much easier....
        choice = get_choice();
        //consume the carriage
        while (getchar() != '\n');
    } while (choice == 1);

    return 0;
}

int get_choice() {
    int user_input;
    printf("Would you like to run another equation? \n Enter 1 for Yes \\\ 2 for No: ");
    scanf_s(" %i", &user_input);

    //carriage return to look nice
    printf("\n");
    return (user_input);
}

void do_fun_math() {
    double value_a, value_b, value_c;
    double discriminant, first_root, second_root;

    printf("I can factor for you by using the quadratic equation!\n Please enter the coeffiecients in an equation with the format ax^2 + bx + c\n");
    
    /*
    "a" must be a real nonzero in order to be quadratic, repeat until a value other than zero is entered.
    */
    do {
        printf("Enter a value for a\n");
        scanf_s("%lf", &value_a);

        if (value_a == 0) {
            printf(" \"a\" must be a real number that does not equal 0, otherwise the equation would be linear!\n");
        }

    } while (value_a == 0);

    printf("Enter a value for b\n");
    scanf_s("%lf", &value_b);

    printf("Enter a value for c\n");
    scanf_s("%lf", &value_c);

    /*calculate the discriminant, and then do a different calculation based on the results
    */
    discriminant = calc_the_discriminant(value_a, value_b, value_c);

    //if there is only one root, do this
    if (discriminant == 0) {
        first_root = (value_b * -1.00) / (2 * value_a);
        //display the long to 2 decimal places: %.2lf
        printf("There is only one root for this equation: \nx = %.2lf\n", first_root);
    }

    //if the discriminant will be negative, do this
    else if (discriminant < 0) {
        /*since there is only one real answer(root P) only calculate - b / 2a
        * the Q value will include an imaginary number, which will be displayed, although the P is the only real number.
        */
        double root_P = (value_b * -1.00) / (2 * value_a);
        double root_Q = sqrt(discriminant * -1.00) / (2 * value_a);
        printf("There are two roots, which include imaginary numbers:\n");
        printf("x = %.2lf + %.2lfi\n", root_P, root_Q);
        printf("x = %.2lf - %.2lfi\n", root_P, root_Q);
    }

    //if the discriminant has two roots, do this
    else {
        first_root = ((value_b * -1.00) + sqrt(discriminant)) / (2 * value_a);
        second_root = ((value_b * -1.00) - sqrt(discriminant)) / (2 * value_a);
        printf("The equation has two roots:\n");
        printf("x = %.2lf\n", first_root);
        printf("x = %.2lf\n", second_root);
    }

}

double calc_the_discriminant(double value_a, double value_b, double value_c) {
    /* (b^2 - 4ac)
    */
    double discriminant = ((value_b * value_b) - (4 * value_a * value_c));
    return discriminant;
}