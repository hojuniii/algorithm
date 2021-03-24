#include <string>
#include <vector>

using namespace std;

// [[1, 4], [3, 2], [4, 1]]	        [[3, 3], [3, 3]]	[[15, 15], [15, 15], [15, 15]]

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> answer;
    int n = arr1.size();
    int m = arr2[0].size();

    //첫째 행
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        //열
        for (int j = 0; j < m; j++)
        {
            int temp = 0;
            for (int k = 0; k < arr1[0].size(); k++)
            {
                temp += arr1[i][k] * arr2[k][j];
            }
            v.push_back(temp);
        }
        answer.push_back(v);
    }

    return answer;
}

// [[1, 4], [3, 2], [4, 1]]	[[3, 3], [3, 3]]

int main()
{
    vector<vector<int>> v1;
    vector<vector<int>> v2;

    v1.push_back({1, 4});
    v1.push_back({3, 2});
    v1.push_back({4, 1});

    v2.push_back({3, 3});
    v2.push_back({3, 3});

    solution(v1, v2);
}