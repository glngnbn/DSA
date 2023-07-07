//GUINOBAN, Glenn M. (CS-1302)
#include <iostream>

struct Node {
    int data;
    Node* next;
};

class Queue {
    Node* front;
    Node* back;

    void enqueue(int element) {
        Node* newNode = new Node;
        newNode->data = element;
        newNode->next = NULL;

        if (isEmpty()) {
            front = back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }

        std::cout << "Element added successfully!" << std::endl;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot delete element." << std::endl;
            return;
        }

        Node* temp = front;
        std::cout << "Deleted element: " << temp->data << std::endl;

        if (front == back) {
            front = back = NULL;
        } else {
            front = front->next;
        }

        delete temp;
    }

    int searchElement(int element) {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot search for element." << std::endl;
            return -1;
        }

        Node* current = front;
        int index = 0;
        while (current != NULL) {
            if (current->data == element) {
                return index;
            }
            current = current->next;
            index++;
        }

        return -1;
    }

    bool isEmpty() const {
        return front == NULL;
    }

    void displayElements() const {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }

        Node* current = front;
        std::cout << "Elements: ";
        while (current != NULL) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    int identifyLargestInteger() const {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot identify largest integer." << std::endl;
            return -1;
        }

        int largest = front->data;

        Node* current = front->next;
        while (current != NULL) {
            if (current->data > largest) {
                largest = current->data;
            }
            current = current->next;
        }

        return largest;
    }

public:
    Queue() : front(NULL), back(NULL) {}

    ~Queue() {
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        back = NULL;
    }

    void performOperations() {
        char choice;

        do {
            std::cout << "QUEUE" << std::endl;
            std::cout << "a. Add" << std::endl;
            std::cout << "b. Delete" << std::endl;
            std::cout << "c. Search" << std::endl;
            std::cout << "d. Display" << std::endl;
            std::cout << "e. Largest" << std::endl;
            std::cout << "f. Exit" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 'a': {
                    int element;
                    std::cout << "Enter the element to add: ";
                    std::cin >> element;

                    if (std::cin.fail()) {
                        std::cout << "Invalid input. Please enter an integer." << std::endl;
                        std::cin.clear();
                        while (std::cin.get() != '\n');
                        break;
                    }

                    enqueue(element);
                    break;
                }
                case 'b':
                    dequeue();
                    break;
                case 'c': {
                    int element;
                    std::cout << "Enter the element to search: ";
                    std::cin >> element;

                    if (std::cin.fail()) {
                        std::cout << "Invalid input. Please enter an integer." << std::endl;
                        std::cin.clear();
                        while (std::cin.get() != '\n');
                        break;
                    }

                    int index = searchElement(element);
                    if (index != -1) {
                        std::cout << "Element Index: " << index << std::endl;
                    } else {
                        std::cout << "Element not found." << std::endl;
                    }
                    break;
                }
                case 'd':
                    displayElements();
                    break;
                case 'e': {
                    int largest = identifyLargestInteger();
                    if (largest != -1) {
                        std::cout << "Largest integer: " << largest << std::endl;
                    }
                    break;
                }
                case 'f':
                    std::cout << "Exiting the program..." << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Try again." << std::endl;
            }

            std::cout << std::endl;
        } while (choice != 'f');
    }
};

int main() {
    Queue myQueue;
    myQueue.performOperations();

    return 0;
}
