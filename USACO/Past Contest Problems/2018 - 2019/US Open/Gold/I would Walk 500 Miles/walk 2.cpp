#include <bits/stdc++.h>
using namespace std;
#define MOD 2019201997
#define INF LLONG_MAX

int n,k;
typedef long long ll;
ll cost(ll a, ll b)
{
    return (-48 * b - 84 * a) + MOD;
}

ll ans = INF;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream cin("walk.in");
    ofstream cout("walk.out");

    cin >> n >> k;
    cout << cost(k - 1,n) << endl;
}