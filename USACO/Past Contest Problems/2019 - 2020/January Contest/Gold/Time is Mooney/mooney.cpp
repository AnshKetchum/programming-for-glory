#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
using namespace std;
#define MAXN 5500
#define INF 1e6
#define BOUND_TIME 1500
typedef long long ll;

void setIO(string name) 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}


ll n,c,M,dp[MAXN][MAXN],m[MAXN],ans;
vector<int> connections [MAXN];
int main()
{
    setIO("time");
    cin >> n >> M >> c;
    for(int i = 1; i <= n; i++)    
        cin >> m[i];
    for(int i = 1; i <= M; i++)
    {
        int a,b; cin >> a >> b;
        connections[b].push_back(a);
    }

    for(int i = 0; i <= n; i++)
        fill(dp[i], dp[i] + BOUND_TIME, -INF);

    dp[1][0] = 0;
    for(int t = 1; t <= BOUND_TIME; t++)
    {
        for(int i = 1; i <= n; i++)
            for(int x  : connections[i])
                if(dp[x][t - 1] != -INF)
                    dp[i][t] = max(dp[i][t], dp[x][t - 1] + m[i]);
    }

    for(int t = 0; t <= BOUND_TIME; t++)
        ans = max(ans, dp[1][t] - c * t * t);
    cout << ans << endl;
    return 0;  
}
