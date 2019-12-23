#include <iostream>
using namespace std;

int main(){
    int num, su = 0;

    cin >> num;
    int arr[100];
    
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    
    for (int i = 0; i < num; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= arr[i]; j++)
        {
            if (arr[i] % j == 0)
            {
                cnt++;
            }
        }
        
        if (cnt == 2) su++;
    }
    cout << su;
}