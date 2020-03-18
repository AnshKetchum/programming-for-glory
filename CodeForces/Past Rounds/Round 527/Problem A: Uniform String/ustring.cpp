//https://codeforces.com/contest/1092/problem/A
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

int t;
int main()
{
	setIO();
	cin >> t;
	while(t--)
	{
		int n,k,freq; cin >> n >> k;
		freq = n / k;
		string s = "";

		int cnt = 0;
		char c = 'a';
		for(int i = 0; i < n; i++)
		{
			s.push_back(c);
			cnt++;

			if(cnt % freq == 0 && c - 'a' + 1 < k)
				c++;
		}

		cout << s << endl;
	}

    return 0;
}