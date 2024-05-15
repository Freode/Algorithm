// Lv.1 - 42576번 : 완주하지 못한 선수 
// 작성자 : jeonghoe22

#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string, int> lists;
    // 각 이름을 추가
    for(string& each : participant)
    {
        lists[each]++;
    }
    // 완주한 이름을 하나씩 뺌.
    for(string& each : completion)
    {
        lists[each]--;
    }
    // 완주하지 못한 이름이 하나 있을 경우, 해당 이름을 반환
    for(auto& each : lists)
    {
        if(each.second == 1)
        {
            answer = each.first;
            break;
        }
    }
    
    return answer;
}