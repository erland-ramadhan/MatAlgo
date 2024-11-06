#include "Cholesky.h"
#include <iostream>
#include <cassert>
#include <cmath>

// Helper function to check if matrix is approximately equal to another
bool isApproxEqual(const std::vector<std::vector<double>>& A, const std::vector<std::vector<double>>& B, double tolerance = 1e-6) {
    if (A.size() != B.size() || A[0].size() != B[0].size()) {
        return false;
    }
    for (size_t i = 0; i < A.size(); ++i) {
        for (size_t j = 0; j < A[i].size(); ++j) {
            if (std::fabs(A[i][j] - B[i][j]) > tolerance) {
                return false;
            }
        }
    }
    return true;
}

void testCholesky() {
    // Symmetric positive-definite matrix for testing
    std::vector<std::vector<double>> matrix = {
        {4, 12, -16},
        {12, 37, -43},
        {-16, -43, 98}
    };

    Cholesky cholesky(matrix);
    cholesky.decompose();

    std::vector<std::vector<double>> L = cholesky.getL();

    // Check if L is lower triangular
    for (size_t i = 0; i < L.size(); ++i) {
        for (size_t j = i + 1; j < L[i].size(); ++j) {
            assert(L[i][j] == 0 && "Matrix L should be lower triangular");
        }
    }

    // Verify that L * L^T ≈ original matrix
    std::vector<std::vector<double>> LLT(matrix.size(), std::vector<double>(matrix.size(), 0.0));

    for (size_t i = 0; i < L.size(); ++i) {
        for (size_t j = 0; j <= i; ++j) {
            for (size_t k = 0; k <= i; ++k) {
                LLT[i][j] += L[i][k] * L[j][k];
            }
        }
    }

    assert(isApproxEqual(LLT, matrix) && "L * L^T should approximate the original matrix");

    std::cout << "Cholesky Decomposition test passed!" << std::endl;
}

int main() {
    testCholesky();
    return 0;
}

