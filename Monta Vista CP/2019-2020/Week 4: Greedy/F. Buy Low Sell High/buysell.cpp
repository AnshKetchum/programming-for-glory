#include <bits/stdc++.h>
using namespace std;
#define MAXN 500000

typedef long long ll;
typedef pair<ll,ll> pii;
priority_queue<pii> sell_points;
pii sorted [MAXN];
map<ll,ll> pos;
ll vals[MAXN],n,buy,sell;
bool buyer[MAXN],used[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //ifstream cin("test.in");

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> vals[i];
        sorted[i] = pii(vals[i],i);
    }
    sort(sorted, sorted + n);

    for(int i = 0; i < n / 2; i++) //Creating position lookup
        buyer[sorted[i].second] = true;

    for(int i = n - 1; i >= 0; i--)
    {
        if(!buyer[i])
            sell_points.push(pii(vals[i],i));

        else
        {
            if(!sell_points.empty())
            {
                buy += vals[i];
                sell += sell_points.top().first;
                used[sell_points.top().second] = true;
                used[i] = true;
                sell_points.pop();
                
            }
        }
    } 
    while(!sell_points.empty())
        sell_points.pop();

    for(int i = n - 1; i >= 0; i--)
        if(!used[i])
        {
            if(!sell_points.empty() && sell_points.top().first > vals[i])
            {
                sell += sell_points.top().first;
                buy += vals[i];
                sell_points.pop();
            }
            else
                sell_points.push(pii(vals[i],i));
        }


    
    cout << (sell - buy) << endl;
    return 0;
}