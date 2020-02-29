#include <bits/stdc++.h>
using namespace std;
#define MAXM 29
#define MAXN 150000
#define INF 2e9

void setIO(string name) //Borrowed from USACO Legend Mr. Benjamin Qi (GitHub user Benq)
{
	ios_base::sync_with_stdio(nullptr); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int n,m,k,cost[MAXM][MAXM],pref[MAXN][MAXM],letter[MAXN],minDP[MAXN],dp[MAXN][MAXM];

void floyd_warshall() //Minimum Cost
{
    for(int a = 0; a < m; a++)
        for(int i = 0; i < m; i++)
            for(int j = 0; j < m; j++)
                cost[i][j] = min(cost[i][j], cost[i][a] + cost[a][j]);
}

void precalc_sum() //Build Prefix
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            pref[i + 1][j] = pref[i][j] + cost[letter[i]][j];
}

int query(int from, int to, int let) //Cost to convert from letter i to letter j over a range
{
    return (pref[to + 1][let] - pref[from][let]);
}

int main()
{
    setIO("cowmbat");
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
    {
        char c; cin >> c;
        letter[i] = c - 'a';
    }

    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            cin >> cost[i][j];

    floyd_warshall();
    precalc_sum();

    for(int i = 0; i < n; i++)
    {
        minDP[i] = INF; 
        for(int j = 0; j < m; j++)
        {
            int trans1 = INF,trans2 = 0;
            if(i >= k) //Case = K
                trans1 = min(trans1, minDP[i - k] + query(i - k + 1, i,j) );
            if(i > 0)
                trans2 = dp[i - 1][j];
            trans2 += cost[letter[i]][j];

            dp[i][j] = min(trans1,trans2);
            minDP[i] = min(minDP[i], dp[i][j]);
        }
    }

    cout << minDP[n - 1] << endl;
    return 0;
}