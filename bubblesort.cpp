#include <iostream>
using namespace std;
void Sort(int Arr[], int num);
int main(){
    int Arr[10] = {1,4,5,2,7,8,9,3,6,0};
    int num;

    Sort(Arr, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << Arr[i] << endl;
    }
    
}


void Sort(int Arr[], int num){

    for (int  i = 0; i < num; i++)
    {
        for (int j = 0; j < num-i-1; j++)
        {
            int temp = 0;
            if (Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;   
            }
        }
        
    }
}