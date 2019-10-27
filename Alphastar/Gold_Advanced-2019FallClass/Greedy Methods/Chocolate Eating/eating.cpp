#include <bits/stdc++.h>
using namespace std;
#define MAXN 150000
#define INF 1000000000

int n,d,chocolate[MAXN];
bool pos(int happiness_value)
{
    int day_count = 1,sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(sum < happiness_value)
            sum += chocolate[i];

        while(sum >= happiness_value)
        {
            sum /= 2;
            day_count++;
        }
    }

    return day_count - 1 <= d;
}

int binary_search(int l, int r)
{
    if(l == r)
        return l;
    int mid = (l + r) / 2;

    if(pos(mid))
        return binary_search(l, mid);

    return binary_search(mid + 1, r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> d;
    for(int i = 0; i < n; i++)
        cin >> chocolate[i];

    cout << binary_search(0,INF) << endl;
    return 0;
}
