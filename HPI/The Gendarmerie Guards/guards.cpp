#include <bits/stdc++.h>
using namespace std;

void setIO() //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
}

int n,cnt;
int main()
{
    setIO();
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cnt = 0;
        for(int j = 1; j <= i; j++)
            if(i % j == 0)
                cnt++;
        cout << cnt << " ";
    }
    cout << endl;
    return 0;
}