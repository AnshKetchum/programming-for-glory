#include <bits/stdc++.h>
using namespace std;
#define MAXN 55000
#define MAXM 55000
#define INF 1000000000

int n,m;
typedef pair<int,int> pii;
vector <pii> connections [MAXN];

int shortest_path()
{
    int cost [MAXN],nodeCount = 0;
    bool visited [MAXN];

    fill(cost, cost + n + 1, INF);
    fill(visited, visited + n + 1, false);
    cost[1] = 0;

    priority_queue<pii> best_edges;
    best_edges.push(pii(0,1));

    while(nodeCount < n && best_edges.size() > 0)
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

    return cost[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a,b,c; cin >> a >> b >> c;
        connections[a].push_back(pii(b,c));
        connections[b].push_back(pii(a,c));
    }

    cout << shortest_path() << endl;
    return 0;
}
