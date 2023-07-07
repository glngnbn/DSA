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
        head = nullptr;
    }

    void addToStart(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        cout << "Added " << value << " at the start of the list." << endl;
    }

    void addToEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Added " << value << " at the end of the list." << endl;
    }

    void addToPosition(int value, int position) {
        if (position <= 0) {
            addToStart(value);
            return;
        }

        int count = 1;
        Node* temp = head;
        while (temp != nullptr && count < position) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr) {
            cout << "Position exceeds the size of the list." << endl;
        } else {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Added " << value << " at position " << position << " in the list." << endl;
        }
    }

    void deleteFromStart() {
        if (head == nullptr) {
            cout << "The list is already empty." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted node from the start of the list." << endl;
    }

    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "The list is already empty." << endl;
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            cout << "Deleted the only node in the list." << endl;
            return;
        }

        Node* prev = nullptr;
        Node* current = head;
        while (current->next != nullptr) {
            prev = current;
            current = current->next;
        }
        delete current;
        prev->next = nullptr;
        cout << "Deleted node from the end of the list." << endl;
    }

    void deleteFromPosition(int position) {
        if (position <= 0 || head == nullptr) {
            deleteFromStart();
            return;
        }

        int count = 1;
        Node* prev = nullptr;
        Node* current = head;
        while (current != nullptr && count < position) {
            prev = current;
            current = current->next;
            count++;
        }

        if (current == nullptr) {
            cout << "Position exceeds the size of the list." << endl;
        } else {
            prev->next = current->next;
            delete current;
            cout << "Deleted node from position " << position << " in the list." << endl;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    int value, position;
    char choice;

    while (true) {
    	cout << "LINKED LIST\n";
        cout << "a. Add\n";
        cout << "b. Delete\n";
        cout << "c. Display\n";
        cout << "d. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'a':
                cout << "Enter the value to add: ";
                cin >> value;

                cout << "Where do you want to add?\n";
                cout << "1. Start\n";
                cout << "2. End\n";
                cout << "3. Specific position\n";
                cout << "Enter your choice: ";
                cin >> position;

                switch (position) {
                    case 1:
                        list.addToStart(value);
                        break;
                    case 2:
                        list.addToEnd(value);
                        break;
                    case 3:
                        cout << "Enter the position to add: ";
                        cin >> position;
                        list.addToPosition(value, position);
                        break;
                    default:
                        cout << "Invalid position choice." << endl;
                }
                break;

            case 'b':
                cout << "Where do you want to delete?\n";
                cout << "1. Start\n";
                cout << "2. End\n";
                cout << "3. Specific position\n";
                cout << "Enter your choice: ";
                cin >> position;

                switch (position) {
                    case 1:
                        list.deleteFromStart();
                        break;
                    case 2:
                        list.deleteFromEnd();
                        break;
                    case 3:
                        cout << "Enter the position to delete: ";
                        cin >> position;
                        list.deleteFromPosition(position);
                        break;
                    default:
                        cout << "Invalid position choice." << endl;
                }
                break;

            case 'c':
                list.display();
                break;

            case 'd':
                exit(0);

            default:
                cout << "Invalid choice." << endl;
        }

        cout << endl;
    }

    return 0;
}