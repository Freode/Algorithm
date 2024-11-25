// Lv.3 - 12938번 : 최고의 집합
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>

using namespace std;


// 1. 차이가 적은 수들로 s를 구성
// 2. s가 n으로 나눠 떨어지면, 그 수로만 구성
// 3. s가 n으로 나눠 떨어지지 않으면, 몫으로 n개 구성하고 s - n * 몫의 개수만큼 + 1
// 4. s가 n으로 나눴는데 0이라면, -1로 반환

vector<int> solution(int n, int s) {
    vector<int> answer;

    int portion = s / n;
    // 4번 조건
    if(portion == 0)
    {
        answer.push_back(-1);
        return answer;
    }
    
    // n개만큼 몫의 값을 추가
    for(int i = 0; i < n; i++)
    {
        answer.push_back(portion);
    }

    int remain = s - n * portion;
    // 나머지가 존재할 때, 마지막부터 1씩 증가
    int seq = answer.size() - 1;
    while(remain > 0)
    {
        answer[seq]++;

        // 순서 감소
        remain--;
        seq--;
    }

    return answer;
}