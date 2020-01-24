#include <bits/stdc++.h>
using namespace std;
#define MAXB 30
#define MAXN 500
#define GREATEST_VOLUME 1500000
#define INF 1e9

int n,b,v[MAXB],tot[MAXN],mvalue,dp[GREATEST_VOLUME],ans;

void create_lookup()
{
    fill(dp, dp + mvalue + 5, INF);
    dp[0] = 0;
    for(int i = 0; i < b; i++)
        for(int j = 0; j <= mvalue; j++)
            dp[j + v[i]] = min(dp[j + v[i]], dp[j] + 1);
}

int upd(int v)
{
    return dp[v] == INF ? 0 : dp[v];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> b;
    for(int i = 0; i < b; i++)
    {
        cin >> v[i];
    }

   for(int i = 0; i < n; i++)
    {
        cin >> tot[i];
        mvalue = max(mvalue, tot[i]);
    }

    create_lookup();
    ans += upd(tot[0]);
    for(int i = 1; i < n; i++)
    {
        int diff = (tot[i - 1] == 0 ? tot[i] : (tot[i] - (tot[i - 1] - 1))) ;
        if(diff > 0)
            ans += upd(diff);
    }
    cout << ans << endl;    

}

/*
5 2

5

7

0

17

16

20

19
*/