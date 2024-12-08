#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to perform the Jacobi iteration
void jacobi_iteration(const vector<vector<double>>& A, const vector<double>& f, vector<double>& x_prev, vector<double>& x_next, int n) {
    // Perform one iteration of the Jacobi method was similar to what I did in 311k with charlie so that was cool :)
    for (int i = 0; i < n; ++i) {
        double sum = 0.0;
        // takes the sum over all the elements except the diagonal element
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                sum += A[i][j] * x_prev[j];
            }
        }
        // Update the value of x[i]
        x_next[i] = (f[i] - sum) / A[i][i];
    }
}

int main() {
    int size = 5; // Set the size of the matrix

    // Initialize matrix A (diagonally dominant)
    vector<vector<double>> A(size, vector<double>(size, 0.0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == j) {
                A[i][j] = 10; // Set diagonal dominance with an absurdly high number lol
            } else {
                A[i][j] = 1;  // Non-diagonal elements
            }
        }
    }

    // Initialize right-hand side or my "b" vector in A*x = b. made these all ones
    vector<double> f(size, 1.0);  // f = [1, 1, 1, 1, 1]

    // Create an initial guess for the solution vector x
    vector<double> x_prev(size, 0.0); // Initially all zeros
    vector<double> x_next(size, 0.0); // To store the next iteration

    // Set the desired precision and maximum iterations
    double precision = 1e-8;
    int max_iterations = 100;

    // Perform Jacobi iterations until convergence or max iterations reached
    int iteration_count = 0;
    while (iteration_count < max_iterations) {
	// runs method
        jacobi_iteration(A, f, x_prev, x_next, size);
        

        // Check the error (difference between the current and previous solution vectors)
	// had to put error here so that the errors would add with eachother figured this out after so many errors
        double error = 0.0;
        for (int i = 0; i < size; ++i) {
            error += pow(x_next[i] - x_prev[i], 2); // Sum of squared differences
        }
        error = sqrt(error); // Take the square root to normalize it cause pythagoras is the goat

        cout << "Iteration: " << iteration_count << ", Error: " << error << endl;
        
        // If the error is less than the desired precision, stop the iteration
        if (error < precision) {
            break;
        }

        // Update the previous solution with the current one
        x_prev = x_next;

        iteration_count++;
    }

    // Print the solution
    cout << "Solution after " << iteration_count << " iterations:\n";
    for (int i = 0; i < size; ++i) {
        cout << "x[" << i << "] = " << x_next[i] << endl;
    }

    return 0;
}

