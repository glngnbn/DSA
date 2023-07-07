#include <iostream>
#include <string>
using namespace std;

struct stack_header {
    string* data;
    int top;
    int bottom;
    int capacity;
};

typedef struct stack_header* stack;

stack stack_new() {
    stack S = new struct stack_header;
    S->bottom = 0;
    S->top = -1;
    S->capacity = 100;
    S->data = new string[S->capacity];
    return S;
}

void push(stack S, string e) {
    if (S->top == S->capacity - 1) {
        throw overflow_error("Stack is full. Cannot push element.");
    }
    
    S->top++;
    S->data[S->top] = e;
}

string pop(stack S) {
    if (S->top == -1) {
        throw underflow_error("Stack is empty. Cannot pop element.");
    }
    
    string element = S->data[S->top];
    S->top--;
    return element;
}

void display(stack S) {
    if (S->top == -1) {
        cout << "Stack is empty." << endl;
        return;
    }
    
    cout << "Stack elements: ";
    for (int i = S->top; i >= 0; i--) {
        cout << S->data[i] << " ";
    }
    cout << endl;
}

int search(stack S, string e) {
    if (S->top == -1) {
        return -1;  // Stack is empty
    }
    
    for (int i = S->top; i >= 0; i--) {
        if (S->data[i] == e) {
            return S->top - i + 1;  // Position of the element from the top
        }
    }
    
    return -1;  // Element not found in stack
}

int main() {
    stack S = stack_new();
    int choice;
    string element;
    
    while (true) {
        cout << "Stack Operations:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Search" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter element to push: ";
                cin >> element;
                push(S, element);
                break;
                
            case 2:
                try {
                    element = pop(S);
                    cout << "Popped element: " << element << endl;
                } catch (const underflow_error& e) {
                    cout << e.what() << endl;
                }
                break;
                
            case 3:
                display(S);
                break;
                
            case 4:
                cout << "Enter element to search: ";
                cin >> element;
                int position = search(S, element);
                if (position != -1) {
                    cout << "Element found at position " << position << " from the top." << endl;
                } else {
                    cout << "Element not found in the stack." << endl;
                }
                break;
                
            case 5:
                cout << "Exiting..." << endl;
                delete[] S->data;
                delete S;
                return 0;
                
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        
        cout << endl;
    }
}
