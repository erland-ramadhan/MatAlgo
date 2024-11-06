#ifndef CHOLESKY_H
#define CHOLESKY_H

#include <vector>

class Cholesky {
public:
    // Constructor
    Cholesky(const std::vector<std::vector<double>>& matrix);

    // Perform Cholesky decomposition
    void decompose();

    // Getter for lower triangular matrix
    std::vector<std::vector<double>> getL() const;

    // Destructor
    ~Cholesky();

private:
    std::vector<std::vector<double>> matrix;
    std::vector<std::vector<double>> L;

    // Helper methods for initialization
    void initializeL();
};

#endif // CHOLESKY_DECOMPOSITION_H

