#include <bits/stdc++.h>
using namespace std;
#define STOP_VAL 150000

int n,cnt;

bool is_prime(int v)
{
    if(v == 1)
        return false;

    for(int i = 2; i <= sqrt(v); i++)
        if(v % i == 0)
            return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i < STOP_VAL && cnt != n; i++)
    {
        if(is_prime(i))
            cnt++;
        if(cnt == n)
            cout << i << endl;
    }

    return 0;
}