#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define MAXN 1000
#define MAX_DP 1350 // Solution: Binary Search on MAX_DP (a.k.a. keep toggling this value based on submissions - WA = too low, TLE = too high)
using namespace std;
typedef pair<int,int> pii;

void setIO(string name) 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int n,dp[MAX_DP],w;
pii cows[MAXN];
int main()
{
    setIO("talent");
    cin >> n >> w;
    for(int i = 1; i <= n; i++)
        cin >> cows[i].first >> cows[i].second;

    fill(dp, dp + MAX_DP - 1, -1);

    dp[0] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = MAX_DP - 1; j >= 0; j--)
            if(dp[j] != -1 && j + cows[i].first < MAX_DP)
                dp[j + cows[i].first] = max(dp[j + cows[i].first], dp[j] + cows[i].second);

    double ans = 0.0;
    for(int i = w; i < MAX_DP; i++)
        ans = max(ans, dp[i] / (double)i);

    cout << (int)(1000 * ans) << endl;
    return 0;
}