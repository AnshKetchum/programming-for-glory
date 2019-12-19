#include <bits/stdc++.h>
using namespace std;
#define MAXN 350000


int n,ans = 0,s[MAXN],elsie_top;
vector <int> stacks [MAXN];
set <int> bases;

void delete_bases(int base, int val)
{
    while(*bases.begin() != base) //Delete everything up to the current base
        bases.erase(bases.begin());
}

void delete_plates(int base, int val)
{
    while(stacks[base][stacks[base].size() - 1] < val && stacks[base][stacks[base].size() - 1] != 0)
    {
        elsie_top = stacks[base][stacks[base].size() - 1];
        stacks[base].pop_back();
    }
}

void insert_into_stack(int val)
{
    
    if(bases.size() == 0 || val > *(--bases.end()))
    {
        bases.insert(val);
        stacks[val].push_back(0);
    }
    else
    {
        int next_larger_base = *(bases.upper_bound(val));

        int s = stacks[next_larger_base].size() - 1;
        if(stacks[next_larger_base][s] < val)
        {
            delete_bases(next_larger_base,val);
            delete_plates(next_larger_base,val);
            stacks[next_larger_base].push_back(val);
        }
        
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ifstream cin("dishes.in");
    ofstream cout("dishes.out");

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    
    for(int i = 0; i < n; i++)
    {
        if(s[i] < elsie_top)
            break;
        insert_into_stack(s[i]);
        ans++;
    }

    cout << (ans == 0 ? 1 : ans) << endl;
    return 0;
}