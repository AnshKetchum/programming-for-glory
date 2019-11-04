#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
string inp;

ll get_best(int l, int r)
{
    ll local_max = 0,cnt = 0;
    for(int i = l; i < r; i++)
    {
        ll num = 0;
        bool t = false;
        while(inp[i] >= '0'  && inp[i] <= '9')
        {
            num = 10 * num + (inp[i] - '0');
            i++;
            t = true;
        }
        if(t)
            cnt++;
        if(cnt > 1)
            local_max = max(local_max,num);
    }
    return local_max;
}

int get_end()
{
    int i,cnt = 0,ct = 0;
    for(i = 0; i < inp.length() && cnt < 2; i++)
    {   
        if(inp[i] == '(')
        {
            ct++;
            if(ct == 1)
                cnt++;
        }
        else if(inp[i] == ')')
        {
            ct--;
            if(ct == 1)
                cnt++;
        }
    }

    return i;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    char c;
    while(cin >> c)
        inp += c;

    int ending = get_end();
    cout << get_best(0, ending) + get_best(ending, inp.length()) << endl;
    return 0;
}