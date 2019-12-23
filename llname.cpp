#include <iostream>
using namespace std;

class student{
    private:
    string name;
    int mark;
    student* next;

    public:

    student(string a, int b, student* c){
        name = a;
        mark = b;
        next = c;
    }
    student(){
        name = "";
        mark = 0;
        next = NULL;
    }

    string getname(){
        return name;
    }
    
    int getmark(){
        return mark;
    }

    student* getnext(){
        return next;
    }

    void setnext(student* next){
        this->next = next;
    }

};

void Sort1(student* Head, int cnt){
    for (int  i = 0; i < cnt; i++)
    {
        student* temp = Head;
        for (int j = 0; j < cnt-i-1; j++)
        {
            if (temp->getname().compare(temp->getnext()->getname()) < 0)
            {
                student* temp1 = temp->getnext();
                student* temp2 = temp->getnext()->getnext();
                temp->setnext(temp2);
                temp1->setnext(temp2->getnext());
                temp2->setnext(temp1);
            }
            temp = temp->getnext();
        }
    }
    
}

void Sort2(student* Head, int cnt){
    student* temp = Head;
    for (int  i = 0; i < cnt; i++)
    {
        for (int j = 0; j < cnt-i-1; j++)
        {
            student* temp2;
            if (temp->getmark() > temp->getnext()->getmark())
            {
                temp2->setnext(temp);
                temp->setnext(temp->getnext());
                temp->getnext()->setnext(temp2);
            }
            temp = temp->getnext();
        }
    }
}

int main(){
    student* Head = new student();
    int cnt = 0;

    while(1){
        string input;
        cin >> input;
        if (input.compare("Insert") == 0){
            string name;
            int mark;
            cin >> name >> mark;
            cnt++;
            student* temp = Head;
            while (temp->getnext() != NULL){
                temp = temp->getnext();
            }
            student* _new = new student(name, mark, temp->getnext());
            temp->setnext(_new);
        }
        else if (input.compare("Delete") == 0){
            string name;
            cin >> name;
            student* temp = Head;
            while (temp->getnext() != NULL){
                if (temp->getnext()->getname() == name){
                    student* _old = temp->getnext();
                    temp->setnext(_old->getnext());
                    delete _old;
                    break;
                }
                temp = temp->getnext();
            }
            cnt--;
        }
        else if (input.compare("Print") == 0){
            student* temp = Head->getnext();
            while (temp != NULL){
                cout << temp->getname() << "(" << temp->getmark() << ")" << " -> ";
                temp = temp->getnext();
            }
            cout << endl;
        }
        else if (input.compare("Sort1") == 0){
            Sort1(Head, cnt);
            student* temp = Head->getnext();
            while (temp != NULL){
                cout << temp->getname() << "(" << temp->getmark() << ")" << " -> ";
                temp = temp->getnext();
            }
            cout << endl;
        }
        else if (input.compare("Sort2") == 0){
            Sort2(Head, cnt);
            student* temp = Head->getnext();
            while (temp != NULL){
                cout << temp->getname() << "(" << temp->getmark() << ")" << " -> ";
                temp = temp->getnext();
            }
            cout << endl;
        }
        else if (input.compare("Exit") == 0){
            student* temp = Head;
            while (temp != NULL){
                cout << temp->getname() << "(" << temp->getmark() << ")" << " -> ";
                temp = temp->getnext();
            }
            cout << endl;
            return 0;
        }

    }

}