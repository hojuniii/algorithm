#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int l, c;
bool isVowel[26];
char a[15];
char p[16];

void backtacking(int pos, int prev, int consonant, int vowel)
{
    if (pos == l)
    {
        if (consonant >= 2 && vowel >= 1)
            cout << p << endl;
        return;
    }

    for (int i = prev + 1; i < c; i++)
    {
        p[pos] = a[i];
        backtacking(pos + 1, i, consonant + !isVowel[a[i] - 97], vowel + isVowel[a[i] - 97]);
    }
}

int main()
{
    cin >> l >> c;
    for (int i = 0; i < c; i++)
    {
        cin >> a[i];
    }
    sort(a, a + c);
    isVowel['a' - 97] = true;
    isVowel['e' - 97] = true;
    isVowel['i' - 97] = true;
    isVowel['o' - 97] = true;
    isVowel['u' - 97] = true;

    backtacking(0, -1, 0, 0);
}
