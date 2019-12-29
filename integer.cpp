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
    int size = max(int1.size(), int2.size());
    int* a = new int[size];
    int* b = new int[size];
    int* res = new int[size];
    // 크기 비교 아직 안됨
    for (int i = 0; i < int1.size(); i++)
    {
        a[i] = int1.at(int1.size()-i-1) - '0';
    }
    for (int i = 0; i < int2.size(); i++)
    {
        b[i] = int2.at(int2.size()-i-1) - '0';
    }

    // int1이 더 클 때

    for (int i = 0; i < size; i++)
    {
        if (a[i] > b[i])
        {
            res[i] = a[i] - b[i];
        }
        else if (a[i] < b[i]){
            int temp = i;
            while (1){
                a[temp]--;
                temp++;
                if (a[temp] > b[temp]) break;
            }
            a[i] += 10;
            res[i] = a[i] - b[i];
        }
        else {
            res[i] = 0;
        }
        
    }
    
    for (int i = 0; i < size; i++)
    {
        cout << result << endl;
        if(i == 0 && res[size] == 0) continue;
        result += to_string(res[size-i]);
    }

}

void mul(string &int1, string &int2, string &result){
    int size = max(int1.size(), int2.size());
    int* a = new int[size];
    int* b = new int[size];
    int* res = new int[size*2];
    for (int i = 0; i < int1.size(); i++)
    {
        a[i] = int1.at(int1.size()-i-1) - '0';
    }
    for (int i = 0; i < int2.size(); i++)
    {
        b[i] = int2.at(int2.size()-i-1) - '0';
    }
    // int2가 짧다는 가정
    for (int i = 0; i < int1.size(); i++)
    {
        for (int j = 0; j < int2.size(); j++)
        {
            int re;
            re = a[j] * b[i];
            res[j] = re%10;
            res[i+1] += re/10;
            if (res[i+1] >= 10){
                int temp = i+1;
                while (1){
                    res[temp]++;
                    temp++;
                    if (res[temp] < 10) break;
                }
            }
        }
    }
    
    for (int i = 0; i < size*2; i++)
    {
        cout << result << endl;
        if(i == 0 && res[size] == 0) continue;
        result += to_string(res[size-i]);
    }

}