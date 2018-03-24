#include <iostream>
#include <cmath>
#include <chrono>
#include <cstdlib>

using namespace std;
//definition e^x = \lim_{x\to\infty} (1 + x/n)^n
//Here we use taylor series exp(x) = 1 + x + x^2/2! + x^3/3! + x^4/4! + ... + x^n/n! + ...
inline double fexp(double x, int n)
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

int find_optimal_iteration(double x, double threshold)
{
    double default_ans = exp(x);
    int n = 0;
    for (int i = 1; i < 100; ++i) {
	double e = fexp(x, i);
	double err = e - default_ans;
	if (abs(err) < threshold) {
	    n = i;
	    break;
	}
    }
    return n;
}

int main()
{
    cout << "Enter a value between -16 and 16(e.g. 8.8):";
    double x = 0;
    cin >> x;
    cout << "Enter an acceptable error term(e.g. 0.01):";
    double err = 0;
    cin >> err;
    cout << "Searching for Optimal number of iteration..." <<endl;
    auto a = std::chrono::high_resolution_clock::now();
    int num_iterations = find_optimal_iteration(x, err);
    cout << "Optimal number of iteration is " << num_iterations << endl;
    auto b = std::chrono::high_resolution_clock::now();
    std::cout << "^That took " << std::chrono::duration_cast<std::chrono::nanoseconds>(b-a).count() << " ns\n\n\n";

    
    cout << "---Benchmark---"<< endl;
    auto t3 = std::chrono::high_resolution_clock::now();
    cout << "exp(" << x << ") = " << exp(x) << endl;
    auto t4 = std::chrono::high_resolution_clock::now();
    std::cout << "exp() took " << std::chrono::duration_cast<std::chrono::nanoseconds>(t4-t3).count() << " ns\n\n";

    auto t1 = std::chrono::high_resolution_clock::now();
    cout << "fexp(" << x << ") = " << fexp(x, num_iterations) << endl;
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "fexp() took " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count() << " ns\n";

}
