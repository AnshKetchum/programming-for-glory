#include <bits/stdc++.h>
using namespace std;
#define MAX_ROOMS 60

struct Room
{
    bool hasWall[4]; //West, North, East, South indexed
};

struct Wall
{
    char pos;
    int x,y;
};

int n,m,tempArea,rreference[MAX_ROOMS][MAX_ROOMS],key,highestRegion,highestWithTwoRegions,totalRegions;
Room rooms[MAX_ROOMS][MAX_ROOMS];
vector <int> regionSizes;
pair <int,int> lowestCoord;
char wallPlacement;

bool visited[MAX_ROOMS][MAX_ROOMS];

int dx [] = {0,-1,0,1};
int dy [] = {-1,0,1,0};
void flood(int r,int c)
{
    if(r < 0 || c < 0 || r >= n || c >= m || visited[r][c])
        return;

    visited[r][c] = true;
    rreference[r][c] = key;
    tempArea++;

    for(int k = 0; k < 4; k++)
    {
        int n_x = dx[k] + r, n_y = dy[k] + c;
        if(!rooms[r][c].hasWall[k])
            flood(n_x,n_y);
    }
}

int main()
{
    cin >> m >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int wallsInBits = 0; cin >> wallsInBits;
            int powerOf2 = 1;
            for(int a = 0; a < 4; a++)
            {
                if(wallsInBits & powerOf2)
                    rooms[i][j].hasWall[a] = true;
                powerOf2 *= 2;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!visited[i][j])
            {
                tempArea = 0;
                key = regionSizes.size();
                flood(i,j);
                regionSizes.push_back(tempArea);
                highestRegion = max(tempArea,highestRegion);
            }
        }
    }

    totalRegions = regionSizes.size();
    for(int j = 0; j < m; j++)
    {
        for(int i = n - 1; i >= 0; i--)
        {
            int totalArea = 0;
            if(i > 0 && rooms[i][j].hasWall[1] && rreference[i][j] != rreference[i - 1][j]) //Check all Distinct North rooms
            {
                totalArea = regionSizes[rreference[i][j]] + regionSizes[rreference[i - 1][j]];
                if(totalArea > highestWithTwoRegions)
                {
                    highestWithTwoRegions = totalArea;
                    lowestCoord.first = i;
                    lowestCoord.second = j;
                    wallPlacement = 'N';
                }
            }
            if(j < m - 1 && rooms[i][j].hasWall[2] && rreference[i][j] != rreference[i][j + 1])//All distinct East
            {
                totalArea = regionSizes[rreference[i][j]] + regionSizes[rreference[i][j + 1]];
                if(totalArea > highestWithTwoRegions)
                {
                    highestWithTwoRegions = totalArea;
                    lowestCoord.first = i;
                    lowestCoord.second = j;
                    wallPlacement = 'E';
                }
            }
        }
    }

    if(highestWithTwoRegions == 0)
        highestWithTwoRegions = regionSizes[0];

    cout << totalRegions << endl;
    cout << highestRegion << endl;
    cout << highestWithTwoRegions << endl;

    return 0;
}
