#include <iostream>
#include <algorithm>

//#include <bits/stdc++.h>
using namespace std;

typedef struct su{
    int x; int y;
}su;

typedef pair<int, int> pa;

int main(){


    su coord[100000];

    pa num[1000000];

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> num[i].first >> num[i].second;
    }
    
    sort(num, num + n);
    
    for (int i = 0; i < n; i++)
    {
        cout << num[i].first << " " << num[i].second << endl;
    }

}