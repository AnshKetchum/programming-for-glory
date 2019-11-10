#include <bits/stdc++.h>
using namespace std;
#define MAXM 150000
#define INF 100000000
#define MAXN 2000

int n,m;
int sequence [MAXM],grid[MAXN][MAXN];

void floyd_warshall()
{
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> sequence[i];
        sequence[i]--;
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    floyd_warshall();

    int ans = 0;
    for(int i = 1; i < m; i++)
        ans += grid[sequence[i - 1]][sequence[i]];
    
    cout << ans << endl;

    return 0;
}
