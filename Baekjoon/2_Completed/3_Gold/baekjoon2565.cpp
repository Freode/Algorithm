// 골드 5 - 2565번 : 전깃줄
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

// LIS
// N <= 100
// 전깃줄이 하나씩 추가되기
// 같은 위치에 두 개 이상 전깃줄은 없음.

// 서로 교차하지 않게 하기 위해 없애야 하는 전깃줄의 최소 개수

// 교차 조건. y기준 오름차순 정렬했을 때, n.x > n.x+1

using namespace std;

struct Line
{
    int y = 0;
    int x = 0;
    int cnt = 1;

    bool operator<(const Line& other) const
    {
        return y < other.y;
    }
};

vector<Line> g_lines;

void initData(const int N)
{
    g_lines = vector<Line>(N);

    for(Line& line : g_lines)
    {
        cin >> line.y >> line.x;
    }
}

// 교차하지 않는 선의 개수 구하기
int simulate(const int N)
{
    sort(g_lines.begin(), g_lines.end());

    // 선이 하나씩 계속해서 추가되었을 때, 교차하지 않는 선의 개수
    int max_cnt = 0;

    // 선이 하나씩 추가되어서 시뮬
    for(int i = 0; i < N; i++)
    {
        
        for(int j = 0; j < i; j++)
        {
            // 교차하지 않는 선의 개수 구하기
            // j가 앞, i가 뒤
            if(g_lines[j].x < g_lines[i].x)
                g_lines[i].cnt = max(g_lines[i].cnt, g_lines[j].cnt + 1);
        }
        max_cnt = max(max_cnt, g_lines[i].cnt);
    }

    return max_cnt;
}


int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 전깃줄 개수 N
    int N;
    cin >> N;

    initData(N);
    cout << N - simulate(N) << "\n";
}