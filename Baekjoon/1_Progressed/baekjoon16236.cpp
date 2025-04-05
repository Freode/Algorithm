// 골드 3 - 16236번 : 아기 상어
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 같은 거리에 다른 크기의 물고기가 존재 -> 같은 크기의 물고기부터 섭취

// N*N 크기 (최댓값 20)
// 물고기 M마리

// 입력
// 0 : 빈칸, 1~6 : 물고기, 9 : 자기 자신 위치
// 초기 : 자기 자신 크기 2

// 먹을 수 있는 물고기가 존재할 때까지 진행

// 작은 크기의 물고기를 크기만큼의 수량을 먹으면, 크기 1씩 증가
// 1초씩 상하좌우 하나 이동 가능

// 출력 : 물고기를 잡아먹을 수 있는 시간

// 거리 : 칸의 개수 최솟값
// 1마리 -> 해당 물고기로 이동
// 여러 마리 -> 거리가 가장 가까운 몰고기로 이동
// 거리가 같은 물고기 여러 마리 -> 가장 위 -> 그 중에서 가장 왼쪽 


// 더 큰 크기의 물고기여도 해당 칸으로 이동 가능(겹치기 가능)
// 좌표 차이로 바로 이동 -> 이동 시간 더하기

struct Loc
{
    int y;
    int x;
    int dist;

    // 우선순위 큐에 위치 기준 오름차순 정렬
    bool operator<(const Loc& other) const
    {
        // 거리가 짧은 순으로 오름차순
        if(dist != other.dist)
            return dist > other.dist;

        // 가장 위에 있는 y 먼저
        if(y != other.y)
            return y > other.y;

        // 가장 왼쪽에 있는 x 먼저
        return x > other.x;
    }
};

struct Fish
{
    vector<Loc> fishes;
};

vector<Fish> g_fishes;
Loc baby_loc;

// 물고기 정보 입력
void input(const int N)
{
    g_fishes = vector<Fish>(7);

    int fish;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> fish;
            g_fishes[fish].fishes.push_back({i, j, 0});
        }
    }
}

void setTarget(const Loc& start)
{

}

void search(const Loc& start, const int size)
{

}

int simulate()
{
    int result = 0;

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    
}