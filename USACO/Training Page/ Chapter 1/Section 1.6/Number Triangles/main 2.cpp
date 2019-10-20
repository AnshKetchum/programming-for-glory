/*****
ID: INSERT_ID_HERE
LANG: C++
PROG: numtri
**/
#include <bits/stdc++.h>
using namespace std;
#define MAX_NUMBERS 1001

int numbers [MAX_NUMBERS][MAX_NUMBERS],n,ans, highestValue[MAX_NUMBERS][MAX_NUMBERS];

int main()
{
    ifstream fin ("numtri.in");
    fin >> n;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            fin >> numbers[i][j];
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            highestValue[i][j] = max(highestValue[i - 1][j],highestValue[i - 1][j - 1]) + numbers[i][j];
        }
    }


    for(int i = 1; i <= n; i++)
        ans = max(ans,highestValue[n][i]);

    ofstream fout ("numtri.out");
    fout << ans << endl;
    cout << ans << endl;
    return 0;
}
