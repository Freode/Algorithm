// 실버 1 - 1446번 : 지름길
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 지름길 정보 구조체
struct Shortcut
{
    int start = 0;
    int end = 0;
    int cost = 0;
    Shortcut(){};
    Shortcut(int _start, int _end, int _cost){ start = _start; end = _end; cost = _cost; }
};

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 지름길 개수와 고속도로 입력
    int N, D;
    cin >> N >> D;

    // 지름길 정보 입력
    Shortcut input;
    vector<Shortcut> shortcuts;
    for(int i = 0; i < N; i++)
    {
        cin >> input.start >> input.end >> input.cost;
        shortcuts.push_back(input);
    }

    // 도착점 기준 오름차순 정렬
    sort(shortcuts.begin(), shortcuts.end(), [](Shortcut &a, Shortcut &b) -> 
    bool {
        return a.end < b.end;
    });

    // 현재 도착점을 기준으로 가장 짧은 거리 계산
    vector<int> costs(D+1, 0);
    int shortcut_index = 0, temp = 0;
    for(int i = 1; i < D+1; i++)
    {
        // 바로 이전꺼로부터 이동한 경우
        costs[i] = costs[i-1] + 1;

        // 확인해야할 지름길이 있으면서 현재 지름길로부터 영향을 받는 방법
        while(shortcut_index < (int)shortcuts.size() && i == shortcuts[shortcut_index].end)
        {
            temp = costs[shortcuts[shortcut_index].start] + shortcuts[shortcut_index].cost;
            // 최소로 이동하는 길이면, 변경
            if(temp < costs[i]){ costs[i] = temp; }
            shortcut_index++;
        }
    }
    // 출력
    cout << costs[D] << "\n";
}