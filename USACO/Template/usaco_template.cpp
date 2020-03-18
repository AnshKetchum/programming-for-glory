#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define LL_INF 1e14
#define INT_INF 1e9
#define sz(x) int(x.size())
#define IMPOSSIBLE -1
#define push_back pb
#define all(x) (x).begin(), (x).end()
#define MOD 1e9 + 7
#define FASTIO 	ios_base::sync_with_stdio(nullptr); cin.tie(nullptr); cout.tie(nullptr);

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

struct Edge
{
    ll to,cost;
};

struct ModdedInteger //TAKEN FROM THE LEGEND BENQ This structure wasn't created by me
{
	T val; 
	ModdedInteger() 
	{ 
		val = 0; 
	}
	ModdedInteger(const ll& v) 
	{ 
		val = (-MOD <= v && v <= MOD) ? v : v % MOD;
		if (val < 0) val += MOD;
	}
	ModdedInteger& operator+=(const ModdedInteger& m) 
	{ 
		if ((val += m.val) >= MOD) val -= MOD; 
		return *this; 
	}
	ModdedInteger& operator-=(const ModdedInteger& m)
	 { 
		if ((val -= m.val) < 0) val += MOD; 
		return *this; 
	}
}

void setIO(string name) //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	ios_base::sync_with_stdio(nullptr); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}


int main()
{

    return 0;
}