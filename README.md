<div align="center">

# MatAlgo (Matrix Algorithms)

<div align="left">

## What is this repo about?

This repository implements key matrix computation algorithms from Matrix Computations by Golub and Van Loan using C++. The focus is on developing efficient and accurate implementations of foundational algorithms, including LU decomposition, Cholesky decomposition, QR factorization, and Singular Value Decomposition (SVD).

The project aims to demonstrate proficiency in both numerical algorithms and C++ programming, with attention to computational efficiency, memory management, and precision. Each algorithm is implemented in a modular format, with accompanying test cases that validate correctness and matrix properties. This repository serves as a practical reference for linear algebra applications in scientific computing, data science, and engineering contexts.

## How to use this repo?

Coming soon!

## How is the performance (so far)?

The tests was run on Intel(R) 8th gen 1.7 GHz quad-core processor with 16 GB of RAM. The test cases will be kept updated.

| - | Algorithms | LU Decomposition | Cholesky Decomposition | QR Decomposition | SVD |
| :---: | ---: | ---: | ---: | ---: | ---: |
| Matrix Size | - | - | - | - |
| 500 × 500 | - | 250 ms | 150 ms | 350 ms | 750 ms |
| 1000 × 1000 | - | 2.5 s | 1.75 s | 4 s | 7 s |
| 2000 × 2000 | - | 18 s | 12.5 s | 25 s | 1.25 minutes |
| 5000 × 5000 | - | 2.5 minutes | 2 minutes | 4 minutes | 7.5 minutes |
