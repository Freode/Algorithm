// 골드 5 - 24391번 : 귀찮은 해강이
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

// 강의 코드 = 건물 번호
// 입력 N -> 1~10^5
// 건물 쌍(연결) M -> 0~10^5

// 건물 이동 최소

// M줄에 걸쳐서 i번 건물과 j번 건물 이어져 있음.

// 1 3
// 2 5
// 3 4
// union-find 사용해서 같은 부모면, 이동 횟수 증가 없이 이동 가능

using namespace std;

vector<int> g_parents;

int find_parent(const int idx)
{
    if(idx == g_parents[idx])
        return idx;

    g_parents[idx] = find_parent(g_parents[idx]);
    return g_parents[idx];
}

void inputConnects(const int M)
{
    int x, y;
    for(int i = 0; i < M; i++)
    {
        cin >> x >> y;
        // 다른 곳에 이미 연결되어 있는 경우, 해당 그룹의 부모와 연결
        int px = find_parent(x);
        int py = find_parent(y);
        g_parents[max(px, py)] = min(px, py);

    }
}

// 강의 순서 입력 및 시뮬레이션
int simulate(const int N)
{
    int cur_loc = 0;
    int next_loc = 0;
    int count = 0;
    for(int i = 0; i < N; i++)
    {
        cin >> next_loc;

        // 처음 위치할 경우
        if(cur_loc == 0)
            cur_loc = next_loc;

        int p1 = find_parent(cur_loc);
        int p2 = find_parent(next_loc);
        
        // 서로 건물이 이어져 있지 않는 경우
        if(p1 != p2)
            count++;

        cur_loc = next_loc;
    }

    return count;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 강의 개수 N, 건물 쌍 개수 M
    int N, M;
    cin >> N >> M;

    // 할당 및 초기화
    g_parents = vector<int>(N+1);
    for(int i = 1; i <= N; i++)
        g_parents[i] = i;

    inputConnects(M);

    int result = simulate(N);
    cout << result << "\n";
}