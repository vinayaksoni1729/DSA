#include <iostream>
#include <vector>
using namespace std;

vector<int> brute_force_string_matc(string text, string patt, int n, int m)
{
    vector<int> matches;
    for (int i = 0; i < (n - m + 1); i++)
    {
        bool match = true;
        for (int j = 0; j < m; j++)
        {
            if (text[i + j] != patt[j])
            {
                match = false;
                break;
            }
        }
        if(match)
            matches.push_back(i);
    }
    return matches;
}

int main()
{
    string text = "ababcabcabababd";
    string patt = "ababd";
    int n = text.length();
    int m=patt.length();
    vector<int> result = brute_force_string_matc(text, patt, n, m);
    for (int i : result) {
        cout << "Pattern found at index " << i << endl;
    }
}