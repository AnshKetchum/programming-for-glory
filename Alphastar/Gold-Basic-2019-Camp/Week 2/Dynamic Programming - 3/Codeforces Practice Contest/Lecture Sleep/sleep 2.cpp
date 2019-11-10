#include <bits/stdc++.h>
using namespace std;
#define MAXN 100500
#define int long long

int dp[MAXN],sum,addition[MAXN],n,k,a[MAXN],t[MAXN],ans;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
    {
        cin >> t[i];
        sum += ((t[i] == 0) ? 0 : a[i]);
        addition[i] = ((t[i] == 0) ? a[i] : 0);
        if(i > 0)
            addition[i] += addition[i - 1];
    }

    for(int i = 0; i < n; i++)
    {
        int ind = min(i + k - 1, n - 1),extra = addition[ind];
        if(i > 0)
            extra -= addition[i - 1];
        ans = max(ans,sum + extra);
    }
    cout << ans << endl;
    return 0;
}
