#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000
#define UNCOMPUTED -1
typedef long long ll;
ll n,ans,total,cnt = 0, dp[MAXN][MAXN];


int solve(int x, int sum)
{
    if(sum < 0 || x < 0) return 0;
    else if(dp[x][sum] != UNCOMPUTED) return dp[x][sum];
    else if(sum == 0) return dp[x][sum] = 1;

    return dp[x][sum] = solve(x - 1, sum) + solve(x - 1, sum - x);
}

int main()
{

    cin >> n;
    total = n * (n + 1) / 2;

    if(total % 2 != 0)
        cout << 0 << endl;

    else
    {
        for(int i = 0; i < MAXN; i++)
            for(int j = 0; j < MAXN; j++)
                dp[i][j] = UNCOMPUTED;

        cout << solve(n - 1,total / 2 - n) << endl;
    }
    return 0;
}
