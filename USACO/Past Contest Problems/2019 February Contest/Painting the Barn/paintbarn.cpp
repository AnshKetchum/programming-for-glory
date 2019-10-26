#include <bits/stdc++.h>
using namespace std;
#define GRID_BOUNDS 250
#define ACTUAL_GRID 200
#define MAXN 150000


typedef pair<int,int> pii;
int grid[GRID_BOUNDS][GRID_BOUNDS],n,k,ans,best_one_area = -1,best2;
priority_queue <int> best_two_area;
bool visited[GRID_BOUNDS][GRID_BOUNDS];
int dx [] = {-1,1,0,0};
int dy [] = {0,0,-1,1};
int minx,miny,maxx,maxy,cnt,mxx,mxy;

void dfs(int x, int y, int key)
{
    if(x < 0 || y < 0 || x > mxx || y > mxy || visited[x][y] || grid[x][y] != key)
        return;
    visited[x][y] = true;

    cnt++;
    cout << x << " " << y << endl;
    maxx = max(maxx,x); 
    minx = min(minx,x);
    maxy = max(maxy,y);
    miny = min(miny,y);

    for(int k = 0; k < 4; k++)
         dfs(x + dx[k],y + dy[k],key);
}

int count_k(int minx, int miny, int maxx, int maxy)
{
    int cnt = 0;
    for(int x = minx; x <= maxx; x++)
        for(int y = miny; y <= maxy; y++)
            cnt += (grid[x][y] == k ? 1 : 0);
    return cnt;
}

void printGrid(int x, int y)
{
    for(int i = 0; i <= x; i++)
    {
        for(int j = 0; j <= y; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream cin ("paintbarn.in");

    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        mxx = max(mxx,max(x1,x2));
        mxy = max(mxy,max(y1,y2));

        for(int r = x2; r >= x1; r--)
        {
            grid[r][y1]++;
            grid[r][y2 + 1]--;
        }
    }

    

    for(int i = 0; i <= mxx; i++)
        for(int j = 1; j <= mxy; j++)
            grid[i][j] += grid[i][j - 1];
    
    printGrid(8,8);
    cout << cnt << endl;
    for(int i = 0; i <= mxx; i++)
        for(int j = 0; j <= mxy; j++)
            if(!visited[i][j])
            {
                maxx = maxy = cnt = 0;
                minx = miny = ACTUAL_GRID;

                if(grid[i][j] == k - 2)
                {
                    cout << "Starting DFS 1 at: " << i << " " << j << endl;
                    best_one_area = max(best_one_area,dfs(i,j,k - 1));
                }
                else if(grid[i][j] == k - 1)
                {
                    cout << "Starting DFS 2 at: " << i << " " << j << endl;
                    dfs(i,j,k - 1);
                    int curans = cnt - count_k(minx,miny,maxx,maxy);
                    cout << "Pushing: " << curans << " " << minx << " " << miny << " " << maxx << " " << maxy << endl;
                    best_two_area.push(curans);
                }
            }



    int s = best_two_area.size();

    for(int i = 0; i < min(s,2); i++)
    {
        best2 += best_two_area.top();
        best_two_area.pop();
    }

    int kc = count_k(0,0,ACTUAL_GRID,ACTUAL_GRID);
    //ans = max(kc + best2,max(kc, kc + best_one_area));
    cout << ans  << " " << kc << " " << best2 << " " << best_one_area << " " << endl;   
    return 0; 
}