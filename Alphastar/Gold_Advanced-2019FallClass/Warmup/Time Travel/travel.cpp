#include <bits/stdc++.h>
using namespace std;
#define MAXN 85000

int last[MAXN], parent[MAXN],n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n; //Reading input

    parent[0] = -1; //There are initially 0 cows
    last[0] = -1;
    for(int i = 1; i <= n; i++)
    {
        char c; int a; cin >> c;

        switch (c)
        {
            case 'a':
                cin >> a;
                parent[i] = i - 1;
                last[i] = a;
                break;
            case 't':
                cin >> a;
                parent[i] = parent[a - 1];
                last[i] = last[a - 1];
                break;
            case 's':
                cout << parent[i] << endl;
                parent[i] = parent[parent[i - 1]];
                last[i] = last[parent[i - 1]];
                break;
        }
        cout << last[i] << endl;
    }   
    return 0;
}