// 골드 5 - 1025번 : 제곱수 찾기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

// 행의 번호와 열의 번호가 각각 등차수열

vector<vector<int>> g_datas;

void inputData(const int N, const int M)
{
    g_datas = vector<vector<int>>(N, vector<int>(M));
    string input;
    for(int i = 0; i < N; i++)
    {
        cin >> input;
        for(int j = 0; j < M; j++)
        {
            g_datas[i][j] = (int)(input[j] - '0');
        }
    }
}

bool isInBoard(const int N, const int M, const int y, const int x)
{
    return y >= 0 && x >= 0 && y < N && x < M;
}

bool isPow(const int X)
{
    return ((int)sqrt(X) * (int)sqrt(X)) == X;
}

int simulate(const int N, const int M)
{
    int result = -1;

    // 각 칸을 기준으로 검사 시작
    for(int y = 0; y < N; y++)
    {
        for(int x = 0; x < M; x++)
        {
            // 등차 간격(값) 결정하기

            // 행의 등차
            for(int i = -N; i < N; i++)
            {
                // 열의 등차
                for(int j = -M; j < M; j++)
                {
                    // 등차가 없는 경우는 무시
                    if(i == 0 && j == 0)
                        continue;

                    int base = 0;
                    int nextY = y;
                    int nextX = x;
                    while(isInBoard(N, M, nextY, nextX))
                    {
                        // 자릿수 증가
                        base *= 10; 
                        base += g_datas[nextY][nextX];

                        // 제곱수 인지 확인
                        if(isPow(base))
                            result = max(result, base);

                        nextY += i;
                        nextX += j;
                    }
                }
            }
        }
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 행 N, 열 M
    int N, M;
    cin >> N >> M;

    inputData(N, M);
    cout << simulate(N, M) << "\n";
}