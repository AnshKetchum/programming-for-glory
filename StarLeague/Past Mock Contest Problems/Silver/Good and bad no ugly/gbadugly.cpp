#include <bits/stdc++.h>
using namespace std;
#define FASTIO 	ios_base::sync_with_stdio(nullptr); cin.tie(nullptr); cout.tie(nullptr);

typedef long long ll;
const ll MOD = 1e9 + 7;

ll factorial(ll n)
{
    ll ret = 1;
    for(ll i = 2; i <= n; i++)
    {
        ret *= i;
    }
    return ret;
}


ll n,ans,sub,denom = 1; 
string str;
map <char,ll> cnts;

int main()
{
    FASTIO cin >> n >> str;
    for(unsigned i = 0; i < str.length(); i++)
        cnts[str[i]]++;

    ans = factorial(n);
    cout << ans << endl;
    for(auto &v : cnts)
        denom *= factorial(v.second);

    ans /= denom;    
    cout << sub << " " << ans << endl;
    cout << (ans - sub) << endl;
    return 0;
}