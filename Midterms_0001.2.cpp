#include <iostream>
using namespace std;

class LinkedList {
private:
    struct Node {
        int num;
        Node* next;
    };

    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertNode(int n) {
        Node* new_node = new Node;
        new_node->num = n;
        new_node->next = head;
        head = new_node;
    }

    int countNodes() {
        Node* tmp = head;
        int ctr = 0;
        while (tmp != NULL) {
            ctr++;
            tmp = tmp->next;
        }
        return ctr;
    }

    void displayAllNodes() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->num << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList linkedList;
    char option;

    do {
        cout << "Select an option:" << endl;
        cout << "a. Insert" << endl;
        cout << "b. Count the number of nodes" << endl;
        cout << "c. Display the linked list" << endl;
        cout << "d. Exit" << endl;
        cin >> option;

        switch (option) {
            case 'a': {
                int value;
                cout << "Enter a number to insert: ";
                cin >> value;
                linkedList.insertNode(value);
                cout << "Number inserted." << endl;
                break;
            }
            case 'b': {
                int nodeCount = linkedList.countNodes();
                cout << "Number of nodes in the linked list: " << nodeCount << endl;
                break;
            }
            case 'c': {
                cout << "Linked List: ";
                linkedList.displayAllNodes();
                break;
            }
            case 'd': {
                cout << "Exiting..." << endl;
                break;
            }
            default: {
                cout << "Invalid option. Please try again." << endl;
                break;
            }
        }
    } while (option != 'd');

    return 0;
}
