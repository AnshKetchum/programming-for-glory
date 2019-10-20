/*****
ID: INSERT_ID_HERE
LANG: C++
PROG: comehome
**/
#include <bits/stdc++.h>
using namespace std;
#define MAXC 52
#define INF 1000000000


int connection[MAXC][MAXC],p;
int getInd(char c) //Returns an index
{
    if(c - 'a' >= 0)
        return (c - 'a' + 26);
    else return c - 'A';
}

char unInd(int i) //Reverts the original 'getInd()' function
{
    if(i < 26 && i >= 0)
        return i + 'A';
    else return (i - 26) + 'a';
}

void floyd_warshall()
{
    for(int k = 0; k < MAXC; k++)
        for(int i = 0; i < MAXC; i++)
            for(int j = 0; j < MAXC; j++)
                 connection[i][j] = min(connection[i][j], connection[i][k] + connection[k][j]);
}

int main()
{
    ifstream cin("comehome.in");
    ofstream cout("comehome.out");
    
    cin >> p;

    for(int i = 0; i < MAXC; i++)
        for(int j = 0; j < MAXC; j++)
        {
            if(i == j) continue;
            connection[i][j] = INF;
        }

    for(int i = 0; i < p; i++)
    {
        char from,to; int dist;
        cin >> from >> to >> dist;

        int a = getInd(from); int b = getInd(to);

        connection[a][b] = min(dist,connection[a][b]);
        connection[b][a] = connection[a][b];
    }

    floyd_warshall();

    pair<char,int> ans;
    ans.first = '#';
    ans.second = INF;

    int f = getInd('Z');
    for(int i = 0; i < 25; i++)
        if(connection[f][i] < ans.second)
        {
            ans.second = connection[f][i];
            ans.first  = unInd(i);
        }

    cout << ans.first << " " << ans.second << "\n";
    return 0;
}
