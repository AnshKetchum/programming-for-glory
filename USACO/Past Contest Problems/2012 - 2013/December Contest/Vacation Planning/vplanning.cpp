#include <bits/stdc++.h>
using namespace std;
#define MAXN 21000
#define MAXQ 55000
#define MAXK 220
#define INF 10000000000

typedef long long ll;
typedef pair<ll,ll> pll;
ll n,k,m,q,cost_from[MAXK][MAXN],cost_to[MAXK][MAXN],hubs[MAXK],sum,cnt;
vector <pll> connections_to [MAXN];
vector <pll> connections_from [MAXN];

void dijkstra(int source, int ind, ll (&cost) [MAXK][MAXN], vector <pll> connections [MAXN])
{
    fill(cost[ind], cost[ind] + n + 1, INF);
    bool visited[MAXN] = {false};
    cost[ind][source] = 0;   
    priority_queue <pll> best_edges;
    best_edges.push(pll(0,source));

    while(!best_edges.empty())
    {
        pll top = best_edges.top();
        best_edges.pop();

        if(visited[top.second])
            continue;
        visited[top.second] = true;

        for(pll x : connections[top.second])
            if(!visited[x.second])
            {
                ll c = cost[ind][top.second] + x.first;
                cost[ind][x.second] = min(cost[ind][x.second],c);
                best_edges.push(pll(-c,x.second));
            }

    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream cin("vacationgold.in");
    ofstream cout("vacationgold.out");

    cin >> n >> m >> k >> q;
    for(int i = 0; i < m; i++)
    {
        ll u,v,d; cin >> u >> v >> d;
        connections_from[v].push_back(pll(d,u));
        connections_to[u].push_back(pll(d,v));

    }

    for(int i = 0; i < k; i++)
        cin >> hubs[i];
    for(int i = 0; i < k; i++)
    {
        dijkstra(hubs[i],i,cost_from,connections_from);
        dijkstra(hubs[i],i,cost_to,connections_to);
    }
    for(int i = 0; i < q; i++)
    {
        ll f,t,ret = INF; cin >> f >> t;
        
        for(int j = 0; j < k; j++)
            ret = min(ret, cost_from[j][f] + cost_to[j][t]);

        sum += (ret == INF ? 0 : ret);
        cnt += (ret == INF ? 0 : 1);
    } 
    
    
    cout << cnt << "\n" << sum << endl;
    return 0;
}