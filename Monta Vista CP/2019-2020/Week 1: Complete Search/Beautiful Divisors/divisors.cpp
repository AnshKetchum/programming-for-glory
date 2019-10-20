#include <bits/stdc++.h>
using namespace std;

int n,ans,k = 0;

int generate_number(int k)
{
    int a = 0;
    for(int i = k - 1; i < 2 * k - 1; i++)
        a += ceil(pow(2,i));
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    int i = 1;
    while(k <= n)
    {
        k = generate_number(i);
        if(n % k == 0)
            ans = k;
        i++;
    }

    cout << ans << endl;
    return 0;
}