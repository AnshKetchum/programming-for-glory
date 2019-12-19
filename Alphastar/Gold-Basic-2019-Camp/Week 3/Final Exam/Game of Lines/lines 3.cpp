#include <bits/stdc++.h>
using namespace std;
#define MAXN 250
#define UP_LINE 1000000000.0

typedef pair<int,int> pii;
int n;
pii points[MAXN];
set <double> slopes;

void createLine(int i, int j)
{
    pii a = points[i], b = points[j];

    double dx = a.first - b.first;
    double dy = a.second - b.second;

    if(dx == 0)
        slopes.insert(UP_LINE);

    else
    {
        double m = dy / dx;
        slopes.insert(m);
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> points[i].first >> points[i].second;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i != j)
                createLine(i,j);

    cout << slopes.size() << endl;
    return 0;
}
