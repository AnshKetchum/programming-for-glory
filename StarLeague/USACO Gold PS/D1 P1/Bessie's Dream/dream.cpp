#include <bits/stdc++.h>
using namespace std;
#define INF 10000000
#define MAX_GRID 1005

int ans = INF,grid[MAX_GRID][MAX_GRID],n,m;
bool visited[MAX_GRID][MAX_GRID][4][2]; //State: X,Y,Direction (0,1,2,3), and whether he has orange or not (1 = has orange), and distance
int dx [] = {-1,1,0,0};
int dy [] = {0,0,-1,1}; 
int counter = 0;  
typedef pair<int,int> pii;

//0 -> up, 1 -> down, 2 -> left, 3 -> right
struct State
{
    int x,y,direction,has_orange,dist;

    State(int x, int y, int direction, int has_orange, int dist)
    {
        this->x = x;
        this->y = y;
        this->direction = direction;
        this->has_orange = has_orange;
        this->dist = dist;
    }

};

bool is_passable(State top)
{
    pii next = pii(top.x + dx[top.direction],top.y + dy[top.direction]);
    if(grid[next.first][next.second] == 0)
        return false;
    if(grid[next.first][next.second] == 3 && top.has_orange == 0)
        return false;

    return true;

}

void bfs()
{
    queue <State> enque;
    for(int dir = 0; dir < 4; dir++) //Push all possible Directions
        enque.push(State(1,1,dir,0,0));

    while(!enque.empty())
    {

        State top = enque.front();
        enque.pop();

        if(top.x <= 0 || top.y <= 0 || top.x > n || top.y > m || visited[top.x][top.y][top.direction][top.has_orange] || grid[top.x][top.y]  == 0 || (grid[top.x][top.y] == 3 && top.has_orange == 0))
            continue;

        if(top.x == n && top.y == m)
        {
            ans = min(ans,top.dist);
            continue;
        }
        
        visited[top.x][top.y][top.direction][top.has_orange] = true;
        if(grid[top.x][top.y] == 4 && is_passable(top))
                enque.push(State(top.x + dx[top.direction],top.y + dy[top.direction],top.direction,0,top.dist + 1));
        else
        {
            for(int k = 0; k < 4; k++)
            {
                int n_x = top.x + dx[k];
                int n_y = top.y + dy[k];

                if(n_x <= 0 || n_y <= 0 || n_x > n || n_y > m)
                    continue;

                int orange_state = (grid[n_x][n_y] == 2 || top.has_orange) && (grid[n_x][n_y] != 4);
                enque.push(State(n_x,n_y,k,orange_state,top.dist + 1));
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> grid[i][j];
    bfs();
    
    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}