#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
#define MAXM 150

int n,m,x,ans = INF;
string input;
vector <int> choose;

int count_pal(string pal)
{
    int ret = 0;
    for(int i = 0; i < pal.length() / 2; i++)
        if(pal[pal.length() - i - 1] != input[i])
            ret++;
    return ret;    
}

void solve(int ind, int cnt)
{

    if(cnt == m - 1)
    {
        int cur = 0,sum = 0;
        for(int i = 0; i < choose.size(); i++)
        {
            sum += count_pal(input.substr(cur,choose[i] - cur));
            cur = choose[i];
        }

        sum += count_pal(input.substr(choose[choose.size() - 1],input.length() - choose[choose.size() - 1]));
        ans = min(ans,sum);
        return;
    }

    if(ind >= input.length())
        return;

    choose.push_back(ind);
    solve(ind + 1, cnt + 1);
    choose.pop_back();

    solve(ind + 1, cnt);
}  

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m >> x >> input;
    
    solve(0,0);
    
    if(ans > x)
        cout << "NO" << endl;
    else
        cout << "YES\n" << ans << endl;  
    
    
    return 0;
}