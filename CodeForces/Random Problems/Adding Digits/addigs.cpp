#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, n; 
string str;
bool fail;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> a >> b >> n;

    str = to_string(a);

    for(int i = 0; i < n; i++)
    {
        a %= b;
        fail = true;
        for(int j = 0; j < 10; j++)
            if((a * 10 + j) % b == 0)
            {
                a = (a * 10 + j) % b;
                str += (char)(j + '0');
                fail = false;
                break;
            }
    }

    cout << (fail ? "-1" : str) << endl;
    return 0;
}

