#include <bits/stdc++.h>
using namespace std;
#define MAXN 15000
#define INF 1000000000

int n,m,parentA[MAXN],parentB[MAXN],costA[MAXN],costB[MAXN],shortestDist[MAXN];
typedef pair<int,int> pii;
vector <pii> connectionsA [MAXN];
vector <pii> connectionsB [MAXN];

void dijkstra(int (&parent) [MAXN],int (&cost) [MAXN],vector<pii> connections [MAXN])
{
    bool visited[MAXN] = {false};
    fill(cost, cost + n + 1, INF);
    cost[n] = 0;

    priority_queue <pii> best_edges;
    best_edges.push(pii(0,n));

    while(!best_edges.empty())
    {
        pii top = best_edges.top();
        best_edges.pop();

        if(visited[top.second] || top.second == 1)
            continue;

        visited[top.second] = true;
        for(pii x : connections[top.second])
            if(!visited[x.second])
            {
                int c = cost[top.second] + x.first;
                if(c < cost[x.second])
                {
                    cost[x.second] = c;
                    parent[x.second] = top.second;
                }
                best_edges.push(pii(-c,x.second));
            }
    }

    for(int i = 1; i <= n; i++)
        cout << cost[i] << " ";
    cout << endl;
}

int computeEdge(int f, int t, int ea,int eb)
{
    bool a  = (costA[t] - costA[f]);
    bool b  = (costB[t] - costB[f]);

    if(a == ea && b == eb)
        return 0;
    if(a == ea || b == eb)
        return 1;
    return 2;
}

int dijkstra2()
{
    int cost [MAXN];
    bool visited[MAXN] = {false};
    fill(cost, cost + n + 1, INF);
    cost[1] = 0;

    priority_queue <pii> best_edges;
    best_edges.push(pii(0,1));

    while(!best_edges.empty())
    {
        pii top = best_edges.top();
        best_edges.pop();

        if(visited[top.second])
            continue;

        visited[top.second] = true;
        for(int i = 0; i < connectionsA[top.second].size(); i++)
        {
            pii x = connectionsA[top.second][i];
            if(!visited[x.second])
            {
                int c = cost[top.second] +  computeEdge(top.second,x.second,x.first,connectionsB[top.second][i].second);
                cout << computeEdge(top.second,x.second,x.first,connectionsB[top.second][i].first) << " " << top.second << " "  << x.second << " " << x.first << " " << connectionsB[top.second][i].first <<  endl;
                cout << costA[top.second] <<  " " << costA[x.second] <<  " " << costB[top.second] << " " << costB[x.second] << endl;
                cost[x.second] = min(cost[x.second], c);
                best_edges.push(pii(-c,x.second));
                cout << "\n\n";
            }
        }
    }

    for(int i = 1; i <= n; i++)
        cout << cost[i] << " ";
    cout << endl;
    return cost[n];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a,b,p,q; cin >> a >> b >> p >> q;
        connectionsA[a].push_back(pii(p,b));
        connectionsA[b].push_back(pii(p,a));
        connectionsB[a].push_back(pii(q,b));
        connectionsB[b].push_back(pii(q,a));
    }


    cout << "\n\n";
    dijkstra(parentA,costA,connectionsA);
    dijkstra(parentB,costB,connectionsB);

    cout << "\n\n\n";
    cout << dijkstra2() << endl;
    return 0;
}