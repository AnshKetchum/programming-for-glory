#include <bits/stdc++.h>
using namespace std;
#define MAX_COWS 15000

typedef pair<int,int> pii;
set<pii> uniqueV;
int n,i,h,r, height[MAX_COWS];
int main()
{
    ios_base::sync_with_stdio(false); //Fast IO
    cin.tie(0);

    cin >> n >> i >> h >> r;

    for(int i = 0; i < n; i++)
        height[i] = h;

    for(int i = 0; i < r; i++)
    {
        int l = -1,r = -1;
        cin >> l >> r;
        l--;
        r--;
        if(r < l)
            swap(l,r);
        uniqueV.insert(pii(l,r));
    }

    for(pii range : uniqueV)
        for(int j = range.first + 1; j < range.second; j++)
            height[j]--;

    for(int i = 0; i < n; i++)
        cout << height[i] << endl;

    return 0;
}
