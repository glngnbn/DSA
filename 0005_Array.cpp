#include <iostream>

int ARRAY_SIZE = 15;

void displayArray(int arr[], int size) {
    std::cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void addElement(int arr[], int& size) {
    if (size < ARRAY_SIZE) {
        int element;
        std::cout << "Enter the element to add: ";
        std::cin >> element;
        arr[size] = element;
        size++;
        std::cout << "Element added successfully!" << std::endl;
    } else {
        std::cout << "Array is full! Cannot add more elements." << std::endl;
    }
}

void deleteElement(int arr[], int& size) {
    if (size > 0) {
        int element;
        std::cout << "Enter the element to delete: ";
        std::cin >> element;
        int foundIndex = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == element) {
                foundIndex = i;
                break;
            }
        }
        if (foundIndex != -1) {
            for (int i = foundIndex; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--;
            std::cout << "Element deleted successfully!" << std::endl;
        } else {
            std::cout << "Element not found in the array." << std::endl;
        }
    } else {
        std::cout << "Array is empty! No elements to delete." << std::endl;
    }
}

void searchElement(int arr[], int size) {
    int element;
    std::cout << "Enter the element to search: ";
    std::cin >> element;
    bool found = false;
    int foundIndex = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            found = true;
            foundIndex = i;
            break;
        }
    }
    if (found) {
        std::cout << "Element found at index " << foundIndex << "." << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
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
                addElement(arr, size);
                displayArray(arr, size);
                break;
            case 'b':
                deleteElement(arr, size);
                displayArray(arr, size);
                break;
            case 'c':
                searchElement(arr, size);
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