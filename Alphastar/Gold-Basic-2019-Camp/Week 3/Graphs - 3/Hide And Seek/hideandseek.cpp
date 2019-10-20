#include <bits/stdc++.h>
using namespace std;
#define MAXN 25000
#define MAXM 55000
#define INF 100000000

typedef pair<int,int> pii;
vector <pii> connections [MAXN];
int n,m;

void get_mst()
{
    int cost [MAXN],nodeCount = 0;
    bool visited [MAXN];

    fill(cost, cost + n + 1,INF);
    fill(visited, visited + n + 1,false);
    cost[1] = 0;

    priority_queue <pii> best_edges;
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

    int farthest = 0;
    for(int i = 1; i <= n; i++)
        if(cost[i] != INF)
            farthest = max(farthest,cost[i]);

    int index  = INF,counts = 0;
    for(int i = 1; i <= n; i++)
        if(cost[i] == farthest)
        {
            index = min(index,i);
            counts++;
        }
    cout << index << " " << farthest << " " << counts << endl;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a,b; cin >> a >> b;
        connections[a].push_back(pii(b,1));
        connections[b].push_back(pii(a,1));
    }

    get_mst();
    return 0;
}
