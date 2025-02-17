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
    unordered_map<int, int> nums_two_valid(N*N);
    int max_num = 0;
    for(int& num : nums){ cin >> num; }
    sort(nums.begin(), nums.end());

    // 미리 두 수를 정해서 더하기
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            nums_two_valid[nums[i] + nums[j]] = 1;
        }
    }

    // two_sum + nums[z] = nums[k];
    // nums[k] - nums[z] -> nums_two_valid 체크

    // 최댓값 찾아야하므로 가장 큰 값 - 작은 값 순서대로 빼기
    for(int k = N-1; k >= 0; k--)
    {
        for(int z = 0; z < N; z++)
        {
            // 존재하는 경우 멈춤
            if(nums_two_valid[nums[k] - nums[z]] == 1)
            {
                cout << nums[k] << "\n";
                return 0;
            }
        }
    }
}