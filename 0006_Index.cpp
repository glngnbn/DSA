#include <iostream>

int ARRAY_SIZE = 15;

void displayArray(int arr[], int size) {
    std::cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void addElement(int arr[], int& size, int index) {
    if (size < ARRAY_SIZE && index >= 0 && index <= size) {
        int element;
        std::cout << "Enter the element to add: ";
        std::cin >> element;

        for (int i = size; i > index; i--) {
            arr[i] = arr[i - 1];
        }

        arr[index] = element;
        size++;
        std::cout << "Element added successfully!" << std::endl;
    } else {
        std::cout << "Invalid index or array is full! No element added." << std::endl;
    }
}

void deleteElement(int arr[], int& size, int index) {
    if (size > 0 && index >= 0 && index < size) {
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        std::cout << "Element at index " << index << " deleted successfully!" << std::endl;
    } else {
        std::cout << "Invalid index! No element deleted." << std::endl;
    }
}

void searchElement(int arr[], int size, int index) {
    if (index >= 0 && index < size) {
        std::cout << "Element at index " << index << ": " << arr[index] << std::endl;
    } else {
        std::cout << "Invalid index! No element found." << std::endl;
    }
}

int main() {
    int arr[ARRAY_SIZE];
    int size = 0;
    char choice;

    std::cout << "Enter 5 elements: " << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cin >> arr[i];
        size++;
    }

    do {
        std::cout << "Menu:\n";
        std::cout << "a. Add\n";
        std::cout << "b. Delete\n";
        std::cout << "c. Search\n";
        std::cout << "d. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 'a':
                int index;
                std::cout << "Enter the index at which to add the element: ";
                std::cin >> index;
                addElement(arr, size, index);
                displayArray(arr, size);
                break;
            case 'b':
                std::cout << "Enter the index of the element to delete: ";
                std::cin >> index;
                deleteElement(arr, size, index);
                displayArray(arr, size);
                break;
            case 'c':
                std::cout << "Enter the index of the element to search: ";
                std::cin >> index;
                searchElement(arr, size, index);
                break;
            case 'd':
                std::cout << "Exiting the program..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
        }
    } while (choice != 'd');

    return 0;
}
