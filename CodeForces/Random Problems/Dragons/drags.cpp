#include <bits/stdc++.h>
using namespace std;
#define MAXN 1200
typedef pair<int,int> pii;
int s, n;
pii drags [MAXN];

bool cmp(pii a, pii b)
{
    if(a.first != b.first)
        return a.first < b.first;
    return a.second > b.second;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> s >> n;
    for(int i = 0; i < n; i++)
        cin >> drags[i].first >> drags[i].second;
    sort(drags, drags + n, cmp);

    bool fail = false;
    for(int i = 0; i < n && !fail; i++)
    {
        if(!(s > drags[i].first))
            fail = true;
        s += drags[i].second;
    }
    cout << (fail ? "NO" : "YES") << endl;
    return 0;
}