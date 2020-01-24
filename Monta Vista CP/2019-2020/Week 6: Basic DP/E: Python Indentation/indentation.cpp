#include <bits/stdc++.h>
using namespace std;
#define LL_INF 1e14
#define INT_INF 1e9
#define sz(x) int(x.size())
#define IMPOSSIBLE -1
#define all(x) (x).begin(), (x).end()
#define MOD (long long)(1e9 + 7)
#define FASTIO 	ios_base::sync_with_stdio(0); cin.tie(0);


typedef long long ll;
ll n,ans = 1,depth = 0;
string str;

int main()
{
    FASTIO
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        char s; cin >> s;
        str.push_back(s);
    }

    for(int i = 0; i < n; i++)
    {
        if(str[i] == 'f')
            depth++;
        if(i && str[i - 1] == 's')
        {
            ans *= depth;
            ans %= MOD;
        }
    }

    cout << ans << endl;
    return 0;
}