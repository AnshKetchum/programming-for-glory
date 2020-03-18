#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
using namespace std;
typedef pair<int,int> pii;
#define MAXN 1500

void setIO() //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
}

pii a[MAXN];
int n,ans;
int main()
{
	setIO();
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a, a + n, greater<pii>());

    for(int i = 0; i < n; i++)
        ans += (i * a[i].first + 1);
    cout << ans << endl;
    for(int i = 0; i < n; i++)
        cout << a[i].second << " ";
    cout << endl;
    return 0;
}