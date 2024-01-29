// 실버 3 - 11727번 : 2×n 타일링 2
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>

// 1*2 타일 선택 -> 남은 칸수 : n-1칸
// 2*1 타일 선택 -> 남은 칸수 : n-2칸
// 2*2 타일 선택 -> 남은 칸수 : n-2칸
// f(n) = f(n-1)+f(n-2)+f(n-2)
// f(0) = 1

using namespace std;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    int n;
    cin >> n;

    // 초기화
    vector<int> cases(n + 1, 0);
    cases[1] = 1;

    // n이 2이상인 경우
    if (n != 1)
    {
        cases[2] = 3;

        for (int i = 3; i < n + 1; i++)
        {
            // f(n) = f(n-1) + f(n-2) + f(n-2)
            cases[i] = cases[i - 1] + cases[i - 2] + cases[i - 2];

            // 나머지 연산
            cases[i] %= 10007;
        }
    }
    // 출력문
    cout << cases[n] << "\n";
}