// 실버 3 - 2579번 : 계단 오르기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 한 계단 or 두 계단
// 연속된 세 개 계단 밟기 금지
// 마지막 계단 밟기

// 1. 두 계단 밟는 경우, 2칸 전에서 밟기
// 2. 한 계단 밟는 경우, 1칸 전 + 3칸 전

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    int n;
    cin >> n;

    // 할당
     vector<int> costs(max(n+1, 3), 0);
     vector<int> results(max(n+1, 3), 0);

     // 비용 입력
     for(int i = 1; i <= n; i++)
     {
        cin >> costs[i];
     }

    // 초기 계산
    results[1] = costs[1];
    results[2] = costs[1] + costs[2];

    // 그 이상 값 계산
    for(int i = 3; i <= n; i++)
    {
        results[i] = max(results[i-2], costs[i-1] + results[i-3]);
        results[i] += costs[i];
    }

    // 결과
    cout << results[n] << "\n";
}