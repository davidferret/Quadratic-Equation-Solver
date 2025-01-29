# Quadratic Equation Solver

This program solves quadratic equations, determines the nature of the roots, and provides an option to visualize the function. It ensures valid input and calculates real or complex roots based on the discriminant.

- **Solves Quadratic Equations**: Computes real or complex roots based on the discriminant.
- **Input Validation**: Ensures the coefficient `a` is nonzero.
- **Graphical Representation**: Displays function values for a range of x-values.

## How It Works
1. The user inputs coefficients `a`, `b`, and `c`.
2. The program validates the input to ensure `a` is nonzero.
3. It calculates the discriminant to determine the nature of the roots.
4. The roots are displayed as real or complex numbers.
5. The user has the option to visualize the quadratic function over a set range.

## Example Usage

```
--- Quadratic Equation Solver ---
1. Solve a Quadratic Equation
2. Display Step-by-Step Solution
3. Graph the Quadratic Function
4. Exit
Enter your choice: 1
Enter the coefficients a, b, and c: 1 -3 2
The roots are real and different.
root1 = 2.00 and root2 = 1.00

Do you want to see the step-by-step solution? (y/n): y
Step 1: Compute the discriminant
Discriminant = ( -3^2 ) - 4 * 1 * 2 = 1
Step 2: Compute the roots
Root formula: (-b ± sqrt(discriminant)) / (2a)

```

