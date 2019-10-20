/*****
ID: INSERT_ID_HERE
LANG: C++
PROG: preface
**/
#include <bits/stdc++.h>
#define MAX_N 500
using namespace std;

int n;
typedef long long ll;
ll counts [MAX_N];
char order [] = {'I','V','X','L','C','D','M'};


int getInd(char c)
{
    for(int i = 0; i < 7; i++)
        if(c == order[i])
            return i;
    return -1; //If our code fails, -1 will be thrown
}
string toRoman(int decimal)
{
    string thousands [] = {"", "M","MM","MMM"};
    string hundreds  [] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    string tens      [] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    string ones      [] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};

    string converted = "";
    converted += thousands[decimal / 1000];
    converted += hundreds[(decimal % 1000) / 100];
    converted += tens[((decimal % 1000) % 100) / 10];
    converted += ones[(((decimal % 1000) % 100) % 10)];
    return converted;
}

int main()
{
    ifstream cin ("preface.in");
    ofstream cout ("preface.out");

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        string str = toRoman(i);
        for(int i = 0; i < str.length(); i++)
            counts[getInd(str[i])]++;
    }

    int i = 0;
    while(counts[i] > 0)
    {
        cout << order[i] << " " << counts[i] << endl;
        i++;
    }

    return 0;
}
