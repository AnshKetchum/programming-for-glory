/*****
ID: INSERT_ID_HERE
LANG: C++
PROG: ttwo
**/
#include <bits/stdc++.h>
using namespace std;
#define MAXN 15
#define ACTUALN 10
#define INF 10000000


typedef pair<int,int> pii;
char grid[MAXN][MAXN];
int ans = INF,fjDir,cowDir;
int dx [] = {-1,0,1,0}; //Directions up, right,down left (Clockwise)
int dy [] = {0,1,0,-1};
pii cowPos,fjPos;

bool outOfBounds(int x, int y)
{
    return x >= ACTUALN || y >= ACTUALN || x < 0 || y < 0 || grid[x][y] == '*';
}

void moveCharacter(pii& position,int& dir)
{
    if(outOfBounds(position.first + dx[dir], position.second + dy[dir]))
    {
        dir++;
        dir %= 4;
    }
    else
    {
        position.first += dx[dir];
        position.second += dy[dir];
    }

}

void simulate() //Simulating the event
{
     //At starting, time = 0
    int time = 0;
    while(time < INF)
    {
        time++;
        moveCharacter(cowPos,cowDir);
        moveCharacter(fjPos,fjDir);

        if(cowPos.first == fjPos.first && cowPos.second == fjPos.second)
        {
            ans = time;
            break;
        }
    }
}

int main()
{
    ifstream cin("ttwo.in");
    ofstream cout("ttwo.out");

    for(int i = 0; i < ACTUALN; i++)
        for(int j = 0; j < ACTUALN; j++)
        {
            cin >> grid[i][j];
            if(grid[i][j] == 'F')
                fjPos = pii(i,j);
            else if(grid[i][j] == 'C')
                cowPos = pii(i,j);
        }

    simulate();
    cout << (ans == INF ? 0 : ans) << endl;
    return 0;
}
