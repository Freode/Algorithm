// 실버 3 - 11727번 : 2×n 타일링 2
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// f(n)
// 1. 1*2칸 채우기 : f(n-1)
// 2. 2*1칸 채우기 : f(n-2)
// 3. 2*2칸 채우기 : f(n-2)
// f(n) = f(n-1) + 2f(n-2)

int MOD = 10007;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 입력
    int n;
    cin >> n;

    // 할당
    vector<int> cases(max(n+1, 3), 0);
    cases[1] = 1;
    cases[2] = cases[1] + 2;

    // 계산
    for(int i = 3; i <= n; i++)
    {
        cases[i] = (cases[i-1] + 2 * cases[i-2]) % MOD;
    }

    cout << cases[n] << "\n";
}