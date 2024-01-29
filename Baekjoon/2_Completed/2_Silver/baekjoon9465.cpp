// 실버 1 - 9465번 : 스티커
// 작성자 : free4760

#include <iostream>
#include <vector>
#include <algorithm>

// 왼쪽에서 오른쪽으로 진행 (열 기준)
// 1행 n열 -> 2행 n-2열 또는 2행 n-1열
// 2행 n열 -> 1행 n-2열 또는 1행 n-1열

using namespace std;

int main()
{
	// 입출력 최적화
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 테스트 개수
	int T;

	cin >> T;

	vector<vector<int>> eachScore;
	vector<vector<int>> totalScore;

	int n;
	int maxScore;

	for (int i = 0; i < T; i++)
	{
		cin >> n;

		// 각 스티커 점수 및 총합 점수 초기화
		eachScore.clear();
		totalScore.clear();

		eachScore.resize(2);
		totalScore.resize(2);

		for (int j = 0; j < 2; j++)
		{
			eachScore[j].resize(n, 0);
			totalScore[j].resize(n, 0);

			// 각 스티커 점수 입력
			for (int k = 0; k < n; k++)
			{
				cin >> eachScore[j][k];
			}
		}
		
		maxScore = 0;
		// 계산
		for (int j = 0; j < n; j++)
		{
			// 조건 : j가 2보다 크면 n행 j-2열 선택 가능, j가 1보다 크면 n행 j-1열 선택 가능

			// 1행 j열 = 2행 j-1열 스티커 선택 또는 2행 j-2열 스티커 선택 
			totalScore[0][j] = max((j > 0 ? totalScore[1][j - 1] : 0), (j > 1 ? totalScore[1][j - 2] : 0)) + eachScore[0][j];

			// 2행 j열 = 1행 j-1열 스티커 선택 또는 1행 j-2열 스티커 선택
			totalScore[1][j] = max((j > 0 ? totalScore[0][j - 1] : 0), (j > 1 ? totalScore[0][j - 2] : 0)) + eachScore[1][j];

			// 최댓값 찾기
			if (max(totalScore[0][j], totalScore[1][j]) > maxScore)
			{
				maxScore = max(totalScore[0][j], totalScore[1][j]);
			}
		}

		cout << maxScore << "\n";
	}
}