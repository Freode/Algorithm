// 골드 5 - 2467번 : 용액
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_VALUE 2000000001

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 사용할 개수
    int N;
    cin >> N;

    // 수 입력
    vector<int> nums(N);
    for(int& num : nums)
    {
        cin >> num;
    }

    int left = 0;
    int right = N-1;

    int result_left, result_right, sums = MAX_VALUE;

    while(left < right)
    {
        int two_sum = nums[left] + nums[right];

        // 0에 가까워 새로 초기화
        if(abs(two_sum) < sums)
        {
            sums = abs(two_sum);
            result_left = left;
            result_right = right;
            
            // 0일 경우, 멈추기
            if(two_sum == 0) break;
        }

        // 합이 음수일 경우
        // 0으로 가까이 하기 위해서 왼쪽 위치를 오른쪽으로 한 칸 이동
        if(two_sum < 0) left++;

        // 합이 양수일 경우
        // 0으로 가까이 하기 위해서 오른쪽 위치를 왼쪽으로 한 칸 이동
        else right--;
    }

    cout << nums[result_left] << " " << nums[result_right] << "\n";
}
