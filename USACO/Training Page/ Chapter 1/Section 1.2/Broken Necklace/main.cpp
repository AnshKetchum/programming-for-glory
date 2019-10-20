/*****
ID: INSERT_NAME_HERE
LANG: C++
PROG: beads
**/
#include <bits/stdc++.h>
using namespace std;

int n,ans;
string beads;
void breakNecklace(int a) //Function that computes the length of a segment starting from position a
{
    int usedR = 0,usedB = 0;
    string broken = beads.substr(a,(n - a)) + beads.substr(0,(n - (n - a))); //"Breaking" the necklace at point a
    string nowhite = "";

    int i,ct = 0;
    for(i = 0; i < n; i++) //Checks how far one can go after the breaking the necklace
    {
        if(broken[i] != 'w')
        {
            if     (broken[i] == 'r' && usedR == 0) usedR = ++ct;
            else if(broken[i] == 'b' && usedB == 0) usedB = ++ct;
            nowhite += broken[i];
            if     (usedB < usedR && nowhite[nowhite.length() - 1] == 'b') break;
            else if(usedR < usedB && nowhite[nowhite.length() - 1] == 'r') break;
        }
    }

    if(a == 0)i++;
    ans = max(ans, i); //Ensuring we get the highest answer
}

int main()
{
    ifstream cin("beads.in");
    ofstream cout("beads.out");

    cin >> n;
    for(int i = 0; i < n; i++) //Input
    {
        char inputC; cin >> inputC;
        beads += inputC;
    }
    for(int i = 1; i <= n; i++) //Testing every position
       breakNecklace(i);
    cout << ans << endl;
    return 0;
}
