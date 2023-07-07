#include <iostream>
#define MAX 100

class Queue {
private:
    int queue[MAX];
    int front;
    int back;

public:
    Queue() {
        front = -1;
        back = -1;
    }

    bool isEmpty() {
        return (front == -1 && back == -1);
    }

    void display() {
        if (isEmpty()) {
            std::cout << "\nQueue is empty.";
            return;
        }

        std::cout << "\nQueue elements: ";
        for (int i = front; i <= back; i++) {
            std::cout << queue[i] << " ";
        }
    }

    void qinsert(int item) {
        if (back == MAX - 1) {
            std::cout << "\nQUEUE OVERFLOW";
        } else if (isEmpty()) {
            front = back = 0;
            queue[back] = item;
            std::cout << "\nITEM INSERTED: " << item;
        } else {
            back++;
            queue[back] = item;
            std::cout << "\nITEM INSERTED: " << item;
        }
    }

    void qdelete() {
        int item;

        if (isEmpty()) {
            std::cout << "\nQUEUE UNDERFLOW";
        } else if (front == back) {
            item = queue[front];
            front = back = -1;
            std::cout << "\n\nITEM DELETED: " << item;
        } else {
            item = queue[front];
            front++;
            std::cout << "\n\nITEM DELETED: " << item;
        }
    }
};

int main() {
    Queue myQueue;
    char choice;
    int item;

    do {
        std::cout << "\n\nQUEUE OPERATIONS";
        std::cout << "\na. Add";
        std::cout << "\nb. Delete";
        std::cout << "\nc. Display";
        std::cout << "\nd. Exit";
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        while (std::cin.get() != '\n');

        switch (choice) {
            case 'a':
                std::cout << "\nEnter the item to add: ";
                if (!(std::cin >> item)) {
                    std::cout << "\nInvalid input. Please enter a valid item.";
                    while (std::cin.get() != '\n');
                    continue;
                }
                myQueue.qinsert(item);
                break;
            case 'b':
                myQueue.qdelete();
                break;
            case 'c':
                myQueue.display();
                break;
            case 'd':
                std::cout << "\nExiting...";
                break;
            default:
                std::cout << "\nInvalid choice. Try again.";
        }
    } while (choice != 'd');

    return 0;
}
