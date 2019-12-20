#include <bits/stdc++.h>
using namespace std;
#define MAXN 500
#define INF 1000000000

int n,connections[MAXN][MAXN],well_costs[MAXN];
int cost[MAXN];
bool visited[MAXN];
typedef pair<int,int> pii;

int prims()
{
    int cost [MAXN];
    fill(cost, cost + n + 5,INF);
    cost[0] = 0;

    priority_queue <pii> best_edges;
    best_edges.push(pii(0,0));

    while(!best_edges.empty())
    {
        pii top = best_edges.top();
        best_edges.pop();

        if(visited[top.second])
            continue;

        visited[top.second] = true;

        for(int i = 1; i <= n; i++)
            if(!visited[i])
            {
                cost[i] = min(cost[i],connections[top.second][i]);
                best_edges.push(pii(-connections[top.second][i],i));
            }
    }

    int total_cost = 0;
    for(int i = 1; i <= n; i++)
        total_cost += cost[i];
    return total_cost;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> connections[0][i]; //Creating a hypothical node 0 with all well costs to run Prim's Algorithm
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> connections[i][j];

    cout << prims() << endl;
    
    return 0;
}

