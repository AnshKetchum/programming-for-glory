#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define MAXN 150000
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void setIO() //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
}

int t,k; 
ll dp[MAXN],sum[MAXN];
int main()
{
    setIO();
    cin >> t >> k;

    for()
    {

    }


    for(int i = 1; i < MAXN; i++)
        sum[i] = sum[i - 1] + dp[i];

    for(int i = 0; i < t; i++)
    {
        int a,b; cin >> a >> b;
        cout << (sum[b] - sum[a - 1]) << endl;
    }

    return 0;
}