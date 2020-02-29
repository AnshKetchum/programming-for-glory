#include <bits/stdc++.h>
using namespace std;
#define MAX_PLAYERS 100005
typedef long long ll;
ll h[2][MAX_PLAYERS],dp[MAX_PLAYERS][2];
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < n; j++)
            cin >> h[i][j];

    dp[0][0] = h[0][0]; //Base Case
    dp[0][1] = h[1][0];

    for(int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + h[0][i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + h[1][i]);
    }

    cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
}