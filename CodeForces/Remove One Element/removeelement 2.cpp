#include <bits/stdc++.h>
using namespace std;
#define MAXN 150000

int n,a[MAXN],dp[MAXN][2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    dp[0][0] = dp[0][1] = 1;
    for(int i = 1; i < n; i++)
    {
        if(a[i] > a[i - 1])
        {
            dp[i][0] = max(dp[i - 1][0],dp[i - 1][1]) + 1;
            dp[i][1] = dp[i - 1][1] + 1;
        }        
        else
        {
            dp[i][0] = max(dp[i - 1][0],dp[i - 1][1]);
            if(i > 1 && a[i] > a[i - 2])
                dp[i][0] = max(dp[i][0],dp[i - 2][0] + 1);
            dp[i][1] = 0;
        }
    }
    for(int i = 0; i < n; i++) {cout << dp[i][0] << " ";} cout << endl;
    for(int i = 0; i < n; i++) {cout << dp[i][1] << " ";} cout << endl;

    cout << max(dp[n - 1][0] , dp[n - 1][1]) << endl;
    return 0;
}