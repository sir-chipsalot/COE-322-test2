#include <iostream>
#include <tuple>
#include <variant>
#include <cmath>

using std::cout;
using std::make_tuple;
using std::tuple;
using std::variant;

// Define a type alias for a quadratic equation's coefficients
using quadratic = tuple<double, double, double>;

// Function to calculate discriminant
double discriminant(quadratic q) {
  auto [a, b, c] = q;
  return b * b - 4 * a * c;
}

// Function to compute the roots of the quadratic equation and also assigns the variants
// states that there can be 3 cases, nothing i.e. monostate, one root m or two roots which would be -
// represented as a tuple
variant<std::monostate, double, tuple<double, double>> abc_cases(quadratic q) {
  auto [a, b, c] = q;
  double d = discriminant(q);

  if (d > 0) {
    // Two distinct real roots
    double x_plus = (-b + std::sqrt(d)) / (2 * a);
    double x_minus = (-b - std::sqrt(d)) / (2 * a);
    return make_tuple(x_plus, x_minus);
  } else if (d == 0) {
    // One real root
    return -b / (2 * a);
  } else {
    // No real roots
    return std::monostate{};
  }
}

int main() {
  // Example usage:
  auto sunk = quadratic(1., 0., -2); // Polynomial: x^2 - 2
  auto root_cases = abc_cases(sunk);

  switch (root_cases.index()) {
    case 0: 
      cout << "No roots\n"; 
      break;
    case 1: 
      cout << "Single root: " << std::get<1>(root_cases) << '\n'; 
      break;
    case 2: {
      auto xs = std::get<2>(root_cases);
      auto [xp, xm] = xs;
      cout << "Roots: " << xp << ", " << xm << '\n';
    }; break;
  }
}
