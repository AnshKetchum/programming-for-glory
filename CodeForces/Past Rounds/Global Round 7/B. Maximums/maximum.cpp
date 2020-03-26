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
    long long n; cin >> n;
    for(long long i = 0, a = 0, b = 0, x = 0; i < n; i++)
    {
        cin >> b;
        if(!i)
        {
            a = b;
            x = a;
        }
        else
        {
            a = b + x;
            x = max(x,a);
        }
        cout << a << " ";
    }
    cout << endl;
    return 0;
}
