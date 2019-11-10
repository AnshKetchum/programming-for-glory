#include <bits/stdc++.h>
using namespace std;
#define MAX_COMPUTERS 110
#define MAX_GRID 210
#define INF 100000000

typedef pair<int,int> pii;
int grid[MAX_GRID][MAX_GRID],connections [MAX_COMPUTERS][MAX_COMPUTERS],optimal_dist[MAX_GRID][MAX_GRID],l,w,n,t,ans = INF;
pii computers [MAX_COMPUTERS];
bool visited[MAX_GRID][MAX_GRID];
int dx [] = {-1,1,0,0};
int dy [] = {0,0,-1,1};

void bfs(int x, int y) //Building Connections matrix using BFS
{
    for(int i = 0; i < l; i++)
    {
        fill(optimal_dist[i], optimal_dist[i] + w + 1, INF);
        fill(visited[i], visited[i] + w + 1, false);
    }
    optimal_dist[x][y] = 0;
    queue <pii> enque;
    enque.push(pii(x,y));

    while(!enque.empty())   
    {
        pii top = enque.front();
        enque.pop();

        if(visited[top.first][top.second])
            continue;
        
        visited[top.first][top.second] = true;

        for(int k = 0; k < 4; k++)
        {
            int nx = top.first + dx[k];
            int ny = top.second + dy[k];

            if(nx < 0  || ny < 0 || nx >= l || ny >= w || visited[nx][ny] || grid[nx][ny])
                continue;

            optimal_dist[nx][ny] = min(optimal_dist[nx][ny], optimal_dist[top.first][top.second] + 1);
            enque.push(pii(nx,ny));
        }
    }
}

int prims(int source)
{
    int cost [MAX_COMPUTERS];
    fill(cost, cost + n + 1,INF);
    bool vis [MAX_COMPUTERS] = {false};
    priority_queue <pii> best_edges;

    cost[source] = 0;
    best_edges.push(pii(0,source));
    while(!best_edges.empty())
    {
        pii top = best_edges.top();
        best_edges.pop();

        if(vis[top.second])
            continue;
        
        vis[top.second] = true;
        for(int i = 0; i < n; i++)
            if(!vis[i])
            {
                cost[i] = min(cost[i],connections[top.second][i]);
                best_edges.push(pii(-connections[top.second][i],i));
            }
    }

    int ret = 0;
    for(int i = 0; i < n; i++)
        ret += cost[i];
    return ret;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> l >> w >> n;
    for(int i = 0; i < n; i++)
        cin >> computers[i].first >> computers[i].second;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        pii x; cin >> x.first >> x.second;
        grid[x.first][x.second] = 1;        
    }

    for(int i = 0; i < n; i++)
    {
        bfs(computers[i].first, computers[i].second);
        for(int j = 0; j < n; j++)
            connections[i][j] = optimal_dist[computers[j].first][computers[j].second];
    }


    for(int i = 0; i < n; i++)
        ans = min(ans, prims(i));
    cout << ans << endl;
    return 0;
}