#include <bits/stdc++.h>
using namespace std;
#define MAXN 50
#define NUM_COWS 8
#define DEBUGPERM for(int i = 0; i < NUM_COWS; i++) {cout << perm[i] << " "; } cout << endl;

int n,perm[NUM_COWS] = {0,1,2,3,4,5,6,7};
map <string,int> lookup;
string possible,ans = "ZZZZZZZZZZZZZZZZZZZZZ", names [NUM_COWS] = {"Bessie","Buttercup","Belinda","Beatrice","Bella","Blue","Betsy","Sue"};
vector<int> connections [NUM_COWS];

void preprocess()
{
    for(int i = 0; i < NUM_COWS; i++)
        lookup[names[i]] = i;
}

bool pos()
{
    possible = "";
    for(int i = 0; i < NUM_COWS; i++)
    {
        int cur = perm[i];
        if(!connections[cur].empty())
        {
            if(connections[cur].size() == 1)
            {
                if(i == 0 && perm[i + 1] != connections[cur][0])
                    return false;
                else if(i == NUM_COWS - 1 && perm[i - 1] != connections[cur][0])
                    return false;
                else if(connections[cur][0] != perm[i + 1] && connections[cur][0] != perm[i - 1])
                    return false;
            }
            else if(connections[cur].size() >= 2)
            {
                if(i == 0 || i == NUM_COWS - 1)
                    return false;
                if(connections[cur][0] + connections[cur][1] != perm[i - 1] + perm[i + 1])
                    return false;
            }
        }
        possible += names[cur];
        if(i < NUM_COWS - 1)
            possible += "\n";

    }
    return true;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    preprocess();

    ifstream cin("lineup.in");
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string n1,n2,s; cin >> n1; 
        for(int i = 0; i < 4; i++) 
            cin >> s;
        cin >> n2;
        connections[lookup[n2]].push_back(lookup[n1]);
        connections[lookup[n1]].push_back(lookup[n2]);
    }

    do
    {
        if(pos() && possible < ans)
            ans = possible;
    }  while(next_permutation(perm, perm + NUM_COWS));

    ofstream cout("lineup.out");
    cout << ans << endl;
    return 0;
}