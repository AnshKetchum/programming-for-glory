#include <bits/stdc++.h>
using namespace std;
#define MAXN 905
#define INF LLONG_MAX
#define X_COORD .second.first
#define Y_COORD .second.second

typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll, pii> piii;
ll m,n,grid[MAXN][MAXN], cost[MAXN][MAXN], ans,dx [] = {-1,1,0,0},dy [] = {0,0,-1,1};
bool vis[MAXN][MAXN], waypoint[MAXN][MAXN]; 
vector<pii> waypoints;
pii start;


ll get_d_value(pii a, pii b)
{
    return abs(grid[a.first][a.second] - grid[b.first][b.second]);
}

void get_mst()
{
    for(int i = 0; i < m; i++)
        fill(cost[i],cost[i] + n, INF);

    priority_queue <piii> enque;
    enque.push(piii(0,start));
    cost[start.first][start.second] = 0;

    while(!enque.empty())
    {
        piii top = enque.top();
        enque.pop();

        if(vis[top.second.first][top.second.second])
            continue;

        vis[top.second.first][top.second.second] = true;
        for(int i = 0; i < 4;i++)
        {
            ll n_x = top.second.first  + dx[i];
            ll n_y = top.second.second + dy[i];

            if(n_x >= m || n_x < 0 || n_y < 0 || n_y >= n)
                continue;
 
            if(!vis[n_x][n_y])
            {
                ll c = get_d_value(pii(n_x,n_y), top.second);

                cost[n_x][n_y] = min(cost[n_x][n_y],max(c,cost[top.second.first][top.second.second]));
                enque.push(piii(-c,pii(n_x,n_y)));
            }

        }


    }

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];
    
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
        {
            int a = 0; cin >> a;
            waypoint[i][j] = (a == 1);
            if(waypoint[i][j])
            {
                start = pii(i,j);
                waypoints.push_back(start);
            }
        }

    get_mst();
    for(pii x : waypoints)
        if(x != start)
            ans = max(ans, cost[x.first][x.second]);

    cout << ans << endl;
    return 0;
}