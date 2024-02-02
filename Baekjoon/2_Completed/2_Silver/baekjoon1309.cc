// 실버 1 - 1309번 : 동물원
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>

using namespace std;

// 1행이 확장될 때마다
// 1) 사자를 배치하지 않는 경우
// 2) 왼쪽에만 사자를 배치하는 경우
// 3) 오른쪽에만 사자를 배치하는 경우

// ==
// 이전 행에 사자가 배치되지 않은 경우 -> 위 3가지 경우 다 가능
// 이전 행의 왼쪽에만 사자 배치 -> 1과 3만 가능
// 이전 행의 오른쪽에만 사자 배치 -> 1과 2만 가능

// 규칙으로 공식은 찾았는데 연관성을 잘 모르겠음.

// f(n) = 2f(n-1) + f(n-2)
// 0  1  2  3  4
// 1  3  7 17 41

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    int N;
    cin >> N;

    vector<int> cases(N + 1, 1);

    // f(n) = 2f(n-1) + f(n-2)
    for(int i = 1; i < N + 1; i++)
    {
        // 1번째는 공식에 적용되지 않음.
        if(i == 1)
        {
            cases[1] = 3;
        }

        else
        {
            cases[i] = 2 * cases[i - 1] + cases[i - 2];
            cases[i] %= 9901;
        }
    }

    // 출력
    cout << cases[N] << "\n";
}