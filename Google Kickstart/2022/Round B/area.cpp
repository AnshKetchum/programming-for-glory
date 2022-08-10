#include <bits/stdc++.h>
using namespace std;
long long r, a, b;


double solve()
{
    cin >> r >> a >> b;

    long long sumr = 0;
    while(r)
    {
        sumr += ((r * r) + ( (r * a) * (r * a)));
        r = (r * a ) / b;
    }

    return M_PI * sumr;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin >> t;
    for(int i = 1; i <= t; i++) 
        cout << "Case #" << setprecision(10) << i << ": " << solve() << endl;
    return 0;
}