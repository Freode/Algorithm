// 골드 2 - 11780번 : 플로이드 2
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int MAX_VALUE = (numeric_limits<int>::max() >> 1);

vector<vector<int>> g_costs;
vector<vector<int>> g_mids;
vector<int> g_path;

void inputData(const int n, const int m)
{
    g_costs = vector<vector<int>>(n+1, vector<int>(n+1, MAX_VALUE));
    g_mids= vector<vector<int>>(n+1, vector<int>(n+1, 0));

    // 경로에 대한 최소 비용으로 입력
    int start, end, cost;
    for(int i = 0; i < m; i++)
    {
        cin >> start >> end >> cost;

        g_costs[start][end] = min(g_costs[start][end], cost);
    }
}

void simulate(const int n)
{
    for(int mid = 1; mid <= n; mid++)
    {
        for(int start = 1; start <= n; start++)
        {
            for(int end = 1; end <= n; end++)
            {
                // 시작점과 출발점이 같으면, 무시
                if(start == end)
                    continue;

                // 경로가 없는 경우는 무시
                if(g_costs[start][mid] == 0 || g_costs[mid][end] == 0)
                    continue;    

                // 기존과 중간점인 mid를 통해서 이동하는 비용 비교
                if(g_costs[start][end] > g_costs[start][mid] + g_costs[mid][end])
                {
                    g_costs[start][end] = g_costs[start][mid] + g_costs[mid][end];
                    
                    // start부터 end로 이동할 때, mid 지점을 방문한다고 기록
                    g_mids[start][end] = mid;
                }
            }
        }
    }
}

void printAllLine(const int n)
{
    for(int start = 1; start <= n; start++)
    {
        for(int end = 1; end <= n; end++)
        {
            // 도달하지 못하는 경우, 0으로 변환
            if(g_costs[start][end] == MAX_VALUE)
                g_costs[start][end] = 0;

            cout << g_costs[start][end] << " ";
        }
        cout << "\n";
    }
}

void findPath(const int start, const int end)
{
    // 더 이상 중간 경로가 없는 경우
    if(g_mids[start][end] == 0)
    {
        g_path.push_back(start);
        g_path.push_back(end);
        return;
    }

    findPath(start, g_mids[start][end]);
    // 시작과 끝이 같은 경우, 중복 제거
    g_path.pop_back();
    findPath(g_mids[start][end], end);

}

void printAllPath(const int n)
{
    for(int start = 1; start <= n; start++)
    {
        for(int end = 1; end <= n; end++)
        {
            g_path.clear();

            // 이동 경로가 있는 경우에만 작동
            if(g_costs[start][end] != 0)
                findPath(start, end);

            // 출발지~도착지의 경로 추적 및 출력
            cout << g_path.size() << " ";

            for(const int& path : g_path)
                cout << path << " ";
            cout << "\n";
        }
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 도시의 개수 n, 버스의 개수 m
    int n, m;
    cin >> n >> m;

    inputData(n, m);
    simulate(n);
    printAllLine(n);
    printAllPath(n);
}