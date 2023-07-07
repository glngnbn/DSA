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

    linkedList.insertNode(1);
    linkedList.insertNode(3);
    linkedList.insertNode(5);
    linkedList.insertNode(7);
    linkedList.insertNode(9);
    linkedList.insertNode(11);
    linkedList.insertNode(13);

    cout << "Original Linked List: ";
    linkedList.displayAllNodes();

    int nodeCount = linkedList.countNodes();
    cout << "Number of nodes in the linked list: " << nodeCount << endl;

    return 0;
}
