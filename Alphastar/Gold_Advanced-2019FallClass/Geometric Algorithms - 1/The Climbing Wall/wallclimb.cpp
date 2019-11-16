#include <bits/stdc++.h>
using namespace std;
#define MAXF 15000
#define COMPRESSED_AREA 35

typedef pair<int,int> pii;
int h,f;
vector <pii> compressed_coords [COMPRESSED_AREA][COMPRESSED_AREA];
bool visited[COMPRESSED_AREA][COMPRESSED_AREA];
int dx [] = {-1,1,0,0};
int dy [] = {0,0,-1,1};

struct State
{
    int x,y,step;

    State(int x,int y, int step)
    {
        this->x = x;
        this->y = y;
        this->step = step;
    }
};

void bfs()
{
    queue <pii> enque;

    for(int i = 0; i < COMPRESSED_AREA; i++)
        for(int j = 0; j < 2; j++)
            if(!compressed_coords[i][j].empty())
                for(pii x : compressed_coords[i][j])
                    if(x.second <= 1000)    
                        enque.push(State(x.first,x.second,0));

    while(!enque.empty())
    {
        pii top = enque.front();
        enque.pop();

        if(visited[top.x][top.y])
            continue;
        visited[top.x][top.y] = true;

        for(int k = 0; k < 4; k++)
        {
            int n_x = top.first + 
        }

    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> f;
    for(int i = 0; i < f; i++)
    {
        int x,y; cin >> x >> y;
        compressed_coords[x / 1000][y / 1000].push_back(pii(x,y));
    }    

    cout << bfs() << endl;
    return 0; 
}