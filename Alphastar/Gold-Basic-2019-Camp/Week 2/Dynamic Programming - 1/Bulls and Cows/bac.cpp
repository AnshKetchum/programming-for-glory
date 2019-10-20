#include <bits/stdc++.h>
using namespace std;
#define MOD 5000011
#define MAXN 200000

typedef long long ll;
ll n,c,ans,dp[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> c;

    for(int i = 0; i < n; i++)
    {
        ll ind1 = i - 1,ind2 = i - c - 1;
        ll v1 = 1,v2 = 1;
        if(ind1 >= 0)
            v1 = dp[ind1];
        if(ind2 >= 0)
            v2 = dp[ind2];
        dp[i] = (v1 + v2) % MOD;
    }


    cout << dp[n - 1] % MOD  << endl;
    return 0;
}
