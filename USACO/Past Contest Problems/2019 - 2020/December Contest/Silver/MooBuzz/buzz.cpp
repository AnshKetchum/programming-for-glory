#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n;

ll pos(ll val)
{
    ll n5 = val / 5;
    ll n3 = val / 3;
    ll n15 = val / 15;
    return val - (n5 + n3 - n15);
}

int bin_search(ll l, ll r)
{
    if(l == r)
        return l;

    ll mid = (l + r) >> 1;

    if(mid % 3 == 0 || mid % 5 == 0)
        mid--;

    ll c = pos(mid);

    if(c == n)
        return mid;
        
    if(c > n)
        return bin_search(l, mid);
    return bin_search(mid + 1, r);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream cin("moobuzz.in");
    cin >> n;

    ofstream cout("moobuzz.out");
    ll ret = bin_search(0,1e10);
    while(ret % 5 == 0 || ret % 3 == 0) ret--;
    cout << ret << endl;
    return 0;
}