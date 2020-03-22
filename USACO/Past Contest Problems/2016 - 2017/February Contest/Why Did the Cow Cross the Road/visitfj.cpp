#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define MAXN 150 
#define INF 1e16
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

void setIO(string name) 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

struct State
{
    ll x,y,moves;

    State(ll a, ll b, ll c)
    {
        x = a;
        y = b;
        moves = c;
    }
};

int n; 
ll t,dp[MAXN][MAXN],times[MAXN][MAXN];
bool visited[MAXN][MAXN];
ll dx [] = {1,-1,0,0};
ll dy [] = {0,0,-1,1};

void print2D(ll a [MAXN][MAXN])
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

int bfs()
{
    for(int i = 1; i <= n; i++)
        fill(dp[i], dp[i] + n + 5, INF);

    queue<State> enque;
    enque.push(State(1,1,0));
    dp[1][1] = 0;

    while(!enque.empty())
    {
        State top = enque.front();
        enque.pop();

        if(visited[top.x][top.y])
            continue;
        visited[top.x][top.y] = true;
        
        for(int k = 0; k < 4; k++)
        {
            ll nx = top.x + dx[k];
            ll ny = top.y + dy[k];

            if(nx < 1 || ny < 1 || nx > n || ny > n || visited[nx][ny])
                continue;
            dp[nx][ny] = min(dp[nx][ny], dp[top.x][top.y] + t + (top.moves + 1 % 3 == 0  && (top.moves + 1 != 0)? times[nx][ny] : 0));
            enque.push(State(nx, ny, top.moves + 1));
        }
    }

    print2D(dp);
    return dp[n][n];
}


int main()
{
    setIO("visitfj");
    cin >> n >> t;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> times[i][j];
    
    cout << n << " " << t << endl;
    print2D(times);
    
    cout << "\n\n\n";
    cout << bfs() << endl;
    return 0;
}
