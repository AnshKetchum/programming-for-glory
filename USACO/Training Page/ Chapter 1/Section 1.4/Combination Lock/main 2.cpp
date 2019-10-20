/*****
ID: INSERT_ID_HERE
LANG: C++
PROG: combo
**/
#include <bits/stdc++.h>
using namespace std;

int masterCombination[3], fJCombination[3], curCombination[3],n,ans;
bool specialCase(int lock, int curSet)
{
    if(lock == n && curSet == 2 || lock == n && curSet == 1) return true;
    else if(lock == 1 && curSet == n || lock == 2 && curSet == n) return true;
    else if(lock == n - 1 && curSet == 1 || lock == 1 && curSet == n - 1) return true;
    return false;
}

bool validCombination(int key[])
{
    for(int i = 0; i < 3; i++) {
        int difference = abs(key[i] - curCombination[i]);
        if(difference > 2 && !specialCase(key[i],curCombination[i])) return false;
    }
    return true;
}

int main()
{
    ifstream cin  ("combo.in");
    ofstream cout ("combo.out");

    cin >> n;
    for(int i = 0; i < 3; i++)
        cin >> fJCombination[i];
    for(int i = 0; i < 3; i++)
        cin >> masterCombination[i];

    for(curCombination[0] = 1; curCombination[0] <= n; curCombination[0]++){
        for(curCombination[1] = 1; curCombination[1] <= n; curCombination[1]++){
            for(curCombination[2] = 1; curCombination[2] <= n; curCombination[2]++){
                if(validCombination(masterCombination) || validCombination(fJCombination)){
                        ans++;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
