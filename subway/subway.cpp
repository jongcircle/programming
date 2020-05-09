#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>
//#include <hash_map>
#include <map>

using namespace std;

class Vertex;

typedef pair<Vertex*, int> edge;

class Vertex{
public:
    string name, id, line;
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
    
    map<string, Vertex *> graph_id;
    map<string, Vertex *> graph_name;

    string line;

    while(getline(data,line))
    {
        // if "" break
        
        
        // split " "

        //istringstream iss;  이거 어떻게 써야하지
        string first = line.substr(0, line.find(" "));                      // id
        string second = line.substr(line.find(" ")+1, line.find(" "));      // 이름
        string third = line.substr(first.length() + second.length() + 2);   // 몇호선
        // map (id, name, line)
        Vertex *temp = new Vertex(second, first, third);
        graph_id[first] = temp;
        graph_id["11"] = temp;
        graph_name[second] = temp;
        cout << graph_id["11"] -> id <<endl;
    } 


    cout << graph_id["11"]->id;

    //while // edge
    //while (/* condition */)
    {
        /* code */
    }
    


    
    data.close();

    // dijkstra


}
