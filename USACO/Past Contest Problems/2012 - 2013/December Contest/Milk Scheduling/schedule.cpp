#include <bits/stdc++.h>
using namespace std;
#define MAXN 15000
#define MAXD 15000

priority_queue <int> best;
multiset <int> optimal_list [MAXN];
int n,ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ifstream cin("msched.in");
    ofstream cout("msched.out");

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a,b; cin >> a >> b;
        optimal_list[b].insert(a);
    }

    for(int i = MAXD - 1; i >= 1; i--)
    {
        while(!optimal_list[i].empty())
        {
            best.push(*optimal_list[i].begin());
            optimal_list[i].erase(optimal_list[i].begin());
        }
        if(!best.empty())
        {
            ans += best.top();
            best.pop();
        }
    }
    cout << ans << endl;
    return 0;

}
