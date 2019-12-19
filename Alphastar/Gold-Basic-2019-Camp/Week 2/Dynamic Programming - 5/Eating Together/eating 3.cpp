#include <bits/stdc++.h>
using namespace std;
#define MAXN 350000
#define INF 100000000

int dpAscending[MAXN][4],dpDescending[MAXN][4],cow[MAXN],n,ans = INF;

int getMin(int arrs [MAXN][4],int ind)
{
    return min(min(arrs[ind][1],arrs[ind][2]), arrs[ind][3]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> cow[i];

    if(cow[0] == 1)
    {
        dpAscending[0][1] = 0;
        dpAscending[0][2] = dpAscending[0][3] = 1;
    }

    if(cow[0] == 2)
    {
        dpAscending[0][2] = 0;
        dpAscending[0][1] = dpAscending[0][3] = 1;
    }

    if(cow[0] == 3)
    {
        dpAscending[0][3] = 0;
        dpAscending[0][1] = dpAscending[0][2] = 1;
    }


    for(int i = 1; i < n; i++)        //Ascending Order
    {
        dpAscending[i][1] = dpAscending[i - 1][1] + ((cow[i] != 1) ? 1 : 0);
        dpAscending[i][2] = min(dpAscending[i - 1][1],dpAscending[i - 1][2]) + ((cow[i] != 2) ? 1 : 0);
        dpAscending[i][3] = min(min(dpAscending[i - 1][1], dpAscending[i - 1][2]) , dpAscending[i - 1][3]) + ((cow[i] != 3) ? 1 : 0);
    }

    if(cow[n - 1] == 1)
    {
        dpDescending[n - 1][1] = 0;
        dpDescending[n - 1][2] = dpDescending[n - 1][3] = 1;
    }

    if(cow[n - 1] == 2)
    {
        dpDescending[n - 1][2] = 0;
        dpDescending[n - 1][1] = dpDescending[n - 1][3] = 1;
    }

    if(cow[n - 1] == 3)
    {
        dpDescending[n - 1][3] = 0;
        dpDescending[n - 1][1] = dpDescending[n - 1][2] = 1;
    }

    for(int i = n - 2; i >= 0; i--)        //Descending Order
    {
        dpDescending[i][1] = dpDescending[i + 1][1] + ((cow[i] != 1) ? 1 : 0);
        dpDescending[i][2] = min(dpDescending[i + 1][1] , dpDescending[i + 1][2]) + ((cow[i] != 2) ? 1 : 0);
        dpDescending[i][3] = min(min(dpDescending[i + 1][1] , dpDescending[i + 1][2]) , dpDescending[i + 1][3]) + ((cow[i] != 3) ? 1 : 0);
    }

    ans = min(getMin(dpDescending,0),getMin(dpAscending, n - 1));
    cout << ans << endl;
    return 0;
}
