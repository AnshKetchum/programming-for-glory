/*****
ID: INSERT_ID_HERE
LANG: C++
PROG: concom
**/
#include <bits/stdc++.h>
using namespace std;
#define MAX_COMPANIES 105

int n,connections[MAX_COMPANIES][MAX_COMPANIES],controls[MAX_COMPANIES][MAX_COMPANIES];
typedef pair<int,int> pii;
bool used[MAX_COMPANIES][MAX_COMPANIES];
vector <int> companies;
vector <pii> ans;

void floyd_warshall()
{
    bool exitFloyd = false;
    while(!exitFloyd)
    {
        exitFloyd = true;
        for(int i = 1; i < MAX_COMPANIES; i++)
            for(int j = 1; j < MAX_COMPANIES; j++)
                if(connections[i][j] > 50 && !used[i][j])
                {
                    used[i][j] = true;
                    for(int k = 1; k <= MAX_COMPANIES; k++)
                        if(controls[j][k])
                        {
                            connections[i][k] += controls[j][k];
                            exitFloyd = false;
                        }
                }
    }
}

int main()
{
    ifstream cin("concom.in");
    ofstream cout("concom.out");

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a,b,c; cin >> a >> b >> c;
        connections[a][b] = controls[a][b] = c;
    }

    floyd_warshall();

    for(int i = 1; i < MAX_COMPANIES; i++)
        for(int j = 1; j < MAX_COMPANIES; j++)
            if(connections[i][j] > 50 && i != j)
                ans.push_back(pii(i,j));

    sort(ans.begin(),ans.end());

    for(pii a : ans)
        cout << a.first << " " << a.second << endl;
    return 0;
}
