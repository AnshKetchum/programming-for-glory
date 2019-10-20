/*****
ID: INSERT_ID_HERE
LANG: C++
PROG: maze1
**/
#include <bits/stdc++.h>
using namespace std;
#define MAX_WIDTH 1005
#define MAX_HEIGHT 1005

struct State
{
    int x,y,dist;
};

State make_state(int a, int b, int c)
{
    State s;
    s.x = a;
    s.y = b;
    s.dist = c;
    return s;
}

char grid [MAX_HEIGHT][MAX_WIDTH];
bool visited[MAX_HEIGHT][MAX_WIDTH];
int w,h,ans;
queue <State> enque;

void bfs()
{
    int dx [] = {0,0,-1,1};
    int dy [] = {1,-1,0,0};

    while(!enque.empty())
    {
        State s = enque.front();
        enque.pop();

        if(visited[s.x][s.y])
            continue;

        ans = max(ans,s.dist);

        visited[s.x][s.y] = true;
        for(int i = 0; i < 4; i++)
        {
            int n_x = s.x + dx[i];
            int n_y = s.y + dy[i];

            int act_x = s.x + dx[i] * 2;
            int act_y = s.y + dy[i] * 2;
            if(grid[n_x][n_y] == ' ' && !visited[act_x][act_y] && act_x >= 0 && act_y >= 0 && act_x < h && act_y < w)
                enque.push(make_state(act_x,act_y,s.dist + 1));
        }

    }

}

int main()
{
    ifstream cin("maze1.in");
    ofstream cout("maze1.out");

    cin >> w >> h;
    string temp;
    getline(cin, temp);

    w = 2 * w + 1;
    h = 2 * h + 1;
    for(int i = 0; i < h; i++)
    {
        string str;
        getline(cin,str);
        for(int j = 0; j < w; j++)
        {
             grid[i][j] = str[j];
        }
    }

    for(int i = 0; i < w; i++)
    if(grid[0][i] == ' ' && grid[1][i] == ' ')
        enque.push(make_state(1,i,1));

    for(int i = 0; i < h; i++)
    if(grid[i][0] == ' ' && grid[i][1] == ' ')
        enque.push(make_state(i,1,1));

    for(int i = 0; i < h; i++)
    if(grid[i][w - 1] == ' ' && grid[i][w - 2] == ' ')
        enque.push(make_state(i,w - 2,1));

    for(int i = 0; i < w; i++)
    if(grid[h - 1][i] == ' ' && grid[h - 2][i] == ' ')
          enque.push(make_state(h - 2,i,1));

    bfs();

    cout << ans << endl;

    return 0;
}
