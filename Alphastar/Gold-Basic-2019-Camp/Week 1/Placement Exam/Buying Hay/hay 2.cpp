#include <bits/stdc++.h>
using namespace std;
#define MAXH 110000
#define MAXN 105
#define INF 1000000000
#define int long long

typedef pair<int,int> pii;
pii farmers [MAXN];
int n,h, dp[MAXH];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> h;
    for(int i = 0; i < n; i++)
        cin >> farmers[i].first >> farmers[i].second;

    for(int i = 1; i < MAXH; i++)
        dp[i] = INF;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < MAXH; j++)
            if(dp[j] != INF && j + farmers[i].first < MAXH)
                dp[j + farmers[i].first] = min(dp[j + farmers[i].first],dp[j] + farmers[i].second);

    int ans = dp[h];
    for(int i = h; i < MAXH; i++)
        ans = min(ans,dp[i]);

    cout << ans << endl;
    return 0;
}
