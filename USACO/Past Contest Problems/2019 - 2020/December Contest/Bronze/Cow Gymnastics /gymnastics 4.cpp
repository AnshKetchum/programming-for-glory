#include <bits/stdc++.h>
using namespace std;
#define MAXN 150


int k,n,rankings[MAXN][MAXN],ans;
bool consistent(int i, int j)
{
    for(int a = 0; a < k; a++)
    {
        bool seeni = false;
        for(int b = 0; b < n; b++)
        {
            if(rankings[a][b] == i)
                seeni  = true;
            else if(rankings[a][b] == j && !seeni)
                return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream cin("gymnastics.in");
    cin >> k >> n;

    for(int i = 0; i < k; i++)
        for(int j = 0; j < n; j++)
            cin >> rankings[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i != j && consistent(i,j))
                ans++;
    
    ofstream cout("gymnastics.out");
    cout << ans << endl;
    return 0;
}