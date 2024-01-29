// 실버 3 - 2579번 : 계단 오르기
// 작성자 : free4760

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 방법은 2가지
// 2 계단 오르기
// 2+1 계단 오르기
// total(n) = max(total(n-2) + each(n), total(n-3) + each(n-1) + each(n))

int main()
{
	// 입출력 최적화
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 입력
	int N;

	cin >> N;

	// 각 계단별 점수
	vector<int> eachScore(N + 1, 0);

	// 현재 계단까지의 총합 중 가장 높은 점수
	vector<int> totalScore(N + 1, 0);

	// 각 계단별 점수 입력
	for (int i = 1; i < N + 1; i++)
	{
		cin >> eachScore[i];
	}
	
	// 계단이 한 개
	if (N == 1)
	{
		totalScore[1] = eachScore[1];
	}

	// 계단이 여러개
	else
	{
		totalScore[1] = eachScore[1];
		totalScore[2] = eachScore[1] + eachScore[2];
	}

	// DP
	for (int i = 3; i < N + 1; i++)
	{
		totalScore[i] = max(totalScore[i - 2] + eachScore[i], totalScore[i - 3] + eachScore[i - 1] + eachScore[i]);
	}

	// 결과 출력
	cout << totalScore[N] << "\n";
}