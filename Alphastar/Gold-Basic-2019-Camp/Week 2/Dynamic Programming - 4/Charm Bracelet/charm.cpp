#include <bits/stdc++.h>
using namespace std;
#define MAXN 3500
#define MAXM 26000
#define UNCOMPUTED -1
#define int long long

typedef pair<int,int> pii;
int dp[MAXM],n,m,ans;
pii objects[MAXN];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> objects[i].first >> objects[i].second;

    for(int i = 1; i <= MAXM; i++)
        dp[i] = UNCOMPUTED;


    for(int i = 0; i < n; i++)
        for(int j = m; j >= 0; j--)
            if(dp[j] != UNCOMPUTED)
                dp[objects[i].first + j] = max(dp[objects[i].first + j],dp[j] + objects[i].second);

    for(int i = 0; i <= m; i++)
        ans = max(ans,dp[i]);
    cout << ans << endl;
    return 0;
}
