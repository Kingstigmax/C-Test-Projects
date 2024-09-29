#include <stdio.h>

int main() 
{
    char operator;
    double num1, num2, result;

    printf("Simple Calculator\n");
    printf("-----------------\n");
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Enter the first number: ");
    scanf("%lf", &num1);

    printf("Enter the second number: ");
    scanf("%lf", &num2);

    switch(operator) 
    {
        case '+':
            result = num1 + num2;
            printf("The result of %lf and %lf is equal to %lf\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("The result of %lf and %lf is equal to %lf\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("The result of %lf and %lf is equal to %lf\n", num1, num2, result);
            break;
        case '/':
            if (num2 == 0) 
            {
                result = num1 / num2;
                printf("The result of %lf and %lf is equal to %lf\n", num1, num2, result);
            }
            else {printf("Eror: Division by zero is not allowed.");}
            break;
        default:
            printf("Invalid operation");
            break;
    }


    return 0;
}