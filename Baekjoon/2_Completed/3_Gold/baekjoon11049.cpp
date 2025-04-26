// 골드 3 - 11049번 : 행렬 곱셈 순서
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// A행렬 : 크기 N x M 과 B행렬 : 크기 NxM -> 곱하기 : NxMxK
// 행렬 N개 (1~500)
// 각 행렬 크기 R,C (1~500)
// 최소 계산 수 구하기

// [행렬 곱 시작 위치][행렬 곱 끝 위치]

// 행렬 연산
// [start][end] => [1][2]
// [1].r * [1].c * [2].c

// 1~3
// (1~1 + 2~3, 1~2 + 3~3) 
// start.r * end.c * 
// 앞 -> start.r * start+1.r * end.c
// 뒤 -> start.r * end-1.c * end.c

// 1~5
// 1~4 + 5~5
// 1~3 + 4~5
// 1~2 + 3~5
// 1~1 + 2~5

// 3 2
// 2 5
// 5 4
// 4 2
// 2 6

// dp[start][mid] + dp[mid+1][end], dp[start][])start.r * mid.c * end.c

const int MAX_SIZE = 501;
const int MAX_VALUE = numeric_limits<int>::max();

struct Matrix
{
    int r = 0;
    int c = 0;
};

vector<vector<int>> g_cases(MAX_SIZE, vector<int>(MAX_SIZE, MAX_VALUE));
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
    int& ref = g_cases[start][end];

    // 이미 있는 경우, 반환
    if(ref != MAX_VALUE)
        return ref;

    // start와 end가 같은 경우는 0 반환
    if(start == end)
        return ref = 0;

    // 없는 경우 계산
    for(int mid = start; mid < end; mid++)
    {
        int temp = simulate(start, mid) + simulate(mid + 1, end);
        temp += (g_matrixs[start].r * g_matrixs[mid].c * g_matrixs[end].c);

        ref = min(ref, temp);
    }

    return ref;
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