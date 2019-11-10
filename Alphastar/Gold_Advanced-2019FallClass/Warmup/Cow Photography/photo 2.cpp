#include <bits/stdc++.h>
using namespace std;
#define MAXN 20005

int n,ans [MAXN], v[5][MAXN];
unordered_map <int,int> pos [MAXN]; 

bool comp(int a, int b)
{
    int cnt = 0;
    for(int i = 0; i < 5; i++)
       if(pos[i][a] < pos[i][b]) 
        cnt++;
    return cnt >= 3;
}


int main()
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < n; j++)
        {
            cin >> v[i][j];
            pos[i][v[i][j]] = j;
        }
    sort(v[0], v[0] + n, comp);

    for(int i = 0; i < n; i++)
        cout << v[0][i] << endl;
    return 0;
}