#include <bits/stdc++.h>
using namespace std;
#define MAXN 500

int n,grid [MAXN][MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++)
        for(int j = 0; j < i; j++)
            cin >> grid[i][j];


    int ans = 0;

    for(int i = 2; i <= n; i++)
        for(int j = 0; j < i; j++)
            {
                if(j > 0)
                    grid[i][j] += max(grid[i - 1][j - 1],grid[i - 1][j]);
                else
                    grid[i][j] += grid[i - 1][j];
            }

    for(int i = 1; i <= n; i++)
        for(int j = 0; j < i; j++)
            ans = max(ans,grid[i][j]);
    cout << ans << endl;

    return 0;
}
