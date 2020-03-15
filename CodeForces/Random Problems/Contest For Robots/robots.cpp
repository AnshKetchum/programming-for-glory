#include <bits/stdc++.h>
using namespace std;
#define MAXN 200

int n,a[MAXN],b[MAXN],oa,ob,p;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    for(int i = 0; i < n; i++)
    {
        oa += (a[i] && !(a[i] == b[i]));
        ob += (b[i] && !(a[i] == b[i]));
    }
    

    cout << ( (oa == 0 ) ? -1 : ceil((ob + 1.0) / oa) ) << endl;
    return 0;
}