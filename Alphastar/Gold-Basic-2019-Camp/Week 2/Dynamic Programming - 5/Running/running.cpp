#include <bits/stdc++.h>
using namespace std;
#define MAXN 15000
#define MAXM 1300
#define INF 10000000

int n,m,dist[MAXN],dp[2][MAXM][2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> dist[i];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= m; j++) //Trying all possible rest
        {
            dp[1][j][0] = max(dp[0][j + 1][0],dp[0][j + 1][1]);
            if(j == 0)
                dp[1][j][0] = max(dp[1][j][0],dp[0][j][0]);

            if(j  > 0)
                dp[1][j][1] = dp[0][j - 1][1] + dist[i];
            if(j == 1) 
                dp[1][j][1] = max(dp[1][j][1],dp[0][j - 1][0] + dist[i]);
            
        }
        for(int j = 0; j <= m; j++)
        {
            dp[0][j][0] = dp[1][j][0];
            dp[0][j][1] = dp[1][j][1];
            
            dp[1][j][0] = dp[1][j][1] = 0;
        }
    }
    cout << dp[0][0][0] << endl;
    return 0;
}
