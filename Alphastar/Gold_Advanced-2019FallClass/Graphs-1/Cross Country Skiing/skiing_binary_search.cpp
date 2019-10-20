#include <bits/stdc++.h>
using namespace std;
#define MAXN 905
#define MAXD 1000001000
#define X_COORD .second.first
#define Y_COORD .second.second

typedef long long ll;
typedef pair<ll,ll> pii;
ll m,n,grid[MAXN][MAXN], dx [] = {-1,1,0,0} ,dy [] = {0,0,-1,1};
bool vis[MAXN][MAXN], waypoint[MAXN][MAXN]; 
vector<pii> waypoints;
pii start;

ll get_d_value(pii a, pii b)
{
    return abs(grid[a.first][a.second] - grid[b.first][b.second]);
}

bool pos(int d_val)
{
    for(int i = 0; i < m; i++)
        fill(vis[i], vis[i] + n, false);
    

    queue <pii> enque;
    enque.push(start);

    while(!enque.empty())
    {
        pii top = enque.front();
        enque.pop();

        if(vis[top.first][top.second])
            continue;

        vis[top.first][top.second] = true;
        
        for(int i = 0; i < 4;i++)
        {
            ll n_x = top.first  + dx[i];
            ll n_y = top.second + dy[i];

            if(n_x >= m || n_x < 0 || n_y < 0 || n_y >= n || vis[n_x][n_y])
                continue;
            ll c = get_d_value(pii(n_x,n_y), top);
            if(c <= d_val)
            {
                enque.push(pii(n_x,n_y));
            }
        }

    }


    
    for(pii x: waypoints)
        if(!vis[x.first][x.second])
            return false;

    return true;
}


int find_answer(int l, int r) //Binary Search on D
{
    if(l == r)
        return l;
    ll mid = (l + r) / 2;

    if(pos(mid))
        return find_answer(l,mid);
    return find_answer(mid + 1, r);
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
            int f = -1; cin >> f;
            waypoint[i][j] = (f == 1);

            if(waypoint[i][j])
            {
                waypoints.push_back(pii(i,j));
                start = pii(i,j);
            }
        }



    cout << find_answer(0, MAXD) << endl;  
    return 0;
}