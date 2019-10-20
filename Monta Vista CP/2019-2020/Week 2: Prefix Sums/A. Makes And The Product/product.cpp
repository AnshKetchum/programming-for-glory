#include <bits/stdc++.h>
using namespace std;
#define MAXN 155000

typedef long long ll;
ll v[MAXN],pref[3][MAXN],n,sorted[MAXN],refe[3],ans,min_prod = 1;
set <int> vals;
ll query(int l, int r, int a)
{
    return (pref[a][r + 1]  - pref[a][l]); 
}

void compute(int val, int index)
{
    for(int lower = 0; lower < vals.size(); lower++)
        for(int upper = 0; upper < vals.size(); upper++)
            if(refe[lower] * refe[upper] * val == min_prod)
                ans += (query(index + 1, n - 1,upper) * query(0, index - 1,lower));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        sorted[i] = v[i];
    }

    sort(sorted, sorted + n);

    for(int i = 0; i < 3; i++) //Take the smallest three integers
    {
        vals.insert(sorted[i]);
        min_prod *= sorted[i];
    }
    
    auto it = vals.begin();
    for(int i = 0; i < vals.size(); i++)
    {
        refe[i] = *it;
        ++it;
    }

    for(int i = 0; i < n; i++) //Building the prefix
    {
        pref[0][i + 1] = pref[0][i];
        pref[1][i + 1] = pref[1][i];
        pref[2][i + 1] = pref[2][i];

        for(int j = 0; j < 3; j++)
            if(refe[j] == v[i])
                pref[j][i + 1]++;
    }
    
    for(int i = 1; i < n - 1; i++)
        if(v[i] == refe[0] || v[i] == refe[1] || v[i] == refe[2])
            compute(v[i],i);
    cout << ans << endl;
    return 0;
}