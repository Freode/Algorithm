// Lv.2 - 12911번 : 다음 큰 숫자
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int OneCount(int n)
{
    int num = 0;

    // 1의 개수 구하기
    while(n > 0)
    {
        // 끝자리부터 계산
        if(n % 2 == 1)
        {
            num++;
        }
        n /= 2;
    }

    return num;
}

int solution(int n) 
{
    int answer = 0;

    int one = OneCount(n);
    int next_one;
    while(true)
    {
        // 수를 계속 증가
        n++;
        // 다음 수를 2진수로 변경했을 때, 1의 개수 세기 
        next_one = OneCount(n);
        
        // 1의 개수가 같으면서 다음 수를 찾았을 때
        if(next_one == one)
        {
            break;
        }
    }

    answer = n;

    return answer;
}