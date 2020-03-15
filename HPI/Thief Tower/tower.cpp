#include <bits/stdc++.h>
using namespace std;
#define MAXN 1500

void setIO() //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
}


int n,a[MAXN];
string ans = "NO COLLAPSE";
int main()
{
    setIO();
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, greater<int>());

    for(int i = 0; i < n - 1; i++)
        if(a[i] < n - i - 1)
        {
            ans = "COLLAPSE";
            break;
        }
    cout << ans << endl;
    return 0;
}

// 2 2 1 0 
// n = 4