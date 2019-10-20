#include <bits/stdc++.h>
using namespace std;
#define MAX_WEIGHTS 50000
#define MAXN 505

int h,n,w[MAX_WEIGHTS];
bool dp[MAXN][MAX_WEIGHTS];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> h >> n;
    for(int i = 0; i < n; i++)
        cin >> w[i];

    dp[0][0] = true;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= h; j++)
        {
            if(i == 0)
                continue;
            int ind = j - w[i - 1];
            if(ind < 0)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = (dp[i - 1][j] || dp[i - 1][ind]);
        }


    int ans = 0;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= h; j++)
            if(dp[i][j]) ans = max(ans,j);
    cout << ans << endl;

    return 0;
}
