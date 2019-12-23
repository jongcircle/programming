#include <iostream>
using namespace std;

class node{
    private :
    int num;
    node* next;

    public :

    node(int a, node* b){
        num = a;
        next = b;
    }

    node(){
        num = 0;
        next = NULL;
    }

    void setnext(node* next){
        this->next = next;
    }
    int getnum(){
        return num;
    }
    node* getnext(){
        return next;
    }

};


int main(){

    node* Head = new node();

    while(true){
        string input;
        cin >> input;
        if(input.compare("Insert") == 0)
        {
            int n;
            cin >> n;
            node* temp = Head;
            while (temp->getnext() != NULL){
                if (n < temp->getnext()->getnum()){
                    break;
                }
                else {
                    temp = temp->getnext();
                }
            }
            node* _new = new node(n, temp->getnext());
            temp->setnext(_new);
        }
        else if(input.compare("Delete") == 0){
            int n;
            cin >> n;
            node* temp = Head;
            while (temp->getnext() != NULL){
                if (temp->getnext()->getnum() == n){
                    node* _old = temp->getnext();
                    temp->setnext(_old->getnext());
                    delete _old;
                    break;
                }
                temp = temp->getnext();
            }
        }
        else if(input.compare("Find") == 0){
            int n;
            cin >> n;            
            node* temp = Head->getnext();
            while (temp != NULL){
                if (temp->getnum() == n){
                    cout << "True" << endl;
                    break;
                }
                temp = temp->getnext();
            }
            if (temp == NULL) cout << "False" << endl;
        }
        else if(input.compare("Print") == 0){
            node* temp = Head->getnext();
            while (temp != NULL){
                cout << temp->getnum() << " ";
                temp = temp->getnext();
            }
            cout << endl;
        }
        else if(input.compare("Exit") == 0){
            node* temp = Head->getnext();
            while (temp != NULL){
                cout << temp->getnum() << " ";
                temp = temp->getnext();
            }
            cout << endl;
            return 0;
        }
    }
}