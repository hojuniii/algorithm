#include <iostream>
using namespace std;

int main()
{
    int count;
    cin >> count;

    int answer = count;

    for (int i = 0; i < count; i++)
    {
        int checked[26] = {
            0,
        };

        string word;
        cin >> word;

        for (int j = 0; j < word.length(); j++)
        {
            char a = word[j];
            while (true)
            {
                if (j == word.length() - 1)
                    break;

                if (a == word[j + 1])
                    j++;
                else
                    break;
            }

            if (checked[a - 97] == 0)
                checked[a - 97] = 1;
            else
            {
                answer--;
                break;
            }
        }
    }

    cout << answer;
}