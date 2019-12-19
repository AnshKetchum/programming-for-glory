#include <bits/stdc++.h>
using namespace std;
#define MAXN 2005 

typedef long long ll;
ll n,d[MAXN],cost[MAXN],connections[MAXN][MAXN],ans;
typedef pair<ll,ll> pii;
bool visited[MAXN];

void dijkstra_adj()
{
    cost[2004] = -1;
    int to_visit = 1,min_node = 2004;
    visited[to_visit] = true;
    cost[to_visit] = 0;
    while(to_visit != -1)
    {

        min_node = 2004;
        for(int i = 1; i <= n; i++)
        {
            if(i == to_visit)
                continue;
            if(cost[i] < connections[to_visit][i] && !visited[i])
                cost[i] = connections[to_visit][i];
        }

        for(int i = 1; i <= n; i++)
            if(!visited[i] && cost[i] > cost[min_node])
                min_node = i;

        visited[min_node] = true;
        if(min_node == 2004)
            min_node = -1;
        to_visit = min_node;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> d[i];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            connections[i][j] = (d[i] ^ d[j]); 
    dijkstra_adj();

    for(int i = 1; i <= n; i++)
        ans += cost[i];
    cout << ans << endl;
}