
#include <bits/stdc++.h>
using namespace std;
 
void setIO() //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
}
 
void solve(int d)
{
    double dis = (d * d) - (4 * d);
 
    if(dis < 0)
        printf("N\n");
    else if(dis == 0)
        printf("Y %.9f %.9f\n", d / 2.0, d / 2.0);
    else
    {
        double sol1 =  0.5 * (d + sqrt(dis)), sol2 = d / sol1;
        printf("Y %.9f %.9f\n", max(sol1,sol2), min(sol1, sol2));
    }
}
 
int n;
int main()
{
    setIO();
    cin >> n;
    while(n--)
    {
        int d; cin >> d;
        solve(d);
    }
 
    return 0;
}