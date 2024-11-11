// Lv.2 - 17687번 : [3차] n진수 게임 
// 작성자 : jeonghoe22

#include <string>
#include <vector>

using namespace std;

void OnePlus(int n, string &num, int loc)
{
    int cur_loc_num = 0;

    // 숫자
    if((int)num[loc] >= 48 && (int)num[loc] <= 57)
    {
        cur_loc_num = (int)num[loc] - 48;
    }
    // 알파벳 문자
    else
    {
        cur_loc_num = (int)num[loc] - 65 + 10;
    }

    cur_loc_num++;

    // 올림해야하는 경우
    if(cur_loc_num % n == 0)
    {
        num[loc] = '0';
        
        // 제일 앞자리가 변경되는 경우
        if(loc - 1 == -1)
        {
            num = '1' + num;
        }
        else
        {
            OnePlus(n, num, loc - 1);
        }
    }
    // 올림하지 않는 경우, 바뀌는 수 반영
    else
    {
        num[loc] = cur_loc_num >= 10 ? (char)(cur_loc_num + 65 - 10) : (char)(cur_loc_num + 48);
    }
}

string solution(int n, int t, int m, int p) {
    string answer = "";

    string str_num = "0";
    int my_count = 0;
    int people_loc = 1;
    int str_num_loc = 0;
    // 
    while(my_count != t)
    {
        // 다음 수로 변경
        if(str_num_loc == str_num.size())
        {
            str_num_loc = 0;
            OnePlus(n, str_num, str_num.size()-1);
        }

        // 내 차례인 경우
        if(people_loc == p)
        {
            my_count++;
            answer += str_num[str_num_loc];
        }

        people_loc++;
        // 마지막 사람 순서까지 다 온 경우, 처음으로 돌아감
        if(people_loc > m)
        {
            people_loc = 1;
        }

        str_num_loc++;
    }

    return answer;
}