// Lv.2 - 12923번 : 숫자 블록
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer;

    int check_end;
    for(int i = begin; i <= end; i++)
    {
        // 1인 경우에는 0
        if(i == 1)
        {
            answer.push_back(0);
        }
        // 나머지는 일단 1로 추가
        else
        {
            answer.push_back(1);
        }

        // 제곱근까지 나눠지는지 확인
        // 안 나눠지면, 1
        // 1000만 번호까지의 약수만 가능

        for(int j = 2; j <= (int)sqrt(i); j++)
        {
            // 나눠지면, i / j가 가장 큰 수이므로 대입하고 break
            if(i % j == 0)
            {
                if(i / j > 10000000)
                {
                    answer[answer.size() - 1] = j;
                }
                else
                {
                    answer[answer.size() - 1] = i / j;
                    break;
                }
            }
        }
    }
    
    return answer;
}