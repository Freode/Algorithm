// 골드 3 - 1719번 : 택배
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_VALUE = 30'000'000;

vector<vector<int>> g_costs;
vector<vector<int>> g_connects;

// 최단 경로로 가기 위해서, 먼저 이동해야하는 집게장 번호 출력
// 플로이드 워셜 한 번 진행 후, 먼저 방문해야하는 집게장 번호 검사

void inputData(const int n, const int m)
{
    g_costs = vector<vector<int>>(n+1, vector<int>(n+1, MAX_VALUE));
    g_connects = vector<vector<int>>(n+1, vector<int>(n+1, 0));

    int start, end, cost;
    for(int i = 0; i < m; i++)
    {
        cin >> start >> end >> cost;

        // 양쪽 연결
        g_costs[start][end] = min(g_costs[start][end], cost);
        g_costs[end][start] = min(g_costs[end][start], cost);

        // 바로 목적지까지 이동할 수 있다고 설정
        g_connects[start][end] = end;
        g_connects[end][start] = start;
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
                // 시작과 도착이 같을 때는 무시
                if(end == start)
                    continue;

                // 새로운 중간점을 통해 이동할 수 있을 때, 
                if(g_costs[start][end] > g_costs[start][mid] + g_costs[mid][end])
                {
                    g_costs[start][end] = g_costs[start][mid] + g_costs[mid][end];
                    g_connects[start][end] = mid;
                }
            }
        }
    }
}

// 최단거리로 가기 위해 먼저 이동해야하는 집게장 구하기
void findFirstConnects(const int n)
{
    for(int start = 1; start <= n; start++)
    {
        for(int end = 1; end <= n; end++)
        {
            int mid = end;
            while(mid != g_connects[start][mid])
            {
                mid = g_connects[start][mid];
            }
            g_connects[start][end] = mid;
        }
    }
}

void printConnects(const int n)
{
    for(int start = 1; start <= n; start++)
    {
        for(int end = 1; end <= n; end++)
        {
            if(start == end)
                cout << "- ";

            else
                cout << g_connects[start][end] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 집하장 개수 n, 경로 개수 m
    int n, m;
    cin >> n >> m;

    inputData(n, m);
    simulate(n);
    findFirstConnects(n);
    printConnects(n);
}