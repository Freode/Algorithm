// Lv.2 - 12945번 : 피보나치 수
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    // f(0)과 f(1) 추가
    vector<int> nums(1, 0);
    nums.push_back(1);

    // f(n) = f(n-1) + f(n-2)
    for(int i = 2; i <= n; i++)
    {
        nums.push_back((nums[i-1] + nums[i-2]) % 1234567);
    }

    // f(n)
    answer = nums[n];

    return answer;
}