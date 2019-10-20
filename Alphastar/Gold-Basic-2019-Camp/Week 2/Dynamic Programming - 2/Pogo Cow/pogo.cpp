#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 1500
typedef pair<int,int> pii;

int dp[MAXN][MAXN],ans,n;
vector<pii> points;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

   for(int i = 0; i < n; i++)
    {
        int a,b; cin >> a >> b;
        points.push_back(pii(a,b));
    }
   sort(points.begin(), points.end());

  for(int a = 0; a < 2; a++) 
  {
        for(int i = n - 1; i >= 0; i--) 
        {
            int k = n,runningMax = 0;
            for(int j = 0; j <= i; j++) 
            {
                while(points[k - 1].first - points[i].first >= points[i].first - points[j].first && k - 1 > i) 
                {
                  k--;
                  runningMax = max(runningMax, points[k].second + dp[k][i]);
                }
                dp[i][j] = runningMax;
            }
            ans = max(ans, points[i].second + runningMax);
        }

    for(int i = 0; i < n; i++)
      points[i].first = -points[i].first;

    reverse(points.begin(), points.end());
  }

  cout << ans << endl;
  return 0;
}
