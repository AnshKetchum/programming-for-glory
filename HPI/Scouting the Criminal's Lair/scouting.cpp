#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define MAX_GRID 1500
#define INF 10000000
#define MAXK 100
 
void setIO() //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
}

int n,k,dx[MAXK],dy[MAXK],m,ans = INF,dist[MAX_GRID][MAX_GRID];
bool visited[MAX_GRID][MAX_GRID];
char grid[MAX_GRID][MAX_GRID];
pii start;
void bfs()
{
    queue<pii> enque;
    enque.push(start);


    while(!enque.empty())
    {
        pii top = enque.front();
        enque.pop();

        if(grid[top.first][top.second] == 'A')
            ans = min(ans,dist[top.first][top.second]);
        if(visited[top.first][top.second])
            continue;

        visited[top.first][top.second] = true;
        for(int i = 0; i < k; i++)
        {
            int nx = top.first + dx[i];
            int ny = top.second + dy[i];

            if(nx < 0 || ny < 0 ||  nx >= m || ny >= n || visited[nx][ny] || grid[nx][ny] == 'X')
                continue;
            dist[nx][ny] = min(dist[nx][ny], dist[top.first][top.second] + 1);
            enque.push(pii(nx,ny));
        }

    }

    if(ans == INF)
        cout << "NO" << endl;
    else 
        cout << "YES" << " " << ans << endl;
}

int main()
{
    setIO();
    cin >> m >> n >> k;

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            if(grid[i][j] == 'A')
                start = pii(i,j);
            dist[i][j] = INF;
        }
    for(int i = 0; i < k; i++)
        cin >> dx[i] >> dy[i];
    bfs();
    return 0;
}