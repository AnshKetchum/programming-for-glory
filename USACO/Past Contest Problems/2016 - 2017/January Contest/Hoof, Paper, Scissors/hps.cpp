#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define MAXN 150000
#define MAXK 25
using namespace std;

void setIO(string name) 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int n,k,dp[MAXN][MAXK][3],a[MAXN]; // 0 -> Rock , 1 -> Paper, 2 -> Scissors

int wins(int a, int b)
{
    if(a == 0 && b == 2)
        return 1;
    if(a == 1 && b == 0)
        return 1;
    if(a == 2 && b == 1)
        return 1;
    return 0;
}

int main()
{
    setIO("hps");
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        char c; cin >> c;
        if(c == 'H') a[i] = 0;
        if(c == 'P') a[i] = 1;
        if(c == 'S') a[i] = 2;
    }

    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= k; j++)
        {
            dp[i][j][0] = dp[i - 1][j][0] + wins(0,a[i]);
            dp[i][j][1] = dp[i - 1][j][1] + wins(1,a[i]);
            dp[i][j][2] = dp[i - 1][j][2] + wins(2,a[i]);
            if(j)
            {
                dp[i][j][0] = max(dp[i - 1][j][0],max(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2])) + wins(0, a[i]);
                dp[i][j][1] = max(dp[i - 1][j][1],max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][2])) + wins(1, a[i]);
                dp[i][j][2] = max(dp[i - 1][j][2],max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1])) + wins(2, a[i]);
            }
        }

    cout << max(dp[n][k][0], max(dp[n][k][1], dp[n][k][2])) << endl;
    return 0;
}
