#include <bits/stdc++.h>
using namespace std;
#define MAXP 150000
#define INF 1000000000000

typedef long long ll;
typedef pair<ll,ll> pii;
ll c,p,pb,pa1,pa2,cost[3][MAXP],ans = INF;
vector <pii> connections [MAXP];

void dijkstra(ll source, ll cost [])
{
    bool visited[MAXP];
    fill(visited,visited + p + 5, false);
    fill(cost, cost + p + 5, INF);
    cost[source] = 0;

    priority_queue<pii>best_edges;
    best_edges.push(pii(0,source));

    while(!best_edges.empty())
    {
        pii top = best_edges.top();
        best_edges.pop();

        if(visited[top.second])
            continue;

        visited[top.second] = true;

        for(pii x : connections[top.second])
            if(!visited[x.second])
            {
                ll c = cost[top.second] + x.first;
                cost[x.second] = min(cost[x.second], c);
                best_edges.push(pii(-c,x.second));
            }
    }


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c >> p >> pb >> pa1 >> pa2;
    for(int i = 0; i < c; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        connections[a].push_back(pii(c,b));
        connections[b].push_back(pii(c,a));
    }


    dijkstra(pb,cost[0]);
    dijkstra(pa1,cost[1]);
    dijkstra(pa2,cost[2]);

    ans = min(ans, (cost[0][pa1] + cost[1][pa2]));
    ans = min(ans, (cost[0][pa2] + cost[2][pa1]));

    cout << ans << endl;
    return 0;
}