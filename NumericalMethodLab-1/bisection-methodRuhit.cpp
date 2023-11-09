#include <iostream>
#include <cmath>

using namespace std;

double equation(double x) {
    // Define your equation here
    // For example, let's solve x^3 - 2x - 5 = 0
    return pow(x, 3) - 2 * x - 5;
}

double bisectionMethod(double a, double b, double tolerance) {
    double c;

    while (fabs(b - a) >= tolerance) {
        c = (a + b) / 2;

        cout << "a = " << a << ", b = " << b << ", f(a) = " << equation(a) << ", f(b) = " << equation(b)
             << ", c = " << c << ", f(c) = " << equation(c) << endl;

        if (equation(c) == 0.0)
            return c;

        if (equation(c) * equation(a) < 0)
            b = c;
        else
            a = c;
    }

    return c;
}

int main() {
    double a, b, tolerance;

    cout << "Enter the interval [a, b]: ";
    cin >> a >> b;

    cout << "Enter the tolerance: ";
    cin >> tolerance;

    double root = bisectionMethod(a, b, tolerance);

    cout << "Approximate root: " << root << endl;

    return 0;
}

