// Lv.2 - 1835번 : 단체사진 찍기
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <cmath>

using namespace std;

// 글자에 따라 어느 위치인지 찾기
int FindCharacterLocs(char check)
{
    string chars = "ACFJMNRT";
    for(int i = 0; i < chars.size(); i++)
    {
        if(chars[i] == check)
        {
            return i;
        }
    }

    return 0;
}
// DFS
int Search(vector<string> &data, string characters, string cur_seq, vector<int> char_locs)
{
    int a_loc, b_loc;
    bool b_is_correct = true;
    // 순서가 모두 정해져서 조건 검사
    if(characters.size() == 0)
    {
        // 각 조건마다 검사
        for(string &each_condition : data)
        {
            a_loc = char_locs[FindCharacterLocs(each_condition[0])];
            b_loc = char_locs[FindCharacterLocs(each_condition[2])];
            // 거리 초과 유지
            if(each_condition[3] == '>')
            {
                // 거리가 이하일 경우 
                if(abs(a_loc - b_loc) <= (int)each_condition[4] - 48 + 1)
                {
                    return 0;
                }
            }
            // 거리 미만 유지
            else if(each_condition[3] == '<')
            {
                // 거리가 이상일 경우
                if(abs(a_loc - b_loc) >= (int)each_condition[4] - 48 + 1)
                {
                    return 0;
                }
            }
            // 일정 거리 유지
            else
            {
                // 틀리다면, return
               if (abs(a_loc - b_loc) != (int)each_condition[4] - 48 + 1)
               {
                    return 0;
               }
            }
        }
        // 모든 조건 통과
        return 1;
    }

    // 순서부터 정하기
    string next_characters, next_seq;
    int answer = 0;
    for(int i = 0; i < characters.size(); i++)
    {
        // 현재 순서와 남은 캐릭터를 미리 저장
        next_characters = characters;
        next_seq = cur_seq;

        // 현재 새롭게 추가하는 캐릭터 정보를 추가하고 목록에서는 지움
        next_seq += characters[i];
        next_characters.erase(i, 1);
        // 위치 미리 저장
        char_locs[FindCharacterLocs(characters[i])] = next_seq.size() - 1;

        // 다음 순서 추가 or 순서에 대한 조건 검사 진행
        answer += Search(data, next_characters, next_seq, char_locs);
    }

    return answer;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;

    // 초기 설정
    string characters = "ACFJMNRT";
    string next_seq = "";
    vector<int> char_locs(8, -1);

    // DFS
    answer = Search(data, characters, next_seq, char_locs);

    return answer;
}