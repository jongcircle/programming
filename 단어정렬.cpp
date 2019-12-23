#include <iostream>
using namespace std;

int main(){
    int num;
    cin >> num;
    string word[20000];

    for (int i = 0; i < num; i++) cin >> word[i];
    
    for (int  i = 0; i < num; i++)
    {
        for (int j = 0; j < num-i-1; j++)
        {
            string temp;
            if ( word[j].compare(word[j+1]) < 0 )
            {
                temp = word[j];
                word[j] = word[j+1];
                word[j+1] = temp;   
            }
        }
    }

    for (int i = 0; i < num; i++)
    {
        cout << word[i] << endl;
    }

}