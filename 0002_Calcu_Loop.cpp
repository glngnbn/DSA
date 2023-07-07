#include <iostream>
#include <string>

using namespace std;

double perf_op(double num1, double num2, char op) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        default:
            return 0;
    }
}

bool is_valid_expression(const string& input) {
    const string validOperators = "+-*/";
    for (size_t i = 0; i < input.length(); i++) {
        if (input[i] == ' ') {
            continue;
        } else if (isdigit(input[i])) {
            while (i < input.length() && (isdigit(input[i]) || input[i] == '.')) {
                i++;
            }
            i--;
        } else if (validOperators.find(input[i]) == string::npos) {
            return false;
        }
    }
    return true;
}

int main() {
    const int max_size = 100;
    double numbers[max_size];
    char operations[max_size];
    string input;
    double number;
    char operation;
    int index = 0;

    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        cout << "CALCULATOR\nEXPRESSION: ";
        getline(cin, input);

        if (!is_valid_expression(input)) {
            cout << "Invalid input. Please enter a valid expression." << endl;
            continue; 
        }
        
        for (size_t i = 0; i < input.length(); i++) {
            if (input[i] == ' ') {
                continue;
            } else if (isdigit(input[i])) {
                string numStr;
                while (i < input.length() && (isdigit(input[i]) || input[i] == '.')) {
                    numStr += input[i];
                    i++;
                }
                i--;
                numbers[index] = stod(numStr);
                index++;
            } else {
                operations[index - 1] = input[i];
            }
        }
        
        double result = numbers[0];
        for (int i = 1; i < index; i++) {
            result = perf_op(result, numbers[i], operations[i - 1]);
        }
    
        cout << "RESULT: " << result << endl;
    
        while (true) {
            cout << "Do you want to try again? (y/n): ";
            cin >> choice;
            cin.ignore();

            if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N') {
                break;
            }
            
            cout << "Invalid input. Please enter 'y' or 'n'." << endl;
        }
        
        index = 0;
    }

    return 0;
}