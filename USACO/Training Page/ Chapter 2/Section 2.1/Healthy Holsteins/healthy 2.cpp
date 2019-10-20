/*****
ID: INSERT_ID_HERE
LANG: C++
PROG: holstein
**/
#include <bits/stdc++.h>
using namespace std;
#define  MAX_SUPPLEMENTS 25

struct Vitamin
{
    int supplement[MAX_SUPPLEMENTS];
    double timesComputed;
};

Vitamin options[MAX_SUPPLEMENTS],needed;
int v,g,totalTimes;
vector <int> ans,cur;
bool visited [MAX_SUPPLEMENTS];

void printVector(vector <int> v)
{
    cout << "{";
    for(int i = 0; i < v.size() - 1; i++)
        cout << v[i] << ",";
    cout << v[v.size() - 1];
    cout << "}" << endl;
}

void solve(int x)
{
    if(x >= g)
    {
        int negCount = 0;
        Vitamin check = needed;
        for(int i = 1; i < cur.size(); i++)
        {
            for(int j = 0; j < v; j++)
            {
                bool positive = false;
                if(check.supplement[j] > 0)
                    positive = true;
                check.supplement[j] -= (options[cur[i]].supplement[j]);
                if(positive && check.supplement[j] <= 0)
                    negCount++;
            }
        }
        if(negCount == v && cur.size() <= ans.size()) // If all vitamins have been used & we know that the set of vitamins are at most equal
        {
            if(cur.size() < ans.size())
                ans = cur;
            for(int i = 1; i <= v && cur.size() == ans.size(); i++)
                if(cur[i] < ans[i])
                {
                    ans = cur;
                    break;
                }
        }
        return;
    }

    cur.push_back(x);

    solve(x + 1);

    cur.pop_back();

    solve(x + 1);
}

int main()
{
    ifstream fin ("holstein.in");
    fin >> v;

    for(int i = 0; i < v; i++)
        fin >> needed.supplement[i];
    fin >> g;

    for(int i = 0; i < g; i++)
        for(int j = 0; j < v; j++)
            fin >> options[i].supplement[j];
    for(int i = 0; i <= g; i++)
        ans.push_back(99999);
    cur.push_back(0);

    solve(0);

    printVector(ans);
    ofstream fout("holstein.out");
    fout << ans.size() - 1;

    for(int i = 1; i < ans.size(); i++)
        fout << " " << ans[i] + 1;
    fout << endl;
    return 0;
}
