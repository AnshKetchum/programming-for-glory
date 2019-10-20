#include <bits/stdc++.h>
using namespace std;
#define MAX_NUMS 8
#define OP_LIMIT 10000
string s = "",wanted = "",ans = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAa";
typedef pair<string,string> pss;
set <string> visited;

char toChar(int a)
{
    return a + '0';
}
string convert(string first)
{
    char a = first[0];
    char b = first[5];
    char c = first[1];
    char d = first[3];
    char e = first[4];
    char f = first[6];
    char g = first[2];
    char h = first[7];

    string st = "";
    st.push_back(a);
    st.push_back(b);
    st.push_back(c);
    st.push_back(d);
    st.push_back(e);
    st.push_back(f);
    st.push_back(g);
    st.push_back(h);
    return st;
}

void bfs()
{
    queue <pss> enque;
    enque.push(pss("12348765",""));

    while(!enque.empty())
    {
        pss top  = enque.front();
        enque.pop();

        if(top.first == wanted)
        {
           // cout << "Found" << endl;
           // cout << top.second << endl;
            if(ans.length() > top.second.length())
                ans = top.second;
            continue;
        }

        if(visited.count(top.first))
            continue;

        visited.insert(top.first);

        string temp = top.first.substr(4,4) + top.first.substr(0,4);
        enque.push(pss(temp,top.second + "A"));

        temp = top.first[3] + top.first.substr(0,3) + top.first[7] + top.first.substr(4,3);
        enque.push(pss(temp,top.second + "B"));

        temp = convert(top.first);
        enque.push(pss(temp,top.second + "C"));
    }
}


int main()
{
    string revers = "";
    for(int i = 1; i <= 4; i++)
    {
        int a; cin >> a;
        wanted += toChar(a);
    }

    for(int i = 1; i <= 4; i++)
    {
        int a; cin >> a;
        revers = toChar(a) + revers;
    }
    wanted += revers;

    bfs();
    cout << ans.length() << endl;
    cout << ans << endl;
    return 0;
}
