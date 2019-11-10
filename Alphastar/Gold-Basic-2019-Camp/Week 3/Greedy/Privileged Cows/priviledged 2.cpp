#include <bits/stdc++.h>
using namespace std;
#define MAX_DISTINCT_NUMBERS 3
#define MAXN 1005

int sorts[MAX_DISTINCT_NUMBERS][MAX_DISTINCT_NUMBERS],n,sorted[MAXN],unsorted[MAXN],ans,v;
void minimize(int i, int j)
{
    int same = min(sorts[i][j],sorts[j][i]);
    sorts[i][j] -= same;
    sorts[j][i] -= same;
    ans += same;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> unsorted[i];
        sorted[i] = unsorted[i];
    }

    sort(sorted, sorted + n);
    for(int i = 0; i < n; i++)
        if(sorted[i] != unsorted[i])
            sorts[unsorted[i] - 1][sorted[i] - 1]++;

    minimize(0,2);
    minimize(1,2);
    minimize(0,1);

    bool exit = false;
    for(int i = 0; i < 3 && !exit; i++)
        for(int j = 0; j < 3 && !exit; j++)
            if(sorts[i][j])
            {
               exit = true;
                v = sorts[i][j];
            }

    cout << ans + 2 * v << endl;
    return 0;
}
