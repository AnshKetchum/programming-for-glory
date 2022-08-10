#include <bits/stdc++.h>
using namespace std;
int n, mx;
string str;
map <char, int> cnt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> str;
    for(int i = 0; i < str.length(); i++)
        cnt[str[i]]++, mx = max(mx, cnt[str[i]]);
    

    bool works = false;
    for(int i = mx; i > 1; i--)
    {
        works = true;
        for(pair<char, int> x : cnt)
            if(x.second % i != 0)
            {
                works = false;
                break;
            }
        if(works)
        {
            string s = "";
            for(pair<char, int> x : cnt)
                for(int j = 0; j < (x.second / i); j++)
                    s += x.first;
            for(int j = 0; j < i; j++)
                cout << s;
            cout << endl;
            break;
        }
    }

    if(mx == 1)
    {
        for(pair<char, int> x : cnt)
            cout << x.first;
        cout << endl;
        works = true;
    }


    if(!works) cout << -1 << endl;
    return 0;
}