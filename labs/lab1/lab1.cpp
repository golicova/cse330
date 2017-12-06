#include <iostream>
#include <stack>
#include <string>

using namespace std;

int prec(char in)
{
    switch (in) {
        case '(': return 0; 
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2; 
        default: return 3; 
    }
} 

int main()
{
    stack <char> mystack;
    char next_character; 
    cin >> next_character;
    
    while (!cin.eof()) {
        if((next_character >= 'a' and next_character <= 'z') or
           (next_character >= 'A' and next_character <= 'Z') or
           (next_character >= '0' and next_character <= '9')) {
                cout << next_character;

           }
        else {
            if(next_character == '(')
                mystack.push(next_character);
            else if(next_character == ')') {
                while(!mystack.empty() && mystack.top() != '(') {
                    cout << mystack.top();
                    mystack.pop();
                }
                if(!mystack.empty())
                    mystack.pop();
                else {
                    cout << "Error.";
                    break;
                }
            }
            else if(next_character == '*' || next_character == '/' || next_character == '+' || next_character == '-') {
                if(mystack.empty() || prec(mystack.top()) < prec(next_character))
                    mystack.push(next_character);
                else {
                    if(prec(mystack.top()) >= prec(next_character)) {
                        while(!mystack.empty() && prec(mystack.top()) >= prec(next_character)) {
                            cout << mystack.top();
                            mystack.pop();
                        }
                    }
                    mystack.push(next_character);
                }
            }
        }
        cin >> next_character;
    }
    
    while(!mystack.empty()) {
        cout << "-";
        cout << mystack.top();
        mystack.pop();
    }
}
