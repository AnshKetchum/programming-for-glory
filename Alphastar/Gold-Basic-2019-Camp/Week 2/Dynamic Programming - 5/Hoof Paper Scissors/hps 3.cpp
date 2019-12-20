#include <bits/stdc++.h>
using namespace std;
#define MAXN 105000
#define MAXK 25

int n,k,dp[MAXN][MAXK][3],fj[MAXN];

int getWins(int play, int b)
{
    int fjplay = fj[b];
    if ( (play == 0 && fjplay == 2) || (play == 1 && fjplay == 0) || (play == 2 && fjplay == 1))
        return 1;
    return 0;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        char c; cin >> c;
        switch (c)
        {
            case 'H':
            fj[i] = 0;
            break;

            case 'P':
            fj[i] = 1;
            break;

            case 'S':
            fj[i] = 2;
            break;
        }
    }

    if(fj[0] == 0)
        dp[0][0][1] = 1;
    else if(fj[0] == 1)
        dp[0][0][2] = 1;
    else
        dp[0][0][0] = 1;

    for(int i = 1; i < n; i++)
        for(int j = 0; j <= k; j++)
        {
            dp[i][j][0] = dp[i - 1][j][0] + getWins(0,i);
            dp[i][j][1] = dp[i - 1][j][1] + getWins(1,i);
            dp[i][j][2] = dp[i - 1][j][2] + getWins(2,i);

            if(j > 0)
            {
                dp[i][j][0] = max(dp[i][j][0],dp[i - 1][j - 1][1] + getWins(0,i));
                dp[i][j][0] = max(dp[i][j][0],dp[i - 1][j - 1][2] + getWins(0,i));

                dp[i][j][1] = max(dp[i][j][1],dp[i - 1][j - 1][0] + getWins(1,i));
                dp[i][j][1] = max(dp[i][j][1],dp[i - 1][j - 1][2] + getWins(1,i));

                dp[i][j][2] = max(dp[i][j][2],dp[i - 1][j - 1][0] + getWins(2,i));
                dp[i][j][2] = max(dp[i][j][2],dp[i - 1][j - 1][1] + getWins(2,i));
            }
        }


    cout << max(max(dp[n - 1][k][0],dp[n - 1][k][1]), dp[n - 1][k][2]) << endl;
    return 0;
}
