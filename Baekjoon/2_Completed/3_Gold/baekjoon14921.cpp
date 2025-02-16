// 골드 5 - 14921번 : 용액 합성하기
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

    // 용액 개수
    int N;
    cin >> N;

    // 용액 정보 입력 - 이미 오름차순인 상태에서 입력됨
    vector<int> liquids(N);
    for(int& liquid : liquids){ cin >> liquid; }

    int near_zero = 200'000'001;
    int result = near_zero;
    int left = 0, right = N-1;

    // 양 쪽에서 검사를 시작
    while(left < right)
    {
        int sum = liquids[left] + liquids[right];

        // 0에 더 가까운 수를 발견
        if(abs(sum) < near_zero)
        {
            near_zero = abs(sum);
            result = sum;

            // 0이면, 종료
            if(sum == 0) break;
        }

        // 합이 음수인 경우, 0에 가깝게 하기 위해 음수의 값을 줄임
        if(sum < 0) left++;
        // 합이 양수인 경우, 0에 가깝게 하기 위해 양수의 값을 줄임
        else right--;
    }

    cout << result << "\n";
}