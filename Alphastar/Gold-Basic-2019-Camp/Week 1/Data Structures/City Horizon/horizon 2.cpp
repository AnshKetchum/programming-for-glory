#include <bits/stdc++.h>
using namespace std;
#define MAX_N 45000
typedef long long ll;

struct Point
{
    bool endpoint;
    ll position,height,index;
};

Point make_point(bool e, int p,  int i, int h)
{
    Point a;
    a.endpoint = e;
    a.position = p;
    a.index = i;
    a.height = h;
    return a;
}

bool comp(Point a, Point b)
{
     if(a.position != b.position)
            return a.position < b.position;
    return a.height < b.height;
}

ll n,ans;
vector <Point> points;
typedef pair<ll,ll> pii;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        ll a,b,h;
        cin >> a >> b >> h;

        points.push_back(make_point(false,a,i,h));
        points.push_back(make_point(true,b,i,h));
    }

    sort(points.begin(), points.end(), comp);

    multiset <pii> active_set;

    active_set.insert(pii(0,-1));
    Point prev  = points[0];
    for(int i = 0; i < points.size(); i++)
    {
        auto it = active_set.end();
        pii curHeight;
        if(active_set.size() > 1)
        {
             it--;
             curHeight = *it;
        }
        else curHeight.first = 0;

        ll totalArea = curHeight.first * (points[i].position - prev.position);
        ans += totalArea;

        if(!points[i].endpoint)
            active_set.insert(pii(points[i].height,points[i].index));
        
        else
            active_set.erase(active_set.find(pii(points[i].height,points[i].index)));
        

        prev = points[i];
    }

    cout << ans << endl;
    return 0;
}
