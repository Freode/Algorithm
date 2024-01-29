// 실버 1 - 1890번 : 점프
// 작성자 : free4760

#include <iostream>
#include <vector>

using namespace std;

// 현재 검사하는 위치에서 몇 칸을 이동하는지 확인하고 
// 이동 위치( 오른쪽 방향, 아래쪽 방향 2가지 )에 이동 경로 경우의 수를 추가
// 이동 위치가 범위 밖일 경우에는 무시
// 현재 검사 위치가 도착점일 경우에는 종료.
// 도착점 경우의 수를 출력

int main()
{
	// 입출력 최적화
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 게임판 크기
	int N;
	cin >> N;

	// 게임판 크기 초기화
	vector<vector<int>> board(N, vector<int>(N, 0));

	// 게임판 입력
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}

	// 경우의 수
	vector<vector<long long>> cases(N, vector<long long>(N, 0));
	// 시작점
	cases[0][0] = 1;

	int tempX, tempY;
	// 게임판 검사
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// 오른쪽 방향으로 이동
			tempX = j + board[i][j];
			// 아래쪽 방향으로 이동
			tempY = i + board[i][j];

			// 오른쪽으로 이동했을 때, 범위 안
			// 현재 위치가 도착점도 아니어야 함.
			if (tempX < N && tempX != j)
			{
				cases[i][tempX] = cases[i][tempX] + cases[i][j];
			}

			// 아래로 이동했을 때, 범위 안
			// 현재 위치가 도착점도 아니어야 함.
			if (tempY < N && tempY != i)
			{
				cases[tempY][j] = cases[tempY][j] + cases[i][j];
			}
		}
	}

	// 출력문
	cout << cases[N - 1][N - 1] << "\n";
}