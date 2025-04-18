// 골드 3 - 11049번 : 행렬 곱셈 순서
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// A행렬 : 크기 N x M 과 B행렬 : 크기 NxM -> 곱하기 : NxMxK
// 행렬 N개 (1~500)
// 각 행렬 크기 R,C (1~500)
// 최소 계산 수 구하기

// [행렬 곱 시작 위치][행렬 곱 끝 위치]

const int MAX_SIZE = 501;

struct Matrix
{
    int r = 0;
    int c = 0;
};

vector<vector<int>> g_cases(MAX_SIZE, vector<int>(MAX_SIZE, 0));
vector<Matrix> g_matrixs;

// 행렬 정보 입력
void inputMatrix(const int N)
{
    g_matrixs = vector<Matrix>(N+1);

    for(int i = 1; i <= N; i++)
    {
        cin >> g_matrixs[i].r >> g_matrixs[i].c;
    }
}

int simulate(const int start, const int end)
{
    // 이미 있는 경우, 반환
    if(g_cases[start][end] != 0)
        return g_cases[start][end];

    // 없는 경우 계산

    // 1~3 계산
    // 1~2 + 3~3 계산, 2~3 + 1~1 계산

    // 1~4 계산
    // 1~3 + 4~4, 2~4 + 1~1
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 행렬 개수 N
    int N;
    cin >> N;

    // 행렬 정보 입력
    inputMatrix(N);

    int result = simulate(1, N);

    cout << result << "\n";
}