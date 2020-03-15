#include <bits/stdc++.h>
using namespace std;

void setIO() //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
}


int n,sum;
int main()
{
    setIO();
    cin >> n;
    for(int i = 0; i < n; i++)  
    {
        int a; cin >> a;
        sum += a;
    }

    cout << sum << endl;
    return 0;
}