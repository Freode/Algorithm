// 골드 5 - 2293번 : 동전 1
// 작성자 : free4760

#include <iostream>
#include <vector>

using namespace std;

// 1. 가장 가치가 낮은 동전으로만 조합 ( 1가지 )
// 2. 그 다음 가치가 낮은 동전과의 조합 ( 2가지 )
// 3. 오름차순으로 하나씩 동전 조합을 추가

// f_현재가치 동전(n) = f_이전가치 동전 조합(n) + f_현재가치 동전 조합(n - 현재 추가된 동전 가치)

// n - 현재 추가된 동전 가치가 0 이상일 때만, 추가
// 0 미만이면, 0을 더함.
// f_현재가치 동전(0), f_이전가치 동전 조합(0)은 무조건 1
// n이 5이고 현재 추가된 동전 가치가 5이면, 하나의 경우가 또 추가되기 때문.

// 예제에서 k가 11일 때도 마찬가지
// f_5(11) = f_2(11) + f_5(11-5) = f_2(11) + f_5(6) = 6 + 5 = 11

// 메모리 절약
// 3줄로 표현하기

int main()
{
	// 입출력 최적화
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 입력
	int n, k;

	cin >> n >> k;

	vector<int> coins(n);
	vector<vector<int>> cases(3, vector<int>(k + 1, 1));

	int line = 0;

	// 각 동전 가치 입력
	for (int& each : coins)
	{
		cin >> each;
	}

	// 동전 가치가 제일 낮은 것을 고려
	// 나누어 떨어지지 않을 경우에는 조합하지 못하는 경우이므로 이 때는 0으로 설정
	for (int i = 0; i < k + 1; i++)
	{
		cases[0][i] = (i % coins[0] == 0) ? 1 : 0;
	}

	// 두 번째 동전 가치가 낮은 것부터 계산
	for (int i = 1; i < n; i++)
	{
		// 줄 바꿈과 동시에 범위를 벗어나는 것을 방지
		line = i % 3;

		// 위에 발견한 점화식으로 계산
		// f_추가된 동전 가치(n) = f_추가되지 않았을 때 동전 가치(n) + f_추가된 동전 가치(n - 현재 추가된 동전 가치)
		for (int j = 1; j < k + 1; j++)
		{
			cases[line][j] = cases[(line - 1 >= 0 ) ? line - 1 : 2][j] + (j - coins[i] >= 0 ? cases[line][j - coins[i]] : 0);
		}
	}

	// 출력문
	cout << cases[line][k] << "\n";
}