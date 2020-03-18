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

int n,ans;
string s,ns = "";
int main()
{
	setIO();
    cin >> n >> s;

    for(int i = 0; i < n; i += 2)
    {
        ns.push_back(s[i]);
        if(s[i] == s[i + 1])
        {
            ns.push_back((s[i] == 'a' ? 'b' : 'a'));
            ++ans;
        }
        else
            ns.push_back(s[i + 1]);
    }
    
    cout << ans << '\n' << ns << endl;
    return 0;
}