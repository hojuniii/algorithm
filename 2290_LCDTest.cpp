#include <iostream>
#include <string>
using namespace std;
#define a '-'
#define b '|'

string one(int s)
{
    string str = "";
    for (int i = 0; i < s; i++)
    {
        str += '\n';
        str += b;
        str += '\n';
        str += b;
        str += '\n';
    }
    str+='\n';
    return str;
}

string two(int s){
    
}

int main()
{
    int s, n;
    cin >> s >> n;
    cout<<one(s);
}