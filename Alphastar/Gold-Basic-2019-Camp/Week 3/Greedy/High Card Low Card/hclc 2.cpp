#include <bits/stdc++.h>
using namespace std;
#define MAXN 550000

int n,wins;
set <int> bessieCards,elsieLowest;
set <int,greater<int>> elsieHighest;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= 2 * n; i++)
        bessieCards.insert(i);
    for(int i = 0; i < n; i++)
    {
        int c; cin >> c;
        bessieCards.erase(c);

        if(i < n / 2)
            elsieHighest.insert(c);
        else
            elsieLowest.insert(c);
    }

    int missing = 0;
    for(int higher : elsieHighest)
    {
        auto it = bessieCards.end();
        it--;
        if(*it > higher)
        {
            wins++;
            bessieCards.erase(it);
        }
        else missing++;
    }

    while(missing > 0)
    {
        auto it = bessieCards.end();
        it--;
        bessieCards.erase(it);
        missing--;
    }

    for(int lower : elsieLowest)
    {
        auto it = bessieCards.begin();
        if(*it < lower )
        {
            wins++;
            bessieCards.erase(it);
        }
    }

    cout << wins << endl;
    return 0;
}
