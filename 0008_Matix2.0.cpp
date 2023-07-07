#include <iostream>

const int max_array = 15;

void displayMatrix(int arr[][max_array], int rows, int cols) {
    std::cout << "Array elements are:\n";

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    int rows, cols;

    std::cout << "MATRIX\n";

    std::cout << "No. of Rows: ";
    std::cin >> rows;

    std::cout << "No. of Columns: ";
    std::cin >> cols;

    int arr[max_array][max_array];

    std::cout << "\nELEMENT OF THE ARRAY:\n";

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Enter element at position [" << i << "][" << j << "]: ";
            std::cin >> arr[i][j];
        }
    }

    char choice;

    do {
        std::cout << "\nChoose an operation:\n";
        std::cout << "a. Add rows\n";
        std::cout << "b. Add columns\n";
        std::cout << "c. Delete rows\n";
        std::cout << "d. Delete columns\n";
        std::cout << "e. Search for an element\n";
        std::cout << "f. Display the matrix\n";
        std::cout << "g. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 'a':
            case 'A': {
                int numRows;
                std::cout << "Enter the number of rows to add: ";
                std::cin >> numRows;

                if (numRows <= 0) {
                    std::cout << "Invalid number of rows.\n";
                    break;
                }

                if (rows + numRows > max_array) {
                    std::cout << "Exceeded maximum array size.\n";
                    break;
                }

                for (int i = rows; i < rows + numRows; ++i) {
                    for (int j = 0; j < cols; ++j) {
                        std::cout << "Enter element at position [" << i << "][" << j << "]: ";
                        std::cin >> arr[i][j];
                    }
                }

                rows += numRows;

                std::cout << "Rows added successfully.\n";
                break;
            }
            case 'b':
            case 'B': {
                int numCols;
                std::cout << "Enter the number of columns to add: ";
                std::cin >> numCols;

                if (numCols <= 0) {
                    std::cout << "Invalid number of columns.\n";
                    break;
                }

                if (cols + numCols > max_array) {
                    std::cout << "Exceeded maximum array size.\n";
                    break;
                }

                for (int i = 0; i < rows; ++i) {
                    for (int j = cols; j < cols + numCols; ++j) {
                        std::cout << "Enter element at position [" << i << "][" << j << "]: ";
                        std::cin >> arr[i][j];
                    }
                }

                cols += numCols;

                std::cout << "Columns added successfully.\n";
                break;
            }
            case 'c':
            case 'C': {
                int numRows;
                std::cout << "Enter the number of rows to delete: ";
                std::cin >> numRows;

                if (numRows <= 0) {
                    std::cout << "Invalid number of rows.\n";
                    break;
                }

                if (rows - numRows < 0) {
                    std::cout << "Invalid number of rows to delete.\n";
                    break;
                }

                for (int i = rows - numRows; i < rows; ++i) {
                    for (int j = 0; j < cols; ++j) {
                        arr[i][j] = 0;
                    }
                }

                rows -= numRows;

                std::cout << "Rows deleted successfully.\n";
                break;
            }
            case 'd':
            case 'D': {
                int numCols;
                std::cout << "Enter the number of columns to delete: ";
                std::cin >> numCols;

                if (numCols <= 0) {
                    std::cout << "Invalid number of columns.\n";
                    break;
                }

                if (cols - numCols < 0) {
                    std::cout << "Invalid number of columns to delete.\n";
                    break;
                }

                for (int i = 0; i < rows; ++i) {
                    for (int j = cols - numCols; j < cols; ++j) {
                        arr[i][j] = 0;
                    }
                }

                cols -= numCols;

                std::cout << "Columns deleted successfully.\n";
                break;
            }
            case 'e':
            case 'E': {
                int value;
                bool found = false;
                std::cout << "Enter the value to search for: ";
                std::cin >> value;
                for (int i = 0; i < rows; ++i) {
                    for (int j = 0; j < cols; ++j) {
                        if (arr[i][j] == value) {
                            std::cout << "Element found at position [" << i << "][" << j << "].\n";
                            found = true;
                            break;
                        }
                    }
                    if (found)
                        break;
                }
                if (!found)
                    std::cout << "Element not found.\n";
                break;
            }
            case 'f':
            case 'F':
                displayMatrix(arr, rows, cols);
                break;
            case 'g':
            case 'G':
                std::cout << "Exiting the program.\n";
                return 0;
            default:
                std::cout << "Invalid choice.\n";
        }

    } while (true);

    return 0;
}
