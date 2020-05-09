#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ifstream data222;
    data222.open("data222.txt");

    string line;

    while (getline(data222,line)){
        //cout << line << endl;

        string first = line.substr(0, line.find(" "));
        string second = line.substr(line.find(" ")+1, line.find(" "));
        string third = line.substr(first.length() + second.length() + 2);

        cout << "first :" << first << endl;
        cout << "second :" << second << endl;
        cout << "third :" << third << endl;
        cout << endl;
        
        string *a = new string;
        *a = first;

    }

    while (getline(data222, line))
    {
        string first = line.substr(0, line.find(" "));
        string second = line.substr(line.find(" ")+1, line.find(" "));
        string third = line.substr(first.length() + second.length() + 2);    

        cout << first << second << third;
    }


    
    data222.close();


}