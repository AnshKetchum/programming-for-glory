#include <bits/stdc++.h>
using namespace std;
#define LL_INF 1e14
#define INT_INF 1e9
#define sz(x) int(x.size())
#define IMPOSSIBLE -1
#define push_back pb
#define all(x) (x).begin(), (x).end()
#define MOD 1e9 + 7
#define FASTIO 	ios_base::sync_with_stdio(nullptr); cin.tie(nullptr); cout.tie(nullptr);
#define MAXN 15000

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;



int n,k,pref[MAXN],ret;
int main()
{
    FASTIO
    cin >> n >> k;

    for(int i = 1; i <= n; i++)
    {
        int a; cin >> a; 
        pref[i] = pref[i - 1] + a;
    }

    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
            if(pref[j + 1] - pref[i] >= k)
                ret++;
    cout << ret << endl;
    return 0;
}