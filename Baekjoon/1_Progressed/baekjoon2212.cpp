// 골드 5 - 2212번 : 센서
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 거리 구조체
struct Distance
{
    int start = 0;
    int end = 0;
    int dist = 0;

    // 생성자
    Distance(){}
    void Init(int _start, int _end)
    {
        start = _start;
        end = _end;
        dist = end - start;
    }
};

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    int N, K;
    cin >> N >> K;

    // 센서 위치
    vector<int> locs(N);
    for(int& loc : locs){ cin >> loc; }

    // 오름차순으로 정렬
    sort(locs.begin(), locs.end());

    vector<Distance> dists(N - 1);
    // 다음 점까지의 거리
    for(int i = 0; i < N - 1; i++)
    {
        dists[i].Init(locs[i], locs[i + 1]);
    }

    sort(dists.begin(), dists.end(), [](Distance a, Distance b) 
    {
        // 거리 내림차순.
        if(a.dist != b.dist) { return a.dist > b.dist; }
        // 거리가 같으면, 시작 지점이 더 높은 순으로 오름차순
        else { return a.start < b.start; }
    });

    // 집중국 위치
    vector<int> focus;

    for(int i = 0; i < N - 1; i++)
    {
        // 집중국 개수 제한
        if((int)focus.size() < K)
        {
            focus.push_back(dists[i]);
        }
    }
}
