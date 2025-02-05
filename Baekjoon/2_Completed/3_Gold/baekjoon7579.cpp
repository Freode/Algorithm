// 골드 3 - 7579번 : 앱
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_COST 10001

// 앱 정보 구조체
struct Info
{
    int memory = 0;
    int cost = 0;
};

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    int N, M;
    cin >> N >> M;

    // 앱 정보 입력
    vector<Info> apps(N);

    for(Info& app : apps)
    {
        cin >> app.memory;
    }
    for(Info& app : apps)
    {
        cin >> app.cost;
    }

    // 앱 개수 * 비용 최대치
    vector<vector<int>> max_memory(N, vector<int>(MAX_COST, 0));
    int result = MAX_COST;

    for(int item_num = 0; item_num < N; item_num++)
    {
        for(int check_cost = 0; check_cost < MAX_COST; check_cost++)
        {
            // 현재 비용으로 앱 종료 불가능
            // 이 경우에는 현재까지 종료한 앱의 메모리 크기로만은 메모리 확보가 절대로 되지 않음
            if(apps[item_num].cost > check_cost)
            {
                // 첫 앱은 무시
                if(item_num == 0) continue;

                // 두 번째 앱부터 이전 앱의 최대 메모리 값을 가져옴
                max_memory[item_num][check_cost] = max_memory[item_num-1][check_cost];
            }

            // 현재 비용으로 앱 종료 가능
            else
            {
                int cur_memory = apps[item_num].memory;
                int cur_cost = apps[item_num].cost;

                // 첫 앱인 경우
                if(item_num == 0)
                {
                    max_memory[item_num][check_cost] = cur_memory;
                }

                // 두 번째 앱부터는 추가
                else
                {
                    // 하지만, 현재 앱을 종료하는 경우와 아닌 경우를 비교
                    max_memory[item_num][check_cost] = max(max_memory[item_num-1][check_cost], max_memory[item_num-1][check_cost-cur_cost] + cur_memory);
                }

                // 만약에 현재까지 종료된 앱들의 메모리 총합이 M 바이트 이상 확보한 경우면, 종료
                if(max_memory[item_num][check_cost] >= M)
                {
                    result = min(result, check_cost);
                    break;
                }
            }
        }
    }

    // 출력
    cout << result << "\n";
}