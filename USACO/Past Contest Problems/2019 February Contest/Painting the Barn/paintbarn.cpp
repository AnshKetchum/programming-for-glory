#include <bits/stdc++.h>
using namespace std;
#define GRID_BOUNDS 250
#define MAXN 150000

struct Rectangle
{
    int x1,x2,y1,y2;
};

int grid[GRID_BOUNDS][GRID_BOUNDS],n;
priority_queue <int> best_two_area;
Rectangle rectangles [MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> rectangles[i].x1 >> rectangles[i].y1 >> rectangles[i].x2 >> rectangles[i].y2;
        for(int r = rectangles[i].x2; r >= rectangles[i].x1; r--)
        {
            grid[r][rectangles[i].y1]++;
            grid[r][rectangles[i].y2 + 1]--;
        }
    }

    

    return 0;
}