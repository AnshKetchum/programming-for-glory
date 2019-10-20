#include <bits/stdc++.h>
using namespace std;
#define MAXN 505
#define INF 10000000000
#define int long long

typedef pair<int,int> pii;
pii checkpoints[MAXN];
int n,k,dp[MAXN][MAXN]; //N Checkpoints, K < N possible stops -> output will be dp[n - 1][k]

int getDist(int a, int b)
{
    pii c = checkpoints[a], d = checkpoints[b];
    return abs(c.first - d.first) + abs(c.second - d.second);
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> checkpoints[i].first >> checkpoints[i].second;

    for(int i = 0; i < MAXN; i++) //DP of 0 slips will always equal 0
        for(int j = 0; j < MAXN; j++)
            dp[i][j] = INF;
    
    dp[0][0] = 0;
    for(int i = 0; i <= k; i++) 
        for(int j = 0; j < n; j++) 
            for(int x = j + 1; x < n && i + x - j - 1 <= k; x++) //Trying all possible j + k values
            {
                int n_i = i + (x - j - 1);
                int n_j = x;
                dp[n_i][n_j] = min(dp[n_i][n_j], dp[i][j] + getDist(j, x));
            }

    cout << dp[k][n - 1] << endl;
    return 0;
}
