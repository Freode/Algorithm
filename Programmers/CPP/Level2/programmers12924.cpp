// Lv.2 - 12924번 : 숫자의 표현
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    int sum = 0;
    int seq = 0;
    // 1부터 n까지 검사
    for(int i = 1; i <= n; i++)
    {
        sum = 0;
        seq = i;
        // 누적합이 n보다 같거나 클 때까지 더하기
        while(sum < n)
        {
            sum += seq;
            seq++;
        }
        // 값이 같을 때, answer + 1
        if(sum == n)
        {
            answer++;
        }
    }

    return answer;
}