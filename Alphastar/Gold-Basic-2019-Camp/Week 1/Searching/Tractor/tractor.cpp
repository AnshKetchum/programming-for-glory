#include <bits/stdc++.h>
using namespace std;
#define MAX_GRID 1010
#define MAXN 51000
typedef pair<int,int> pii;

pii start;
int grid[MAX_GRID][MAX_GRID],n,bales[MAX_GRID][MAX_GRID], ans = 1000000;
int dx [] = {0,0,1,-1};
int dy [] = {1,-1,0,0};
bool visited[MAX_GRID][MAX_GRID];

void bfs() // 0 1 BFS 
{
    deque <pii> enque;
    enque.push_front(start);

    while(!enque.empty())
    {
        pii top = enque.front();
        enque.pop_front();

        if(top.first == 0 && top.second == 0)
            ans = min(ans,bales[0][0]);

        if(visited[top.first][top.second])
            continue;

        visited[top.first][top.second] = true;

        for(int k = 0; k < 4; k++)
        {
            int n_x = top.first + dx[k];
            int n_y = top.second + dy[k];

            if(n_x < 0 || n_x >= MAX_GRID || n_y < 0 || n_y >= MAX_GRID || visited[n_x][n_y])
                continue;
            if(grid[n_x][n_y])
             {
                 bales[n_x][n_y] = bales[top.first][top.second] + 1;
                 enque.push_back(pii(n_x,n_y));
             }
            else
            {
                bales[n_x][n_y] = bales[top.first][top.second];
                enque.push_front(pii(n_x,n_y));
            }


        }

    }

}

int main()
{
    cin >> n >> start.first >> start.second;
    for(int i = 0; i < n; i++)
    {
        int x,y; cin >> x >> y;
        grid[x][y] = 1;
    }

    bfs();

    cout << ans << endl;
    return 0;
}
