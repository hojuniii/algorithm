#include <iostream>
#include <string>
using namespace std;

int main()
{
    int count;
    cin >> count;

    while (count--)
    {
        string str;
        cin >> str;

        char first = *str.begin();
        char end = *(str.end() - 1);

        cout << first << end << endl;
    }
}