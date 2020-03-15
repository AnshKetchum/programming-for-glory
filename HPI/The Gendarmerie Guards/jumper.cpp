#include <bits/stdc++.h>
using namespace std;

void setIO() //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
}


int n,d,ans;
int main()
{
    setIO();
    cin >> n >> d;
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        ans += (d - a);
    }
    
    cout << ans << endl;
    return 0;
}