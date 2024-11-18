// Lv.2 - 340212번 : [PCCP 기출문제] 2번 / 퍼즐 게임 챌린지
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <limits>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int level = 0;

    // 초기값 설정
    int left_level = 1;
    int right_level = numeric_limits<int>::max();
    long long middle_level;

    long long spend_time = 0;

    // 값을 찾을 때까지 이분 탐색
    while(left_level < right_level)
    {
        middle_level = ((long long)left_level + (long long)right_level) / 2;
        spend_time = 0;

        // 시간 확인
        for(int i = 0; i < diffs.size(); i++)
        {
            // 쉽게 풀 수 있는 경우
            if(middle_level >= diffs[i])
            {
                spend_time += times[i];
            }
            // n번 틀리고 풀 수 있는 경우
            else
            {
                spend_time += ((times[i] + times[i-1]) * (diffs[i] - middle_level) + times[i]);
            }
        }

        // 제한 시간보다 널널하므로 현재 숙련도 낮추기
        if(limit > spend_time)
        {
            right_level = middle_level;
        }
        // 제한 시간을 넘어서므로 현재 숙련도를 기존보다 + 1해서 높이기
        else if(limit < spend_time)
        {
            left_level = middle_level + 1;
        }
        // 값을 정확히 찾은 경우
        else
        {
            right_level = middle_level;
            break;
        }
    }
    
    // 끝날 때, 항상 오른쪽 경계가 limit > spend_time을 만족
    level = right_level;

    return level;
}