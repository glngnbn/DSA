#include <iostream>

int main() {
    int count = 0;
    int sum = 0;
    int largest = INT_MIN;
    int smallest = INT_MAX;
    char choice;
    
    do {
        std::cout << "Choose an option:\n";
        std::cout << "a. Average\n";
        std::cout << "b. Largest\n";
        std::cout << "c. Smallest\n";
        std::cout << "d. Exit\n";
        std::cout << "Choose a letter: ";
        std::cin >> choice;
        
        if (choice == 'a') {
            sum = 0;
            count = 0;
            
            std::cout << "Enter 10 numbers:\n";
            
            for (int i = 0; i < 10; ++i) {
                int num;
                std::cin >> num;
                sum += num;
                ++count;
            }
            
            double average = static_cast<double>(sum) / count;
            std::cout << "Average: " << average << std::endl;
        } else if (choice == 'b') {
            largest = INT_MIN;
            
            std::cout << "Enter 10 numbers:\n";
            
            for (int i = 0; i < 10; ++i) {
                int num;
                std::cin >> num;
                
                if (num > largest) {
                    largest = num;
                }
            }
            
            std::cout << "Largest: " << largest << std::endl;
        } else if (choice == 'c') {
            smallest = INT_MAX;
            
            std::cout << "Enter 10 numbers:\n";
            
            for (int i = 0; i < 10; ++i) {
                int num;
                std::cin >> num;
                
                if (num < smallest) {
                    smallest = num;
                }
            }
            
            std::cout << "Smallest: " << smallest << std::endl;
        } else if (choice == 'd') {
            std::cout << "Exiting the program...\n";
        } else {
            std::cout << "Invalid choice! Please try again.\n";
        }
        
        std::cout << std::endl;
        
    } while (choice != 'd');
    
    return 0;
}