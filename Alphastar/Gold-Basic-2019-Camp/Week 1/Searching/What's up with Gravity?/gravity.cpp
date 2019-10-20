#include <bits/stdc++.h>
using namespace std;
#define MAX_GRID 600
typedef pair<int,int> pii;

int m,n,ans = 1000000;
pii start;
bool visited[MAX_GRID][MAX_GRID][4];
char grid [MAX_GRID][MAX_GRID];
struct state
{
    int x,y,op,dir;
};

state make_state(int a, int b, int c,int d)
{
    state s;
    s.x = a;
    s.y = b;
    s.op = c;
    s.dir = d;
    return s;
}

bool valid(int x, int y, int dir)
{
    return !visited[x][y][dir + 1] && x >= 0 && x < n && y >= 0 && y < n && grid[x][y] != '#';
}

void bfs()
{
    deque <state> enque;
    enque.push_front(make_state(start.first,start.second,0,1));

    while(!enque.empty())
    {
        state top = enque.front();
        enque.pop_front();

        if(grid[top.x][top.y] == 'D')
        {
            ans = min(ans,top.op);
            continue;
        }
        if(visited[top.x][top.y][top.dir + 1])
            continue;
        
        visited[top.x][top.y][top.dir + 1] = true;

        int n_x = top.x + top.dir;
        if(n_x < n && n_x >= 0 && grid[n_x][top.y] != '#')
             if(n_x != 0 && n_x != n - 1)
                enque.push_front(make_state(n_x,top.y,top.op,top.dir));

        else
        {
            if(valid(top.x, top.y + 1,top.dir))
                enque.push_front(make_state(top.x, top.y + 1, top.op, top.dir));
            if(valid(top.x, top.y - 1,top.dir))
                enque.push_front(make_state(top.x, top.y - 1, top.op, top.dir));
            

            top.dir *= -1;
            enque.push_back(make_state(top.x,top.y,top.op + 1,top.dir));

        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
         {
            cin >> grid[i][j];
            if(grid[i][j] == 'C')
                 start = pii(i,j);
         }


    bfs();
    if(ans == 1000000)
        ans = -1;
    cout << ans << endl;
    return 0;
}
