#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
using namespace std;

void setIO() //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
}

string s;
int solve(int ind)
{
    s = "1";
    for(int i = 1; ind - (int)(s.length()) >= 0; i++,s += to_string(i))
        if(ind - (int)(s.length()) >= 0)
            ind -= s.length();
    return (int)(s[ind] - '0');
}

int main()
{
	setIO();
    int q; cin >> q;

    while(q--)
    {
        int a; cin >> a;
        cout << solve(a - 1) << endl;
    }
    return 0;
}