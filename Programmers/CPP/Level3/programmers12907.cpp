// Lv.3 - 12907번 : 거스름돈
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 1. 돈의 종류 - 오름차순
// 2. 가장 싼 동전부터 사용
// 3. 동전 사용 종류를 1개씩 증가

int MOD = 1000000007;

// 
int solution(int n, vector<int> money) {
    int answer = 0;

    // DP
    vector<int> cases(n + 1, 0);
    cases[0] = 1;

    // 동전 오름차순 정렬
    sort(money.begin(), money.end());

    // 사용한 동전 종류를 한 개씩 증가
    for(const int &coin : money)
    {
        // 현재 동전 가격부터 n까지 순환
        for(int i = coin; i <= n; i++)
        {
            // 현재 목표 가격에서 새로운 동전을 한 개 추가할 때, 목표 가격 - 현재 가격의 경우의 수를 더하면 됨
            // 기존 경우 + 새로운 동전을 사용한 경우
            cases[i] = (cases[i] + cases[i - coin]) % MOD;
        }
    }

    answer = cases[n];

    return answer;
}