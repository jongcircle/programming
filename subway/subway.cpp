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
        last = NULL;
    }

    Vertex(string a, string b, string c){
        name = a;
        id = b;
        line = c;
        visited = false;
        last = NULL;
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

        if (graph_name.find(first) == graph_name.end())
        {
            Vertex *temp = new Vertex(first, second, third);
            graph_id[second] = temp;
            graph_name[first] = temp;
        } else {
            //Vertex *temp = new Vertex(first, second, third);
            graph_id[second] = graph_name[first];
            graph_id[second]->line = "환승역";          // 둘다표기하고싶은데??????
        }
        
        
        
    }

    while (getline(data, line))     // 환승
    {
        string a, b;
        int c;
        istringstream iss (line);
        iss >> a >> b >> c;
        

        graph_id[a]->edgelist.push_back(edge(graph_id[b], c));
    }

    data.close();

    for (int  i = 0; i < 4; i++)
    {
        cout << graph_name["잠실"]->edgelist[i].first->name << endl;
    }
    

    // dijkstra
    while (true){
        string input, a, b;
        getline(cin, input);
        if (input.compare("quit") == 0) break;

        istringstream iss (input);
        iss >> a >> b;      // a : 출발지   b : 도착지


        if (graph_name[a]->id.empty() && graph_name[b]->id.empty()){         // 있는지 확인
            cout << "다시 입력 : ";
            continue;
        }

        priority_queue<edge, vector<edge>, comparedist> pq;

        pq.push(edge(graph_name[a], 0));
        graph_name[a]->visited = true;
        graph_name[a]->last = NULL;

        while (!pq.empty())
        {
            edge temp = pq.top();           // 가장 작은거 (뽑은거)
            pq.pop();

            if (temp.first->dist < temp.second) continue;

            cout << "역이름 : " << temp.first->name << "  현재까지거리 : " << temp.second << endl;
            
            if (temp.first->name == b) break;

            for (int i = 0; i < temp.first->edgelist.size(); i++)
            {
                edge w = temp.first->edgelist[i];     // 지금보고있는 vertex의 페어 vertex*, dist

                Vertex* new_vertex = w.first;
                int weight = w.second;
/*
환승역에서 모든 edge가 다 들어갔는데 큐에 제대로 잘 안들어간거같음ㅇㅇ
아니면 나올때 최소값이 안나옴;;
뭐징
*/

                if (new_vertex->visited == false){      // 처음보는거다~
                    new_vertex->dist = temp.second + weight;
                    pq.push(edge(new_vertex,new_vertex->dist));
                    new_vertex->last = temp.first;
                    new_vertex->visited = true;
                    //cout << "처음보는거 ; " << new_vertex->name << endl;
                }
                else if (temp.second + weight < new_vertex->dist) {
                    new_vertex->dist = temp.second + weight;
                    pq.push(edge(new_vertex, new_vertex->dist));
                    new_vertex->last = temp.first;
                }
               
            }
        }
        
        cout << "거리 : " << graph_name[b]->dist << endl;
        Vertex* temp = graph_name[b];
        while (temp != NULL){
            cout << temp->name << " - ";
            temp = temp->last;
        }
    }


}
