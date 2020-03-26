#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define MAXN 25
#define INF MAXN * MAXN * MAXN * MAXN 
using namespace std;

void setIO(string name) 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    //freopen((name+".out").c_str(),"w",stdout);
}


/*
Direction mapping
Up -> 0
Right -> 1
Down -> 2
Left -> 3
*/
int n,ans = INF,grid[MAXN][MAXN],dp[MAXN][MAXN][4][MAXN][MAXN][4];
int dx [] = {0, 1, 0, -1};
int dy [] = {1, 0, -1, 0};

struct State
{
    int x1,y1,x2,y2,o1,o2;
    State(int a, int b, int c, int d , int e, int f)
    {
        x1 = a;
        y1 = b;
        o1 = c;

        x2 = a;
        y2 = b;
        o2 = c;
    }
};

State move_forward(State a)
{
    State ret = a;
    if(!(ret.x1 == n && ret.y1 == n) && ret.x1 - dx[ret.o1] >= 1 && ret.x1 - dx[ret.o1] <= n && ret.y1 - dy[ret.o1] >= 1 && ret.y1 - dy[ret.o1] <= n)
    {
        ret.x1 += dx[ret.o1];
        ret.y1 += dy[ret.o1];
    }
    if(!(ret.x2 == n && ret.y2 == n) && ret.x2 - dx[ret.o2] >= 1 && ret.x2 - dx[ret.o2] <= n && ret.y2 - dy[ret.o2] >= 1 && ret.y2 - dy[ret.y2] <= n)
    {
        ret.x2 += dx[ret.o2];
        ret.y2 += dy[ret.o2];
    }
    return ret;
}

State turn(State a, int dir)
{
    State ret = a;
    
    ret.o1 += dir;
    if(ret.o1 < 0)
        ret.o1 += 4;
    ret.o1 %= 4;

    ret.o2 += dir;
    if(ret.o2 < 0)
        ret.o2 += 4;
    ret.o2 %= 4;

    return ret;
}

void bfs()
{
    queue<State> enque;


    //(x1,y1) = right, (x2, y2) = up
    enque.push(State(1,1,1,1,1,0));
    dp[1][1][1][1][1][0] = 0;
    bool flag = false;

    while(!enque.empty())
    {
        State top = enque.front();
        enque.pop();

        if(!flag)
            flag = true;
        else if(flag && !dp[top.x1][top.y1][top.o1][top.x2][top.y2][top.o2])
            dp[top.x1][top.y1][top.o1][top.x2][top.y2][top.o2] = INF;

        if(top.x1 == n && top.y1 == n && top.x2 == n && top.y2 == n)
            ans = min(ans, dp[top.x1][top.y1][top.o1][top.x2][top.y2][top.o2]);

        //Forward
        State forward = move_forward(top);
        dp[forward.x1][forward.y1][forward.o1][forward.x2][forward.y2][forward.o2] = min(dp[forward.x1][forward.y1][forward.o1][forward.x2][forward.y2][forward.o2], 1 + dp[top.x1][top.y1][top.o1][top.x2][top.y2][top.o2] );

        forward = turn(top, 1);
        dp[forward.x1][forward.y1][forward.o1][forward.x2][forward.y2][forward.o2] = min(dp[forward.x1][forward.y1][forward.o1][forward.x2][forward.y2][forward.o2], 1 + dp[top.x1][top.y1][top.o1][top.x2][top.y2][top.o2] );


        forward = turn(top, -1);
        dp[forward.x1][forward.y1][forward.o1][forward.x2][forward.y2][forward.o2] = min(dp[forward.x1][forward.y1][forward.o1][forward.x2][forward.y2][forward.o2], 1 + dp[top.x1][top.y1][top.o1][top.x2][top.y2][top.o2] );
    }
}

int main()
{
    setIO("cownav");
    cin >> n;

    char c;
    for(int i = n; i > 0; i--)
        for(int j = 1; j <= n; j++)
        {
            cin >> c;
            grid[i][j] = (int)(c == 'H');
        }

    bfs();
    cout << ans << endl;
    return 0;
}
