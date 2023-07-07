#include <iostream>
using namespace std;

struct Node {
    int num;
    Node* next;
};

Node* head = nullptr;

void insert_Node(int n) {
    Node* new_node = new Node;
    new_node->num = n;
    new_node->next = head;
    head = new_node;
    cout << "Node with value " << n << " inserted." << endl;
}

int count_nodes() {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void display_all_nodes() {
    Node* temp = head;
    if (temp == nullptr) {
        cout << "Linked List is empty." << endl;
        return;
    }

    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->num << " ";
        temp = temp->next;
    }
    cout << endl;
}

void exit_program() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    cout << "Exiting the program." << endl;
}

int main() {
    while (true) {
        cout << "Menu:" << endl;
        cout << "a. Add" << endl;
        cout << "b. Count the number of nodes" << endl;
        cout << "c. Display Linked List" << endl;
        cout << "d. Exit" << endl;
        cout << "Enter your choice: ";
        char choice;
        cin >> choice;

        switch (choice) {
            case 'a': {
                cout << "Enter the value to insert: ";
                int value;
                if (!(cin >> value)) {
                    cout << "Invalid input. Please enter an integer value." << endl;
                    cin.clear();
                    while (cin.get() != '\n')
                        continue;
                    break;
                }
                insert_Node(value);
                break;
            }
            case 'b': {
                int count = count_nodes();
                cout << "Number of nodes: " << count << endl;
                break;
            }
            case 'c':
                display_all_nodes();
                break;
            case 'd':
                exit_program();
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                cin.clear();
                while (cin.get() != '\n')
                    continue;
        }

        cout << endl;
    }
}
