//https://codeforces.com/group/bO58xxnmVp/contest/254442/problem/D
#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define MAX_TIMES 450000
using namespace std;

void setIO() //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
}


int n,k,q,temperatures[MAX_TIMES],pref[MAX_TIMES];
int main()
{
	setIO();
	cin >> n >> k >> q;
	for(int i = 0; i < n; i++)
	{
		int l,r; cin >> l >> r;
		temperatures[l]++; temperatures[r + 1]--;
	}

	for(int i = 1; i < MAX_TIMES; i++)
	{
		temperatures[i] += temperatures[i - 1];
		pref[i] += pref[i - 1] + (temperatures[i] >= k);
	}
	
	while(q--)
	
	{
		int a,b; cin >> a >> b;
		cout << (pref[b] - pref[a - 1]) << endl;
	}
	
    return 0;
}