#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INDEX(character) character - 'A'
#define MAXN 5505
#define MAX_ALPHABET 27
typedef long long ll;
typedef pair<ll,ll> pll;

int n,m,k,schemeOfPoem[MAX_ALPHABET],value[MAXN];
vector <ll> syllables [MAXN];
ll ans = 1,rhymeCounts[MAXN],combinations[5 * MAXN],multiply;

//Credit to GFG for Fast Expo Method
ll fast_expo(ll base, ll exp) 
{ 
    if (exp == 0) 
        return 1; 
  
    if (exp == 1) 
        return (base % MOD); 
  
    long int t = fast_expo(base, exp / 2); 
    t = (t * t) % MOD; 
  
    // if exponent is even value 
    if (exp % 2 == 0) 
        return t; 
  
    // if exponent is odd value 
    else
        return ((base % MOD) * t) % MOD; 
} 

int main()
{
    ifstream cin("poetry.in"); //File I/O
    ofstream cout("poetry.out");

    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
    {
        int group; cin >> value[i] >> group;
        group--;
        syllables[group].push_back(value[i]); //Creating a list of syllable values per group 
    }

    combinations[0] = 1;
        for(int j = 0; j <= k; j++) // Applying a Knapsack to count combinations
            for(int i = 0; i < n; i++)
                {
                    combinations[j + value[i]] += combinations[j];
                    combinations[j + value[i]] %= MOD;
                }

    for(int i = 0; i <= n; i++)
        for(int j : syllables[i])
            if(k >= j) //Prevents Array Errors (Just a Safety)
            {
                rhymeCounts[i] += combinations[k - j];
                rhymeCounts[i] %= MOD;
            }

    for(int i = 0; i < m; i++) //Counting occurances of each line
    {
        char schemeLetter; cin >> schemeLetter;
        schemeOfPoem[INDEX(schemeLetter)]++;
    }

    for(int i = 0; i < MAX_ALPHABET; i++)
        if(schemeOfPoem[i]) //If there exists a line with the alphabet
        {
            multiply = 0; //Resetting the variable
            for(int j = 0; j < n; j++)
                if(rhymeCounts[j])
                {
                    ll expo  = fast_expo(rhymeCounts[j],schemeOfPoem[i]); //Fast Exponentiation (log n)
                    multiply += expo;
                    multiply %= MOD;   //Remember to take mods!
                }
            ans = (ans * multiply) % MOD; 
        }
    cout << ans << endl;
}   