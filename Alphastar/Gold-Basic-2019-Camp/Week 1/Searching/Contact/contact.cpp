#include <bits/stdc++.h>
#include <stdlib.h>     
using namespace std;
#define int long long 
#define MAX_STRING 900000

map <int,int> cnts;
int a,b,n;
string str = "";
vector <string> output [MAX_STRING];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s = "";
    cin >> a >> b >> n;
    while(cin >> s)
      str += s;

    for(int i = 0; i < str.length(); i++)
    {
        int stop = i + b;
        string seq = "1";
        for(int j = i; j < str.length() && j < stop; j++)
        {
            seq += str[j];
            cnts[atol(seq.c_str())]++;
        } 
    }
    

    int c = 0,last = 0;
    for(auto it = cnts.begin(); it != cnts.end(); it++)
    {
        int value = it->second;
        string key = to_string(it->first).substr(1,str.length());

	if(key.length()  < a || key.length() > b)
		continue;
        output[value].push_back(key);
    }
    

    int total = 0;
    for(int i = MAX_STRING - 1; i > 0 && total < n; i--)
        if(!output[i].empty())
        {
            cout << i << endl;
            int six = 0;
            for(string s : output[i])
            {
                cout << s << " ";
                six++;

                if(six % 6 == 0)
                    cout << endl;
            }
            if(six % 6 != 0)
                cout << endl;
            total++;
        } 

    return 0;
}
