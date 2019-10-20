/*****
ID: INSERT_ID_HERE
LANG: C++
PROG: sprime
**/
#include <bits/stdc++.h>
using namespace std;
#define GREATEST_DIGITS 9
set <int> ans;
int n,pow10,bound = 1,num[9],curPow = 1;

bool isPrime(int n) //Credit to GFG for optimized primes check
{
    // Corner cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return false;

    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;

    return true;
}

int getNum(int x,int power) //Returns the number created by the array
{
    int number = 0,pow10 = power;
    for(int i = 0; i <= x; i++)
    {
        number += num[i] * pow10;
        pow10 /= 10;
    }
    return number;
}

void getSuperprimes(int x) //Recursive "generate all combinations" function
{
    if(x >= n)
    {
        int curNum = getNum(x,curPow / 10);
        ans.insert(curNum);
        return;
    }
    for(int i = 9; i >= 0; i--)
    {
        if(x == 0 && i != 2 && i != 3 && i != 5 && i != 7) //Reducing complexity with guarentee of the first number being prime
            continue;
        num[x] = i;
        int curNum = getNum(x,curPow);
        if(isPrime(curNum))
        {
            curPow *= 10;
            getSuperprimes(x + 1);
            curPow /= 10;
        }
    }
}
int main()
{
    ifstream fin("sprime.in");
    fin >> n;

    for(int i = 1; i < n; i++)
        bound *= 10;
    getSuperprimes(0);

    ofstream fout("sprime.out");
    for(auto it : ans)
        fout << it << endl;
    return 0;
}
