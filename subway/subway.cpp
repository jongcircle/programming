#include <iostream>
#include <fstream>
#include <vector>
#include <string>
//#include <sstream>

typedef pair<Vertex*, int> edge;

using namespace std;

class Vertex{

    string name, id, line;
    vector<edge> edgelist;
    

};


int main(){

    ifstream data;
    data.open("data.txt");

    string line;

    while(getline(data,line))
    {
        // if "" break
        
         cout << line;
        // split " "
        
        
        
        // map (id, name, line)
    }

    //while // edge


    // dijkstra


}