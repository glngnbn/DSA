#include <iostream>
#include <string>

const int ARRAY_SIZE = 15;
const int MAX_INPUT = 10;

void addString(std::string array[], int& count) {
    if (count >= ARRAY_SIZE) {
        std::cout << "Array is full. Cannot add more strings." << std::endl;
        return;
    }

    std::string newString;
    std::cout << "Enter a new string: ";
    std::getline(std::cin >> std::ws, newString);

    array[count] = newString;
    count++;

    std::cout << "String added successfully!" << std::endl;

    std::cout << "Array elements:" << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << array[i] << std::endl;
    }
}

void deleteString(std::string array[], int& count) {
    std::string stringToDelete;
    std::cout << "Enter the string to delete: ";
    std::getline(std::cin >> std::ws, stringToDelete);

    int deletions = 0;
    for (int i = 0; i < count; i++) {
        if (array[i] == stringToDelete) {
            for (int j = i; j < count - 1; j++) {
                array[j] = array[j + 1];
            }
            count--;
            deletions++;
            i--;
        }
    }

    if (deletions == 0) {
        std::cout << "String not found." << std::endl;
    }
    else {
        std::cout << "Array elements:" << std::endl;
        for (int i = 0; i < count; i++) {
            std::cout << array[i] << std::endl;
        }
    }
}

void searchArray(const std::string array[], int count) {
    std::string searchString;
    std::cout << "Enter the string to search for: ";
    std::getline(std::cin >> std::ws, searchString);

    bool found = false;
    std::cout << "String found at index: ";
    for (int i = 0; i < count; i++) {
        if (array[i] == searchString) {
            found = true;
            std::cout << i << " ";
        }
    }

    if (!found) {
        std::cout << "String not found." << std::endl;
    }
    else {
        std::cout << std::endl;
    }
}

int main() {
    std::string array[ARRAY_SIZE];
    int count = 0;

    std::cout << "Enter " << MAX_INPUT << " Strings" << std::endl;
    for (int i = 0; i < MAX_INPUT; i++) {
        std::string input;
        std::cout << "String " << i + 1 << " : ";
        std::getline(std::cin >> std::ws, input);
        array[count] = input;
        count++;
    }

    while (true) {
        std::cout << "\nMAIN MENU\n";
        std::cout << "a. add\n";
        std::cout << "b. delete\n";
        std::cout << "c. search\n";
        std::cout << "d. exit\n";
        std::cout << "Choose a letter: ";

        char choice;
        std::cin >> choice;

        switch (choice) {
            case 'a':
                addString(array, count);
                break;
            case 'b':
                deleteString(array, count);
                break;
            case 'c':
                searchArray(array, count);
                break;
            case 'd':
                std::cout << "Exiting program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
