/*
Problem 1: USACO
*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN 550000

struct Edge
{
    int flow,cost;
    double ratio;
    Edge(int f, int c)
    {
        flow = f;
        cost = c;
        if(c != 0)
            ratio = (double)(f) / c;
        
    }
};

bool operator<(const Edge& p1, const Edge& p2) 
{ 
    return  p1.ratio < p2.ratio;
} 

int n,m;
typedef pair<Edge,int> pie;
vector<pie> connections [MAXN];

int dijkstra()
{
    double cost2 [MAXN];
    bool visited[MAXN] = {false};
    fill(cost2, cost2 + n + 1, 0);

    cost2[1] = 0;
    priority_queue<pie> best_edges;
    best_edges.push(pie(Edge(1e9,0),1));

    while(!best_edges.empty())
    {
        pie top = best_edges.top();
        best_edges.pop();

        if(visited[top.second])
            continue;
        visited[top.second] = true;

        for(pie x : connections[top.second])
            if(!visited[x.second])
            {
                int flo = min(top.first.flow,x.first.flow);
                int cost = top.first.cost + x.first.cost;
                Edge nedge = Edge(flo,cost);

                cost2[x.second] = max(cost2[x.second],nedge.ratio);
                best_edges.push(pie(nedge,x.second));
            }
    } 

    return (int)(1e6 * cost2[n]);
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream cin("pump.in");
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a,b,c,d; cin >> a >> b >> c >> d;
        connections[a].push_back(pie(Edge(d,c),b));
        connections[b].push_back(pie(Edge(d,c),a));
    }

    ofstream cout("pump.out");
    cout << dijkstra() << endl; 
    return 0;
}