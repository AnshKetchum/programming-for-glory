#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define MAX_ID 1200000
#define MAXN 55000
using namespace std;

void setIO(string name) 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}


int n,a[MAXN][5],ans;
set <int> ids [MAX_ID];

int get_pairs(int x)
{
    return (x * (x - 1)) / 2;
}

int main()
{
    setIO("cowpatibility");
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 5; j++)
        {
            cin >> a[i][j];
            ids[a[i][j]].insert(i);
        }
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 5; j++)
        {
            ans += 
        }

    cout << (get_pairs(n) - ans) << endl;
    return 0;
}
