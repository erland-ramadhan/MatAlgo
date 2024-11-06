#ifndef QR_H
#define QR_H

#include <vector>

class QR {
public:
    QR(const std::vector<std::vector<double>>& matrix);

    void decompose(); // Perform QR decomposition

    std::vector<std::vector<double>> getQ() const;
    std::vector<std::vector<double>> getR() const;

    ~QR();

private:
    std::vector<std::vector<double>> matrix;
    std::vector<std::vector<double>> Q;
    std::vector<std::vector<double>> R;

    // Additional helper methods for QR decomposition, if needed
    void initializeQR();
};

#endif // QR_FACTORIZATION_H

