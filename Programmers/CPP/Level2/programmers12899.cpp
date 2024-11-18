// Lv.2 - 12899번 : 124 나라의 숫자
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
using namespace std;

string solution(int n) {
    string answer = "";
    string num_124 = "124";

    int share = n;
    int rest = 0;
    
    // 계산할 때까지 돌리기
    while(share > 0)
    {
        // 3으로 나눈 나머지와 몫 구하기
        rest = share % 3;
        share /= 3;

        // 3의 배수라면, 몫을 하나 줄이고 나머지를 3으로 만듦
        // 0을 4로 만들어야함.
        if(rest == 0 && share != 0)
        {
            share--;
            rest = 3;
        }
        // 뒷에서부터 추가
        answer = num_124[rest - 1] + answer;
    }

    return answer;
}