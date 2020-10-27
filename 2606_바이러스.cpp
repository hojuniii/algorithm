#include <iostream>
using namespace std;

int com[101][101];
bool check[101];
int cnt = 0;
int n, m;

void dfs(int v){
    int node = v;
    check[v] = true;

    for(int i = 1; i<=n ; i++){
        if(com[v][i] == true && !check[i]){
            cnt++;
            dfs(i);
        }
    }
}
int main()
{
    
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d %d", &x,&y);
        com[x][y] = 1;
        com[y][x] = 1;
    }

    dfs(1);
    printf("%d", cnt);
    return 0;
}