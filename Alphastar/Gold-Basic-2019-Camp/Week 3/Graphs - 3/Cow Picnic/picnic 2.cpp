#include <bits/stdc++.h>
using namespace std;
#define MAXN 1500
#define MAXM 12000
#define MAXK 150
#define INF 1000000


typedef pair<int,int> pii;
int cnts[MAXN],n,m,k,cows[MAXK];
bool connections[MAXN][MAXN];

void dijkstras(int source)
{
    int cost[MAXN],nodeCount = 0;
    bool visited[MAXN];

    fill(cost, cost + n + 1,INF);
    fill(visited, visited + n + 1,false);

    cost[source] = 0;
    priority_queue <pii> best_edges;
    best_edges.push(pii(0,source));

    while(nodeCount < n && best_edges.size() > 0)
    {
        int node  = best_edges.top().second;
        best_edges.pop();

        if(visited[node])
            continue;

        visited[node] = true;
        for(int i = 1; i <= n; i++)
            if(!visited[i] && connections[node][i])
            {
                int c = cost[node] + 1;
                cost[i] = min(cost[i], c);
                best_edges.push(pii(-c,i));
            }
    }

    for(int i = 1; i <= n; i++)
        if(cost[i] != INF)
            cnts[i]++;

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> k >> n >> m;
    for(int i = 0; i < k; i++)
        cin >> cows[i];
    for(int i = 0; i < m; i++)
    {
        int a,b; cin >> a >> b;
        connections[a][b] = true;
    }

    for(int i = 0; i < k; i++)
        dijkstras(cows[i]);

    int ans = 0;
    for(int i = 0; i <=  n; i++)
        if(cnts[i] == k)
            ans++;
    cout << ans << endl;
    return 0;
}
