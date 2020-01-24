#include <bits/stdc++.h>
using namespace std;
#define FASTIO 	ios_base::sync_with_stdio(nullptr); cin.tie(nullptr); cout.tie(nullptr);
#define MAXN 5000
typedef long long ll;



int n,dp[MAXN][MAXN],coins[MAXN],pref[MAXN];
int main()
{
    FASTIO
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> coins[n - i + 1];
    for(int i = 1; i <= n; i++) //Building a prefix 
        pref[i] = pref[i - 1] + coins[i];

    //Base Case: i = 0 is always 0 (0 left = 0 score)
    for(int i = 1; i <= n; i++) //Index
        for(int j = 1; j <= n; j++) //Previous
        {
            dp[i][j] = max(dp[i][j],dp[i][j - 1]);
            if(2 * j - 1 <= i)
                dp[i][j] = max(dp[i][j], pref[i] - dp[i - 2 * j + 1][ 2 * j - 1]);
            
            if( 2 * j <= i)
                dp[i][j]=max(dp[i][j], pref[i] - dp[i - 2 * j][2 * j]);
        }
    cout << dp[n][1] << endl;
    return 0;
}