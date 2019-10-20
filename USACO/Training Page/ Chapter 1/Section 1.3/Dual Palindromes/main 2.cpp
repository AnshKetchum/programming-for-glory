/*****
ID: INSERT_ID_HERE
LANG: C++
PROG: dualpal
**/
#include <bits/stdc++.h>
using namespace std;

int s,n;
string convertBase(int num, int base) //Modified base conversion method from the Palindromic Squares problem code
{
    string convertedNumber = "";
    while(num != 0)
    {
        int remainder = num % base;
        if(remainder > 9)
        {
            remainder -= 10;
            convertedNumber = (char)(65 + remainder) + convertedNumber;
        }
        else convertedNumber = (char)(remainder + '0') + convertedNumber;
        num /= base;
    }
    return convertedNumber;
}

bool isPalindrome(string str) //Copied from the Palindromic Squares Problem code
{
    for(int i = 0; i < str.length(); i++)
        if(str[i] != str[str.length() - i - 1]) return false;
    return true;
}

int main()
{
    ifstream cin ("dualpal.in");
    ofstream cout ("dualpal.out");
    cin >> n >> s;
    int totalCount = 0;
    for(int i = s + 1; totalCount < n; i++)
    {
        int baseCount = 0;
        for(int base = 2; base <= 10; base++) //Tests all bases
        {
            string numConverted = convertBase(i,base);
            if(isPalindrome(numConverted)) baseCount++;
        }
        if(baseCount >= 2)
        {
            cout << i << endl;
            totalCount++;
        }
    }
    return 0;
}
