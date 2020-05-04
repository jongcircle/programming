#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

typedef pair<Vertex*, int> edge;

class Vertex{

    string name, id, line;
    vector<edge> edgelist;
    
    void setname(string a){
        name = a;
    }

    void setid(string a){
        id = a;
    }
    
    void setline(string a){
        line = a;
    }

    string getname(){
        return name;
    }

    string getid(){
        return id;
    }

    string getline(){
        return line;
    }


};


int main(){

    ifstream data;
    data.open("data.txt");

    vector<Vertex> station;

    

    string line;

    while(getline(data,line))
    {
        int i = 0;
        // if "" break
        
        
        // split " "

        //istringstream iss;  이거 어떻게 써야하지
        string first = line.substr(0, line.find(" "));
        string second = line.substr(line.find(" ")+1, line.find(" "));
        string thrid = line.substr(first.length() + second.length() + 2);
        
        // map (id, name, line)
        
        


        i++;
    } 

    data.close();

    //while // edge


    // dijkstra


}
