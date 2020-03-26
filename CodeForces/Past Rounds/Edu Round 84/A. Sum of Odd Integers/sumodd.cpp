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


int main()
{
    setIO();
    long long t,n,k; cin >> t;
    while(t--)
    {
        cin >> n >> k;
        cout << (n % 2 == k % 2 && k * k <= n ? "YES" : "NO") << endl;
    }

    return 0;
}
