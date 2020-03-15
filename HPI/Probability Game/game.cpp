#include <bits/stdc++.h>
using namespace std;

void setIO() //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
}

int n;
int pA,pB;
double ans = 0.0;
int main()
{
    setIO();
    cin >> n >> pA;

    pB = 100 - pA;
    while(n--)
    {
        cout << pA << " " << pB << endl;
        if(pA >= pB)
        {
            ans += (pA / 100.0);
            int loss = pA / 2;
            pB += loss;
            pA -= loss;
        }
        else
        {
            ans -= (pB / 100.0);
            int loss = pB / 2;
            pA += loss;
            pB -= loss;
        }
    }

    cout << ans << endl;
    return 0;
}