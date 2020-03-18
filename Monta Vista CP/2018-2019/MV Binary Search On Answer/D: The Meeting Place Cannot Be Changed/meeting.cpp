#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define MAXN 65000
#define PP(x) cout << x.first << " " << x.second << endl;
using namespace std;
typedef pair<double,double> pii;



void setIO() 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
}

int n,p[MAXN],v[MAXN];
double ans,best_time = 1e10;

pii get_dists(double tme , int i)
{
    double dist = (tme * v[i]);
    return pii( max((double)p[i] - dist, 0.0), p[i] + dist);
}

bool overlaps(pii super, pii sub)
{
    return super.second <= sub.first || super.first >= sub.second;
}



bool can_meet(double possible_time)
{
    pii range = get_dists(possible_time, 0);
    
    for(int i = 1; i < n; i++)  
    {

        pii x = get_dists(possible_time, i);
        if(overlaps(range, x))
            return false;
        
        range.first = max(range.first, x.first);
        range.second = min(range.second, x.second);
    }
    return true;
}

double bin_search(double l, double r)
{
    while(abs(r - l) >= 1e-6)
    {
        double mid = (l + r) / 2.0;

        if(can_meet(mid))
            r = mid;
        else
            l = mid;
    }
    return l;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> p[i];
    for(int i = 0; i < n; i++)
        cin >> v[i];

    printf("%.12f \n", bin_search(0.0, 1e9 + 1));
    return 0;
}
