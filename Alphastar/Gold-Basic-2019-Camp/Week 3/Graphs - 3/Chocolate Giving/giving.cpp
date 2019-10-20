#include <bits/stdc++.h>
using namespace std;
#define MAXN 55000
#define INF 1000000000

typedef pair<int,int> pii;
vector <pii> connections [MAXN];
int n,m,b,cost[MAXN];


void dijkstras()
{
    bool visited[MAXN];
    int nodeCount = 0;

    fill(cost, cost + n + 1, INF);
    fill(visited, visited + n + 1, false);
    cost[1] = 0; //Setting barn to 0 cost

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

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> b;
    for(int i = 0; i < m; i++)
    {
        int r,s,l; cin >> r >> s >> l;
        connections[r].push_back(pii(s,l));
        connections[s].push_back(pii(r,l));
    }

    dijkstras();

    for(int i = 0; i < b; i++)
    {
        int a,b; cin >> a >> b;
        cout << (cost[a] + cost[b]) << endl;
    }

    return 0;
}
