#include "LU.h"
#include <iostream>
#include <cassert>

void testLU() {
    // Test case setup
    std::vector<std::vector<double>> matrix = {
        {4, 3},
        {6, 3}
    };

    LU lu(matrix);
    lu.decompose();

    // TODO: Replace with actual test logic
    std::vector<std::vector<double>> L = lu.getL();
    std::vector<std::vector<double>> U = lu.getU();

    // Example assertion (replace with real test conditions)
    assert(L.size() == matrix.size());
    assert(U.size() == matrix.size());

    std::cout << "LU Decomposition test passed!" << std::endl;
}

int main() {
    testLU();
    return 0;
}

