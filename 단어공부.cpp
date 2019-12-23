#include <iostream>
using namespace std;

int main(){
    int cnt[26] = {0, };
    char word[1000000];
    int max;
    cin >> word;

    for (int i = 0; i < strlen(word); i++)
    {
        char x = word[i];
        if( x >= 'A' && x <'Z')
        {
            cnt[x-'A']++;
        }
        else
        {
            cnt[x-'a']++;
        }

    }
    
    int m =0, a =0;
    bool flag = true;
    for (int i = 0; i < 26; i++)
    {
        if(cnt[i] > m)
        {
            m = cnt[i];
            a = i;
            flag = false;
        }
        if(cnt[i] == m) flag = true;
    }
    
    cout << (flag ? '?' : ('a' + a)) <<endl;

}