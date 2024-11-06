#include "SVD.h"
#include <iostream>
#include <cassert>
#include <cmath>

// Helper function to check if a matrix is orthogonal
bool isOrthogonal(const std::vector<std::vector<double>>& matrix, double tolerance = 1e-6) {
    size_t n = matrix.size();
    std::vector<std::vector<double>> identity(n, std::vector<double>(n, 0.0));

    for (size_t i = 0; i < n; ++i) {
        identity[i][i] = 1.0;
    }

    std::vector<std::vector<double>> product(n, std::vector<double>(n, 0.0));

    // Check if matrix * matrix^T is approximately the identity
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            for (size_t k = 0; k < n; ++k) {
                product[i][j] += matrix[i][k] * matrix[j][k];
            }
            if (std::fabs(product[i][j] - identity[i][j]) > tolerance) {
                return false;
            }
        }
    }
    return true;
}

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

void testSVD() {
    // Example matrix for testing
    std::vector<std::vector<double>> matrix = {
        {1, 0, 0, 0, 2},
        {0, 0, 3, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 4, 0}
    };

    SVD svd(matrix);
    svd.decompose();

    std::vector<std::vector<double>> U = svd.getU();
    std::vector<std::vector<double>> S = svd.getS();
    std::vector<std::vector<double>> V = svd.getV();

    // Check orthogonality of U and V
    assert(isOrthogonal(U) && "Matrix U should be orthogonal");
    assert(isOrthogonal(V) && "Matrix V should be orthogonal");

    // Verify that U * S * V^T approximates the original matrix
    std::vector<std::vector<double>> US(matrix.size(), std::vector<double>(S[0].size(), 0.0));
    std::vector<std::vector<double>> USVt(matrix.size(), std::vector<double>(matrix[0].size(), 0.0));

    // Compute US
    for (size_t i = 0; i < U.size(); ++i) {
        for (size_t j = 0; j < S[0].size(); ++j) {
            for (size_t k = 0; k < U[0].size(); ++k) {
                US[i][j] += U[i][k] * S[k][j];
            }
        }
    }

    // Compute USV^T
    for (size_t i = 0; i < US.size(); ++i) {
        for (size_t j = 0; j < V.size(); ++j) {
            for (size_t k = 0; k < V[0].size(); ++k) {
                USVt[i][j] += US[i][k] * V[j][k];
            }
        }
    }

    assert(isApproxEqual(USVt, matrix) && "U * S * V^T should approximate the original matrix");

    std::cout << "SVD test passed!" << std::endl;
}

int main() {
    testSVD();
    return 0;
}

