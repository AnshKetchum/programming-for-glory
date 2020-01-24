#include <bits/stdc++.h>
using namespace std;
#define FASTIO 	ios_base::sync_with_stdio(nullptr); cin.tie(nullptr); cout.tie(nullptr);

int n;
bool is_prime(int v)
{
    if(v < 2)
        return false;

    for(int i = 2; i <= sqrt(v); i++)
        if(n % i == 0)
            return false;
    return true;
}

bool check(string str)
{
    if(str == "")
        return true;
    return is_prime(stoi(str));
}

int main()
{
    FASTIO

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        bool good = false;
        string str; cin >> str;
        for(int i = 0; i < str.length() - 1 && !good; i++)
            if(check(str.substr(0,i)) && check(str.substr(i,str.length() - i)))
                good = true;
        cout << (good ? "YES" : "NO") << endl;
    }
    

    return 0;
}