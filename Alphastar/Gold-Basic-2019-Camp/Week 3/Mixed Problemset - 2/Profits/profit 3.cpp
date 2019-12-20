#include <bits/stdc++.h>
using namespace std;
#define MAXN 150000

int dp[MAXN],num[MAXN],n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> num[i];
        dp[i] = max(0,dp[i - 1]) + num[i]; //Either Start Over, or Continue
    }

    int ans = dp[1];
    for(int i = 2; i <= n; i++)
        ans = max(ans,dp[i]);
    cout << ans << endl;
    return 0;
}
