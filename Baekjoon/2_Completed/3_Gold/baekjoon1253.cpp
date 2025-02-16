// 골드 4 - 1253번 : 좋다
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 개수 입력
    int N;
    cin >> N;

    // 수 입력 및 오름차순
    vector<int> nums(N);
    for(int& num : nums){ cin >> num; }
    sort(nums.begin(), nums.end());

    // 좋은 수 판별
    int result = 0;
    for(int idx = 0; idx < N; idx++)
    {
        int left = 0;
        int right = N-1;

        // 양 옆에서부터 찾기
        while(left < right)
        {
            // 현재 좋은 수로 판별하고자 고정하는 수는 무시
            if(left == idx) left++;
            if(right == idx) right--;
            if(left < right == false) break;

            int sum = nums[left] + nums[right];

            // 목표랑 일치하는 경우, 좋은 수 1개 추가
            if(sum == nums[idx])
            {
                result++;
                break;
            }

            // 목표보다 수가 작은 경우, 왼쪽 기준을 한 칸 오른쪽으로 옮김
            if(sum < nums[idx]) left++;
            // 목표보다 수가 큰 경우, 오른쪽 기준을 한 칸 왼쪽으로 옮김
            else right--;
        }
    }
    cout << result << "\n";
}
