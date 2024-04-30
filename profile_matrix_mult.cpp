#include <AMDProfileController.h>
#include "matrix_mult.hpp"

int main() {
    // Define matrices
    std::vector<std::vector<int>> matrix1 = {{1, 2}, {3, 4}};
    std::vector<std::vector<int>> matrix2 = {{5, 6}, {7, 8}};

    std::cout << "Starting matrix multiplication\n";

    amdProfileResume (AMD_PROFILE_CPU);

    for(int i = 0; i < 10000; i++) {
        // Multiply matrices
        auto result = matrixMultiply(matrix1, matrix2);
    }

    amdProfilePause (AMD_PROFILE_CPU);


    // Print result
    std::cout << "Completed matrix multiplication!\n";

    return 0;
}