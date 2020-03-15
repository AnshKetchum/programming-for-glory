#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
typedef long long ll;
using namespace std;

void setIO() //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
}


bool works(ll a, ll b, ll n, ll S)
{
    if(S > a * n + b)
        return false;
    return !(S % n > b);
}

int z;
int main()
{
	setIO();
    cin >> z;
    for(int i = 1; i <= z; i++)
    {
        ll a,b,n,s; cin >> a >> b >> n >> s;
        if(works(a,b,n,s))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}