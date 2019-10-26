#include <bits/stdc++.h>
using namespace std;
#define MAXN 1500
#define MAXP 15
#define INF 10000000000
 
typedef long long ll;
ll n,m,p,s[MAXP],area[MAXN],turn,cost[MAXN][MAXN],skip_count,no_change;
char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dx [] = {-1,1,0,0};
int dy [] = {0,0,1,-1};
bool skip[MAXN];
 
void printGrid()
{
    cout << "\n\n";
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            cout << grid[i][j];
        cout << endl;
    }
}
struct Point
{
    int x,y;
    ll cost;
 
    Point(int x, int y, ll cost)
    {   
        this->x = x;
        this->y = y;
        this->cost = cost;
    }
};
 
bool operator<(const Point& p1, const Point& p2) 
{ 
    return p1.cost < p2.cost; 
} 
 
 
bool out_of_bounds(int x, int y)
{
    return (x < 1 || y < 1 || x > n || y > m || visited[x][y]);
}
 
bool has_player_neighbor(int x, int y, int player)
{
    for(int k = 0; k < 4; k++)
    {
        int n_x = x + dx[k];
        int n_y = y + dy[k];
        
        if(!out_of_bounds(n_x,n_y) && grid[n_x][n_y] - '0' == player)
            return true;
    }
    return false;
}
 
bool iterate() //Decides whether to iterate or not
{
 
    int skipcnt = 0;
    while(true)
    {
        turn++;
        if(turn > p)
            turn = 1;
        if(!skip[turn])
            break;
        skipcnt++;
        if(skipcnt > 2 * p)
            return false;
        
    }

    //cout << "Turn = " << turn << endl;
 
    for(int i = 1; i <= n; i++)
    {
        fill(visited[i], visited[i] + m + 1, false);
        fill(cost[i], cost[i] + m + 1, INF);
    }
 
    queue <Point> best_edges;
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++)
            if(has_player_neighbor(i,j,turn) && grid[i][j] == '.')
            {
               // cout << i << " " << j << endl;
                cost[i][j] = 1;
                best_edges.push(Point(i,j,1));
            }
    while(!best_edges.empty())
    {
        Point top = best_edges.front();
        best_edges.pop();
 
        if(visited[top.x][top.y])
            continue;
 
        visited[top.x][top.y] = true;
 
        for(int k = 0; k < 4; k++)
        {
            int n_x = top.x + dx[k];
            int n_y = top.y + dy[k];
 
            if(out_of_bounds(n_x,n_y) || grid[n_x][n_y] != '.')
                continue;
 
            ll c = cost[top.x][top.y] + 1;
            cost[n_x][n_y] = min(cost[n_x][n_y], c);
            best_edges.push(Point(n_x,n_y,c));
        }
    }
 
    int cnt = 0;
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++)
            if( (grid[i][j] == '.' && cost[i][j] <= s[turn]) || grid[i][j] - '0' == turn)
            {
                cnt++;
                grid[i][j] = (char)('0' + turn);
            }
 
    /*cout << "\n\n";
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            cout << cost[i][j] << " ";
        cout << endl; 
    } */
 
    //printGrid();
 
    no_change = (area[turn] == cnt ? no_change + 1 : 0) + skip_count;

    if(area[turn] == cnt)
    {
        skip[turn] = true;
        skip_count++;
    }
    area[turn] = cnt;
    return no_change <= p;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    //ifstream cin("test.in");
 
    cin >> n >> m >> p;
    for(int i = 1; i <= p; i++)
        cin >> s[i];
 
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> grid[i][j];
 
    //cout << "Completed IO" << endl;
    while(iterate());
 
    for(int i = 1; i <= p; i++)
        cout << area[i] << " ";
    cout << endl;
    return 0;
}