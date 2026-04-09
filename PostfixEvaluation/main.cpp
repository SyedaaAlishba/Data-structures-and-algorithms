#include <iostream>
#include <stack>
using namespace std;

int evaluatePostfix(string eq) {
    stack<int> st;
    for (int i = 0; i < eq.length(); i++) {
        char c = eq[i];
        if (c>'0' && c<='9') {
            st.push(c-'0');
        }
        else {
            int val2= st.top();
            st.pop();
            int val1 = st.top();
            st.pop();
            int result;
            switch (c) {
                    case '+':
                    result = val1 + val2;
                    break;
                    case '-':
                    result = val1 - val2;
                    break;
                    case '*':
                    result = val1 * val2;
                    break;
                    case '/':
                    result = val1 / val2;
            }
            st.push(result);
        }
    }
    return st.top();

}
int main() {
    cout<<"Enter an expression: ";
    string expr;
    cin>>expr;
    int result = evaluatePostfix(expr);
    cout<<result;



}