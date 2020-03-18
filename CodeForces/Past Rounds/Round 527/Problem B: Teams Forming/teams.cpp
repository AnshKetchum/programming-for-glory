//https://codeforces.com/contest/1092/problem/B
#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define MAXN 150 
using namespace std;

void setIO() //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
}

int n,a[MAXN],ans;
int main()
{
	setIO();
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);

	for(int i = 1; i < n; i += 2)
		ans += (a[i] - a[i - 1]);
	cout << ans << endl;
    return 0;
}