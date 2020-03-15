#include <bits/stdc++.h>
using namespace std;
#define MAXN 2020 
#define MOD 998244353
typedef long long ll;


void setIO() //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
}

int n,m,k;
ll dp[MAXN][MAXN];
int main()
{
    setIO();
    cin >> n >> m >> k;

    dp[1][0] = m;
    for(int i = 2; i <= n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if(j) dp[i][j] += dp[i - 1][j - 1] * (m - 1);
            dp[i][j] %= MOD;
        }
    }

    cout << dp[n][k] << endl;
    return 0;
}