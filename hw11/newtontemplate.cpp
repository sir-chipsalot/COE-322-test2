#include <iostream>
using std::cout;
using std::cin;

#include <functional>
using std::function;

#include <cmath>
using std::abs;

#include <complex>
using std::complex;

template<typename T>
T newton_root(function<T(T)> f, function<T(T)> deriv) {

  // Starting guess
  T current_x = 10000000.;

  // Iteration for newton method
  T function_value = f(current_x);
  for (int iteration_count = 0; ; ++iteration_count) {
    current_x -= f(current_x) / deriv(current_x);
    function_value = f(current_x);

    // stop condition
    if (abs(function_value) < 1.e-7) {
      break;
    }
  }
  return current_x;
}

int main() {
  
  // Example wih regular double
  double n_double;
  cout << "Type the number you want to find the root of: \n";
  std::cin >> n_double;
  cout << "Sqrt of " << n_double << ": "
       << newton_root<double>(
            [n_double](double x) { return x * x - n_double; },
            [](double x) { return 2 * x; })
       << '\n';

  //complex<double>
  double real, imag;
  cout << "Enter the real part of the complex number: ";
  cin >> real;
  cout << "Enter the imaginary part of the complex number: ";
  cin >> imag;


  // runs the code with imaginary numbers, a real and complex part
  complex<double> n_complex(real, imag);
  cout << "Sqrt of " << n_complex << ": "
       << newton_root<complex<double>>(
            [n_complex](complex<double> x) { return x * x - n_complex; },
            [](complex<double> x) { return 2. * x; })
       << '\n';
}

