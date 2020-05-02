#include <bits/stdc++.h>

using namespace std;

vector<int> graph[100001];
int n, k;
int R[100001];
int L[100001];

void dfs1(int cur, int par)
{
    R[cur] = R[par] + 1;
    int l = 10000;
    for(int i=0; i<graph[cur].size(); i++)
    {
        if(graph[cur][i] == par) continue;
        dfs1(graph[cur][i], cur);
        l = min(l, L[graph[cur][i]] + 1);
    }
    if(l != 10000) L[cur] = l;
}

void dfs2(int cur, int par){

    L[cur] = min(L[cur], L[par] + 1);
    for(int i=0; i<graph[cur].size(); i++)
    {
        if(graph[cur][i] == par) continue;
        dfs2(graph[cur][i], cur);
    }
    
}

int dfs3(int cur, int par)
{
    int cnt = 0;
    if(L[cur] <= R[cur] && L[par] > R[par]) cnt++;
    for(int i=0; i<graph[cur].size(); i++)
    {
        if(graph[cur][i] == par) continue;
        cnt += dfs3(graph[cur][i], cur);
    }
    return cnt;
}

int main(){
    
    cin >> n >> k;

    for(int i=0; i<n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }   
    R[0] = -1;
    dfs1(1, 0);
    dfs2(1, 1);

    cout << dfs3(1,1);

}