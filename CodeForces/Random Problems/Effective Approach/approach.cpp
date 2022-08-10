#include <bits/stdc++.h>
using namespace std;
#define MAXN 110000
int a[MAXN], b[MAXN], c[MAXN], n, q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[a[i]] = ( (!i || !b[a[i]] ) ? i : b[a[i]] );
        c[a[i]] = max(i, c[a[i]]);
    }

    cin >> q;
    long long a1 = 0, a2 = 0, x; 
    while(q--)
    {
        cin >> x;
        a1 += (b[x] + 1); 
        a2 += (n - c[x]);
    }
    cout << a1 << " " << a2 << endl;
    return 0;
}