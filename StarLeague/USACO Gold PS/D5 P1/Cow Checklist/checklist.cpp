#include <bits/stdc++.h>
using namespace std;
#define MAXC 1500
#define INF 1e9
typedef pair<int,int> pii;

int cost(pii a, pii b)
{
    int dx = a.first - b.first;
    int dy = a.second - b.second;
    return (dx * dx) + (dy * dy);
}

int g,h,dp[MAXC][MAXC][2];
pii gu[MAXC] , ho[MAXC];
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> h >> g;
    for(int i = 0; i < h; i++)
        cin >> ho[i].first >> ho[i].second;
    for(int i = 0; i < g; i++)
        cin >> gu[i].first >> gu[i].second;

    for(int i = 0; i < MAXC; i++)
        for(int j = 0; j < MAXC; j++)
            dp[i][j][0] = dp[i][j][1] = INF;
    
    dp[1][0][0] = 0;
    for(int i = 0; i <= h; i++)
        for(int j = 0; j <= g; j++)
            for(int k = 0; k < 2; k++) 
            {
                if(k == 0 && i == 0) 
                    continue;
                if(k == 1 && j == 0) 
                    continue;
            
                pii source = ( k == 0 ? ho[i - 1] : gu[j - 1] );
                if(i < h) 
                    dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][k] + cost(ho[i], source));
                if(j < g) 
                    dp[i][j+1][1] = min(dp[i][j+1][1], dp[i][j][k] + cost(gu[j], source));
            }




    cout << dp[h][g][0] << endl;
    return 0;
}