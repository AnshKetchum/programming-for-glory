#include <bits/stdc++.h>
using namespace std;
#define MAXN 21000

int dp[MAXN],n,sequence[MAXN],ans  = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> sequence[i];

    for(int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
            if(sequence[j] < sequence[i])
                    dp[i] = max(dp[i],dp[j] + 1);
        ans = max(ans,dp[i]);
    }

    cout << ans << endl;
    return 0;
}
