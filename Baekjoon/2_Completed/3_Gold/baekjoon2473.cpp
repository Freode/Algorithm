// 골드 3 - 2473번 : 세 용액
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 용액 개수
    int N;
    cin >> N;

    // 용액 정보 입력 및 오름차순 정렬
    vector<ll> liquids(N);
    for(ll& liquid : liquids){ cin >> liquid; }
    sort(liquids.begin(), liquids.end());

    // 한 액체 고정 
    // 5000 * 5000 = 25 * 10^6
    ll sum = 3'000'000'001;
    vector<ll> result_nums(3, 0);

    for(int fix = 0; fix < N; fix++)
    {
        int left = 0;
        int right = N-1;

        // 두 용액을 계속해서 선택
        while(left < right)
        {
            // 현재 검사하고 있는 용액은 제외
            if(left == fix) left++;
            if(right == fix) right--;
            if(left < right == false) break;

            // 세 용액 합이 기존보다 0에 가까우면, 
            ll check_sum = liquids[fix] + liquids[left] + liquids[right];
            // 새롭게 초기화
            if(abs(check_sum) < sum)
            {
                sum = abs(check_sum);
                result_nums[0] = liquids[fix];
                result_nums[1] = liquids[left];
                result_nums[2] = liquids[right];

                // 0이면, 그냥 종료
                if(check_sum == 0) break;
            }

            // 음수면, 0에 가깝게 하기 위해서 음수를 줄이기
            if(check_sum <= 0)
            {
                left++;
            }
            // 양수면, 0에 가깝게 하기 위해서 양수를 줄이기
            else
            {
                right--;
            }
        }
    }

    // 결과를 오름차순으로 정렬
    sort(result_nums.begin(), result_nums.end());

    // 출력
    cout << result_nums[0] << " " << result_nums[1] << " " << result_nums[2] << "\n";
}