// 실버 2 - 30205번 : 전역 임무
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 아이템 개수를 별도로 하고, 적에 대한 정보를 오름차순 정렬
// 현재 전투력보다 적의 전투력이 더 클 경우, 아이템 사용
// 남아 있는 아이템이 없는 경우에는 진행 불가 판정
// 아이템은 전투력이 가장 높을 때, 사용하는 것이 좋음

using ll = long long;

vector<vector<int>> g_values;
vector<int> g_items;

void inputData(const int N, const int M)
{
    g_values = vector<vector<int>>(N, vector<int>(M, 0));
    g_items = vector<int>(N, 0);

    int item_cnt = 0;
    for(int i = 0; i < N; i++)
    {
        item_cnt = 0;

        for(int j = 0; j < M; j++)
        {
            cin >> g_values[i][j];
            if(g_values[i][j] == -1)
                item_cnt++;
        }

        g_items[i] = item_cnt;

        // 오름차순으로 정렬
        sort(g_values[i].begin(), g_values[i].end());
    }
}

int simulate(const int N, const int M, const ll P)
{
    ll value = P;

    for(int base = 0; base < N; base++)
    {
        int start_idx = g_items[base];

        // 아이템 정보가 아닌 것부터 검사 시작
        for(int idx = start_idx; idx < M; idx++)
        {
            // 전투력이 김 병장보다 작거나 같을 때, 흡수
            if(g_values[base][idx] <= value)
            {
                value += g_values[base][idx];
            }
            // 전투력이 김 병장보다 클 때, 아이템 사용
            else
            {
                // 아이템이 있는 경우, 전투력 2배
                if(g_items[base] > 0)
                {
                    g_items[base]--;
                    value = (value << 1);
                    // 다시 해당 층의 병사와 전투
                    idx--;
                }
                // 아이템이 없는 경우, 더 이상 진행하지 못하므로 시뮬레이션 종료
                else
                {
                    return 0;
                }
            }
        }

        // 만약에 아이템이 남은 경우, 모두 사용
        value = (value << g_items[base]);
    }

    return 1;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 적군 기지의 수 N, 기지의 층 수 M. 김 병장의 전투력 P
    int N, M;
    ll P;
    cin >> N >> M >> P;

    inputData(N, M);
    cout << simulate(N, M, P) << "\n";
}