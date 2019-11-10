#include <bits/stdc++.h>
using namespace std;
#define MAXN 15
#define MAXC 10005
#define INF 100000000000
#define int long long

int dp [MAXC],n,v[MAXN],c;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> c >> n;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    for(int i = 1; i <= c; i++)
        dp[i] = INF;

    for(int i = 0; i < n; i++)
        for(int j = 0; j <= c; j++)
            if(dp[j] != INF)
                dp[v[i] + j] = min(dp[j] + 1,dp[v[i] + j]);

    cout << dp[c] << endl;
    return 0;
}
