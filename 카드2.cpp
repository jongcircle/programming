#include <iostream>
using namespace std;

/* 1. ll써서 하려고했는데 아닌거같음 배열로 다시
    2. 배열써서 나머지 초기화시키는거 -> 너무 오래걸림
*/

int main(){
    int num[500000];
    int su;
    cin >> su;

    for (int i = 1; i < su+1; i++) num[i] = i;

    int cnt = 5;
    //sizeof(num) - 1;

    while (1)
    {
        if (num[1] == 0) break;
        int temp;
        temp = num[1];
        for (int i = 0; i < su; i++)
        {
            num[i] = num[i+2];
        }
        //for (int i = 0; i < su; i++) cout<<num[i];
        num[cnt-1] = temp;
        num[cnt] = 0;
        cnt--;
        cout << endl;
    }
    
    cout << num[0] << endl;    
    
}