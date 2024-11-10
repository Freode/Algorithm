// Lv.3 - 43164번 : 여행 경로
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    // 맵에 도착지와 방문 여부 정보 입력
    map<string, vector<pair<string, bool>>> collect;
    
    for(int i = 0; i < (int)tickets.size(); i++)
    {
        collect[tickets[i][0]].push_back(make_pair(tickets[i][1], false));
    }
    
    // 각 출발지에서의 도착지 정보들을 알파벳 순으로 정렬
    for(map<string, vector<pair<string, bool>>>::iterator it = collect.begin(); it != collect.end(); ++it)
    {
        sort(it->second.begin(), it->second.end(), [](const pair<string, bool> &a, const pair<string, bool> &b)
        {
         return a.first < b.first;   
        });
    }
    
    // queue 시작
    string temp;
    queue<string> que_ticket;
    que_ticket.push("ICN");
    answer.push_back("ICN");
    while(que_ticket.empty() == false)
    {
        temp = que_ticket.front();
        // 현재 출발지에서 방문하지 않은 도착지 중 가장 빠른 도착지로 이동.
        for(int i = 0; i < (int)collect[temp].size(); i++)
        {
            if(collect[temp][i].second == false)
            {
                collect[temp][i].second = true;
                que_ticket.push(collect[temp][i].first);
                answer.push_back(collect[temp][i].first);
                break;
            }
        }
        que_ticket.pop();
    }
    
    return answer;
}