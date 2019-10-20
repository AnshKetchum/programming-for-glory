/*****
ID: INSERT_ID_HERE
LANG: C++
PROG: palsquare
**/
#include <bits/stdc++.h>
using namespace std;

int base,n;
string convertBase(int num) //Converts the base to the current base (Denoted by the variable base)
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

bool isPalindrome(string str) //Checks if a value (Converted to string for simplicity) is a palindrome
{
    for(int i = 0; i < str.length(); i++)
        if(str[i] != str[str.length() - i - 1]) return false;
    return true;
}

int main()
{
    ifstream cin ("palsquare.in");
    ofstream cout ("palsquare.out");
    cin >> base;

    for(n = 1; n <= 300; n++)
    {
        string numSquared = convertBase(n * n);
        if(isPalindrome(numSquared))
            cout << convertBase(n) << " " << numSquared << endl;
    }
    return 0;
}
