// Lv.2 - 131701번 : 연속 부분 수열 합의 개수
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {

    vector<int> sum_cases;
    int temp_sum = 0;
    int answer = 0;
    int len = elements.size();

    // 길이 개수
    for(int i = 1; i <= len; i++)
    {
        temp_sum = 0;
        // 처음에는 합을 미리 구하기
        for(int j = 0; j < i; j++)
        {
            temp_sum += elements[j];
        }
        sum_cases.push_back(temp_sum);

        // 두번째부터 끝까지 수열 돌기
        for(int j = 1; j < len; j++)
        {
            // 이전 값 하나씩 제거
            temp_sum -= elements[j - 1];

            // 이후 값 하나씩 추가
            temp_sum += elements[(j + i - 1) % len];

            // 경우 추가
            sum_cases.push_back(temp_sum);
        }
    }

    // set으로 중복 제거
    set<int> unique_sum_cases(sum_cases.begin(), sum_cases.end());
    answer = unique_sum_cases.size();

    return answer;
}
