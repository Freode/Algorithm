// Lv.2 - 12914번 : 멀리 뛰기
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>

using namespace std;

// f(1) = 1
// f(2) = f(1)에서 1칸 뛰는 경우 + 2칸 뛰기 = 2
// f(3) = f(2)에서 1칸 뛰는 경우 + f(1)에서 2칸 뛰는 경우
// f(4) = f(3)에서 1칸 뛰는 경우 + f(2)에서 2칸 뛰는 경우
// f(n) = f(n-1) + f(n-2)

int MOD = 1234567;

long long solution(int n) {
    long long answer = 0;

    vector<int> cases(n+1, 1);

    // 점화식으로 계산
    for(int i = 2; i <= n; i++)
    {
        cases[i] = (cases[i-1] + cases[i-2]) % MOD;
    }

    answer = cases[n];

    return answer;
}