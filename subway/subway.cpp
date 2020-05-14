#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>
//#include <hash_map>
#include <map>
#include <sstream>
#include <queue>

using namespace std;

class Vertex;

typedef pair<Vertex*, int> edge;

class Vertex{
public:
    string name, id, line;
    vector<edge> edgelist;
    bool visited;
    Vertex* last;
    int dist;

    Vertex(){
        name = "없음";
        id = "없음";
        line = "없음";
        visited = false;
    }

    Vertex(string a, string b, string c){
        name = a;
        id = b;
        line = c;
        visited = false;
    }

};

struct comparedist{
    bool operator()(edge const& a, edge const& b){
        return a.second < b.second;
    }
};


int main(){

    ifstream data;
    data.open("seoul.in");    

    //vector<Vertex> station;
    
    map<string, Vertex *> graph_id;
    map<string, Vertex *> graph_name;

    string line;

    while(getline(data,line) && !line.empty())
    {

        istringstream iss (line);
        string second, first, third;            // first : 역이름      second : id      third : 호선
        iss >> second >> first >> third;

        //cout << second << endl << first << endl;
        Vertex *temp = new Vertex(first, second, third);
        graph_id[second] = temp;
        graph_name[first] = temp;
        
    }

    while (getline(data, line))
    {
        string a, b;
        int c;
        istringstream iss (line);
        iss >> a >> b >> c;

        graph_id[a]->edgelist.push_back(edge(graph_id[b], c));
    }

    data.close();


    // dijkstra
    while (true){
        string input, a, b;
        cin >> input;
        if (input.compare("quit") == 0) break;

        istringstream iss (input);
        iss >> a >> b;      // a : 출발지   b : 도착지

        if (graph_name[a]->id.empty()){         // 있는지 확인
            cout << "다시 입력 : ";
            continue;
        }

        priority_queue<edge, vector<edge>, comparedist> pq;

        pq.push(edge(graph_name[a], 0));

        while (!pq.empty())
        {
            edge temp = pq.top();           // 가장 작은거 (뽑은거)
            pq.pop();

            cout << "역이름 : " << temp.first->name << "  현재까지거리 : " << temp.second << endl;

            graph_name[temp.first->name]->visited = true;       // 정복했다고 표시

            int d = temp.second;

            for (int i = 0; i < temp.first->edgelist.size(); i++)
            {
                int w = temp.first->edgelist[i].second;     // 지금보고있는 vertex의 dist

                if (temp.first->edgelist[i].first->visited == false || d + w < temp.first->edgelist[i].first->dist)
                {
                    temp.first->edgelist[i].first->dist = d + w;
                    pq.push(edge(temp.first->edgelist[i].first, temp.first->edgelist[i].first->dist));
                }
                
               
            }
        }
        
        cout << "거리 : " << graph_name[b]->dist << endl;
    }

    

}
