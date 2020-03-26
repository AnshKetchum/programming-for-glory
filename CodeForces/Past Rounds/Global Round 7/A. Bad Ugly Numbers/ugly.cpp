#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
using namespace std;

void setIO() 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
}

int solve(int n)
{
    if(n == 1)
        cout << "-1" << endl;
    else
    {
        for(int i = 1; i <= n - 1; i++)
            cout << "9";
        cout << "8" << endl;
    }
}

int main()
{
    setIO();

    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        solve(n);
    }

    return 0;
}
