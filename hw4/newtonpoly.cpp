#include <iostream>
using std::cout;
#include <functional>
using std::function;
using std::cin;

double newton_root( function< double(double) > f, function< double(double) > deriv ) {

  // find the square root of two
  // start somewhere
  double current_x = 10000000.;
  // while the function in the current value is too large keep looping
  double function_value = f(current_x);
  for ( int iteration_count=0; ; ++iteration_count ) {
    // update current x
    current_x -= f(current_x) / deriv(current_x);
    // calcute new function value
    function_value = f(current_x);
    if ( std::abs(function_value)<1.e-5 ) {
        break;
    }
  }
  return current_x;
}


double newton_root( function< double(double) > f)
{
    double current_x = 10000000.;
    double function_value = f(current_x);

    for (int iteration_count = 0; ; ++iteration_count)
    {
        current_x -= f(current_x)/(2*current_x);
        function_value = f(current_x);
        if ( std::abs(function_value)<1.e-5 )
        {
            break;
        }
    }
    return current_x;

}

int main() {

double n;
cout << "Type the number you want to find the root of: \n";
std::cin >> n;

// print results
cout << "Sqrt of " << n << ": " << newton_root([n] ( double x ) { return x*x-n; },[] ( double x ) { return 2*x; }) << '\n';

cout <<"Sqrt of " << n << " using the second, (polymorphed), newton_root function is: " << newton_root([n] ( double x ) { return x*x-n; }) << '\n';
}
