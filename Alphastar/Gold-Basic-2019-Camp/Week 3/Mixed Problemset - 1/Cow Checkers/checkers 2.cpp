#include <bits/stdc++.h>
using namespace std;
#define int long long
#define RANGE 2000000
#define ACTUAL_RANGE 1000000

int m,n,q,zeroes[RANGE];
typedef pair<int,int> pii;
bool used[RANGE];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n;

    int y = 0;
    for(int i = 0; i <= ACTUAL_RANGE; i++)
        if(!used[i])
        {
            used[i] = true;
            used[i + y] = true;
            zeroes[i] = i + y;
            zeroes[i + y] = i;
            y++;
        } 

    cin >> q;

    for(int i = 0; i < q; i++)
    {
        int x,y; cin >> x >> y;
        if(zeroes[x] != y)
            cout << "Bessie" << endl;
        else
            cout << "Farmer John" << endl;
    } 

    return 0;
}
