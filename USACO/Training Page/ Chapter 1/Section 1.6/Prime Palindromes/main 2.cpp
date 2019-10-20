/*****
ID: INSERT_ID_HERE
LANG: C++
PROG: pprime
**/
#include <bits/stdc++.h>
using namespace std;

set <int> palindromeList;
int curComb [9],upper,lower;

void getCombinations(int x, int palindromicDigits, int sizeOfNumber) //Tries all combinations of palindromes
{
    if(x > (palindromicDigits - 1))
    {
        int pow10 = 1,curPalindrome = 0;
        for(int i = 0; i < palindromicDigits; i++)
            curComb[(sizeOfNumber - 1) - i] = curComb[i];
        for(int i = 0; i < sizeOfNumber; i++)
        {
            curPalindrome += (curComb[i] * pow10);
            pow10 *= 10;
        }

        if(curPalindrome >= lower && curPalindrome <= upper && !palindromeList.count(curPalindrome))
            palindromeList.insert(curPalindrome);

        return;
    }

    for(int i = 0; i <= 9; i++)
    {
        if(x == 0 && i == 0)
            continue;
        curComb[x] = i;
        getCombinations(x + 1,palindromicDigits,sizeOfNumber);
    }
}

bool isPrime(int n)  //Optimized Method: Credit to GFG for Code
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
    return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0)
        return false;

    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;

    return true;
}

int main()
{
    ifstream fin ("pprime.in");
    fin >> lower >> upper;

    int palDig = 1;
    for(int digits = 1; digits <= 8; digits += 2) //Tries all combination of digits
    {
        getCombinations(0,palDig,digits);
        getCombinations(0,palDig,digits + 1);
        palDig++;
    }

    ofstream fout("pprime.out");
    for(auto it : palindromeList)
    {
        int curVal = it;
        if(isPrime(curVal))
            fout << curVal << endl;
    }

    return 0;
}
