// 골드 2 - 2013번 : 선그리기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

// N : 1~10'000
// float -> 1677만 이상 값에서 부정확
// 소수점 둘째 자리를 정수로 올리면, 최대 100'000 이므로 상관 x

using ll = long long;

struct Loc
{
    ll y = 0;
    ll x = 0;
};

struct Line
{
    Loc start;
    Loc end;
};

vector<int> g_parents;
vector<Line> g_lines;

// CCW
// x1 x2 x3 x1
// y1 y2 y3 y1
ll ccw(const Line& base, const Loc& other)
{
    return ((base.start.x * base.end.y + base.end.x * other.y + other.x * base.start.y) - (base.end.x * base.start.y + other.x * base.end.y + base.start.x * other.y));
}

// 다른 점이 선분 사이에 위치하는지 확인
bool between(const Line& base, const Loc& other)
{
    return (min(base.start.x, base.end.x) <= other.x) &&
        (other.x <= max(base.start.x, base.end.x)) &&
        (min(base.start.y, base.end.y) <= other.y) &&
        (other.y <= max(base.start.y, base.end.y));
}

// 그룹 내 가장 작은 idx(부모) 찾기
int findParent(const int idx)
{
    if(idx == g_parents[idx])
        return idx;

    g_parents[idx] = findParent(g_parents[idx]);
    return g_parents[idx];
}

// 같은 선으로 연결 가능한지 확인
bool checkConnectLine(const Line& a, const Line& b)
{
    ll ab1 = ccw(a, b.start);
    ll ab2 = ccw(a, b.end);
    ll ba1 = ccw(b, a.start);
    ll ba2 = ccw(b, a.end);

    // 평행하면서 일직선 상에 있을 때만, 판단
    if(ab1 == 0 && ab2 == 0 && ba1 == 0 && ba2 == 0)
        return between(a, b.start) || between(a, b.end) || between(b, a.start) || between(b, a.end);

    return false;
}

int simulate(const int N)
{
    // 할당 및 초기화
    g_parents = vector<int>(N+1, 0);
    g_lines = vector<Line>(N+1);

    for(int i = 1; i <= N; i++)
        g_parents[i] = i;

    // 시뮬레이션
    double ax, ay, bx, by;
    for(int i = 1; i <= N; i++)
    {
        // 좌표 입력
        cin >> ax >> ay >> bx >> by;
        ax *= 100.0;
        ay *= 100.0;
        bx *= 100.0;
        by *= 100.0;

        // long long으로 변환해서 입력
        g_lines[i].start.y = static_cast<ll>(round(ay));
        g_lines[i].start.x = static_cast<ll>(round(ax));
        g_lines[i].end.y = static_cast<ll>(round(by));
        g_lines[i].end.x = static_cast<ll>(round(bx));

        // 하나의 선으로 만들 수 있는지 확인
        for(int j = 1; j < i; j++)
        {
            int pi = findParent(i);
            int pj = findParent(j);

            // 같은 선이면, 무시
            if(pi == pj)
                continue;

            // 현재 검사하는 두 선을 기준으로 이을 수 있다고 판단
            if(checkConnectLine(g_lines[i], g_lines[j]))
                g_parents[max(pi, pj)] = min(pi, pj);
        }
    }

    // 선의 개수 구하기
    unordered_map<int, bool> lines;
    for(int i = 1; i <= N; i++)
    {
        lines[findParent(i)] = true;
    }

    return lines.size();
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 선분의 개수 N
    int N;
    cin >> N;

    cout << simulate(N) << "\n";
}