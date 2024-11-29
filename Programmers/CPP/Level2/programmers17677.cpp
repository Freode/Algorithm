// Lv.2 - 17677번 : [1차] 뉴스 클러스터링
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <map>
#include <cctype>
#include <cmath>

using namespace std;

void input_case(string &str, map<string, int> &str_cases)
{
        // 두 글자씩 확인
    string temp = "";
    for(int i = 0; i < str.size() - 1; i++)
    {
        // 두 글자 모두 알파벳
        if(isalpha(str[i]) && isalpha(str[i+1]))
        {
            // 대문자인지 확인
            temp = isupper(str[i]) ? tolower(str[i]) : str[i];
            temp += isupper(str[i + 1]) ? tolower(str[i + 1]) : str[i + 1];
            str_cases[temp]++;
        }
    }
}

int check_case(map<string, int> &a_cases, map<string, int> &b_cases)
{
    int inter_case = 0;
    int union_case = 0;
    // 겹치는 개수 확인
    for(const auto& each : a_cases)
    {
        inter_case += min(each.second, b_cases[each.first]);
        union_case += each.second;
    }

    // 나머지 B의 개수도 모두 추가
    for(const auto& each : b_cases)
    {
        union_case += each.second;
    }

    // 겹치는 개수 제거
    union_case -= inter_case;

    // 존재 x
    if(union_case == 0)
    {
        return 65536;
    }
    // 존재 o
    int result = (float)inter_case / (float)union_case * 65536.0f;

    return result;
}

int solution(string str1, string str2) {
    int answer = 0;

    map<string, int> str1_cases;
    map<string, int> str2_cases;

    // 두 글자씩 확인
    input_case(str1, str1_cases);
    input_case(str2, str2_cases);

    // 합집합과 교집합 개수 확인
    answer = check_case(str1_cases, str2_cases);

    return answer;
}