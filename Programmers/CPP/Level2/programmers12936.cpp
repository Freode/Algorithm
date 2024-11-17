// Lv.2 - 12936번 : 줄 서는 방법
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    
    // 미리 경우의 수를 계산
    vector<long long> cases(1, 1);
    for(int i = 1; i <= 20; i++)
    {
        cases.push_back(0);
        cases[i] = cases[i-1] * i;
    }

    // 1 ~ 20까지의 수 가지기
    vector<int> nums(20, 0);
    for(int i = 0; i < nums.size(); i++)
    {
        nums[i] = i + 1;
    }
    int num;
    // k--로 나눴을 때, 다음 수로 넘어가는 것을 방지
    k--;
    // 1부터 n까지 추가
    for(int i = n; i > 0; i--)
    {
        // k가 0인 경우에는, 항상 제일 작은 수로 나열하면 됨.
        if(k == 0)
        {
            num = 0;
            answer.push_back(nums[0]);
        }
        // k가 더 크거나 같은 경우
        else
        {
            // cases[i - 1]로 나눠 몇 번째로 큰 값을 사용하면 되는지 알아내기
            num = (int)(k / cases[i - 1]);
            answer.push_back(nums[num]);
        }
        // 현재 사용한 수 제거
        nums.erase(nums.begin() + num);
        k %= cases[i - 1];
    }
    
    return answer;
}