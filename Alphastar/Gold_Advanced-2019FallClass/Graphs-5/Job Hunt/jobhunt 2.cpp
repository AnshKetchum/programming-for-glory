#include <bits/stdc++.h>
using namespace std;
#define MAXN 1500   
#define INF 1000000000

int d,p,c,f,s;

struct Edge
{
    int from,to,cost;
};

vector <Edge> connections;

int bellman_ford()
{
    int cost [MAXN];
    fill(cost, cost + MAXN - 5, -INF);

    cost[s] = d;
    for(int i = 1; i <= c - 1; i++)
        for(Edge x : connections)
            cost[x.to] = max(cost[x.to], cost[x.from] + x.cost);
    
    for(Edge x : connections)
        if(cost[x.to] < cost[x.from] + x.cost)
            return -1;
        
    int ans = 0;
    for(int i = 1; i <= c; i++)
        ans = max(ans,cost[i]);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> d >> p >> c >> f >> s;
    for(int i = 0; i < p; i++)j
    {
        int a,b; cin >> a >> b;
        Edge t = {a,b,d};
        connections.push_back(t);
    }

    for(int i = 0; i < f; i++)
    {
        int a,b,z; cin >> a >> b >> z;
        Edge t =  {a,b,d - z};
        connections.push_back(t);
    }

    cout << bellman_ford() << endl;
    return 0;
}