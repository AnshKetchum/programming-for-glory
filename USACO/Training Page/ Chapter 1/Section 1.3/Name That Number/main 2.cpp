/*****
ID: INSERT_ID_HERE
LANG: C++
PROG: namenum
**/
#include <bits/stdc++.h>
using namespace std;

set <string> dictionary;
queue <string> ans;
string possibleLetters[12],n;
char curName[12];
bool usedLetter[26];

void fillDictionary() //Fills the dictionary
{
    ifstream cin("dict.txt");
    while(!cin.eof())
    {
        string in; cin >> in;
        dictionary.insert(in);
    }
}

void solve(int x) //Recursive method that checks all possible combinations
{
    if(x == n.length())
    {
        string s;
        for(int i = 0; i < n.length(); i++)
            s += curName[i];
        if(dictionary.find(s) != dictionary.end())
           ans.push(s);
        return;
    }
    for(int i = 0; i < 3; i++)
    {
        curName[x] = possibleLetters[x][i];
        solve(x + 1);
    }
}

int main()
{
    fillDictionary(); //Updates the dictionary
    ifstream cin("namenum.in");
    ofstream cout("namenum.out");
    cin >> n;

    for(int i = 0; i < n.length(); i++)
    {
        int num = (int)(n[i] - '0');
        for(int j = 0; j < 3; j++)
        {
            char letter = (char)(65 + (num - 2) * 3  + j);
            if(letter == 'Q' || letter == 'R') letter++;
            possibleLetters[i] += letter;
        }
    }

    solve(0);
    if(ans.size() == 0) cout << "NONE" << endl;
    while(ans.size() != 0)
    {
        cout << ans.front() << endl;
        ans.pop();
    }
    return 0;
}
