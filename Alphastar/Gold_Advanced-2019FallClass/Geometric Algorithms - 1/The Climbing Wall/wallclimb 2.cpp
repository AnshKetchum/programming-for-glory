#include <bits/stdc++.h>
using namespace std;
#define MAXF 15000

typedef pair<int,int> pii;
int h,f;
pii points[MAXF];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> f;
    for(int i = 0; i < f; i++)
        cin >> points[i].first >> points[i].second;


    return 0; 
}