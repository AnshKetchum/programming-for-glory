#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MAX_GRID 150

typedef long long ll;
ll dp[MAX_GRID][MAX_GRID],r,c,k,grid[MAX_GRID][MAX_GRID];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c >> k;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> grid[i][j];

    dp[0][0] = 1;

    for(int x = 0; x < r; x++)
        for(int y = 0; y < c; y++)
            for(int i = x + 1; i < r; i++)
                for(int j = y + 1; j < c; j++)
                    if(grid[i][j] != grid[x][y])
                        dp[i][j] = (dp[i][j] + dp[x][y]) % MOD;
    cout << dp[r - 1][c - 1] % MOD << endl;
    return 0;
}
