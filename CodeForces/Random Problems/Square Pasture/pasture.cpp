#include <bits/stdc++.h>
using namespace std;


typedef pair<int,int> pii;
int x[4],y[4];

pii lower_corner, upper_corner;
int main()
{
    ifstream cin("square.in");
    ofstream cout("square.out");

    lower_corner = pii(100000,100000);

    cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2] >> x[3] >> y[3];
    for(int i = 0; i < 4; i++)
    {
        lower_corner.first = min(lower_corner.first,x[i]);
        lower_corner.second = min(lower_corner.second,y[i]);
        upper_corner.first = max(upper_corner.first,x[i]);
        upper_corner.second = max(upper_corner.second,y[i]);
        
    }

    int length = max(abs(upper_corner.first - lower_corner.first), abs(upper_corner.second - lower_corner.second));
    cout << (length * length) << endl;
}