#include <bits/stdc++.h>
using namespace std;
#define MAXN 150000
int n, mx, cnt;
vector<int> a[MAXN];
string ret = "";

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for(int i = 1, b; i <= n; i++)
    {
        cin >> b, a[b].push_back(i);
        mx = max(mx, b);
    }

    for(int i = 1; i <= mx; i++)
    {
        if(a[i].size())
        {
            if(a[i].size() == 1)
                ret += "" + to_string(i) + " 0\n", ++cnt; 
            else
            {
                bool flag = false;
                for(int j = 2; j < a[i].size() && !flag; j++)
                    if((a[i][j] - a[i][j - 1]) != (a[i][1] - a[i][0]))
                        flag = true;
                if(!flag) ret += to_string(i) + " " + to_string((a[i][1] - a[i][0])) + "\n", ++cnt;
            }
        }
    }
    cout << cnt << endl;
    cout << ret;
    return 0;
}