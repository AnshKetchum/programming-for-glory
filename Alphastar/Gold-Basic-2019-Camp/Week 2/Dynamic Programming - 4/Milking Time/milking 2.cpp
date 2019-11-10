#include <bits/stdc++.h>
using namespace std;
#define MAXM 10005
#define int long long

int n,m,r,ans,dp[MAXM];
struct Interval
{
    int starting,ending,efficiency;
    Interval(int starting, int ending, int efficiency)
    {
        this->starting = starting;
        this->ending = ending;
        this->efficiency = efficiency;
    }
};

bool dontIntersect(Interval a, Interval b)
{
    return a.ending + r <= b.starting;
}

vector <Interval> intervals;
main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);

   cin >> n >> m >> r;
   for(int i = 0; i < m; i++)
   {
        int a,b,c; cin >> a >> b >> c;
        intervals.push_back(Interval(a,b,c));
   }

   sort(intervals.begin(),intervals.end(),[](const Interval a, const Interval b)
    {
        return a.ending < b.ending;
    });

    for(int i = 0; i < m; i++)
    {
        int bestInt = -1;
        for(int j = 0; j < i; j++)
            if(dontIntersect(intervals[j],intervals[i]) && (dp[j] > dp[bestInt] || bestInt == -1))
                bestInt = j;
        dp[i] = (bestInt == -1 ? 0 : dp[bestInt] ) + intervals[i].efficiency;
        ans = max(dp[i],ans);
    }

    cout << ans << endl;
    return 0;
}
