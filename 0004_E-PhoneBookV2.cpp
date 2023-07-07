#include <iostream>
#include <string>

const int max_size = 10;

struct Contact {
    std::string name;
    std::string phoneNumber;
    std::string address;
};

void addContact(Contact phoneBook[], int& size) {
    if (size >= max_size) {
        std::cout << "Phone book is full. Cannot add more contacts." << std::endl;
        return;
    }

    Contact newContact;
    std::cout << "Enter name: ";
    std::cin.ignore();
    std::getline(std::cin, newContact.name);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, newContact.phoneNumber);
    std::cout << "Enter address: ";
    std::getline(std::cin, newContact.address);

    phoneBook[size] = newContact;
    size++;

    std::cout << "Contact added successfully." << std::endl;
}

void deleteContact(Contact phoneBook[], int& size) {
    if (size == 0) {
        std::cout << "Phone book is empty. No contacts to delete." << std::endl;
        return;
    }

    std::string name;
    std::cout << "Enter the name of the contact to delete: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    bool contactFound = false;
    for (int i = 0; i < size; i++) {
        if (phoneBook[i].name == name) {
            contactFound = true;

            for (int j = i; j < size - 1; j++) {
                phoneBook[j] = phoneBook[j + 1];
            }

            size--;
            std::cout << "Contact deleted successfully." << std::endl;
            break;
        }
    }

    if (!contactFound) {
        std::cout << "Contact not found." << std::endl;
    }
}

void searchPhoneNumber(const Contact phoneBook[], int size) {
    std::string name;
    std::cout << "Enter the name to search for phone number: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    bool contactFound = false;
    for (int i = 0; i < size; i++) {
        if (phoneBook[i].name == name) {
            contactFound = true;
            std::cout << "Phone number: " << phoneBook[i].phoneNumber << std::endl;
            break;
        }
    }

    if (!contactFound) {
        std::cout << "Contact not found." << std::endl;
    }
}

void searchAddress(const Contact phoneBook[], int size) {
    std::string name;
    std::cout << "Enter the name to search for address: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    bool contactFound = false;
    for (int i = 0; i < size; i++) {
        if (phoneBook[i].name == name) {
            contactFound = true;
            std::cout << "Address: " << phoneBook[i].address << std::endl;
            break;
        }
    }

    if (!contactFound) {
        std::cout << "Contact not found." << std::endl;
    }
}

int main() {
    Contact phoneBook[max_size];
    int size = 0;

    int choice;
    do {
        std::cout << "Phone Book Menu" << std::endl;
        std::cout << "1. Add a contact" << std::endl;
        std::cout << "2. Delete a contact" << std::endl;
        std::cout << "3. Search for a phone number" << std::endl;
        std::cout << "4. Search for an address" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addContact(phoneBook, size);
                break;
            case 2:
                deleteContact(phoneBook, size);
                break;
            case 3:
                searchPhoneNumber(phoneBook, size);
                break;
            case 4:
                searchAddress(phoneBook, size);
                break;
            case 5:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

        std::cout << std::endl;
    } while (choice != 5);

    return 0;
}
