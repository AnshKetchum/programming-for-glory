#include <bits/stdc++.h>
using namespace std;
#define MAXN 150000
#define INF 9000000


//SOLUTION ONE

typedef pair<int,int> pii;  //First y, Second x 
pii coords [MAXN];
int n,d,ans = INF;

void two_pointers() //Two Pointers
{
    multiset <int>  active_set;
    int l = 0, r = 0;
    active_set.insert(coords[0].second);

    while(true) 
    {
        auto it = active_set.end();
        --it;
        if (*it - *active_set.begin() >= d) 
        {
            ans = min(ans, (coords[r].first - coords[l].first));
            active_set.erase(active_set.find(coords[l++].second));
        }
        else 
        { 
            if (r == n - 1)
                break;
            active_set.insert(coords[++r].second);
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> d;
    for(int i = 0; i < n; i++)
        cin >> coords[i].first >> coords[i].second; //Reversing the pair for better sorting (pair sorts by first)

    sort(coords, coords + n); //Sorting by x-coordinates

    two_pointers();
    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}