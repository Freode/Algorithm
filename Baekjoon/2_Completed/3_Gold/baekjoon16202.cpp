// 골드 3 - 16202번 : MST 게임
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 최소 스패닝 트리
// 간선을 하나씩 제거하면서 MST 비용 구하기
// 각 턴의 점수 = 해당 턴에서 찾은 MST 비용
// 각 턴 종료 -> 그 턴에서 구한 MST에서 가장 가중치가 작은 간선 하나 제거
// 한 번 제거된 간선은 이후에서도 사용 불가

// 

struct Line
{
    int x = 0;
    int y = 0;
    int val = 0;
    bool use = false;
};

vector<int> g_parents;
vector<Line> g_lines;

int findParnet(int x)
{
    if(x == g_parents[x])
        return x;

    g_parents[x] = findParnet(g_parents[x]);
    return g_parents[x];
}

bool unionGroup(int x, int y)
{
    int px = findParnet(x);
    int py = findParnet(y);

    if(px == py)
        return false;

    g_parents[max(px, py)] = min(px, py);
    return true;
}

void inputData(const int N, const int M)
{
    g_parents = vector<int>(N+1, 0);

    g_lines = vector<Line>(M);
    
    for(int i = 0; i < M; i++)
    {
        cin >> g_lines[i].x >> g_lines[i].y;
        g_lines[i].val = i + 1;
    }
}

void initVisit(const int N)
{
    for(int i = 1; i <= N; i++)
    {
        g_parents[i] = i;
    }
}

bool checkMST(const int N)
{
    int result = 0;

    for(int i = 1; i <= N; i++)
    {
        if(findParnet(i) != 1)
            return false;
    }
    return true;
}

void simulate(const int N, const int M, const int K)
{
    for(int i = 0; i < K; i++)
    {
        // 부모값 초기화
        initVisit(N);

        // MST 찾기
        int cost = 0;
        Line* minLine = nullptr;
        for(Line& line : g_lines)
        {
            if(line.use == true)
                continue;

            if(unionGroup(line.x, line.y) == false)
                continue;

            cost += line.val;

            if(minLine == nullptr)
                minLine = &line;
        }

        int result = 0;
        // MST 찾는데 성공 여부 확인
        if(checkMST(N) == true)
        {
            result = cost;
            minLine->use = true;
        }

        cout << result << " ";
    }
    cout << "\n";
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 정점 개수 N, 간선 개수 M, 턴 개수 K
    int N, M, K;
    cin >> N >> M >> K;

    inputData(N, M);
    simulate(N, M, K);
}