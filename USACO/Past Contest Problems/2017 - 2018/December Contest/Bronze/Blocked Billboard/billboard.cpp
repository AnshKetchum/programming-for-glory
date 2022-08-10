#include <bits/stdc++.h>
using namespace std;
#define MAXN 3
typedef long long ll;
typedef pair<ll,ll> pii;

ll area;
pii x[MAXN], y[MAXN];

ll intersect(pii xa, pii ya, pii xb, pii yb)
{
    pii x_com = pii(max(xa.first, xb.first), min(xa.second, xb.second) ); 
    pii y_com = pii(max(ya.first, yb.first), min(ya.second, yb.second) ); 

    if( (xa.first <= x_com.first && x_com.second <= xa.second) && (xb.first <= x_com.first && x_com.second <= xb.second) && 
        (ya.first <= y_com.first && y_com.second <= ya.second) && (yb.first <= y_com.first && y_com.second <= yb.second))
        return abs((y_com.second - y_com.first) * (x_com.second - x_com.first));
    return 0;
}


int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);

    ifstream cin ("billboard.in");
    ofstream cout ("billboard.out");

    for(int i = 0; i < MAXN; i++)
    {
        cin >> x[i].first >> y[i].first >> x[i].second >> y[i].second;
        
        if(i != 2)
            area += (ll) (x[i].second - x[i].first) * (y[i].second - y[i].first);
    }

    // cout << "Area beforehand: " << area << endl;
    for(int i = 0; i < MAXN; i++)
        for(int j = 0; j < i; j++)
            if(i != j)
            {
                ll inter = intersect(x[i], y[i], x[j], y[j]);
                // cout << "Intersection between: " << (i + 1) << " and " << (j + 1) << " is: " << inter << endl;
                area -= inter;
            }

    cout << area + max(intersect(x[0], y[0], x[1], y[1]),intersect(x[1], y[1], x[0], y[0])  )<< endl;
    return 0;
}