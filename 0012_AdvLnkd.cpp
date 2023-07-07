#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void addAtStart(const string& value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        cout << "Value \"" << value << "\" added at the beginning" << endl;
    }

    void addAtEnd(const string& value) {
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

        cout << "Value \"" << value << "\" added at the end" << endl;
    }

    void addAtPosition(const string& value, int position) {
        if (position <= 0) {
            cout << "Invalid position.\n" << endl;
            return;
        }

        Node* newNode = new Node;
        newNode->data = value;

        if (position == 1) {
            newNode->next = head;
            head = newNode;
            cout << "Value \"" << value << "\" added at position " << position << endl;
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
        cout << "Element \"" << value << "\" added at position " << position << endl;
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

    void deleteByValue(const string& value) {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        while (temp != NULL && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Value not found in the list." << endl;
            return;
        }

        if (prev == NULL) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
        cout << "Deleted the node with value \"" << value << "\"" << endl;
    }

    void searchByValue(const string& value) {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = head;
        int position = 1;
        bool found = false;

        while (temp != NULL) {
            if (temp->data == value) {
                cout << "Value \"" << value << "\" found at position " << position << endl;
                found = true;
            }
            temp = temp->next;
            position++;
        }

        if (!found) {
            cout << "Value \"" << value << "\" not found in the list." << endl;
        }
    }

    void searchByPosition(int position) {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }

        if (position <= 0) {
            cout << "Invalid position. Please enter a positive position value." << endl;
            return;
        }

        Node* temp = head;
        int currentPosition = 1;

        while (temp != NULL && currentPosition < position) {
            temp = temp->next;
            currentPosition++;
        }

        if (temp == NULL) {
            cout << "Invalid position." << endl;
            return;
        }

        cout << "Value at position " << position << ": \"" << temp->data << "\"" << endl;
    }

    void display() {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "Your List: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList linkedList;
    string value;
    int position;
    char choice;

    while (true) {
        cout << "MENU:\n";
        cout << "a. Add\n";
        cout << "b. Delete\n";
        cout << "c. Search\n";
        cout << "d. Display\n";
        cout << "e. Exit\n";
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
                        cout << "\nInvalid choice.\n";
                }
                break;
            case 'b':
                cout << "DELETE:\n";
                cout << "a. Start\n";
                cout << "b. End\n";
                cout << "c. Any Position\n";
                cout << "d. Value\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                    case 'a':
                        linkedList.deleteFromStart();
                        break;
                    case 'b':
                        linkedList.deleteFromEnd();
                        break;
                    case 'c':
                        cout << "Enter the position to delete: ";
                        cin >> position;
                        linkedList.deleteFromPosition(position);
                        break;
                    case 'd':
                        cout << "Enter the value to delete: ";
                        cin >> value;
                        linkedList.deleteByValue(value);
                        break;
                    default:
                        cout << "Invalid choice." << endl;
                }
                break;
            case 'c':
                cout << "SEARCH:\n";
                cout << "a. Value\n";
                cout << "b. Position\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                    case 'a':
                        cout << "Enter the value to search: ";
                        cin >> value;
                        linkedList.searchByValue(value);
                        break;
                    case 'b':
                        cout << "Enter the position to search: ";
                        cin >> position;
                        linkedList.searchByPosition(position);
                        break;
                    default:
                        cout << "Invalid choice." << endl;
                }
                break;
            case 'd':
                linkedList.display();
                break;
            case 'e':
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice." << endl;
        }

        cout << endl;
    }

    return 0;
}
