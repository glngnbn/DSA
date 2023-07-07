#include <iostream>
#include <map>

struct Contact {
    std::string phoneNumber;
    std::string address;
};

class PhoneBook {
private:
    std::map<std::string, Contact> contacts;

public:
    void addContact() {
        Contact contact;
        std::string name, phoneNumber, address;
        std::cout << "Enter name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Enter phone number: ";
        std::getline(std::cin, phoneNumber);
        std::cout << "Enter address: ";
        std::getline(std::cin, address);
        contact.phoneNumber = phoneNumber;
        contact.address = address;
        contacts[name] = contact;
        std::cout << "Contact added successfully." << std::endl;
    }

    void deleteContact() {
        std::string name;
        std::cout << "Enter name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        auto it = contacts.find(name);
        if (it != contacts.end()) {
            contacts.erase(it);
            std::cout << "Contact deleted successfully." << std::endl;
        } else {
            std::cout << "Contact not found." << std::endl;
        }
    }

    void searchPhoneNumber() {
        std::string name;
        std::cout << "Enter name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        auto it = contacts.find(name);
        if (it != contacts.end()) {
            std::cout << "Phone number: " << it->second.phoneNumber << std::endl;
        } else {
            std::cout << "Contact not found." << std::endl;
        }
    }

    void searchAddress() {
        std::string name;
        std::cout << "Enter name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        auto it = contacts.find(name);
        if (it != contacts.end()) {
            std::cout << "Address: " << it->second.address << std::endl;
        } else {
            std::cout << "Contact not found." << std::endl;
        }
    }
};

int main() {
    PhoneBook phoneBook;

    while (true) {
        int choice;
        std::cout << "Electronic Phone Book" << std::endl;
        std::cout << "1. Add Contact" << std::endl;
        std::cout << "2. Delete Contact" << std::endl;
        std::cout << "3. Search Phone Number" << std::endl;
        std::cout << "4. Search Address" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                phoneBook.addContact();
                break;

            case 2:
                phoneBook.deleteContact();
                break;

            case 3:
                phoneBook.searchPhoneNumber();
                break;

            case 4:
                phoneBook.searchAddress();
                break;

            case 5:
                std::cout << "Thank You!";
                return 0;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

        std::cout << std::endl;
    }
}