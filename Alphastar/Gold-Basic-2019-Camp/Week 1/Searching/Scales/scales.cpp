#include <bits/stdc++.h>
#define MAXN 5000
using namespace std;

int weights [MAXN],n,c,ans;

void comb(int ind , int sum) //Trying all possibilities
{
    if(sum > c)
        return;
    
    if(ind >= n)
    {
        ans = max(ans, sum);
        return;
    }
    if(weights[ind] + weights[ind + 1] +sum <= c) //Take the weight if the combined sum is still < c
        comb(ind + 1, sum + weights[ind]);
    else if(weights[ind] + sum > c) //Don't take the weight if the sum is > c
        comb(ind + 1, sum);
    else //Try both cases
    {
        comb(ind + 1, sum + weights[ind]);
        comb(ind + 1, sum);
    }
}


int main()
{
    cin >> n >> c;
    for(int i = 0; i < n; i++)
        cin >> weights[n - i - 1];
    comb(0,0);
    cout << ans << endl;
    return 0;
}
