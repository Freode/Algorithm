// 골드 3 - 1005번 : ACM Craft
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 건물 짓는 순서가 정해져 있지 않음
// 즉, 첫 번째 게임과 두 번째 게임 건물 짓는 순서 다를 수 있음.

// 게임 시작 -> 건물 짓는 순서
// 모든 건물 : 건설 완성까지 Delay 존재

// ==예제==
// 1->(2,3)동시 진행 가능 -> 4
// 4번 (2,3) 모두 건설 완료되어야 함.
// 1(10), 2(1), 3(100), 4(10) -> 4번까지 건설 완료 : 총 120초 소요

// 모든 경기 -> 특정 건물만 짓는다면, 무조건 게임에서 이길 수 있음.
// 게임마다 특정건물 짓기 위한 순서가 달라짐
// 특정 건물을 가장 빨리 지을 때까지 걸리는 최소시간 알아내기

// ==입력==
// 테스트 케이스 개수 T
// 첫 번째 줄 : 건물 개수 N, 건물 순서 규칙 K개
// 건물 1~N번 존재
// 두 번째 줄 : 각 건물 당 건설에 걸리는 시간 : D1, D2, ... Dn
// 세 번째 줄 ~ K+2번째 줄 : 건설 순서(X Y) -> X를 지은 다음 Y 짓기 가능
// 마지막 줄 : 건설해야 할 건물 번호 W

// ==출력==
// 10^5 * 10^5 -> 100억 : ll

// 사전 건설 조건이 필요없는 건물들을 모음.
// 해당 건물들을 시작으로 검사 시작

typedef long long ll;

struct Info
{
    ll total_time = -1;
    int build_time = 0;
    vector<int> g_pre_buildings;

    Info()
    {
        g_pre_buildings = vector<int>(1000);
    }
};

vector<Info> g_building;

// 건물 건설 시간 입력
void inputBuildTime(const int N)
{
    g_building.resize(N+1);
    for(int i = 1; i <= N; i++)
    {
        g_building[i].total_time = -1;
        g_building[i].g_pre_buildings.resize(0);

        cin >> g_building[i].build_time;
    }
}

// 건설 순서 입력
void inputSequnece(const int K)
{
    int pre, post;
    for(int i = 0; i < K; i++)
    {
        cin >> pre >> post;
        g_building[post].g_pre_buildings.push_back(pre);
    }
}

// 해당 건물 번호로 이동해서 검사
void move(const int post, const int idx)
{
    // 만약에 사전 건물이 없는 경우
    if(g_building[idx].g_pre_buildings.size() == 0)
    {
        g_building[idx].total_time = g_building[idx].build_time;
    }

    // 사전 건물로 이동
    for(const int& pre : g_building[idx].g_pre_buildings)
    {
        // 사전 건물 비용이 없는 경우, 이동
        if(g_building[pre].total_time == -1)
            move(idx, pre);

        // 사전 건물 비용이 있는 경우, 바로 계산
        g_building[idx].total_time = max(g_building[idx].total_time, g_building[pre].total_time + g_building[idx].build_time);
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 테스트 케이스 T
    int T;
    cin >> T;

    g_building = vector<Info>(1001);

    for(int i = 0; i < T; i++)
    {
        // 건물 개수 N, 건물 순서 규칙 K개
        int N, K;
        cin >> N >> K;

        inputBuildTime(N);
        inputSequnece(K);

        // 건설해야 할 건물 번호 W
        int W;
        cin >> W;

        move(0, W);

        cout << g_building[W].total_time << "\n";
    }
}