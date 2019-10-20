#include <bits/stdc++.h>
using namespace std;
#define MAXN 510000

typedef pair<int,int> pii;
pii ranges [MAXN];
int n,dp[MAXN];

bool canShare(int i, int j)
{
    return i <= j;
}

bool cmp(pii a, pii b)
{
    return a.second < b.second;
}

int binSearch(int start) //Exploiting the monotonicity of the problem
{
    int l = -1,r = n -  1,mid;

    while (l < r)
    {
        mid = (l + r + 1) / 2;
        if (canShare(ranges[mid].second,start))  //Satisfying the inequality
            l = mid;
        else
            r = mid - 1;
    }
    return l + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> ranges[i].first >> ranges[i].second;
    sort(ranges,ranges + n,cmp);

    for(int i = 0; i < n; i++)
        dp[i + 1] = max(dp[binSearch(ranges[i].first)] + 1, dp[i]);

    cout << dp[n] << endl;
    return 0;
}
