#include <iostream>

class LinkedList {
private:
    struct Node {
        int num;
        Node* next;
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert_Node(int n) {
        Node* new_node = new Node;
        new_node->num = n;
        new_node->next = head;
        head = new_node;
    }

    void display_all_nodes() {
        std::cout << "The list contains the data entered:" << std::endl;
        Node* temp = head;

        while (temp != nullptr) {
            std::cout << temp->num << " ";
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList linkedList;
    linkedList.insert_Node(1);
    linkedList.insert_Node(3);
    linkedList.insert_Node(15);
    linkedList.insert_Node(7);
    linkedList.insert_Node(9);
    linkedList.insert_Node(11);
    linkedList.display_all_nodes();

    return 0;
}
