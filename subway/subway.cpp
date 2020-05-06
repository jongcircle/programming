#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>
//#include <hash_map>
#include <map>

using namespace std;

//typedef pair<Vertex*, int> edge;

class Vertex{

    string name, id, line;
    typedef pair<Vertex*, int> edge;
    vector<edge> edgelist;

    Vertex(){
        name = "없음";
        id = "없음";
        line = "없음";
    }

    Vertex(string a, string b, string c){
        name = a;
        id = b;
        line = c;
    }

};


int main(){

    ifstream data;
    data.open("data.txt");    

    //vector<Vertex> station;
    Vertex a = Vertex();
    


    string line;

    while(getline(data,line))
    {
        int i = 0;
        // if "" break
        
        
        // split " "

        //istringstream iss;  이거 어떻게 써야하지
        string first = line.substr(0, line.find(" "));                      // id
        string second = line.substr(line.find(" ")+1, line.find(" "));      // 이름
        string thrid = line.substr(first.length() + second.length() + 2);   // 몇호선
        
        // map (id, name, line)
        map<string, Vertex> a;


        i++;
    } 

    data.close();

    //while // edge
    


    // dijkstra


}
