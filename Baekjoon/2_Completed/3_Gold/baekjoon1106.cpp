// 골드 4 - 1106번 : 호텔
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_VALUE 1e9

struct City
{
    int cost = 0;
    int effect = 0;
};

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 기본 정보 입력
    int C, N;
    cin >> C >> N;

    // 비용별 효과 -> 고객 수
    vector<int> effects(C + 101, MAX_VALUE);

    // 도시 정보 입력
    vector<City> cities(N);
    for(int i = 0; i < N; i++)
    {
        cin >> cities[i].cost >> cities[i].effect;
        // 첫 비용에 대한 효과 입력
        effects[cities[i].effect] = min(cities[i].cost, effects[cities[i].effect]);
    }

    // 효과에 대한 비용 계산
    for(int i = 0; i < C; i++)
    {
        for(const City &city : cities)
        {
            effects[i + city.effect] = min(effects[i + city.effect], effects[i] + city.cost);
        }
    }

    // 결과 찾기
    int result = MAX_VALUE;
    for(int i = C; i < C + 101; i++)
    {
        result = min(result, effects[i]);
    }

    cout << result << "\n";
}