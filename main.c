#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

void solveQuadratic(double a, double b, double c);
bool validateInput(double a);
void graphQuadratic(double a, double b, double c);
void displayMenu();
void stepByStepSolution(double a, double b, double c);
void plotGraphToFile(double a, double b, double c);

int main(void) {
    double a, b, c;
    char choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        if (choice == '4') {
            printf("Exiting program.\n");
            break;
        }

        printf("Enter the coefficients a, b, and c: ");
        while (scanf("%lf%lf%lf", &a, &b, &c) != 3 || !validateInput(a)) {
            printf("Invalid input! 'a' cannot be zero. Enter valid coefficients: ");
            while (getchar() != '\n'); 
        }

        solveQuadratic(a, b, c);
        stepByStepSolution(a, b, c);
        plotGraphToFile(a, b, c);
    }
    return 0;
}


void displayMenu() {
    printf("\n--- Quadratic Equation Solver ---\n");
    printf("1. Solve a Quadratic Equation\n");
    printf("2. Display Step-by-Step Solution\n");
    printf("3. Graph the Quadratic Function\n");
    printf("4. Exit\n");
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

void stepByStepSolution(double a, double b, double c) {
    printf("\n--- Step-by-Step Solution ---\n");
    printf("Quadratic equation: %.2lfx^2 + %.2lfx + %.2lf = 0\n", a, b, c);
    printf("Step 1: Compute the discriminant\n");
    double discriminant = b * b - 4 * a * c;
    printf("Discriminant = (%.2lf^2) - 4 * %.2lf * %.2lf = %.2lf\n", b, a, c, discriminant);
    printf("Step 2: Compute the roots\n");
    if (discriminant >= 0) {
        printf("Root formula: (-b ± sqrt(discriminant)) / (2a)\n");
    } else {
        printf("Root formula: (-b ± sqrt(|discriminant|) i) / (2a)\n");
    }
}

void plotGraphToFile(double a, double b, double c) {
    FILE *fp = fopen("quadratic_graph.csv", "w");
    if (!fp) {
        printf("Error creating graph file!\n");
        return;
    }
    fprintf(fp, "x,y\n");
    for (int x = -10; x <= 10; x++) {
        double y = a * x * x + b * x + c;
        fprintf(fp, "%d,%.2lf\n", x, y);
    }
    fclose(fp);
    printf("\nGraph data saved to 'quadratic_graph.csv'. You can plot it using Excel or Python.\n");
}
