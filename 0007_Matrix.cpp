#include <iostream>

int main() {
    int rows, cols;
    char tryAgain;

    do {
        std::cout << "MATRIX\n";

        std::cout << "No. of Rows: ";
        std::cin >> rows;

        std::cout << "No. of Columns: ";
        std::cin >> cols;

        int arr[rows][cols];

        std::cout << "\nELEMENT OF THE ARRAY:\n";

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << "Enter element at position [" << i << "][" << j << "]: ";
                std::cin >> arr[i][j];
            }
        }

        std::cout << "\nArray elements are:\n";

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << arr[i][j] << " ";
            }
            std::cout << "\n";
        }

        std::cout << "\nDo you want to try again? (y/n): ";
        std::cin >> tryAgain;
        std::cout << "\n";

    } while (tryAgain == 'y' || tryAgain == 'Y');

    return 0;
}
