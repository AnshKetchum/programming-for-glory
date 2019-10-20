/*****
ID: INSERT_ID_HERE
LANG: C++
PROG: frac1
**/
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 165

typedef pair <int,int> pii;
vector <pii> allFractions;
bool visited [MAX_N][MAX_N];
int n;

void visit(int i,int j)
{
    allFractions.push_back(make_pair(i,j));

    int minI = n,minJ = n;
    if(i != 0)
        minI /= i;
    if(j != 0)
        minJ /= j;
    int highestCF = min(minI,minJ);
    for(int a = 1; a <= highestCF; a++) //Set all others which are congruent to visited
        visited[i * a][j * a] = true;
}

int main()
{
    ifstream fin ("frac1.in");
    fin >> n;

    for(int i = 0; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(!visited[i][j] && i <= j)
                visit(i,j);

    sort(allFractions.begin(),allFractions.end(),[](const pii a, const pii b){
         return (a.first * b.second) < (b.first * a.second);
    });

    ofstream fout("frac1.out");
    for(int i = 0; i < allFractions.size(); i++)
        fout << allFractions[i].first << "/" << allFractions[i].second << endl;
    return 0;
}
