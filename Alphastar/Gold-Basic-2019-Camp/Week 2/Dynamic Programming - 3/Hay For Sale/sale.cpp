#include <bits/stdc++.h>
using namespace std;
#define MAXH 5005
#define MAXC 50010

int c,h,v[MAXH],best;
bool dp[2][MAXC];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> c >> h;
    for(int i = 0; i < h; i++)
        cin >> v[i];

    dp[0][0] = true;
    for(int i = 1; i <= h; i++)
    {
        for(int j = 0; j <= c; j++)
        {
            int ind = j - v[i - 1];
            if(ind < 0)
                dp[1][j] = dp[0][j];
            else
                dp[1][j] = (dp[0][j] || dp[0][ind]);
            if(dp[1][j])
                best = max(best,j);
        }
        swap(dp[0],dp[1]); //I replaced this with my manual swap as it is faster
    }

    cout << best << endl;
    return 0;
}
