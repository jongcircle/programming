#include <iostream>
#include <fstream>
#include <vector>
typedef pair<Vertex*, int> edge;

using namespace std;

class Vertex{

    string name, id;
    vector<edge> edgelist;
    

};


int main(){

    ifstream ifs = ifstream("data.txt");

    string line;

    while(getline(ifs,line))
    {
        // if "" break
        // split " "
        // map (id, name)
    }

    while // edge


    // dijkstra


}