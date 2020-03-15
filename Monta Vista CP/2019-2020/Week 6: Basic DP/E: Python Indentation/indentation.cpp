#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MAXN 5005
typedef long long ll;
 
void setIO() //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
}
 
ll n,dp[MAXN][MAXN],command[MAXN],sum[MAXN],ans;
char let[MAXN];
int main()
{
    setIO();
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> let[i];
    dp[1][1] = 1;
 
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            sum[j + 1] = sum[j] + dp[i - 1][j];        
        for(int j = 1; j <= n; j++)
            dp[i][j] = (let[i - 1] == 'f' ? dp[i - 1][j - 1] % MOD : (sum[n + 1] - sum[j]) % MOD);
    }
 
    for(int i = 1; i <= n; i++)
        ans = (ans % MOD + dp[n][i] % MOD ) % MOD;
    cout << ans % MOD << endl;
    return 0;
}