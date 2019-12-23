#include <iostream>
using namespace std;

void add(string &int1, string &int2, string &result);
void sub(string &int1, string &int2, string &result);
void mul(string &int1, string &int2, string &result);

int main(){
    string input;
    cin >> input;
    string int1, int2;
    char op;
    string result ="";
    for (int i = 0; i < input.size(); i++)
    {
        if (input.at(i) == '+' || input.at(i) == '-' || input.at(i) == '*'){
            int1 = input.substr(0,i);
            int2 = input.substr(i+1);
            op = input.at(i);
            break;
        }
    }
    
    if (op == '+')
    {
        add(int1, int2, result);
        cout << result << endl;
    }
    else if (op == '-'){
        sub(int1, int2, result);
        cout << result << endl;
    }
    else if (op == '*'){
        mul(int1, int2, result);
        cout << result << endl;
    }
    



}

void add(string &int1, string &int2, string &result){
    
    int size = max(int1.size(), int2.size());
    int* a = new int[size];
    int* b = new int[size];
    int* res = new int[size+1];
    for (int i = 0; i < int1.size(); i++)
    {
        a[i] = int1.at(int1.size()-i-1) - '0';
    }
    for (int i = 0; i < int2.size(); i++)
    {
        b[i] = int2.at(int2.size()-i-1) - '0';
    }

    for (int i = 0; i < max(int1.size(), int2.size()); i++)
    {
        res[i] += a[i] + b[i];
        res[i+1] = res[i]/10;
        res[i] = res[i]%10;
    }
    
    for (int i = 0; i < size+1; i++)
    {
        cout << result << endl;
        if(i == 0 && res[size] == 0) continue;
        result += to_string(res[size-i]);
    }

}

void sub(string &int1, string &int2, string &result){



}

void mul(string &int1, string &int2, string &result){

}