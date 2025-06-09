// 골드 2 - 1486번 : 등산
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <limits>

using namespace std;

// 갔다가 돌아와야 함

const int MAX_VALUE = numeric_limits<int>::max();

struct Loc
{
    int y = 0;
    int x = 0;
    int cost = 0;

    bool operator<(const Loc& other) const
    {
        return cost > other.cost;
    }
};

vector<vector<int>> g_mountains;

void inputData(const int N, const int M)
{
    g_mountains = vector<vector<int>>(N, vector<int>(M));

    string line;
    for(int i = 0; i < N; i++)
    {
        cin >> line;
        for(int j = 0; j < M; j++)
        {
            // 높이 처리
            if(line[j] > 'A' && line[j] < 'Z')
                g_mountains[i][j] = (int)(line[j] - 'A');

            else
                g_mountains[i][j] = (int)(line[j] - 'a') + 26;
        }
    }
}

// 경계 안에 있는지 확인
bool isInBoard(const int N, const int M, const int y, const int x)
{
    return y >= 0 && x >= 0 && y < N && x < M;
}

int simulate(const int N, const int M, const int T, const int D)
{
    vector<vector<int>> g_cases = vector<vector<int>>(N, vector<int>(M, MAX_VALUE));
    g_cases[0][0] = 0;

    priority_queue<Loc> pq;
    pq.push({0, 0, 0});

    while(pq.empty() == false)
    {
        Loc cur = pq.top();
        pq.pop();
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 세로 N, 가로 M, 최대 높이차 T, 총 시간 D
    int N, M, T, D;
    cin >> N >> M >> T >> D;

    inputData(N, M);

}