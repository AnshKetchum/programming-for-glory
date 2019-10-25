#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define MAX_GRID 55

typedef pair <int,int> pii;
pii start,finish;
int grid[MAX_GRID][MAX_GRID],ans = 1000000000,n;
bool visited[MAX_GRID][MAX_GRID];
int changeX [] = {0,0,1,-1};
int changeY [] = {-1,1,0,0};
vector <pii> possibleFirsts,possibleLasts;

int getCost(pii first,pii second)
{
    return (first.X - second.X) * (first.X - second.X) + (first.Y - second.Y) * (first.Y - second.Y);
}

void visit(int r, int c, vector <pii>& vec)
{
    visited[r][c] = true; //Setting to visited
    vec.push_back(make_pair(r,c));
    for(int i = 0; i < 4; i++)
    {
        int dx = r + changeX[i], dy = c + changeY[i];
        if(dx < 1 || dy < 1 || dx > n || dy > n || visited[dx][dy] || grid[dx][dy]) //Boundary and visited check
            continue;
        visit(dx,dy,vec);
    }
}

int main()
{

    cin >> n >> start.X >> start.Y >> finish.X >> finish.Y;
    for(int i = 1; i <= n; i++)
     {
         string str; cin >> str;
         for(int j = 1; j <= n; j++)
            grid[i][j] = str[j - 1] - '0';
     }

    visit(start.X,start.Y,possibleFirsts);
    visit(finish.X,finish.Y,possibleLasts);

    for(int i = 0; i < possibleFirsts.size(); i++)
        for(int j = 0; j < possibleLasts.size(); j++)
            ans = min(ans,getCost(possibleFirsts[i],possibleLasts[j]));

    cout << ans << endl;
    return 0;
}