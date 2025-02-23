// 골드 3 - 1082번 : 방 번호
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Money
{
    // 현재 돈으로 어떤 종류의 동전을 살 수 있는지 확인
    vector<int> cases;
    int total = 0;
    bool b_only_zero = true;

    Money()
    {
        for(int i = 0; i < 10; i++)
        {
            cases.push_back(0);
        }
    }

    // 현재 살 수 있는 동전 개수 합
    void SumCases()
    {
        total = 0;
        for(const int& each : cases){ total += each; }
        b_only_zero = (total - cases[0] == 0);
    }
};

// 각 비용별로 살 수 있는 번호 수 검사
void CheckCases(vector<Money> &in_dp, const vector<int> &in_costs, const int in_N, const int in_M)
{
    for(int cur_money = 1; cur_money <= in_M; cur_money++)
    {
        Money cur_best;
        // 각 번호 비용 확인
        for(int num = 0; num < in_N; num++)
        {
            int cost = in_costs[num];
            // 현재 비용이 가지고 있는 돈보다 작은 경우는 무시
            if(cur_money < cost) continue;

            // 일단 복사 후, 해당 숫자를 하나 샀다고 가정
            Money cost_check;
            cost_check.cases = in_dp[cur_money - cost].cases;
            cost_check.cases[num]++;

            // 현재 경우가 가장 좋은 경우인지 판단
            cost_check.SumCases();
            bool is_changed = false;
            // 1. 0의 숫자 개수만 있는 경우는 다른 숫자 있는 것이 더 큼
            // 0이 아닌 다른 것이 하나라도 많은 경우 해당 번호가 더 큰 수

            // 0이 아닌 숫자가 1개라도 있으면, 수를 구성할 수 있음.
            if(cost_check.b_only_zero == false)
            {
                // 1. 이전 수가 0으로만 구성되어 있으면, 바로 수정
                if(cur_best.b_only_zero == true){ is_changed = true; }
                // 2. 숫자 개수가 많은 것이 좋음. 
                else if(cur_best.total < cost_check.total){ is_changed = true; }
                // 3. 더 큰 숫자가 더 많을수록 좋음
                else if(cur_best.total == cost_check.total)
                {
                    for(int i = in_N-1; i >= 0; i--)
                    {
                        if(cur_best.cases[i] < cost_check.cases[i])
                        {
                            is_changed = true;
                            break;
                        }
                        else if(cur_best.cases[i] > cost_check.cases[i])
                        {
                            break;
                        }
                    }
                }
            }
            // 모두 다 0일 경우
            else if(cost_check.b_only_zero && cur_best.b_only_zero)
            {
                // 0의 개수가 더 많은 것으로 변경
                if(cur_best.total < cost_check.total){ is_changed = true; }
            }

            // 더 좋은 경우로 변경
            if(is_changed){ cur_best = cost_check; }
        }

        // 가장 좋은 경우를 등록
        in_dp[cur_money] = cur_best;
    }
}

// 현재 가지고 있는 번호에 따라 최댓값인 번호 출력
string MakeNum(const vector<Money>& in_dp, const int in_N, const int in_M)
{
    string name;
    // 가장 높은 번호부터 앞 자리에 사용
    for(int num = in_N-1; num >= 0; num--)
    {
        for(int count = 0; count < in_dp[in_M].cases[num]; count++)
        {
            name += to_string(num);
        }
    }

    // 모두 0일 때는, 0으로 반환
    if(name[0] == '0'){ name = "0"; }
    return name;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 숫자 종류 N, 준비한 금액 M
    int N, M;
    cin >> N;

    // 각 번호 별로의 금액
    vector<int> costs(N);
    for(int& cost : costs) { cin >> cost; }
    cin >> M;

    // 현재 돈(cur_money)으로 살 수 있는 개수 측정
    vector<Money> dp(M+1);
    CheckCases(dp, costs, N, M);

    // M원으로 산 가장 최고의 경우로 번호 생성
    string name = MakeNum(dp, N, M);
    cout << name << "\n";
}