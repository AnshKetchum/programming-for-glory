#include <bits/stdc++.h>
using namespace std;
#define MAXN 55000
#define INF 1000000000

typedef pair<int,int> pii;
int v,e,s;
vector <pii> connections[MAXN];

void dijkstras()
{
    int cost [MAXN],nodeCount = 0;
    bool visited[MAXN];

    fill(cost, cost + v + 1, INF);
    fill(visited, visited + v + 1, false);

    priority_queue <pii> best_edges;
    best_edges.push(pii(0,s));
    cost[s] = 0;

    while(nodeCount < v && best_edges.size() > 0)
    {
        int node = best_edges.top().second;
        best_edges.pop();

        if(visited[node])
            continue;

        visited[node] = true;
        nodeCount++;

        for(pii x : connections[node])
        {
            if(!visited[x.first])
            {
                int c = cost[node] + x.second;

                cost[x.first] = min(cost[x.first],c);
                best_edges.push(pii(-c,x.first));
            }

        }

    }

    for(int i = 1; i <= v; i++)
        cout << (cost[i] == INF ? -1 : cost[i]) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> v >> e >> s;
    for(int i = 0; i < e; i++)
    {
        int a,b,c; cin >> a >> b >> c;
        connections[a].push_back(pii(b,c));
        connections[b].push_back(pii(a,c));
    }

    dijkstras();
    return 0;
}
