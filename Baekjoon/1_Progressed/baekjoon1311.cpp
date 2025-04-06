// 골드 1 - 1311번 : 할 일 정하기 1
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// N명 사람, N개 일
// 1명 당 1개 일을 해야 함.
// 모든 일을 하는데, 필요한 비용의 최솟값 구하기

// [현재 선택된 일의 정보(int)][현재 선택한 사람의 수?] = 현재 선택한 일의 값
// [문제 번호][현재 선택한 사람 번호] -> ?

const int MAX_VALUE = numeric_limits<int>::max();

vector<vector<int>> g_works;

// 일 정보 입력
void input(const int N)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> g_works[i][j];
        }
    }
}

// 정보 계산
int simulate(const int N)
{
    int result = MAX_VALUE;



    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 일의 수 N
    int N;
    cin >> N;

    input(N);

}
