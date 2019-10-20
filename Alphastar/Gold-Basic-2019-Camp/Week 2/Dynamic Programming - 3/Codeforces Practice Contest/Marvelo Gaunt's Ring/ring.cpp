#include <bits/stdc++.h>
using namespace std;
#define int long long
#define NEGINF LLONG_MIN

int a = NEGINF,b = NEGINF,c = NEGINF,n,p,q,r;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> p >> q >> r;
    for(int i = 0; i < n; i++)
    {
        int d; cin >> d;
        a = max(a,p * d);
        b = max(b,a + q * d);
        c = max(c,b + r * d);
    }
    cout << c << endl;
}
