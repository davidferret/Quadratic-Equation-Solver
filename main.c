#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

void solveQuadratic(double a, double b, double c);
bool validateInput(double a);
void graphQuadratic(double a, double b, double c);

int main(void) {
    double a, b, c;
    char choice;

    do {
        printf("Enter the coefficients a, b, and c: ");
        while (scanf("%lf%lf%lf", &a, &b, &c) != 3 || !validateInput(a)) {
            printf("Invalid input! 'a' cannot be zero. Enter valid coefficients: ");
            while (getchar() != '\n');
        }

        solveQuadratic(a, b, c);

        printf("\nDo you want to graph the quadratic function? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            graphQuadratic(a, b, c);
        }

        printf("\nDo you want to solve another equation? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

void solveQuadratic(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;
    double realPart, imaginaryPart;

    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("The roots are real and different.\n");
        printf("root1 = %.2lf and root2 = %.2lf\n", root1, root2);
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        printf("The roots are real and the same.\n");
        printf("root1 = root2 = %.2lf\n", root);
    } else {
        realPart = -b / (2 * a);
        imaginaryPart = sqrt(-discriminant) / (2 * a);
        printf("The roots are complex and different.\n");
        printf("root1 = %.2lf + %.2lfi and root2 = %.2lf - %.2lfi\n", realPart, imaginaryPart, realPart, imaginaryPart);
    }
}

bool validateInput(double a) {
    return a != 0;
}

void graphQuadratic(double a, double b, double c) {
    printf("\nGraph of the quadratic function y = %.2lfx^2 + %.2lfx + %.2lf\n", a, b, c);
    for (int x = -10; x <= 10; x++) {
        double y = a * x * x + b * x + c;
        printf("x = %2d, y = %.2lf\n", x, y);
    }
}
