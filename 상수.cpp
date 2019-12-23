#include <iostream>
using namespace std;

int main(){
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    
    if (num1 % 10 > num2 % 10){
        cout << num1 % 10 << (num1 % 100)/10 << num1/100 << endl;
        return 0;
    } 
    else if (num1 % 10 == num2 % 10){
        if ((num1%100)/10 > (num2%100)/10){
            cout << num1 % 10 << (num1 % 100)/10 << num1/100 << endl;
            return 0;
        }
        else if ((num1%100)/10 == (num2%100)/10){
            if (num1/100 > num2/100){
                cout << num1 % 10 << (num1 % 100)/10 << num1/100 << endl;
                return 0;
            } else if (num1/100 == num2/100){
                cout << "같다" << endl;
                return 0;
            } else {
                cout << num2 % 10 << (num2 % 100)/10 << num2/100 << endl;
                return 0;
            }
        } else {
            cout << num2 % 10 << (num2 % 100)/10 << num2/100 << endl;
            return 0;
        }


    } else{
        cout << num2 % 10 << (num2 % 100)/10 << num2/100 << endl;
        return 0;
    }
}