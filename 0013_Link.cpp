#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void addAtStart(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        cout << "Value " << value << " added at the beginning" << endl;
    }

    void addAtEnd(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        cout << "Value " << value << " added at the end" << endl;
    }

    void addAtPosition(int value, int position) {
        if (position <= 0) {
            cout << "Invalid position.\n" << endl;
            return;
        }

        Node* newNode = new Node;
        newNode->data = value;

        if (position == 1) {
            newNode->next = head;
            head = newNode;
            cout << "Value " << value << " added at position " << position << endl;
            return;
        }

        Node* temp = head;
        int currentPosition = 1;

        while (temp != NULL && currentPosition < position - 1) {
            temp = temp->next;
            currentPosition++;
        }

        if (temp == NULL) {
            cout << "Invalid position." << endl;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Element " << value << " added at position " << position << endl;
    }

    void deleteDuplicates(int value) {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }

        bool deleted = false;
        Node* current = head;
        Node* prev = NULL;

        while (current != NULL) {
            if (current->data == value) {
                if (prev == NULL) {
                    // Node to be deleted is the head node
                    head = current->next;
                    delete current;
                    current = head;
                } else {
                    // Node to be deleted is not the head node
                    prev->next = current->next;
                    delete current;
                    current = prev->next;
                }
                deleted = true;
            } else {
                prev = current;
                current = current->next;
            }
        }

        if (deleted) {
            cout << "All occurrences of value " << value << " deleted." << endl;
        } else {
            cout << "Value " << value << " not found in the list." << endl;
        }
    }

    void deleteFromStart() {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted the first element from the list." << endl;
    }

    void deleteFromEnd() {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            cout << "Deleted the last element from the list." << endl;
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
        cout << "Deleted the last element from the list." << endl;
    }

    void deleteFromPosition(int position) {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }

        if (position <= 0) {
            cout << "Invalid position. Please enter a positive position value." << endl;
            return;
        }

        if (position == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted the element at position " << position << endl;
            return;
        }

        Node* temp = head;
        int currentPosition = 1;

        while (temp->next != NULL && currentPosition < position - 1) {
            temp = temp->next;
            currentPosition++;
        }

        if (temp->next == NULL) {
            cout << "Invalid position." << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        cout << "Deleted the element at position " << position << endl;
    }

    void display() {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "Your List (head to tail): ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void compare() {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = head;
        int tailValue = temp->data;

        while (temp->next != NULL) {
            temp = temp->next;
            tailValue = temp->data;
        }

        if (head->data > tailValue) {
            cout << "Head node is larger." << endl;
        } else if (head->data < tailValue) {
            cout << "Tail node is larger." << endl;
        } else {
            cout << "Head and tail nodes have the same value." << endl;
        }
    }
};

int main() {
    LinkedList linkedList;
    int value, position;
    char choice;

    while (true) {
        cout << "MENU:\n";
        cout << "a. Add\n";
        cout << "b. Delete\n";
        cout << "c. Display\n";
        cout << "e. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'a':
                cout << "ADD:\n";
                cout << "a. Add\n";
                cout << "b. Display\n";
                cout << "c. Compare\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                    case 'a':
                        cout << "Enter the value to add: ";
                        cin >> value;
                        cout << "ADD:\n";
                        cout << "a. Start\n";
                        cout << "b. End\n";
                        cout << "c. Any Position\n";
                        cout << "Enter your choice: ";
                        cin >> choice;

                        switch (choice) {
                            case 'a':
                                linkedList.addAtStart(value);
                                break;
                            case 'b':
                                linkedList.addAtEnd(value);
                                break;
                            case 'c':
                                cout << "Enter the position to add: ";
                                cin >> position;
                                linkedList.addAtPosition(value, position);
                                break;
                            default:
                                cout << "Invalid choice." << endl;
                        }
                        break;
                    case 'b':
                        linkedList.display();
                        break;
                    case 'c':
                        linkedList.compare();
                        break;
                    default:
                        cout << "Invalid choice." << endl;
                }
                break;
            case 'b':
                cout << "DELETE:\n";
                cout << "a. Display\n";
                cout << "b. Delete\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                    case 'a':
                        linkedList.display();
                        break;
                    case 'b':
                        cout << "DELETE:\n";
                        cout << "a. Duplicates\n";
                        cout << "b. Start\n";
                        cout << "c. End\n";
                        cout << "d. Any Position\n";
                        cout << "Enter your choice: ";
                        cin >> choice;

                        switch (choice) {
                            case 'a':
                                cout << "Enter the value to delete all occurrences: ";
                                cin >> value;
                                linkedList.deleteDuplicates(value);
                                break;
                            case 'b':
                                linkedList.deleteFromStart();
                                break;
                            case 'c':
                                linkedList.deleteFromEnd();
                                break;
                            case 'd':
                                cout << "Enter the position to delete: ";
                                cin >> position;
                                linkedList.deleteFromPosition(position);
                                break;
                            default:
                                cout << "Invalid choice." << endl;
                        }
                        break;
                    default:
                        cout << "Invalid choice." << endl;
                }
                break;
            case 'c':
                linkedList.display();
                break;
            case 'e':
                exit(0);
            default:
                cout << "Invalid choice." << endl;
        }

        cout << endl;
    }

    return 0;
}
