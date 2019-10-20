#include <bits/stdc++.h>
using namespace std;
#define MAXN 300

int grid [MAXN][MAXN],n,b,ans = 0,temp = 0,cnt = 0; //We aren't counting the orig square
int visited [MAXN][MAXN];


int dx [] = {0,1,0,-1}, dy [] = {1,0,-1,0};

void dfs(int x, int y, int dx, int dy)
{
    bool stop = false;

    if(x <= 0 || y <= 0 || x > n || y > n || visited[x][y] || grid[x][y]) //Boundary Case
         return;

    int n_x = x,n_y = y;
    while(!grid[n_x][n_y] && n_x <= n && n_y <= n && n_x > 0 && n_y > 0)
    {
        if(visited[n_x][n_y] == 0)
            cnt++;
        else
        {
            stop = true;
            break;

        }

        visited[n_x][n_y]++;
        n_x += dx;
        n_y += dy;
    }
    n_x -= dx;
    n_y -= dy;
    ans = max(ans,cnt);

    if(!stop && dx == 0) //If we do not change x, change it
    {
        dfs(n_x + 1,n_y,1,0);
        dfs(n_x - 1,n_y,-1,0);
    }
    else if(!stop && dy == 0) //If we do not change y, change it
    {
        dfs(n_x,n_y + 1,0,1);
        dfs(n_x,n_y - 1,0,-1);
    }

    while(n_x != x - dx|| n_y != y - dy) //Reverting everything
    {
        cnt--;
        visited[n_x][n_y]--;
        n_x -= dx;
        n_y -= dy;
    }
}


int main()
{
    //    ifstream cin("test.in");
    cin >> n >> b;

    for(int i = 0; i < b; i++)
    {
        char c; int a;
        cin >> c >> a;
        grid[a][c - 'A' + 1] = 1;
    }

    dfs(1,1,1,0); //Down 
    dfs(1,1,0,1); //Right

    cout << ans << endl;
    return 0;
}


