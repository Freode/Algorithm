// 골드 1 - 1045번 : 도로
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 모든 도시는 연결되어 있는 상태 (한 그룹으로 되어야 함.)
// 튜플 -> 같은 위치의 요소끼리 비교했을 때, 더 작으면 우선순위가 높음.
// M개 만큼 연결된 도로를 선택해야 함. 그렇지 않으면, -1
// 모든 도시를 연결하지 못하면, -1

struct Road
{
    int start = 0;
    int end = 0;
    bool b_use = false;
};

vector<int> g_parents;
vector<int> g_road_cnts;
vector<Road> g_road_checks;

int findParent(const int idx)
{
    // 그룹에 있는 최상단 부모 노드를 찾은 경우, 바로 반환
    if(g_parents[idx] == idx)
        return idx;

    g_parents[idx] = findParent(g_parents[idx]);
    return g_parents[idx];
}

// 같은 그룹으로 묶기
bool unionCity(const int idx_a, const int idx_b)
{
    int p_a = findParent(idx_a);
    int p_b = findParent(idx_b);

    // 부모가 같으면, 이미 같은 그룹이므로 더 이상 추가 작업이 필요하지 않음.
    if(p_a == p_b)
        return false;

    g_parents[max(p_a, p_b)] = min(p_a, p_b);
    return true;
}

void init(const int N, const int M)
{
    g_parents = vector<int>(N, 0);
    g_road_cnts = vector<int>(N, 0);
    g_road_checks.reserve(M);

    for(int i = 0; i < N; i++)
        g_parents[i] = i;
}

void inputData(const int N, const int M)
{
    string input;

    for(int i = 0; i < N; i++)
    {
        cin >> input;
        for(int j = i + 1; j < N; j++)
        {
            if(input[j] == 'Y')
                g_road_checks.push_back({i, j});
        }
    }
}

bool simulate(const int N, const int M)
{
    // 도로 개수가 더 적을 때, -1을 반환
    if(g_road_checks.size() < M)
    {
        cout << "-1\n";
        return false;
    }

    // MST를 만족하면서, 도로 선택
    int m = 0;
    for(Road& road : g_road_checks)
    {
        if(m == M)
            return true;

        // 다른 그룹일 때만, 도로를 선택하기
        if(unionCity(road.start, road.end) == false)
            continue;

        g_road_cnts[road.start]++;
        g_road_cnts[road.end]++;
        road.b_use = true;
        m++;
    }

    // 도로의 개수를 더 추가할 수 있는 경우에는, 우선순위를 바탕으로 추가
    for(const Road& road : g_road_checks)
    {
        if(road.b_use == true)
            continue;

        if(m == M)
            return true;

        g_road_cnts[road.start]++;
        g_road_cnts[road.end]++;
        m++;
    }

    return true;
}

void printResult(const int N, const int M)
{
    for(int i = 0; i < N; i++)
    {
        // 모두 다 같은 그룹이 아닌 경우면, -1 출력
        if(findParent(g_parents[i]) != 0)
        {
            cout << "-1\n";
            return;
        }
    }

    for(const int& each : g_road_cnts)
        cout << each << " ";
    cout << "\n";
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 도시 N, 도로 M
    int N, M;
    cin >> N >> M;

    init(N, M);
    inputData(N, M);
    bool b_result = simulate(N, M);
    if(b_result == true)
        printResult(N, M);
}