#include <bits/stdc++.h>
using namespace std;
#define MAXN 500 //Pushing the memory limit
#define INF 10000

int dist [MAXN][MAXN],n = 0,meteor [MAXN][MAXN],ans = INF;
int dx [] = {0,0,-1,1};
int dy [] = {1,-1,0,0};
bool visited[MAXN][MAXN];

void bfs() //Simple Breadth First Search Solution to problem
{
    queue< pair<int, int>> enque;
    enque.push( pair<int, int>(0, 0));
    
    while (!enque.empty())
    {
        pair<int, int> top = enque.front();
        enque.pop();
        
        if(meteor[top.first][top.second] == INF)
           ans = min(ans,dist[top.first][top.second]);

        visited[top.first][top.second] = true;
        
        for (int k = 0; k < 4; k++) //Trying all directions - up,down,left, right
        {
            
            int n_x = top.first + dx[k];
            int n_y = top.second + dy[k];
            
            if(n_x < 0 || n_x >= MAXN || n_y < 0 || n_y >= MAXN || dist[top.first][top.second] + 1 >= meteor[n_x][n_y] || visited[n_x][n_y])
                continue;
            
            visited[n_x][n_y] = true;
            dist[n_x][n_y] = dist[top.first][top.second] + 1;
            pair<int,int> a = pair<int,int>(n_x,n_y);
            enque.push(a);
        }
    }
    
    
}

int main()
{
    cin >> n;

    for(int i = 0; i < MAXN; i++) //Initializing entire array to "Infinite" in order to use min() to locate meteors
        for(int j = 0; j < MAXN; j++)
             meteor[i][j] = INF;
    
    for(int j = 0; j < n; j++)
    {
        int a,b,t;
        cin >> a >> b >> t;
        meteor[a][b] = min(meteor[a][b],t);
        for (int k = 0; k < 4; k++)
        {
            int n_x = a + dx[k];
            int n_y = b + dy[k];
            
            if(n_x < 0 || n_x >= MAXN || n_y < 0 || n_y >= MAXN)
                continue;
            
            meteor[n_x][n_y] = min(t,meteor[n_x][n_y]);
        }
    }
    
    bfs();

    if(ans == INF)
        ans = -1;
    cout << ans << endl; 
}
