// Lv.2 - 12899번 : 124 나라의 숫자
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(int n) {
    string answer = "";
    string num_124 = "124";

    int each_num, i = 1;
    while(n > 0)
    {
        each_num = n % (int)pow(3,i);
        n -= each_num * (int)pow(3,i-1);
        each_num = each_num % (int)pow(3,i-1);
        answer = num_124[each_num-1] + answer;
    }

    return answer;
}