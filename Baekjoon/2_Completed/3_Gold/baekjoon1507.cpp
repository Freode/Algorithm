// 골드 4 - 1507번 : 궁금한 민호
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

vector<vector<int>> g_roads;
vector<vector<bool>> g_uses;

void inputData(const int N)
{
    g_roads = vector<vector<int>>(N+1, vector<int>(N+1, 0));
    g_uses = vector<vector<bool>>(N+1, vector<bool>(N+1, true));

    for(int start = 1; start <= N; start++)
    {
        for(int end = 1; end <= N; end++)
        {
            cin >> g_roads[start][end];
        }
    }
}

bool simulate(const int N)
{
    for(int mid = 1; mid <= N; mid++)
    {
        for(int start = 1; start <= N; start++)
        {
            for(int end = 1; end <= N; end++)
            {
                // 출발지와 도착지가 같은 경우는 무시
                if(start == end || start == mid || end == mid)
                    continue;

                // 중간에 거쳐가는 도시가 있는 경우, 출발지와 도착지를 직접 이어가는 도로 제거
                if(g_roads[start][end] == g_roads[start][mid] + g_roads[mid][end])
                    g_uses[start][end] = false;

                // 중간에 거쳐가는 경우가 더 빠르지만, 현재 출발지와 도착지를 직접 이어가는 도로 정보가 있는 경우
                // 현재 입력 데이터는 모든 도로의 개수가 최솟값이므로, 최적의 경우에서 위와 같은 경우는 모순 발생
                else if(g_roads[start][end] > g_roads[start][mid] + g_roads[mid][end])
                    return false;
            }
        }
    }

    return true;
}

void printResult(const int N)
{
    int result = 0;

    // 출발지와 도착지가 서로 반대인 경우는 중복되므로 제거하고 검사
    for(int start = 1; start < N; start++)
    {
        for(int end = start + 1; end <= N; end++)
        {
            if(g_uses[start][end] == true)
                result += g_roads[start][end];
        }
    }

    cout << result << "\n";
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 도시의 개수 N
    int N;
    cin >> N;

    inputData(N);
    if(simulate(N))
        printResult(N);
    else
        cout << "-1\n";
}