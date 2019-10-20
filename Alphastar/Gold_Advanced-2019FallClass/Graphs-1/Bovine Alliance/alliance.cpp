#include <bits/stdc++.h>
using namespace std;
#define MAXN 105000
#define MOD 1000000007

typedef long long ll;
int n,m,r;
vector <int> connections [MAXN];
ll edges[MAXN],vertices[MAXN];
bool visited [MAXN];


void dfs(int node)
{
    if(visited[node])
        return;
    
    visited[node] = true;
    edges[r] = (edges[r] + (ll)(connections[node].size() % MOD)) % MOD;
    ++vertices[r];

    for(int x : connections[node])
        dfs(x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a,b; cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }

    for(int i = 1; i <= n; i++) //Finding all connected components
        if(!visited[i])
        {
            ++r;
            dfs(i);
            edges[r] /= 2;
        }
    
    ll ans = 1;
    for(int i = 1; i <= r; i++)
    {
        if(edges[i] == vertices[i])
            ans = (ans * 2) % MOD;
        else if(vertices[i] - edges[i] == 1)
            ans = (ans * vertices[i]) % MOD;
    }

    cout << ans << endl;
    return 0;
}