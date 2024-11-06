#ifndef LU_H
#define LU_H

#include <vector>

class LU {
public:
    // Constructor
    LU(const std::vector<std::vector<double>>& matrix);

    // Method to perform LU decomposition
    void decompose();

    // Getters for L and U matrices
    std::vector<std::vector<double>> getL() const;
    std::vector<std::vector<double>> getU() const;

    // Destructor (if needed)
    ~LU();

private:
    std::vector<std::vector<double>> matrix;
    std::vector<std::vector<double>> L;
    std::vector<std::vector<double>> U;

    // Helper methods (if any)
    void initializeLU();
};

#endif // LU_DECOMPOSITION_H

