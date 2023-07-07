#include <iostream>
#define MAX_SIZE 5
using namespace std;

class Queue {
private:
    int myQueue[MAX_SIZE], front, rear;
public:
    Queue () {
        front = -1;
        rear = -1;
    }

    void qinsert(int item) {
        if (rear == MAX_SIZE-1) {
            cout<<"\nQUEUE OVERFLOW (" << item <<  ")";
        }
        else if (front==-1 && rear==-1) {
            front=rear=0;
            myQueue[rear]=item;
            cout<<"\nITEM INSERTED: "<<item;
        } else {
            rear++;
            myQueue[rear]=item;
            cout<<"\nITEM INSERTED: "<<item;
        }
    }

    void qdelete(){
        int item;
        if(rear==-1){
            cout<<"\nQUEUE UNDERFLOW";
        }
        else if(front==0 && rear==0){
            item = myQueue[front];
            front=rear=-1;
            cout<<"\n\nITEM DELETED: "<<item;
        } else {
            item=myQueue[front];
            front++;
            cout<<"\n\nITEM DELETED: "<<item;
        }
    }

    void qtraverse() {
        if(front==-1) {
            cout<<"\n\nQUEUE IS EMPTY\n";
        } else {
            cout<<"\n\nQUEUE ITEMS\n";
            for (int i=front;i<=rear;i++) {
                cout<< myQueue[i] <<" ";
            }
            cout<<endl;
        }
    }
};

int main () {
    Queue myq;
    char choice;

    do {
        cout << "\nChoose an option:" << endl;
        cout << "a. Insert" << endl;
        cout << "b. Delete" << endl;
        cout << "c. Traverse" << endl;
        cout << "d. Exit" << endl;

        cin >> choice;

        switch (choice) {
            case 'a':
                int item;
                cout << "Enter item to insert: ";
                cin >> item;
                myq.qinsert(item);
                break;
            case 'b':
                myq.qdelete();
                break;
            case 'c':
                myq.qtraverse();
                break;
            case 'd':
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (true);

    return 0;
}
