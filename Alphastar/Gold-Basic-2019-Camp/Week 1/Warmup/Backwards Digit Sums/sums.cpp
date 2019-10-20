#include <bits/stdc++.h>
using namespace std;
#define MAX_DIGITS 11


int n, ans [MAX_DIGITS],sum;
bool used [MAX_DIGITS];
int digits [] = {1,2,3,4,5,6,7,8,9,10};
vector <int> coefficients;

int fact(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

int nCr(int n, int r) 
{
    return fact(n) / (fact(r) * fact(n - r));
}

bool smaller()
{
    int gr = 0,le = 0;

    multiset<int> a,b;
    for(int i = 0; i < n; i++)
    {
        a.insert(digits[i]);
        b.insert(ans[i]);
    }

    auto it = a.begin(), it2 = b.begin();
    for(int i = 0; i < n; i++)
    {
        if(*it != *it2)
        {
            if(*it < *it2)
                 le++;
            else if(*it > *it2)
                gr++;
        }
        it++;
        it2++;
    }
    return le > gr;
}

void comb()
{
    while(next_permutation(digits, digits + n))
    {
        int total = 0;
        for(int i = 0; i < coefficients.size(); i++)
                total += (digits[i] * coefficients[i]);
        if(total == sum && smaller())
            for(int i = 0; i < n; i++)
                ans[i] = digits[i];

    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> sum;

    for(int i = 0; i < n; i++)
        ans[i] = 1000000;
    for(int i = 0; i < n; i++)
        coefficients.push_back(nCr((n - 1),i));
    comb();

    if(n == 1)
        ans[0] = sum;

    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
