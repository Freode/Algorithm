// Lv.3 - 64064번 : 불량 사용자
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>

using namespace std;

// 아이디별로 현재 제재한 아이디인지 확인용 boolean 변수 필요
// 불량 사용자별로 제재 가능한 아이디 목록화

// 중복 방지
// 오름차순으로 아이디 번호 수여
// string으로 번호 추가
// 중복 판단

struct PossibleNames
{
    vector<pair<string, int>> names;
};

struct User
{
    int num = 0;
    string user_id = "";
    bool b_is_banned = false;
};

// 벤 가능여부 초기화
void InitializeBanned(vector<User> &users)
{
    for(User &user : users)
    {
        user.b_is_banned = false;
    }
}

void search(vector<User> &users, vector<PossibleNames> &lists, int idx, vector<string> &cases, string each_case)
{
    string target;
    string curr_case;
    // 경우를 아직 다 정함
    if(idx == lists.size())
    {
        cases.push_back(each_case);
        return;
    }
    // 경우를 아직 다 정하지 못한 경우
    for(int i = 0; i < lists[idx].names.size(); i++)
    {
        target = to_string(lists[idx].names[i].second);
        // 중복되지 않은 경우에만 추가
        if(each_case.find(target) == string::npos)
        {
            curr_case = each_case;
            curr_case += target;
            search(users, lists, idx + 1, cases, curr_case);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;

    // 알파벳순
    sort(user_id.begin(), user_id.end());

    // 이름 입력
    vector<User> users(user_id.size());
    for(int i = 0; i < user_id.size(); i++)
    {
        users[i].num = i + 1;
        users[i].user_id = user_id[i];
    }

    // 제재 아이디 목록 입력
    vector<PossibleNames> lists(banned_id.size());
    int idx = 0;
    for(const string& id : banned_id)
    {
        InitializeBanned(users);
        // 길이부터 검사
        for(User &user : users)
        {
            user.b_is_banned = user.user_id.size() != id.size();
        }

        // 각 글자마다 검사
        for(int i = 0; i < id.size(); i++)
        {
            // 모두 통과
            if(id[i] == '*')
            {
                continue;
            }

            // 모든 이름에 해당 글자 검사
            for(User &user : users)
            {
                // 이미 조건이 맞지 않는 이름은 통과
                if(user.b_is_banned)
                {
                    continue;
                }

                // 글자가 다른 이름
                if(user.user_id[i] != id[i])
                {
                    user.b_is_banned = true;
                }
            }
        }
        // 제재 가능한 이름 목록 추가
        for(User &user : users)
        {
            if(!user.b_is_banned)
            {
                lists[idx].names.push_back(make_pair(user.user_id, user.num));
            }
        }
        idx++;
    }

    // 경우 조합
    vector<string> cases;
    string temp = "";
    search(users, lists, 0, cases, temp);

    // 경우별로 오름차순 정렬
    for(string &each : cases)
    {
        sort(each.begin(), each.end());
    }

    // Set에 추가
    set<string> not_duplicate_cases;
    for(string &each : cases)
    {
        not_duplicate_cases.insert(each);
    }

    answer = not_duplicate_cases.size();

    return answer;
}