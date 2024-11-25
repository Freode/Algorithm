// Lv.4 - 1831번 : 4단 고음
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>

using namespace std;

// 1. 처음과 끝은 항상 ()
// 2. ) 개수가 ( 개수보다 많으면, X
// 약 1.25억 경우 검사

int search(int finish, int loc, int left_num, int right_num)
{
    int cases = 0;
    // 목적지 넘어서 검사하는 경우
    if(finish - 1 < loc)
    {
        return 0;
    }
    // 목적지 도달
    if(finish - 1 == loc && left_num - 1 == right_num && left_num == finish / 2)
    {
        return 1;
    }

    // ( 추가
    if(left_num < finish / 2)
    {
        cases += search(finish, loc + 1, left_num + 1, right_num);
    }
    // ) 추가
    if(left_num > right_num)
    {
        cases += search(finish, loc + 1, left_num, right_num + 1);
    }

    return cases;
}

int solution(int n) {
    int answer = 0;

    answer = search(n * 2, 1, 1, 0);

    return answer;
}