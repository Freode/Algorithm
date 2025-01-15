// Lv.2 - 12899번 : 124 나라의 숫자
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <cmath>

using namespace std;

// 거듭제곱 수
int max_multiple(int n)
{
    int multiple = 0;
    if(n == 1)
    {
        return 1;
    }

    while(n > 0)
    {
        n /= 3;
        multiple++;
    }

    return multiple;
}

string solution(int n) {
    string answer = "";
    string num_124 = "124";

    int each_num, i = 0;
    int multiple = max_multiple(n);

    // 124로 변환
    

    for(int i = multiple; i > 0; i--)
    {
        each_num =  n / pow(3, i-1);
        answer += num_124[(each_num - 1) % 3];
        n -= each_num * (int)pow(3, i - 1);
    }

    return answer;
}