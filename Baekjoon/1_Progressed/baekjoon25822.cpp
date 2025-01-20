// 실버 1 - 25822번 : 2000문제 푼 임스
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    float c;
    int n;

    cin >> c >> n;

    int max_problem = 0;
    vector<int> problems(n);
    vector<int> seq_sum;

    // 문제 푼 개수 입력
    for(int i = 0; i < n; i++)
    {
        cin >> problems[i];
        max_problem = max(max_problem, problems[i]);
    }

    int day = c / 0.99f;
    int temp_sum = 0;
    for(const int& problem : problems)
    {
        if(problem == 0)
        {
            seq_sum.push_back(temp_sum);
            temp_sum = 0;
        }
        else
        {

        }
    }

}