#include <bits/stdc++.h>
using namespace std;
#define MAX_GRID 1100

typedef long long ll;
ll leftVal[MAX_GRID],rightVal[MAX_GRID],n,dp[MAX_GRID][MAX_GRID];

bool areFriendly(ll a, ll b)
{
    return abs(a - b) <= 4;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> leftVal[i];
    for(int i = 0; i < n; i++)
        cin >> rightVal [i];

    //Precomputing the row and column
    for(int i = 0; i < n; i++)
    {
        dp[0][i] = areFriendly(leftVal[0],rightVal[i]);
        dp[i][0] = areFriendly(leftVal[i],rightVal[0]);
    }

    for(int i = 1; i < n; i++)
        for(int j = 1; j < n; j++)
        {
            if(areFriendly(leftVal[i],rightVal[j])) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
        }
    cout << dp[n - 1][n - 1] << endl;
    return 0;
}
