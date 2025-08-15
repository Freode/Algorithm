// 골드 2 - 1766번 : 문제집
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 1번이 가장 쉬운 문제, N번이 가장 어려운 문제

struct Problem
{
    int count = 0;
    vector<int> nexts;

    Problem()
    {
        nexts.reserve(10);
    }
};

vector<Problem> g_problems;

void initAndInputData(const int N, const int M)
{
    g_problems = vector<Problem>(N+1);

    int prev, next;
    for(int i = 0; i < M; ++i)
    {
        cin >> prev >> next;

        g_problems[next].count++;
        g_problems[prev].nexts.push_back(next);
    }
}

void simulate(const int N)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    
    // 먼저 풀 수 있는 문제 대입
    for(int i = 1; i <= N; i++)
    {
        if(g_problems[i].count == 0)
            pq.push(i);
    }

    while(pq.empty() == false)
    {
        int cur = pq.top();
        pq.pop();

        cout << cur << " ";

        // 다음 문제들 찾기
        for(const int& next : g_problems[cur].nexts)
        {
            g_problems[next].count--;

            // 선행 문제들을 모두 해결한 경우, 추가
            if(g_problems[next].count == 0)
                pq.push(next);
        }
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 문제 수 N, 정보 수 M
    int N, M;
    cin >> N >> M;

    initAndInputData(N, M);
    simulate(N);
}