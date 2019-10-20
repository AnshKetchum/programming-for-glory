/*****
ID: INSERT_ID_HERE
LANG: C++
PROG: crypt1
**/
#include <bits/stdc++.h>
using namespace std;

bool usable[10];
int n;

string toString(int a)  //Returns a string version of the integer
{
    string str = "";
    while(a != 0){
        str = (char)(a % 10 + '0') + str;
        a /= 10;
    }
    return str;
}

bool checkDigits(string str){ //Processes the integer as a string and checks if it is a feasible combination
    for(int i = 0; i < str.length(); i++){
        int converted = str[i] - '0';
        if(!usable[converted]) return false;
    }
    return true;
}

int main()
{
    ifstream cin ("crypt1.in");
    ofstream cout("crypt1.out");
    cin >> n;
    for(int i = 0; i < n; i++){
        int dig; cin >> dig;
        usable[dig] = true;
    }

    int answer = 0;
    for(int i = 100; i < 1000; i++){ //Tries all combinations
        if(checkDigits(toString(i)))
        for(int j = 11; j < 100; j++){
            if(!checkDigits(toString(j))) continue;
            string pp1 = toString(i * (j % 10));
            string pp2 = toString(i * (j / 10));
            //cout << pp1 << " " << pp2 << endl;
            if(pp2.length() == 3 && pp1.length() == 3 && checkDigits(pp1) && checkDigits(pp2)){
                bool works = false;
                string product = toString(i * j);
                works = checkDigits(product);
                if(works) answer++;
            }
        }
    }

    cout << answer << endl;
    return 0;
}
