// 골드 4 - 1956번 : 운동
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int MAX_VALUE = (numeric_limits<int>::max() >> 1);

vector<vector<int>> g_areas;

void inputData(const int V, const int E)
{
    g_areas = vector<vector<int>>(V+1, vector<int>(V+1, MAX_VALUE));

    // 간선 정보 입력
    int start, end, cost;
    for(int i = 0; i < E; i++)
    {
        cin >> start >> end >> cost;

        g_areas[start][end] = cost;
    }
}

void simulate(const int V)
{
    for(int mid = 1; mid <= V; mid++)
    {
        for(int start = 1; start <= V; start++)
        {
            for(int end = 1; end <= V; end++)
            {
                g_areas[start][end] = min(g_areas[start][end], g_areas[start][mid] + g_areas[mid][end]);
            }
        }
    }
}

int findResult(const int V)
{
    int result = MAX_VALUE;

    // 출발지와 도착지가 같을 때, 사이클 발생
    for(int idx = 1; idx <= V; idx++)
    {
        result = min(result, g_areas[idx][idx]);
    }

    return (result == MAX_VALUE) ? -1 : result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // V개 마을, E개 도로
    int V, E;
    cin >> V >> E;

    inputData(V, E);
    simulate(V);
    cout << findResult(V) << "\n";

}