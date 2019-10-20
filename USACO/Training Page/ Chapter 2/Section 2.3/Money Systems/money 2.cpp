/*****
ID: INSERT_ID_HERE
LANG: C++
PROG: money
**/
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000
#define MAX_COINS 30
#define IMPOSSIBLE -1
#define int long long

int dp[MAXN];
int n,coin[MAX_COINS],want;

main()
{
    ifstream cin("money.in");
    ofstream cout("money.out");

    cin >> n >> want;
    for(int i = 0; i < n; i++)
        cin >> coin[i];

    dp[0] = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= want; j++)
            dp[j + coin[i]] += dp[j];

    cout << dp[want] << endl;
    return 0;
}
