#include <bits/stdc++.h>
using namespace std;
#define FASTIO 	ios_base::sync_with_stdio(nullptr); cin.tie(nullptr); cout.tie(nullptr);

int n;
string s1,s2;
void swap_character(int ind)
{
    char temp = s1[ind];
    s1[ind] = s2[ind];
    s2[ind] = temp;
}

int main()
{
    FASTIO
    cin >> n >> s1 >> s2;

    for(int i = 0; i < n; i++)
        if(s2[i] < s1[i])
            swap_character(i);
    cout << (s1 + s2) << endl;
    return 0;
}