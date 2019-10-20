#include <bits/stdc++.h>
using namespace std;
#define MAXN 50
#define x_coord .second.first
#define y_coord .second.second
#define INF 1000000000

struct State
{
    int x,y,edge;

    State(int x, int y, int edge)
    {
        this->x = x;
        this->y = y;
        this->edge = edge;
    }

    bool operator<(const State &o) const
    {
        return edge > o.edge;
    }
};


int n,a,b,ans,grid[MAXN][MAXN];
int dx [] = {-1,1,0,0};
int dy [] = {0,0,-1,1};

int dijkstra(int x, int y)
{
    int cost[MAXN][MAXN];
    bool visited[MAXN][MAXN];

    for(int i = 1; i <= n; i++)
    {
        fill(cost[i], cost[i] + n + 5, INF);
        fill(visited[i], visited[i] + n + 5, false);

    }

    cost[x][y] = 0;
    priority_queue <State> best_edges;
    best_edges.push(State(x,y,0));



    while(!best_edges.empty())
    {
        State top = best_edges.top();
        best_edges.pop();

      //  cout << "Top: " << top.x << " " << top.y << " " << top.edge << endl;
        if(visited[top.x][top.y])
            continue;
        visited[top.x][top.y] = true;

        for(int k = 0; k < 4; k++)
        {
            int n_x = top.x + dx[k];
            int n_y = top.y + dy[k];

            if(n_x <= 0 || n_y <= 0 || n_x > n || n_y > n || visited[n_x][n_y])
                continue;
            int c = (top.edge + (grid[top.x][top.y] == grid[n_x][n_y] ? a : b));
            cost[n_x][n_y] = min(cost[n_x][n_y], c );
            best_edges.push(State(n_x,n_y,c));
        }

    }

    int ret = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            ret  = max(ret,cost[i][j]);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

   cin >> n >> a >> b;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            char c; cin >> c; 
           grid[i][j] = (c == ')' ? 1 : 0);
        }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            ans = max(ans, dijkstra(i,j));
    cout << ans << endl; 
    return 0; 
}