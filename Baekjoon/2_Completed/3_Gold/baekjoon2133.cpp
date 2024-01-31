// 골드 4 - 2133번 : 타일 채우기
// 작성자 : free4760 (jeonghoe22)

#include <iostream>
#include <vector>

using namespace std;

// f(0) = 1;
// f(홀수) = 0;
// 이전꺼로부터 2칸씩 확장
// 2칸에 들어갈 경우의 수는 3가지이므로
// f(n) = 3*f(n-2) + a
// n-1번째 줄과 n-2번째 줄이 동시에 걸쳐 있는 경우 추가
// f(n-2) - f(n-4)
// 3*(f(n-4) - f(n-6)) + 2*f(n-6)
// 두 가지의 규칙을 찾았으나 이유는 모르겠음.

int main()
{
	// 입출력 최적화
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    // 입력
    int N;
    cin >> N;

    // 초기화
    vector<int> cases(N + 1, 0);
    cases[0] = 1;

    // 반복문으로 수식에 따른 경우의 수 구하기
    // 짝수에서만 작동
    for(int i = 2; i < N + 1; i+=2)
    {
        // f(n) = 3*f(n-2) + f(n-2)-f(n-4)
        cases[i] = 3 * cases[i-2];

        // i가 4 이상일 때만 작동
        if(i >= 4)
        {
            cases[i] += (cases[i-2] - cases[i-4]);
        }
    }

    // 출력
    cout << cases[N] << "\n";
}