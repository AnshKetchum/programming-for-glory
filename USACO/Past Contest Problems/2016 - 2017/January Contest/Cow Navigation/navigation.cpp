#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define MAXN 50 
#define INF 1e9
using namespace std;
typedef pair<int,int> pii;


void setIO(string name) 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    //freopen((name+".out").c_str(),"w",stdout);
}

bool visited[MAXN][MAXN];
int n,dp[MAXN][MAXN][4][MAXN][MAXN][4];
char grid[MAXN][MAXN];
int dx [] = {-1,0,1,0};
int dy [] = {0,1,0,-1};

/*
Directions:
1 -> up
2 -> right
3 -> down
4 -> left
*/

bool in_bounds(int i, int j, int o)
{
    return (i >= 1 && j >= 1 && i <= n && j <= n);
}




int main()
{
    setIO("cownav");
    cin >> n;
    for(int i = n; i > 0; i--)
        for(int j = 1; j <= n; j++)
            cin >> grid[i][j];

    for(int a = 1; a <= n; a++)
        for(int b = 1; b <= n; b++)
            for(int c = 0; c < 4; c++)
                for(int d = 1; d <= n; d++)
                    for(int e = 1; e <= n; e++) 
                        for(int f = 0; f < 4; f++)  
                            dp[a][b][c][d][e][f] = INF;

    //First three indices represent starting up, next three starting right
    dp[1][1][1][1][1][2] = 0;
    bfs();


    return 0;
}
