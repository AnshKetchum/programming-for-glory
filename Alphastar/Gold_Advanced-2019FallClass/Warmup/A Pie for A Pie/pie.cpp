#include <bits/stdc++.h>
using namespace std;
#define LL_INF 1e14
#define INT_INF 1e9
#define sz(x) int(x.size())
#define IMPOSSIBLE -1
#define push_back pb
#define all(x) (x).begin(), (x).end()
#define MOD 1e9 + 7
#define FASTIO 	ios_base::sync_with_stdio(nullptr); cin.tie(nullptr); cout.tie(nullptr);
#define MAXN 1e5 + 1e4
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

int n,d,dp[2][MAXN];
pll pie_list [2]; // 0 -> Bessie and 1 -> Elsie
set<pll> optimal_edge [2];
int dfs(int cow, int node)
{
    if(!pie_list[cow][node])
        return 0;
    if(dp[cow][node] != IMPOSSIBLE)
        return dp[cow][node];
    
    pll best_edge = optimal_edge

    return dp[cow][node] + (dfs(1 - cow, ) != IMPOSSIBLE); 
}

int main()
{
    FASTIO
    cin >> n >> d;

    fill(dp[0], dp[0] + n + 1, IMPOSSIBLE);
    fill(dp[0], dp[0] + n + 1, IMPOSSIBLE);

    for(int i = 0; i < n; i++)
    {
        cin >> pie_list[0].first >> pie_list[0].second;
        optimal_edge[0].insert(pll(pie_list[0].first,pie_list[0].second))
    }

    for(int i = 0; i < n; i++)
    {
        cin >> pie_list[1].first >> pie_list[1].second;
        optimal_edge[1].insert(pll(pie_list[1].first,pie_list[1].second))
    }

    for(int i = 0; i < n; i++)
        cout << dfs(0,i) << endl;
    return 0;
}