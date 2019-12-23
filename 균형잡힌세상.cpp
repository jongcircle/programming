#include <iostream>
#include <string>
using namespace std;

int main(){
    string sent;
    while (1)
    {
        getline(cin, sent);
        if(sent.compare(".") == 0) break;
        int small = 0, big = 0;
        char his[100];
        int cnt = 0, i;
        for (i = 0; i < sent.size(); i++)
        {
            char a = sent.at(i);
            if (a == '(') {
                small++;
                his[cnt] = '(';
                cnt++;
            }
            else if (a == '[') {
                big++;
                his[cnt] = '[';
                cnt++;
            }
            else if (a == ')'){
                small--;
                if (small < 0)
                {
                    cout << "no" << endl;
                    break;
                }
                if (his[cnt--] == '[')
                {
                    cout << "no" << endl;
                    break;
                }

            }
            else if (a == ']'){
                big--;
                if (big < 0)
                {
                    cout << "no" << endl;
                    break;
                }
                if (his[cnt--] == '(')
                {
                    cout << "no" << endl;
                    break;
                }
                
            }

        }

        if(i == sent.size())
        {
            if (small == 0 && big == 0)
            {
                cout << "yes" << endl;
            } else cout << "no" << endl;
        }

    }
    
}