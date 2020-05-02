#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pa;
vector<pa> graph[1000];

int distan[1000];

int main(){

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        
        graph[a].push_back(pa(b,w));
    }
    
    for(int i=0; i<=n; i++) distan[i] = 100000;

    priority_queue<pa, vector<pa>, greater<pa> > pq;

    pq.push(pa(0, 1));

    while(!pq.empty())
    {
        pa temp = pq.top();
        pq.pop();

        int cur = temp.second;
        int dist = temp.first;

        if(dist != distan[cur]) continue;

        for(int i=0; i<graph[cur].size(); i++)
        {
            int next = graph[cur][i].first;
            int w = graph[cur][i].second;

            if(dist + w < distan[next]){
                distan[next] = dist + w;
                pq.push(pa(distan[next], next));
            }
        }
    }

}