#include <bits/stdc++.h>
using namespace std;
#define MAXN 1010
#define INF 1000000000
bool connection [MAXN][MAXN];
int n,m,q;
typedef pair<int,int> pii;

bool dijkstra(int starting, int ending)
{
    bool visited[MAXN] = {false};
    int cost[MAXN],nodeCount = 0;

    fill(cost, cost + n + 1, INF);
    cost[starting] = 0;

    priority_queue <pii> best_edges;
    best_edges.push(pii(0,starting));

    while(!best_edges.empty() && nodeCount < n)
    {
        int node = best_edges.top().second;
        best_edges.pop();

        if(visited[node])
            continue;

        visited[node] = true;
        nodeCount++;

        for(int i = 1; i <= n; i++)
            if(connection[node][i] && !visited[i])
            {
                int c = cost[node] + 1;
                cost[i] = min(c,cost[i]);
                best_edges.push(pii(-c,i));
            }
    }
    return (cost[ending] != INF);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> q;
    for(int i = 0; i < m; i++)
    {
        int a,b; cin >> a >> b;
        connection[a][b] = connection[b][a] = true;
    }

    for(int i = 0; i < q; i++)
    {
        int a,b; cin >> a >> b;
        cout << (dijkstra(a,b) ? "Y" : "N") << endl;
    }

    return 0;
}
