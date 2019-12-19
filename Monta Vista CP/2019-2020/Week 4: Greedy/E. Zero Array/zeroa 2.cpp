#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,sum,mx;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        ll a; cin >> a; sum += a;
        mx = max(mx,a);
    }

    if(mx <= sum - mx && sum % 2 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0; 
}