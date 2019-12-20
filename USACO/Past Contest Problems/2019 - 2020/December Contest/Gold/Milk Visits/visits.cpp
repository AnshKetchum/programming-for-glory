/*
Problem 2: USACO
*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001

int n,m,t[MAXN];
vector <int> connections [MAXN];

struct Edge
{
    int node;
    bool seen;

    Edge(int n, bool s)
    {
        node = n;
        seen = s;
    }
};

bool operator<(const Edge& p1, const Edge& p2) 
{ 
    return  p1.node < p2.node;
} 

typedef pair<int,Edge> pib;
bool dijkstra(int s, int e, int key)
{
    bool cost[MAXN] = {false};
    bool visited[MAXN] = {false};
    cost[s] = true;
    priority_queue<pib> best_edges;
    best_edges.push(pib(0,Edge(s,false)));

    while(!best_edges.empty())
    {
        pib top = best_edges.top();
        best_edges.pop();

        
        int cur = top.second.node;

        if(visited[cur])
            continue;
        visited[cur] = true;
        for(int x : connections[cur])
            if(!visited[x])
            {
                int c = top.first + 1;
                bool s = (top.second.seen || t[x] == key);
                cost[x] = cost[x] || s;
                best_edges.push(pib(c,Edge(x,s)));
            }
    }
    
    return cost[e];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream cin("milkvisits.in");
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> t[i];
    for(int i = 0; i < n - 1; i++)
    {
        int a,b; cin >> a  >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }

    ofstream cout("milkvisits.out");
    for(int i = 0; i < m; i++)
    {
        int a,b,u; cin >> a >> b >> u;
        if(a == b)
            cout << (t[a] == u);
        else
            cout << dijkstra(a,b,u);
    }
    cout << endl;
    return 0;
}