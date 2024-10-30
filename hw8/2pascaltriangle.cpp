#include <iostream>
#include <vector>

using namespace std;

// Storage class 
class storage {
protected:
    vector<vector<int>> data;
    int currentRows;

public:
    storage() : currentRows(0) {}

    // Get value at (i, j), dynamically extend if needed
    int get(int i, int j) {
        if (i >= currentRows) {
            extend_to(i);
        }
        if (j >= data[i].size()) {
            data[i].resize(j + 1, 0);
        }
        return data[i][j];
    }

    // Set value at (i, j), dynamically extend if needed
    void set(int i, int j, int value) {
        if (i >= currentRows) {
            extend_to(i);
        }
        if (j >= data[i].size()) {
            data[i].resize(j + 1, 0);
        }
        data[i][j] = value;
    }
    // Extend the storage to row 'i'
    void extend_to(int i) {
        data.resize(i + 1);
        for (int row = currentRows; row <= i; ++row) {
            data[row].resize(row + 1);
            data[row][0] = data[row][row] = 1;  // Initialize the edges of Pascal's triangle row to 1
        }
        currentRows = i + 1;
    }
};

// Pascal class inheriting from storage
class pascal : public storage {
public:
    // Constructor
    pascal(int n) {
        // Initialize storage
        storage::extend_to(n - 1);
        
        // Calculate coefficients
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < i; ++j) {
                set(i, j, get(i - 1, j - 1) + get(i - 1, j));
            }
        }
    }

    // Get coefficient at (i, j)
    int getvalue(int i, int j) {
        if (i < 0 || j < 0 || j > i) {
            cerr << "Error: Index out of bounds." << endl;
            return -1;
        }
        return storage::get(i, j); 
    }

    // Print the triangle
    void print() {
        for (int i = 0; i < currentRows; ++i) {
            for (int k = 0; k < currentRows - i - 1; ++k) {
                cout << "  ";
            }
            for (int j = 0; j <= i; ++j) {
                cout << get(i, j) << "   ";
            }
            cout << endl;
        }
    }
};

int main() {
    pascal triangle(5); 
    triangle.print();

    cout << "Coefficient at (4, 3): " << triangle.getvalue(4, 3) << endl;  // Adjusted to avoid out-of-bounds

    return 0;
}

