#include <iostream>

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void add(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void remove(int value) {
        if (head == nullptr) {
            std::cout << "The list is empty." << std::endl;
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            std::cout << "Element " << value << " deleted from the list." << std::endl;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        if (current->next == nullptr) {
            std::cout << "Element " << value << " not found in the list." << std::endl;
            return;
        }

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        std::cout << "Element " << value << " deleted from the list." << std::endl;
    }

    bool search(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void display() {
        if (head == nullptr) {
            std::cout << "The list is empty." << std::endl;
            return;
        }

        std::cout << "Linked List: ";
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList list;
    int value;

    std::cout << "Enter 5 elements:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cin >> value;
        list.add(value);
    }

    char choice;

    while (true) {
        std::cout << std::endl;
        std::cout << "LINKED LIST" << std::endl;
        std::cout << "a. Add" << std::endl;
        std::cout << "b. Delete" << std::endl;
        std::cout << "c. Search" << std::endl;
        std::cout << "d. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 'a':
                std::cout << "Enter the element to add: ";
                std::cin >> value;
                list.add(value);
                std::cout << "Element " << value << " added to the list." << std::endl;
                list.display();
                break;
            case 'b':
                std::cout << "Enter the element to delete: ";
                std::cin >> value;
                list.remove(value);
                list.display();
                break;
            case 'c':
                std::cout << "Enter the element to search: ";
                std::cin >> value;
                if (list.search(value)) {
                    std::cout << "Element " << value << " found in the list." << std::endl;
                } else {
                    std::cout << "Element " << value << " not found in the list." << std::endl;
                }
                break;
            case 'd':
                std::cout << "Exiting..." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
