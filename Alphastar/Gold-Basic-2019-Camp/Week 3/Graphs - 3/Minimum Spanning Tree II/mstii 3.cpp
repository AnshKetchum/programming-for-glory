
#include <bits/stdc++.h>
using namespace std;
#define MAXN 55000
#define INF 1000000


typedef pair<int,int> pii;
int v,e;
vector <pii> connections [MAXN];


int get_mst()
{
    int cost [MAXN],nodeCount = 0;
    bool visited [MAXN];

    fill(cost, cost + v + 1, INF);
    fill(visited, visited + v + 1, false);

    cost[1] = 0;
    priority_queue <pii> best_edges;
    best_edges.push(pii(0,1));

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
                int c = x.second;
                cost[x.first] = min(cost[x.first],x.second);
                best_edges.push(pii(-c,x.first));
            }

        }

    }

    int ans = 0;
    for(int i = 1; i <= v; i++)
        ans += cost[i];
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> v >> e;


    for(int i = 0; i < e; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        connections[a].push_back(pii(b,c));
        connections[b].push_back(pii(a,c));
    }

    cout << get_mst() << endl;
    return 0;
}
