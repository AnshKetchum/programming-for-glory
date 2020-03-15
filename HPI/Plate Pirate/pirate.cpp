#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define MAXN 1500

void setIO() //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
}

int n,dp[MAXN],ans;
pii plates[MAXN];
int main()
{
    setIO();
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> plates[i].first >> plates[i].second;
    sort(plates, plates + n);

    for(int i = 0; i < n; i++)
        dp[i] = plates[i].second;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < i; j++)
            if(plates[i].first > plates[j].first)
                dp[i] = max(dp[i], dp[j] + plates[i].second);

    for(int i = 0; i < n; i++)
        ans = max(dp[i], ans);    
    cout << ans << endl;
    return 0;
}