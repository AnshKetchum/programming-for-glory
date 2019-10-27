#include <bits/stdc++.h>
using namespace std;
#define MAXN 150000
#define INF 1000000000

int n,m,money[MAXN];
bool pos(int money_value)
{
    int group_count = 1,sum = 0;

    for(int i = 0; i < n; i++)
    {
        if(sum + money[i] <= money_value)
            sum += money[i];
        else if(money[i] > money_value)
            return false;
        else
        {
            sum = money[i];
            group_count++;
        }
        
    }

    return group_count <= m;
}

int binary_search(int l, int r)
{
    if(l == r)
        return l;
    int mid = (l + r) / 2;

    if(pos(mid))
        return binary_search(l,mid);
    return binary_search(mid + 1, r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> money[i];

    cout << binary_search(0,INF) << endl;
    return 0;
}
