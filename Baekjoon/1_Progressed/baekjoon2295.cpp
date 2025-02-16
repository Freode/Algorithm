// 골드 4 - 2295번 : 세 수의 합
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long ll;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 집합 개수 N
    int N;
    cin >> N;

    // 수 정보 입력 및 오름차순 정렬
    vector<int> nums(N);
    unordered_map<int, int> nums_valid;
    int max_num = 0;
    for(int& num : nums)
    { 
        cin >> num;
        // 존재하고 있음을 기록
        nums_valid[num] = 1;
        // 최댓값 찾기
        if(num > max_num){ max_num = num; }
    }
    sort(nums.begin(), nums.end());

    // 한 개의 수를 고정
    // 두 개의 수를 합하기
    int max_sum = 0;
    for(int fix = 0; fix < N; fix++)
    {
        int left = 0;
        int right = N-1;

        while(left < right)
        {
            // 현재 검사하는 수는 띄어넘기
            if(left == fix) left++;
            if(right == fix) right--;
            if(left < right == false) break;

            int sum = nums[fix] + nums[left] + nums[right];

            // 합이 집합에 존재하고 최댓값 갱신이 가능한 경우
            if(nums_valid[sum] == 1 && max_sum < sum)
            {
                max_sum = sum;
            }

            // 합이 집합의 최대 수를 넘어가는 경우에는 무시
            if(sum > max_num) break;


        }
    }
}