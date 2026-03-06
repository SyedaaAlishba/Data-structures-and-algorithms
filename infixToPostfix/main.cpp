#include <iostream>
using namespace std;

#define SIZE 20

char stackArr[SIZE];
int top = -1;


bool isOverflow() {
    return (top == SIZE - 1);
}

bool isUnderflow() {
    return (top == -1);
}

void push(char data) {
    if (isOverflow()) {
        cout << "Stack Overflow! Cannot push " << data << endl;
        return;
    }
    stackArr[++top] = data;
}
char peek() {
    if (isUnderflow())
        return '\0';
    return stackArr[top];
}

char pop() {
    if (isUnderflow()) {
        cout << "Stack Underflow!" << endl;
        return '\0';
    }
    return stackArr[top--];
}

void display() {
    if (isUnderflow()) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack elements (top to bottom): ";
    for (int i = top; i >= 0; i--) {
        cout << stackArr[i] << " ";
    }
    cout << endl;
}
int precedence(char op) {
    if(op == '^')
        return 3;
    else if(op == '*' || op == '/' || op == '%')
        return 2;
    else if(op == '+' || op == '-')
        return 1;
    else
        return 0;
}

bool isOperand(char c) {
    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return true;
    return false;
}



int main() {
    string postfix="";
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;
    for(int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if (isOperand(c)) {
            postfix.append(1, c);
        }else if(c == '(')
        {
           push(c);
        }else if(c == ')') {
            while (!isUnderflow() && peek()!='(') {
                postfix.append(1, pop());
            }
            pop();
        }else
        {
            while(!isUnderflow() && precedence(peek()) >= precedence(c))
            {
                postfix += pop();
            }

            push(c);
        }
    }
    while(!isUnderflow())
    {
        postfix += pop();
    }
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}