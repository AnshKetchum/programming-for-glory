#include <bits/stdc++.h>
using namespace std;
#define MAXN 50

int H,h[MAXN],w[MAXN],s[MAXN],n,ans;

void compute_ans(string x)
{
    int hsum = 0, sum = 0;
    for(int i = x.length() - 1; i >= 0; i--)
        if(x[i] == '1')
        {
            if(s[i] < sum) //Not possible
                return;
            sum += w[i];
            hsum
        }
    if(hsum > H)
        ans = max(ans, ;    
    
}

void comb(int i, string x)
{
    if(i >= n)
    {
        cout << x << endl;
        compute_ans(x);
    }
    else
    {
        comb(i + 1, x + "0");
        comb(i + 1, x + "1");
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream cin("guard.in");

    cin >> n >> H;
    for(int i = 0; i < n; i++)
        cin >> h[i] >> w[i] >> s[i];
    cout << "IO Complete" << endl;
    comb(0,"");
    
    if(ans == 0)
        cout << "Mark is too tall!" << endl;
    else 
        cout << ans << endl;
    return 0;
}
