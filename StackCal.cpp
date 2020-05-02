#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <cmath>

using namespace std;

string removeSpaces(string str);
void evaluate(string &input, vector<string> infix);
void infixtopostfix(vector<string> infix, vector<string> postfix);
int getpriority(char op);
int calculate(vector<string> postfix);

template <class T>
class stack{
private:
    T num[1000];
    int index;

public:
    stack(){
        index = -1;
    }

    void push(T data){
        num[++index] = data;      // 왜안돼징;
    }

    T pop(){
        return num[index--];    //이거맞나;
    }

    T peek(){
        return num[index];
    }

    bool isempty(){
        if (index == -1) return true;
        else return false;
    }

    int length(){
        return index;
    }

};

int main(){
    string input;
    cin >> input;
    
    input = removeSpaces(input);
    
    vector<string> infix;
    vector<string> postfix;
    evaluate(input, infix);

    for(int i =0; i<infix.size(); i++) cout << infix[i] << endl;

    infixtopostfix(infix, postfix);

    cout << calculate(postfix) << endl;

}

string removeSpaces(string str)  
{ 
    str.erase(remove(str.begin(), str.end(), ' '), str.end()); 
    return str; 
} 

void evaluate(string &input, vector<string> infix){
    //if (input.at(1) == '-')  = '-';

    regex pattern("[\\d*|\\D]"); 
    sregex_iterator it(input.begin(), input.end(), pattern);
    sregex_iterator end;
    
    while(it != end){
        smatch m = *it;
        cout << m.str(0).c_str() << m.str(1).c_str() << endl;
        infix.push_back(m.str(0).c_str());
        it++;
    }
    //operand1 = m.str(1).c_str();
    //operand2 = m.str(3).c_str();
    //op = m.str(2).c_str()[0];
    //cout << operand1 << ' ' << operand2 << endl;

}

void infixtopostfix(vector<string> infix, vector<string> postfix){
    stack<char> infix_stack = stack<char>();

    for(int i=0; i<infix.size(); i++)
    {
        string op = infix[i];
        
        if (isdigit(op.at(0)))
        {
            postfix.push_back(op);
        }
        else {
            char oper = op.at(0);
            if (oper == ')')
            {
                while (infix_stack.peek() != '('){
                    postfix.push_back(string(1, infix_stack.pop()));
                }
                infix_stack.pop();
            }
            else {
                while (!infix_stack.isempty() && infix_stack.peek() != '(' && getpriority(infix_stack.peek()) >= getpriority(oper))
                {
                    postfix.push_back(string(1,infix_stack.pop()));
                }
                infix_stack.push(oper);
            }
            
        }
        
    }
    while (!infix_stack.isempty()){
        postfix.push_back(string(1, infix_stack.pop()));
    }
    
}

int getpriority(char op){
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/' || op == '%'){
        return 2;
    }
    else if (op == '^'){
        return 3;
    }
    else if (op == '(' || op == ')'){
        return 4;
    }
    
}

int calculate(vector<string> postfix){
    stack<int> postfix_stack = stack<int>();

    for (int i = 0; i < postfix.size(); i++)
    {
        string op = postfix[i];
        if (isdigit(op.at(0)))
        {
            postfix_stack.push(atoi(op.c_str()));
        }
        else {
            int res;
            int b = postfix_stack.pop();
            int a = postfix_stack.pop();
            switch (op.at(0))
            {
            case '+':
                res = a + b;
                break;

            case '-':
                res = a - b;
                break;  

            case '*':
                res = a * b;
                break;

            case '/':
                res = a / b;
                break;

            case '%':
                res = a % b;
                break;

            case '^':
                res = (int)pow(a, b);
                break;
            }
            postfix_stack.push(res);
        }
    }
    return postfix_stack.pop();
}