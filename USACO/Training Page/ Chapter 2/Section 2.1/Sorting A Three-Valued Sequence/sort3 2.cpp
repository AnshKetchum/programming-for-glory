/*****
ID: INSERT_ID_HERE
LANG: C++
PROG: sort3
**/

/*
Logic: This problem is essentially asking us to pair all unsorted integers together in order to find an optimal minimum.
In order to do that, we maintain two arrays - one sorted and one unsorted. From there, we can deduce how many "unsorted" values are there
Finally, we need to pair them - there are n / 2 ways to do this when even
but there are (n / 2) + 1 ways to do this when odd (we undercount due to integer division)
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1005

int n,unsorted[MAX_N],sorted[MAX_N],notSortedCount,twoPairCount;
int main()
{
    ifstream fin ("sort3.in");
    fin >> n;

    for(int i = 0; i < n; i++)
    {
        fin >> unsorted[i];
        sorted[i] = unsorted[i];
    }

    sort(sorted,sorted + n);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(unsorted[i] != sorted[i] && unsorted[j] != sorted[j] && unsorted[i] == sorted[j] && unsorted[j] == sorted[i])
            {
                unsorted[i] = sorted[i];
                unsorted[j] = sorted[j];
                twoPairCount++;
            }

    for(int i = 0; i < n; i++)
        if(unsorted[i] != sorted[i])
            notSortedCount++;
    int ans = twoPairCount + (notSortedCount / 3) * 2;

    ofstream fout("sort3.out");
    fout << ans << endl;
    return 0;
}
