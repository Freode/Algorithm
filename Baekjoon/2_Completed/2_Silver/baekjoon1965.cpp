// 실버 2 - 1965번 : 상자넣기
// 작성자 : free4760 (jeonghoe22)

#include <iostream>
#include <vector>

using namespace std;

// 초기 경우는 1로 모두 초기화
// 자신의 것을 1개로 처리하기 때문

// n번째에 있는 수에 넣을 수 있는 최대 상자 개수
// f(n) = max( n번째 수보다 작은 수의 값 + 1과 모두 비교, f(n) )

// 모두 비교하는 이유는
// 3 4 2 1 5 6
// 1 2 1 1 3 4
// 와 같은 경우가 있음.

// 예제 1번
// 1 5 2 3 7
// 1 2 2 3 4

// 1 6 2 5 7 3 5 6
// 1 2 2 3 4 3 4 5

int main()
{
	// 입출력 최적화
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    // 입력
    int n;
    cin >> n;

    int max_case = 0;

    vector<int> boxes(n);
    for(int& box : boxes)
    {
        cin >> box;
    }

    // 모든 경우의 수를 1로 초기화
    vector<int> cases(n, 1);

    // f(1) ~ f(n)까지 검사
    for(int i = 1; i < n; i++)
    {
        // 현재 검사하고 있는 수보다 앞에 있는 값들과 모두 비교
        // f(1) ~ f(n-1)
        for(int j = 0; j < i; j++)
        {
            // n번째의 수보다 작은 수라면, 값을 비교
            // f(n) = max(f(j) + 1, f(n))
            if(boxes[j] < boxes[i])
            {
                cases[i] = max(cases[j] + 1, cases[i]);
            }
        }

        // 최대 상자 개수 비교
        if(max_case < cases[i])
        {
            max_case = cases[i];
        }
    }

    // 출력
    cout << max_case << "\n";
}