/*****
ID: INSERT_NAME_HERE
LANG: C++
PROG: butter
**/
#include <bits/stdc++.h>
using namespace std;
#define MAXN 950
#define MAXC 2000
#define INF 100000000

typedef pair<int,int> pll;
int total_cost[MAXN],n,p,c,loc[MAXC],ans = INF;
vector <pll> connections [MAXN];

void dijkstra(int source)
{
    int cost [MAXN];
    fill(cost, cost + p + 1,INF);
    bool visited[MAXN] = {false};
    priority_queue <pll> best_edges;
    best_edges.push(pll(0,source));
    cost[source] = 0;
    
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
                int c = cost[top.second] + x.first;
                cost[x.second] = min(c,cost[x.second]);
                best_edges.push(pll(-c,x.second));
            }
    }

    for(int i = 1; i <= p; i++)
        total_cost[i] += cost[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream cin("butter.in");
    ofstream cout("butter.out");

    cin >> n >> p >> c;
    for(int i = 0; i < n; i++)
        cin >> loc[i];
    for(int i = 0; i < c; i++)
    {
        int a,b,c; cin >> a >> b >> c;
        connections[a].push_back(pll(c,b));
        connections[b].push_back(pll(c,a));
    }

    for(int i = 0; i < n; i++)
        dijkstra(loc[i]);


    for(int i = 1; i <= p; i++)
        ans = min(ans,total_cost[i]);
    cout << ans << endl;
    return 0;
}