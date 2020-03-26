#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define INF 1e9
#define MAXN 1500
#define MAXC 1500
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

int n,dp[MAXN][MAXC];
int main()
{
    //setIO("shopping");
    cin >> n;
    
    for(int i = 0; i < MAXN; i++)
    {
        fill(dp[i], dp[i] + MAXC - 1, INF);
        dp[i][0] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        int s,p; cin >> s;
        vector<pii> offers;
        for(int j = 0,a,b; j < s; j++)
        {
            cin >> a >> b;
            offers.push_back(pii(b,a)); //Product code b has a items
        }
        cin >> p;

        for(pii x : offers)
            for(int j = MAXN - 1; j >= 0; j--)
                if(j + x.second < MAXN)
                    dp[x.first][j + x.second] = min(dp[x.first][j + x.second], dp[x.first][j] + p);
    }

    
    return 0;
}
