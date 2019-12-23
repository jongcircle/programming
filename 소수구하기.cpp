#include <iostream>
using namespace std;

/*
int main(){
    int su1, su2;
    cin >> su1 >> su2;

    for (int i = su1; i < su2+1; i++)
    {
        int cnt = 0;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0) cnt++;
        }
        
        if (cnt == 0) cout << i << endl;
    }
}
*/

int main(){
    int su1, su2;
    int num[1000000];
    cin >> su1 >> su2;

    for (int i = 0; i < su2-su1+1; i++)
    {
        num[i] = su1 + i;
    }
    
    for (int i = 2; i < su2-su1+3; i++)
    {
        for (int j = 0; j < su2-su1+1; j+=i)
        {

        }
    }
    
    for (int i = 0; i < su2-su1+1; i++)
    {
        if (num[i] != 1) cout << num[i] << endl;
    }
}