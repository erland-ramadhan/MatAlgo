#ifndef SVD_H
#define SVD_H

#include <vector>

class SVD {
public:
    // Constructor
    SVD(const std::vector<std::vector<double>>& matrix);

    // Perform Singular Value Decomposition
    void decompose();

    // Getters for U, S, and V matrices
    std::vector<std::vector<double>> getU() const;
    std::vector<std::vector<double>> getS() const;
    std::vector<std::vector<double>> getV() const;

    // Destructor
    ~SVD();

private:
    std::vector<std::vector<double>> matrix;
    std::vector<std::vector<double>> U;
    std::vector<std::vector<double>> S;
    std::vector<std::vector<double>> V;

    // Helper methods for initialization
    void initializeUSV();
};

#endif // SVD_H

