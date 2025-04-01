// 실버 3 - 11811번 : 데스스타
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 행렬 크기 N (1~1000)
// N개 줄, 행렬 원소인 각 N개의 숫자 (1~10억)

// 조건
// [i][j] : a수열의 i번째 값과 a수열의 j번째 값에 비트연산 and 수행한 결과
// 대각선을 읽을 수 없음
// 항상 답은 존재

// 출력 : 한 줄에 문제의 조건을 만족하는 N개의 음이 아닌 정수
// 각 정수는 10억보다 같거나 작음.
// 답이 여러 개 -> 아무거나

// 입력
// 5
// 0 0 1 1 1
// 0 0 2 0 2
// 1 2 0 1 3
// 1 0 1 0 1
// 1 2 3 1 0

// 2진법
//         a  b  c  d  e
// a와 조합 0  0  1  1  1
// b와 조합 0  0  11 1  11
// c와 조합 1  10 11 1  11
// d와 조합 1  10 11 1  11
// e와 조합 1  10 11 1  11
// 결과     1  2  3  2  3

// 모두 or 연산하면 됨.

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 행렬 크기 N
    int N;
    cin >> N;

    // 행렬 정보 입력
    vector<vector<int>> matrix(N, vector<int>(N));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // a행렬
    vector<int> result(N, 0);

    // 각 원소에 대해서 or 연산
    for(int start = 0; start < N; start++)
    {
        // result의 0번째 = matrix[0~N-1][0]과 검사를 진행하면 됨.
        for(int end = 0; end < N; end++)
        {
            result[start] = result[start] | matrix[end][start];
        }
    }

    // a행렬 출력
    for(const int& each : result)
    {
        cout << each << " ";
    }
    cout << endl;
}