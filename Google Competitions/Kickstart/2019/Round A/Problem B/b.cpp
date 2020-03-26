#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define MAXN 350 
#define INF 1e9
using namespace std;
typedef pair<int,int> pii;

void setIO() 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
}

int mdist(int x1, int x2, int y1, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

int n,r,c, grid[MAXN][MAXN],dist[MAXN][MAXN];
vector <pii> deliv; 
pii ans;
bool visited[MAXN][MAXN],flag;

void print2D(int a [MAXN][MAXN])
{
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

}

void bfs()
{
    queue<pii> enque; 
    for(int i = 0; i <= r + 3; i++)
    {
        fill(dist[i], dist[i] + c + 5, INF);
        fill(visited[i], visited[i] + c + 5, false);
    }
    for(pii x : deliv)
    {
        dist[x.first][x.second] = 0;
        enque.push(x);
    }

    int dx [] = {-1,1,0,0};
    int dy [] = {0,0,-1,1};
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

            if(nx < 1 || nx > r || ny < 1 || ny > c || grid[nx][ny] ||  visited[nx][ny])
                continue;
            dist[nx][ny] = min(dist[nx][ny], dist[top.first][top.second] + 1);
            enque.push(pii(nx,ny));
        }
    }

    ans = pii(1,1);
    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++)
            if(dist[i][j] > dist[ans.first][ans.second] && !grid[i][j])
            {
                flag = true;
                ans = pii(i,j);
            }
}   


int main()
{
    setIO();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> r >> c;
        deliv.clear(); 

        for(int a = 1; a <= r; a++)
        {
            for(int b = 1; b <= c; b++)
            {
                char z; cin >> z;
                grid[a][b] = (int)(z - '0'); 
                if(grid[a][b] == 1)
                    deliv.push_back(pii(a,b));
            }
        }

        bfs();
        int ret = 0;

        if(flag)
        {
            grid[ans.first][ans.second] = 1;

            for(int i = 1; i <= r; i++)
                for(int j = 1; j <= c; j++)
                    if(!grid[i][j])
                        ret = max(ret, min(dist[i][j], mdist(i,ans.first,j,ans.second)));
        }
        cout << "Case #" << i << ": " << (flag ? ret : 0) << endl;
    }

    return 0;
}


/*
3
3 3
101
000
101
1 2
11
5 5
10001
00000
00000
00000
10001

*/

 	

Case #1: 1
Case #2: 0
Case #3: 2