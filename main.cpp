#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;
//definition e^x = \lim_{x\to\infty} (1 + x/n)^n
//Here we use taylor series exp(x) = 1 + x + x^2/2! + x^3/3! + x^4/4! + ... + x^n/n! + ...
double fexp(double x, int n)
{
    double term = 1;
    double ans = 0;
    for (int i = 0; i < n; ++i) {
	ans += term;
	term *= x;
	term /= (double)(i+1);
    }
    return ans;
}

int main()
{
    cout << "Enter a value between [-16, 16]:";
    double x = 0;
    cin >> x;
    std::clock_t    start;
    start = std::clock();
    cout << "fexp(" << x << ") = " << fexp(x, 40) << endl;
    std::cout << "Time: " << (std::clock() - start) << std::endl;

    std::clock_t    start2;
    start2 = std::clock();
    cout << "exp(" << x << ") = " << exp(x) << endl;
    std::cout << "Time: " << (std::clock() - start2) << std::endl;

}
