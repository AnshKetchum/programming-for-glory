/*****
ID: INSERT_ID_HERE
LANG: C++
PROG: zerosum
**/
#include <bits/stdc++.h>
using namespace std;
#define MAX_NUMBERS 15
#define BLANK_OPERATOR 1
#define ADDITION_OPERATOR 2
#define SUBTRACTION_OPERATOR 3

set <string> ans;
string strVersion = "";
int n; //Operators[i] represents operator in between numbers[i] and numbers[i + 1]
vector <int> nums,ops;

string toCharacter(int v)
{
    if(v == ADDITION_OPERATOR)
        return "+";
    else if(v == SUBTRACTION_OPERATOR)
        return "-";
    return " ";

}

int powerOf(int v)
{
    int x = 1;
    while(v > 0)
    {
        v /= 10;
        x *= 10;
    }
    return x;
}

void generateString(vector <int> numbers, vector <int> operators)
{
    strVersion = "";
    for(int i = 0; i < numbers.size(); i++)
    {
        char c = numbers[i] + '0';
        strVersion += c + (operators.size() > i ? toCharacter(operators[i]) : "");
    }
}

int solveEquation(vector <int> numbers, vector <int> operators)
{
    generateString(numbers,operators);

    int ansOfEquation = 0;
    auto f = find(operators.begin(),operators.end(),BLANK_OPERATOR);
    while(f != operators.end())
    {
        int i = f - operators.begin();
        numbers[i] = numbers[i] * (powerOf(numbers[i])) + numbers[i + 1];
        numbers.erase(numbers.begin() + i + 1);
        operators.erase(operators.begin() + i);
        f = find(operators.begin(),operators.end(),BLANK_OPERATOR);
    }

    while(operators.size() > 0)
    {
        switch(operators[0])
        {
        case ADDITION_OPERATOR:
            numbers[0] += numbers[1];
            break;
        case SUBTRACTION_OPERATOR:
            numbers[0] -= numbers[1];
            break;
        }

        numbers.erase(numbers.begin() + 1);
        operators.erase(operators.begin());

    }
    return numbers[0];
}

void solve(int x)
{
    if(x >= n)
    {
        if(solveEquation(nums,ops) == 0)
            ans.insert(strVersion);
        return;
    }

    ops.push_back(ADDITION_OPERATOR);
    solve(x + 1);
    ops.pop_back();

    ops.push_back(SUBTRACTION_OPERATOR);
    solve(x + 1);
    ops.pop_back();

    ops.push_back(BLANK_OPERATOR);
    solve(x + 1);
    ops.pop_back();
}

int main()
{
    ifstream cin("zerosum.in");
    ofstream cout("zerosum.out");
    cin >> n;

    for(int i = 1; i <= n; i++)
        nums.push_back(i);

    solve(1);

    for(string s : ans)
        cout << s << endl;
    return 0;
}
