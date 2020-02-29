#include <bits/stdc++.h>
using namespace std;

void setIO() //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
}

int n;
string inp;

int solve()
{
    int ret = 0,extra = 0;
    bool seen1 = false;
    for(int i = inp.length() - 1; i >= 0; i--)
    {
        seen1 = (seen1 || inp[i] == '1');
        if(seen1 && inp[i] == '0')
        {
            ret++;
            extra++;
        }
        else
            extra = 0;
    }

    return (ret - extra);
}

int main()
{
    setIO();
    cin >> n;
    while(n--)
    {
        cin >> inp;
        cout << solve() << endl;
    }
    return 0;
}