#include <bits/stdc++.h>
using namespace std;
#define MAXN 150 
#define INF 100000000000000

typedef long long ll;
typedef pair<int,int> pii;
int n;
ll t,grid[MAXN][MAXN],cost[MAXN][MAXN][4];
bool visited[MAXN][MAXN];
int dx [] = {1,-1,0,0};
int dy [] = {0,0,1,-1};

struct State
{
    int x,y,cost;

    State(int x, int y, int cost)
    {
        this->x = x;
        this->y = y;
        this->cost = cost;

    }

};

bool operator<(const State& a, const State& b)
{
    return a.cost > b.cost;
}
void print_grid()
{
    cout << "\n\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << min(cost[i][j][1],min(cost[i][j][2],cost[i][j][3])) << " ";
        cout << endl;
    }
    cout << "\n";

}


ll bfs()
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cost[i][j][0] = cost[i][j][1] = cost[i][j][2] = cost[i][j][3] = INF;

 
    cost[0][0][0] = cost[0][0][1] = cost[0][0][2] = cost[0][0][3] = 0;
    priority_queue <State> enque;
    enque.push(State(0,0,0));

    while(!enque.empty())
    {
        State top = enque.top();
        enque.pop();

        if(visited[top.x][top.y])
            continue;

        visited[top.x][top.y] = true;
        for(int k = 0; k < 4; k++)
        {
            int nx = top.x + dx[k];
            int ny = top.y + dy[k];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny])
                continue;

            cost[nx][ny][1] = min(cost[nx][ny][1],cost[top.x][top.y][3] + t);
            cost[nx][ny][2] = min(cost[nx][ny][2],cost[top.x][top.y][1] + t);
            cost[nx][ny][3] = min(cost[nx][ny][3],cost[top.x][top.y][2] + t + grid[nx][ny]);

            enque.push(State(nx,ny, min(cost[nx][ny][1],min(cost[nx][ny][2],cost[nx][ny][3]))));
        }
    }

    //print_grid();

    
    return min(cost[n - 1][n - 1][1],min(cost[n - 1][n - 1][2],cost[n - 1][n - 1][3]));
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream cin("visitfj.in");
    ofstream cout("visitfj.out");

    cin >> n >> t;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];
    
    cout << bfs() << endl;
    return 0;
}