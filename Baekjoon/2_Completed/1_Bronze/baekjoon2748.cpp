// 브론즈 1 - 2748번 : 피보나치 수 2
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    int n;
    cin >> n;

    // 할당
    vector<long long> cases(n+1, 0);
    cases[1] = 1;

    // 피보나치 수 구하기
    for(int i = 2; i <= n; i++)
    {
        cases[i] = cases[i-1] + cases[i-2];
    }

    // 정답
    cout << cases[n] << "\n"; 
}