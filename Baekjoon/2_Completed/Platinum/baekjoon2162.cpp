// 플래티넘 5 - 2162번 : 선분 그룹
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

// N : 1~3000
// 각 좌표 : 절댓값 5'000 이내

// 마지막에 두 선분 그룹이 교차해서, 한 그룹이 되는 경우도 고려

struct Loc
{
    int x = 0;
    int y = 0;
};

struct Line
{
    Loc start;
    Loc end;
};

struct Group
{
    int parent = 0;
    Line line;
};

vector<Group> g_parents;

// 외적 구하기
// x1 x2 x3 x1
// y1 y2 y3 y1
int crossProduct(const Line& base, const Loc& other)
{
    int result = 0;

    result = (base.start.x * base.end.y + base.end.x * other.y + other.x * base.start.y) - (base.start.y * base.end.x + base.end.y * other.x + other.y * base.start.x);

    return result;
}

// 선분 사이에 점이 위치하는지 확인
bool between(const Line& base, const Loc& other)
{
    return (min(base.start.x, base.end.x) <= other.x) &&
            (other.x <= max(base.start.x, base.end.x)) &&
            (min(base.start.y, base.end.y) <= other.y) &&
            (other.y <= max(base.start.y, base.end.y));
}

// 선분 교차 판단
bool checkLineCross(const Line& a, const Line& b)
{
    int ab1 = crossProduct(a, b.start);
    int ab2 = crossProduct(a, b.end);
    int ba1 = crossProduct(b, a.start);
    int ba2 = crossProduct(b, a.end);

    // 두 선분이 일직선인 경우
    if(ab1 == 0 && ab2 == 0 && ba1 == 0 && ba2 == 0)
        return between(a, b.start) || between(a, b.end) || between(b, a.start) || between(b, a.end);

    // 점 하나만 다른 선분에 포함되는 경우
    if(ab1 == 0)
        return between(a, b.start);

    if(ab2 == 0)
        return between(a, b.end);

    if(ba1 == 0)
        return between(b, a.start);

    if(ba2 == 0)
        return between(b, a.end);

    // 서로 방향이 모두 반대 -> 교차
    if((ab1 ^ ab2) < 0 && (ba1 ^ ba2) < 0)
        return true;

    return false;
}

// 그룹의 가장 작은 idx인 부모를 찾기
int findParent(const int idx)
{
    if(idx == g_parents[idx].parent)
        return idx;

    g_parents[idx].parent = findParent(g_parents[idx].parent);
    return g_parents[idx].parent;
}

// 그룹 묶기 여부 판단
void simulate(const int N)
{
    g_parents = vector<Group>(N+1);

    for(int i = 1; i <= N; i++)
        g_parents[i].parent = i;

    for(int i = 1; i <= N; i++)
    {
        // 선분 정보 입력
        cin >> g_parents[i].line.start.x >> g_parents[i].line.start.y >> g_parents[i].line.end.x >> g_parents[i].line.end.y;

        // 교차 여부 판단
        for(int j = 1; j < i; j++)
        {
            int pi = findParent(i);
            int pj = findParent(j);

            // 이미 같은 그룹이면, 무시
            if(pi == pj)
                continue;

            // 서로 다른 그룹이면서, 교차 여부 검사
            if(checkLineCross(g_parents[i].line, g_parents[j].line))
            {
                g_parents[max(pi, pj)].parent = min(pi, pj);
            }
            // 교차하지 않으면, 놔두기
        }
    }

    // 그룹 수 판단
    unordered_map<int, int> groups;
    
    for(int i = 1; i <= N; i++)
    {
        groups[findParent(i)]++;
    }

    int max_line_count = 0;
    for(auto each : groups)
    {
        max_line_count = max(max_line_count, each.second);
    }

    cout << groups.size() << "\n";
    cout << max_line_count << "\n";
}


int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 선분 개수 N
    int N;
    cin >> N;

    simulate(N);
}