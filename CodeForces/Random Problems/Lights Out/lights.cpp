#include <bits/stdc++.h>
using namespace std;
#define MAXN 3


int lights [MAXN][MAXN];
int dx [] = {0, 0, 1, -1, 0}; //Mistake: I forgot to consider 0,0
int dy [] = {0, 1, 0, 0, -1};

void update(int t, int i, int j)
{
    if(!t) return;
    for(int k = 0; k < 5; k++)
        if(i + dx[k] >= 0 && i + dx[k] < 3 && j + dy[k] >= 0 && j + dy[k] < 3)
            lights[i + dx[k]][j + dy[k]] = 1 - lights[i + dx[k]][j + dy[k]]; 
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for(int i = 0; i < 3; i++)
        for(int j = 0, k; j < 3; j++)
            cin >> k, update(k % 2, i , j);

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
            cout << (1 - lights[i][j]);
        cout << endl;
    }
    return 0;
}