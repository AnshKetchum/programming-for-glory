#include <bits/stdc++.h>
using namespace std;
#define MAXN 8

int par[MAXN], r[MAXN];

int findSet(int i) { return (par[i] == i ? i : par[i] = findSet(par[i])); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
void join(int i, int j) 
{ 
    int a = findSet(i), b = findSet(j);
    if(a == b) return;
    if(r[a] > r[b]) par[j] = a;
    else{
        par[i] = b;
        if(r[a] == r[b]) r[b]++;
    }
}

int numDisjointSets()
{
    int ret = 0;
    for(int i = 0; i < MAXN; i++)
        if(par[i] == i)
            ret++;
    return ret;
}

int sizeOfSet(int i)
{
    int ret = 0;
    for(int j = 0, p = findSet(i); j < MAXN; j++)
        if(findSet(j) == p)
            ret++;
    return ret;
}



int main()
{
    for(int i  = 0; i < MAXN; i++)
        par[i] = i;
    

    return 0;
}