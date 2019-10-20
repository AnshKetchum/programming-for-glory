#include <bits/stdc++.h>
using namespace std;
#define MAX_EDGES 60000
#define UNCOMPUTED -100000000000
#define MAX_W 50
#define INF 1000000000000000000
#define int long long

int v,e,k,dp [MAX_EDGES][MAX_W];
typedef pair<int,int> pii;
vector<pii> connections [MAX_EDGES];

int dfs(int node, int slips)
{
    if(node == v || slips < 0)
        return 0;
    if(dp[node][slips] != UNCOMPUTED)
        return dp[node][slips];

    dp[node][slips] = -INF;
    for(pii i : connections[node])
    {
        int a = dfs(i.first,slips) + i.second;
        dp[node][slips] = max(a,dp[node][slips]);
    }

    if(slips > 0)
        for(pii i : connections[node])
        {
            int a = dfs(i.first,slips - 1) + i.second;
            dp[node][slips] = min(a,dp[node][slips]);
        }
    return dp[node][slips];
}


main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> v >> e >> k;
    for(int i = 0; i < e; i++)
    {
        int a,b,c; cin >> a >> b >> c;
        connections[a].push_back(pii(b,c));
    }
    
    for(int i = 0; i < MAX_EDGES; i++)
        for(int j = 0; j < MAX_W; j++)
            dp[i][j] = UNCOMPUTED;

    cout << dfs(1,k) << endl;
    return 0;
}
