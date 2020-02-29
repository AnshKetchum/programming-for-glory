#include <bits/stdc++.h> //Prob 1
using namespace std;
#define MAXN 150000
typedef pair<int,int> pii; //Cost, To -> Node

int n,m,c,dp[MAXN], base[MAXN];
vector < pii> from [MAXN];
int computeDP(int node)
{
	if(dp[node] != 0)
		return dp[node];
	for(pii x : from[node])
		dp[node] = max(dp[node], computeDP(x.second) + x.first);
	dp[node] = max(base[node],dp[node]);
	return dp[node];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ifstream cin("timeline.in");
	ofstream cout("timeline.out");

	cin >> n >> m >> c;
	for(int i = 1; i <= n; i++)
		cin >> base[i];
	for(int i = 0; i < c; i++)
	{
		int a,b,x; cin >> a >> b >> x;
		from[b].push_back(pii(x,a));
	}
	
	for(int i = 1; i <= n; i++)
	{
		computeDP(i);
		cout << dp[i] << endl;
	}
    return 0;
}