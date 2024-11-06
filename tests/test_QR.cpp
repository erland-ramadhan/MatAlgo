#include "QR.h"
#include <iostream>
#include <cassert>

void testQR() {
    std::vector<std::vector<double>> matrix = {
        {12, -51, 4},
        {6, 167, -68},
        {-4, 24, -41}
    };

    QR qr(matrix);
    qr.decompose();

    std::vector<std::vector<double>> Q = qr.getQ();
    std::vector<std::vector<double>> R = qr.getR();

    // Example assertion (replace with real test conditions)
    assert(Q.size() == matrix.size());
    assert(R.size() == matrix.size());

    std::cout << "QR Factorization test passed!" << std::endl;
}

int main() {
    testQR();
    return 0;
}

