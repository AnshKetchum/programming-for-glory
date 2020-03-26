#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define MAX_VAL 2000000
#define MAXN 5500
using namespace std;

void setIO(string name) 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int cnts [7 * MAX_VAL], n,dp[MAXN][MAXN],a[MAXN];
int main()
{
    setIO("threesum");
    int n,q; cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {       
            int sumInd = MAX_VAL - (a[i] + a[j]);
            if(sumInd >= 0 && sumInd <= 2 * MAX_VAL)    
                dp[i][j] = cnts[sumInd];
            ++cnts[MAX_VAL + a[j]];
        } 
        for(int j = i + 1; j <= n; j++)
            --cnts[MAX_VAL + a[j]];
    }

    for(int i = n; i > 0; i--)
        for(int j = i + 1; j <= n; j++)
            dp[i][j] += dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
    
    while(q--)
    {
        int a,b; cin >> a >> b;
        cout << dp[a][b] << endl;
    }
    return 0;
}
