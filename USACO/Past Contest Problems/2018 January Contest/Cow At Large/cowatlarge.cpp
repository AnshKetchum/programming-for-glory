#include <bits/stdc++.h>
using namespace std;
#define MAXN 150000

int n,s,total_paths[MAXN];
bool visited[MAXN];
vector <int> connections [MAXN];

void dfs(int node)
{
    if(visited[node])
        return;
    total_paths[node]++;
    for(int x : connections[node])
    {
        visited[node] = true;
        dfs(x);
        visited[node] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream cin("atlarge.in");
    ofstream cout("atlarge.out");
    cin >> n >> s;
    for(int i = 1; i <= n - 1; i++)
    {
        int a,b; cin >> a >> b;
        connections[b].push_back(a);
        connections[a].push_back(b);
    }

    dfs(s);


    int ans = 0;
    for(int i = 1; i <= n; i++)
        if(connections[i].size() == 1)
            ans += total_paths[i];
    cout << ans << endl;

    return 0;
}