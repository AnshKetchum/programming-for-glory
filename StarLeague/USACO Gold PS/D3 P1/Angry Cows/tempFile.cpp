#include <bits/stdc++.h>
using namespace std;
#define MAXN 55000
#define INF 100000000.0
int n,pos[MAXN],ans,l,r,rad,rad1;
double ans = INF;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> pos[i];
    sort(pos, pos + n);

    r = n - 1;
    while(true)
    {
        double pos_radius = max(max(rad,rad2) + 1, (double)((pos[r] - pos[l]) / 2))
        best = min(best, pos_radius);
        int pot = Math.max(rad+1,l.get(beg+1)-l.get(beg));
        int pot1 = Math.max(rad1+1,l.get(end)-l.get(end-1));
        if(pot<pot1)
        {
            rad=pot; 
            int index = beg;
            while(index<N-1 && l.get(beg)+pot>=l.get(index+1))
                index++; 
            beg=index;
        } 
        else 
        {
            rad1=pot1; 
            int index = end;
            while(index>0 && l.get(end)-pot1<=l.get(index-1))
                index--;
            end=index;
        }
        if(end<=beg)
        {
            best= Math.min(best,Math.max(rad,rad1));
            break;
        }
    }

    cout << ans << endl;
    return 0;
}