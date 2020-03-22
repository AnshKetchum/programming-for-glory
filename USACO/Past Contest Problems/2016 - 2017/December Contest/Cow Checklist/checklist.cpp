#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define MAX_COWS 1500
#define INF 1e15
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

ll cost(pii a, pii b)
{
    ll dx = a.first - b.first, dy = a.second - b.second;
    return (dx * dx) + (dy * dy);
}


ll H,G,dp[MAX_COWS][MAX_COWS][2];
pii h[MAX_COWS], g[MAX_COWS];
int main()
{
    setIO("checklist");
    cin >> H >> G;
    for(int i = 1; i <= H; i++)
        cin >> h[i].first >> h[i].second;
    for(int i = 1; i <= G; i++)
        cin >> g[i].first >> g[i].second;
    
    //Fill DP with large values 
    for(int i = 0; i <= H; i++)
        for(int j = 0; j <= G; j++)
            for(int k = 0; k < 2; k++)
                dp[i][j][k] = INF;
    
    //Base Case
    dp[1][0][0] = 0;

    //Computing DP
    for(int i = 1; i <= H; i++)
        for(int j = 1; j <= G; j++)
        {
            dp[i][j][0] = min( dp[i - 1][j][0] + cost(h[i - 1], h[i]) , dp[i - 1][j][1] + cost(h[i],g[j]));
            dp[i][j][1] = min( dp[i][j - 1][0] + cost(h[i],g[j]), dp[i][j - 1][1] + cost(g[j - 1], g[j]));
        }            
    
    cout << dp[H][G][0] << endl;
    return 0;
}
