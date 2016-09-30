#include <iostream>
#include <iomanip>
#include <complex>
#include <cmath>

int main()
{
    using namespace std::complex_literals;
    std::cout << std::fixed << std::setprecision(1);

    std::complex<double> z1 = 1i * 1i;
    std::cout << "i * i = " << z1 << '\n';
    std::complex<double> z2 = 4. + 2i;

    std::cout << z1 * z2 << '\n';
    std::complex<double> z3 = 1i * sqrt(16);

    std::cout << z3 << '\n';
}
