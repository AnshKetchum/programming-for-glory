#include <bits/stdc++.h>
using namespace std;
#define MAXN 150000
typedef long long ll;
typedef pair<ll,ll> pii;

struct Rectangle
{
    multiset <ll> positions;
    multiset <ll> heights;

    void add_point(ll x, ll y)
    {
        positions.insert(x);
        heights.insert(y);
    }

    void remove_point(ll x, ll y)
    {
        positions.erase(positions.find(x));
        heights.erase(heights.find(y));
    }

    ll calc_area()
    {
        if(heights.size() <= 1 || positions.size() <= 1)
            return 0;
        ll dx = max((*heights.rbegin() - *heights.begin() ),(ll)1);
        ll dy = max((*positions.rbegin() - *positions.begin() ), (ll)1);
        return (  dx * dy );
    }

    void reset()
    {
        heights.clear();
        positions.clear();
    }
};

int n;
Rectangle left_rect,right_rect;
ll ans,init_area;
pii coords [MAXN];

void restart()
{
    left_rect.reset();
    for(int i = 0; i < n; i++)
        swap(coords[i].first,coords[i].second);
    sort(coords,coords + n);
    for(int i = 0; i < n; i++)
        right_rect.add_point(coords[i].first,coords[i].second);
}

void line_sweep()
{
    for(int i = 0; i < n; i++) //Removing points from right rect, adding to left rect
    {        
        left_rect.add_point(coords[i].first,coords[i].second);
        right_rect.remove_point(coords[i].first,coords[i].second);
        ans = min(ans,left_rect.calc_area() + right_rect.calc_area());   //Two rect scenario
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ifstream cin("split.in");

    cin >> n;
    for(int i = 0; i < n; i++) //Reading input, setting up the right rectangle
    {
        cin >> coords[i].first >> coords[i].second;
        right_rect.add_point(coords[i].first,coords[i].second);
    }

    sort(coords, coords + n);
    init_area = ans = right_rect.calc_area(); //Best - single box area
    

    line_sweep();
    restart();
    line_sweep();

    cout << (!ans ? init_area : init_area - ans) << endl; 
    return 0;
}
/*
2
1 1
2 2
*/