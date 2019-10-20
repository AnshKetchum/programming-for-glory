/*****
ID: INSERT_ID_HERE
LANG: C++
PROG: hamming
**/
#include <bits/stdc++.h>
using namespace std;
#define MAX_POW 1024

int n,b,d ,maxPower = 1,currentBitsUsed,powD =0, bits[MAX_POW];
set <int> hammableVals,ans;
bool hammable [MAX_POW] [MAX_POW], visited [MAX_POW];

bool inHammingDistance(int a, int c)
{
    int currentBit = 1,hammingDist = 0; // Starts at 2 ^ 0
    for(int i = 0; i < b; i++)
    {
        bool aHasBit = a & currentBit , bHasBit = c & currentBit;
        if((aHasBit && !bHasBit) || (!aHasBit && bHasBit))
           hammingDist++;
        currentBit *= 2;
    }
    return hammingDist >= d;
}

bool hammer(int i)
{
    for(auto it : hammableVals)
        if(!inHammingDistance(i,it))
            return false;
    return true;
}

void traverse(int cur)
{
    if(hammableVals.size() == n)
    {

        auto it = hammableVals.begin();
        auto it2 = ans.begin();
        for(int i = 0; i < n; i++)
            if(*it < *it2)
            {
                ans =  hammableVals;
                break;
            }
        return;
    }


    for(int i = 0; i <= maxPower; i++)
        if(hammable[cur][i] && !visited[i] && i != cur)
            if(hammer(i))
            {
                int temp = currentBitsUsed,pow2 = 1;

                visited[i] = true;
                hammableVals.insert(i);
                currentBitsUsed = 0;


                for(int a = 0; a < b; a++)
                {
                    if( (temp & pow2) || (i & pow2) )
                        currentBitsUsed += pow2;
                    pow2 *= 2;
                }

                traverse(i);
                currentBitsUsed = temp;
                hammableVals.erase(cur);
            }

}


int main()
{
    ifstream fin("hamming.in");
    ofstream fout("hamming.out");

    fin >> n >> b >> d;

    for(int i = 0; i < n; i++)
        ans.insert(1024);

    maxPower = (int)pow(2,b);
    powD = (int)pow(2,d);

    for(int i = 0; i <= maxPower; i++)
    {
        for(int j = 0; j <= maxPower && hammableVals.size() != n; j++)
        {
            if(i == j)
                continue;
           else if(inHammingDistance(i,j))
            {
                hammable[i][j] = true;
                hammable[j][i] = true;
            }
        }
    }

    traverse(0);

    while(ans.size() != 0)
    {
        if(ans.size() > 10)
            for(int i = 0; i < 9; i++)
            {
                fout << *ans.begin() << " ";
                ans.erase(ans.begin());
            }

        else
        {
            int n = ans.size() - 1;
            for(int i = 0; i < n; i++)
            {
                fout << *ans.begin() << " ";
                ans.erase(ans.begin());
            }
        }
        fout << *ans.begin() << endl;
        ans.erase(ans.begin());

    }

    return 0;
}
