#include <bits/stdc++.h>
using namespace std;
#define MAX_GRID 350
#define NEGINF -100000000000


int r,c,grid[MAX_GRID][MAX_GRID],best[MAX_GRID][MAX_GRID];
int dx [] = {-1,0,1};

bool valid(int a, int b)
{
    return a >= 0 && b >= 0 && a < r && b < c;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
        }

for(int i = 0; i < r; i++)
   for(int j = 0; j < c; j++)
        best[i][j] = NEGINF;
    best[0][0] = grid[0][0];


    for(int i = 0; i < c; i++)
        for(int j = 0; j < r; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                int n_x = j + dx[k];
                int n_y = i - 1;

                if(valid(n_x,n_y))
                {
                    best[j][i] = max(best[j][i],best[n_x][n_y] + grid[j][i]);
                }
            }
        }
    cout << best[r - 1][c - 1] << endl;
    return 0;
}
