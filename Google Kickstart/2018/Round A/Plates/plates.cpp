#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define MAX_TOT 2500
using namespace std;

void setIO() 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
}

int dp [MAX_TOT][MAX_TOT],sums[MAX_TOT];
void solve(int tc)
{
    int n,k,p; cin >> n >> k >> p;

    fill(sums, sums + MAX_TOT - 1, 0);
    for(int i = 0; i <= n; i++)
        fill(dp[i], dp[i] + MAX_TOT - 1, 0);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1, a = 0; j <= k; j++)
        {
            cin >> a; 
            sums[j] = sums[j - 1] + a;
        }

        dp[i][0] = 0;
        for(int j = 1; j <= k; j++)
            for(int a = p; a >= 0; a--)
                dp[i][a + j] = max(max(dp[i][a + j],dp[i - 1][a + j]), dp[i - 1][a] + sums[j]);

    }


    cout << "Case #" << tc << ": " << dp[n][p] << endl;
}


int main()
{
    setIO();
    int t; cin >> t;
    for(int i = 1; i <= t; i++)
        solve(i);


    return 0;
}
