#include <bits/stdc++.h>
using namespace std;
#define MAXT 1500000

int a,b,t,ans;
bool dp[MAXT][2];

void trans(int i, int j)
{
    if(dp[i][0] && i + j <= t)
    {
        dp[i + j][0] = true;
        dp[(i + j) / 2][1] = true;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream cin("feast.in");
    ofstream cout("feast.out");

    cin >> t >> a >> b;
    dp[0][0] = dp[0][1] = true;

    for(int i = 0; i <= t; i++)
    {
        trans(i,a);
        trans(i,b);
    }

    for(int i = 0; i <= t; i++)
        if(dp[i][1])
        {
            dp[i + a][1] = true;
            dp[i + b][1] = true;
            ans = i;
        }
    cout << ans << endl;
    return 0;
}