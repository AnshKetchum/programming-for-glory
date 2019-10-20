/*****
ID: INSERT_ID_HERE
LANG: C++
PROG: nocows
**/
#include <bits/stdc++.h>
using namespace std;
#define MAX_NODES 500
#define MAX_HEIGHT 500
#define MOD 9901
#define int long long

int n,k,dp[MAX_HEIGHT][MAX_NODES];
main()
{
    ifstream cin("nocows.in");
    ofstream cout("nocows.out");

    cin >> n >> k;

    for(int i = 1; i <= k; i++)
        dp[i][1] = 1;

    for(int i = 1; i <= k; i++)
        for(int j = 3; j <= n; j += 2)
            for(int tree = 1; tree <= j - 2; tree += 2)
            {
                dp[i][j] += dp[i - 1][tree] * dp[i - 1][j - tree - 1];
                dp[i][j] %= MOD;
            }

    cout << (dp[k][n] - dp[k - 1][n] + MOD) % MOD << endl;
    return 0;
}
