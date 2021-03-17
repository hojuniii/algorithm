#include <iostream>
#include <string>
#include <vector>

using namespace std;
int answer = 0;

void dfs(vector<int> nums, int target, int sum, int count)
{
    if (count == 5) 
    {
        if (target == sum)
            answer++;
        return;
    }
    dfs(nums, target, sum + nums[count], count + 1);
    dfs(nums, target, sum - nums[count], count + 1);
}

int solution(vector<int> numbers, int target)
{
    dfs(numbers, target, 0, 0);

    return answer;
}