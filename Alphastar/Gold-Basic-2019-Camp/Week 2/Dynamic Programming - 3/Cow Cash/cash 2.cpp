#include <bits/stdc++.h>
using namespace std;
#define MAXN 30000
#define MAXV 30
#define int long long

int dp [MAXN],n,v,c[MAXV];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> v >> n;
    for(int i = 0; i < v; i++)
        cin >> c[i];
    dp[0] = 1;

    for(int i = 0; i < v; i++)
        for(int j = 0; j <= n; j++)
            if(dp[j])
                dp[c[i] + j] += dp[j];

    cout << dp[n] << endl;
    return 0;
}
