#include <bits/stdc++.h>
using namespace std;
#define MAXN 500

typedef pair<int,int> pii;
int n,unsorted[MAXN];
pii vals[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> vals[i].first;
        vals[i].second = i;
        unsorted[i] = vals[i].first;
    }
    sort(vals,vals + n);

    bool exit = false;

    while(!exit)
    {
        exit = true;
        pii range;        

        if(!exit)
            cout << range.first << " " << range.second << endl;
    }

    return 0;
}