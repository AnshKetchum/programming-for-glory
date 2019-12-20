#include <bits/stdc++.h>
using namespace std;
#define MAXN 4000
#define INF 100000000000000

typedef long long ll;
ll dp[MAXN][MAXN],ans,n,k,s[MAXN],running_max,sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream cin("snakes.in");
    ofstream cout("snakes.out");

    for(int i = 0; i < MAXN; i++)
        fill(dp[i], dp[i] + MAXN - 1, INF);

    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
        sum += s[i];
    }

    k++;
    for(int i = 1; i <= n; i++)
    {
        running_max = max(running_max,s[i]); //Taking the running max
        dp[i][1] = running_max * i;
        
        for(int p = 2; p <= k; p++)
        {
            ll rm2 = s[i];
            for(int j = i - 1; j >= 1; j--)
            {
                dp[i][p] = min(dp[i][p], dp[j][p - 1] + rm2 * (i - j));
                rm2 = max(rm2,s[j]);
            }
        }
    }

    cout << (dp[n][k] - sum) << endl;
    return 0;
}