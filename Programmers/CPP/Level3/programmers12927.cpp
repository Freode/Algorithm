// Lv.3 - 12927번 : 야근 지수
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;

    // 내림차순
    sort(works.begin(), works.end(), greater<int>());

    int idx = 0;
    for(int count = 0; count < n; count++)
    {
        // 마지막 일의 양이 0인 경우, 남은 일이 없으므로 0 반환
        if(works[works.size() - 1] == 0)
        {
            return 0;
        }
        // 남은 일 감소
        works[idx]--;

        // 끝에 도달한 경우, 처음부터 감소
        if(idx == works.size() - 1)
        {
            idx = 0;
        }
        // 바로 뒷 일과 같거나 큰 경우면, 처음부터 감소
        else if(works[idx] >= works[idx + 1])
        {
            idx = 0;
        }
        // 위 조건에 해당하지 않으면, 다음 idx
        else
        {
            idx++;
        }
    }

    // 남은 일의 양을 각각 제곱해서 더하기
    for(int &work : works)
    {
        answer += (long long)work * (long long)work;
    }

    return answer;
}
