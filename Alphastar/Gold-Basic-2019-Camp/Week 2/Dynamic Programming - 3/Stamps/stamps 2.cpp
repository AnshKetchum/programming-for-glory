#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 55
#define INF 1000000000
#define MAX_ARR 2000003

int n,k,v[MAXN],dp[MAX_ARR];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> k >> n;
    for(int i = 0; i < n; i++)
        cin >> v[i];

    for(int i = 1; i < MAX_ARR; i++)
        dp[i] = INF;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < MAX_ARR; j++)
            if(dp[j] != INF && dp[j] + 1 <= k)
                dp[j + v[i]] = min(dp[j + v[i]],dp[j] + 1);

    int ans = 1;
    while(dp[ans++] != INF);
    cout << ans - 2 << endl;
    return 0;
}
