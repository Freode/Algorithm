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

    int stric_day = c / 0.99f;
    stric_day = min(stric_day, 2);
    int temp_sum = 0;

    // 계산
    for(int i = 0; i < (int)problems.size(); i++)
    {
        // 문제 안 푼 경우
        if(problems[i] == 0)
        {
            // 이전에 푼 일 수 추가
            seq_sum.push_back(temp_sum);
            // 처음으로 안 풀었을 때, 0문제 새롭게 추가 (누락 방지)
            if(temp_sum != 0)
            {
                seq_sum.push_back(0);
            }

            temp_sum = 0;
        }
        else
        {
            temp_sum++;
            // 마지막에 누락되는 경우 방지
            if(i == (int)problems.size() - 1)
            {
                seq_sum.push_back(temp_sum);
            }
        }
    }

    // 가장 긴 풀이 수 구하기
    int max_day = 0;
    int temp_day, temp_stric, temp_seq;
    for(int i = 0; i < (int)seq_sum.size(); i++)
    {
        temp_day = 0;
        temp_stric = stric_day;
        temp_seq = i;

        // 역순으로 추적
        while(temp_stric >= 0 && temp_seq >= 0)
        {
            // 스트릭 사용할 수 있고 0문제인 경우, 스트릭 하나 사용
            if(seq_sum[temp_seq] == 0 && temp_stric != 0)
            {
                temp_stric--;
                temp_day++;
            }
            // 스트릭 사용할 수 없는데 0문제 인 경우
            else if (seq_sum[temp_seq] == 0 && temp_stric == 0)
            {
                break;
            }
            // 1문제 이상 푼 경우
            else
            {
                temp_day += seq_sum[temp_seq];
            }
            temp_seq--;
        }
        // 최대 연속 푼 일 수 검사
        max_day = max(max_day, temp_day);
    }

    cout << max_day << "\n" << max_problem << "\n";
}