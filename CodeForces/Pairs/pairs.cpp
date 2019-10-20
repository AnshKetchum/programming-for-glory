#include <bits/stdc++.h>
using namespace std;
#define MAX_PAIRS 300005
typedef pair<int,int> pii;
map<pii,int> overlap;
pii coords [MAX_PAIRS];
int n,m,ans,cnts[MAX_PAIRS];

int pie(int a, int b) //Principle of Exclusion / Inclusion
{
    int sizeA = cnts[a], sizeB = cnts[b],between = overlap[pii(a,b)];
    return sizeA + sizeB - between;
}

void fix(int initVal)
{
    for(int i = 0; i < m; i++)
    {
        if(coords[i].first != initVal)
            ans = max(ans,pie(initVal,coords[i].first));
        if(coords[i].second != initVal)
            ans = max(ans,pie(initVal,coords[i].second));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m; //Read Input
    for(int i = 0; i < m; i++)
    {
        cin >> coords[i].first >> coords[i].second; 
        overlap[pii(coords[i].first,coords[i].second)]++; //Counting Overlap between two regions (Adding to both (a,b) & (b,a) as they are the same)
        overlap[pii(coords[i].second,coords[i].first)]++;
        cnts[coords[i].first]++;
        cnts[coords[i].second]++;
    }

    fix(coords[0].first);
    fix(coords[0].second);

    cout << (ans  == m ? "YES" : "NO") << endl;
}