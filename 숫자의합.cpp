#include <iostream>
using namespace std;
int main(){
    int count;
    string num;
    int sum = 0;

    cin >> count;
    cin >> num;

    for (int i = 0; i < count; i++)
    {
        sum += (num.at(i)-'0');
    }
    cout << sum << endl;
}