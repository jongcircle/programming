#include <iostream>
using namespace std;

int main(){

    int num = 0;
    cin >> num;

    for (int i = 0; i < num ; i++)
    {
        if (num%2 == 0){
            for (int j = 0; j < num/2; j++)
            {
                cout << "*" << " ";
            }
            cout << endl;
            for (int j = 0; j < num/2; j++)
            {
                cout << " " << "*";
            }
            cout << endl;
        } else {
            for (int j = 0; j < num/2+1; j++)
            {
                cout << "*" << " ";
            }
            cout << endl;
            for (int j = 0; j < num/2; j++)
            {
                cout << " " << "*";
            }
            cout << endl;
        }
            
    }
    cout << endl;
    
}