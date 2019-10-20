#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string str;
ll wcount,combinations,ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> str;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == 'o')//Case O
            combinations += wcount;
        else if(str[i - 1] == 'v' && i > 0) //Case V
        {
            ++wcount;
            ans += combinations;
        }
    }

    cout << ans << endl;
    return 0;
}