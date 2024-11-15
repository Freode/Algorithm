// Lv.2 - 12902번 : 3 x n 타일링
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>

using namespace std;

int MOD = 1000000007;

int solution(int n) {
    int answer = 0;

    // n이 홀수일 때는 불가능
    // f(2) = 3
    // f(4) = 3*3 + 2
    // f(4) = f(2)에서 3가지 케이스 * (가로 3개 1가지 경우, 가로 1개 & 세로 2개의 2가지 경우)
    // + 2번째, 3번째 줄에서 가로로 눕히는 새로운 경우 2가지
    // f(4) = 11

    // f(6)
    // 1. f(4)로 고정하고 뒤에 2줄을 3가지 케이스로 곱하기 -> f(4) * f(2)
    // 2. f(2)로 고정하고 뒤에 4줄 중 2번째, 3번째 줄을 가로로 눕히는 2가지 경우 -> f(2) * 2
    // + 2~5번째 줄을 모두 가로로 눕히는 2가지 경우 -> 2가지
    // f(6) = f(4) * f(2) + f(2) * 2 + 2 = 33 + 6 + 2 = 41

    // f(8)
    // 1. f(6)에서 f(2)가지 경우 추가 -> f(6) * f(2)
    // 2. f(4)에서 누워있는 2가지 경우로 추가 -> 2 * f(4)
    // 3. f(2)에서 누워있는 2가지 경우로 추가 -> 2 * f(2)
    // 4. 2~7번째 줄이 누운 2가지 경우 추가 
    // f(8) = f(6) * f(2) + f(4) * 2 + f(2) * 2 + 2
    // f(8) = 41 * 3 + 11 * 2 + 3 * 2 + 2 = 123 + 22 + 6 + 2 = 153

    // f(0) = 1로 가정
    // f(n) = f(n-2) * f(2) + 0부터 n-4까지 Sigma(f(k) * 2)

    vector<int> cases(1, 0);
    vector<int> acc_2(1, 0);
    for(int i = 1; i <= n; i++)
    {
        // 홀수인 경우
        if(i % 2 == 1)
        {
            cases.push_back(0);
            acc_2.push_back(0);
        }
        else if(i == 2)
        {
            cases.push_back(3);
            acc_2.push_back(0);
        }
        else
        {
            cases.push_back((cases[i-2] * 3) % MOD);
            acc_2.push_back(((cases[i-4]*2) % MOD + acc_2[i-2]) % MOD);
            cases[i] += acc_2[i];
            cases[i] %= MOD;
        }
    }

    answer = cases[n];

    return answer;
}