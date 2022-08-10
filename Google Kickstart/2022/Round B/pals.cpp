#include <bits/stdc++.h>
using namespace std;
#define MAXN 200000
typedef long long ll;
ll n, ans;

bool ispal(ll num)
{
    ll n = num;
    ll rev = 0;
    while (num > 0)
    {
        ll dig = num % 10;
        rev = rev * 10 + dig;
        num = num / 10;
    }
    return (n == rev);
}


ll solve()
{
    cin >> n;
    set<int> ans;

    for(ll i = 1; i * i <= n; i++)
        if(n % i == 0)
        {
            if(ispal(i)) ans.insert(i);
            if(ispal(n / i)) ans.insert(n / i);
        }
    return ans.size();
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin >> t;
    for(int i = 1; i <= t; i++)
        cout << "Case #" << i << ": " << solve() << endl;

}