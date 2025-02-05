// 골드 5 - 12865번 : 평범한 배낭
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item
{
    int weight = 0;
    int value = 0;
};

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    int N, K;
    cin >> N >> K;

    // 물건 정보 입력
    vector<Item> items(N);

    for(int i = 0; i < items.size(); i++)
    {
        cin >> items[i].weight >> items[i].value;
    }

    vector<vector<int>> max_values(N, vector<int>(K + 1, 0));
    // 물건 담기

    // 최대 무게인 K까지 검사 진행
    for(int case_weight = 1; case_weight <= K; case_weight++)
    {
        // 현재 아이템을 담을 수 있는지 확인
        for(int item_num = 0; item_num < N; item_num++)
        {
            // 현재 아이템 무게가 가방에 담을 수 있는 무게를 넘은 경우
            // 이전 아이템을 담을 수 있는 최대 가치로 설정
            if(items[item_num].weight > case_weight && item_num != 0)
            {
                max_values[item_num][case_weight] = max_values[item_num-1][case_weight];
            }
            // 현재 아이템을 가방에 담을 수 있는 경우
            // 현재 아이템을 안 담는 경우와 현재 아이템을 담는 경우의 가치로 비교
            // DP[n][m] = max(DP[n][m-1], DP[n-1][m-현재 아이템 무게] + 현재 아이템 가치)
            else if(items[item_num].weight <= case_weight)
            {
                int cur_value = items[item_num].value;
                int cur_weight = items[item_num].weight;
                // 첫 번째 아이템은 담는 경우가 가장 가치가 높음
                if(item_num == 0)
                {
                    max_values[item_num][case_weight] = cur_value;
                }
                // 두 번째 아이템부터 담을지 안담을지를 고려
                else
                {
                    max_values[item_num][case_weight] = max(max_values[item_num-1][case_weight], max_values[item_num-1][case_weight-cur_weight] + cur_value);
                }
            }
        }
    }

    // 출력
    cout << max_values[N-1][K] << "\n";
}