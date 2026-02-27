// 골드 2 - 20303번 : 할로윈의 양아치
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 울음 소리가 공명하기 전까지 뺏을 수 있는 최대 사탕 수
// K명 미만으로 사탕을 뺏을 수 있는 최대수

// 1. 그룹으로 묶는다
// 2. 1차원 배열 사용 [뺏은 인원]

// 1 2 3 4 5 6 7  8  9  10
// 9 15 4 4 1 5 19 14 20 5
// 1 2 1 4 2 2 7  7  4  2

// 1 : 2 -> 13
// 2 : 4
// 4 : 2
// 7 : 2

struct Child
{
    int count = 0;
    int total_count = 0;
    int group = 0;
    int child_count = 1;
};

struct Group
{
    int child_count = 0;
    int value = 0;
};

vector<Child> g_childs;
vector<Group> g_groups;
vector<int> g_counts;

int findParent(int x)
{
    if(x == g_childs[x].group)
        return x;

    g_childs[x].group = findParent(g_childs[x].group);
    return g_childs[x].group;
}

bool unionGroup(int x, int y)
{
    int px = findParent(x);
    int py = findParent(y);

    if(px == py)
        return false;

    g_childs[max(px, py)].group = min(px, py);
    g_childs[min(px, py)].child_count += g_childs[max(px, py)].child_count;
    g_childs[min(px, py)].total_count += g_childs[max(px, py)].total_count;
    return true;
}

void initData(const int N, const int M)
{
    g_childs = vector<Child>(N + 1);

    for(int i = 1; i <= N; i++)
    {
        cin >> g_childs[i].count;
        g_childs[i].total_count = g_childs[i].count;
        g_childs[i].group = i;
    }

    for(int i = 0; i < M; i++)
    {
        int left, right;
        cin >> left >> right;

        unionGroup(left, right);
    }

    g_groups.reserve(N+1);
    for(int i = 1; i <= N; i++)
    {
        if(i == g_childs[i].group)
            g_groups.push_back({g_childs[i].child_count, g_childs[i].total_count});
    }
}

void simulate(const int N, const int K)
{
    g_counts = vector<int>(K, 0);
    vector<int> temps = vector<int>(K, 0);

    // 그룹 검사 인덱스
    for(int i = 1; i <= g_groups.size(); i++)
    {
        // 뺏은 사람 수 
        for(int j = 0; j < K; j++)
        {
            int prev_child_count = j - g_groups[i - 1].child_count;
            // 처음 뺏거나 뺏을 때 이전에 뺏은 기록이 있을 때만 가능
            if(prev_child_count >= 0 && (g_counts[prev_child_count] != 0 || prev_child_count == 0))
                temps[j] = max(g_counts[j], g_groups[i - 1].value + g_counts[prev_child_count]);
            // 처음 뺏는게 아닌데 이전 기록이 없으면, 못 뺏음 - 기록 유지
        }

        // 중첩 방지
        g_counts = temps;
    }
}

int getResult(const int K)
{
    int result = 0;

    for(int i = 1; i < K; i++)
    {
        result = max(result, g_counts[i]);
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 아이들 수 N, 친구 관계 수 M, 공명하는 수 K
    int N, M, K;
    cin >> N >> M >> K;

    initData(N, M);
    simulate(N, K);
    cout << getResult(K) << "\n";
}