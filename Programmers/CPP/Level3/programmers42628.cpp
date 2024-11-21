// Lv.3 - 42628번 : 이중우선순위큐
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    // 최솟값과 최댓값
    // 기본 옵션이 최댓값의 우선순위 큐
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;

    int count = 0;
    int cur_num;
    int delete_num;
    map<int, int> cases;
    // 각 명령어
    for(const string& operation : operations)
    {
        cur_num = stoi(operation.substr(2));
        // 입력
        if(operation[0] == 'I')
        {   
            min_pq.push(cur_num);
            max_pq.push(cur_num);
            cases[cur_num] = 1;
            count++;
        }
        // 출력
        else if(operation[0] == 'D' && count > 0)
        {
            count--;
            // 최댓값 추출
            if(cur_num == 1)
            {
                // 이미 제거된 것들 제거
                while(cases[max_pq.top()] != 1)
                {
                    max_pq.pop();
                }
                delete_num = max_pq.top();
                max_pq.pop();
            }
            // 최솟값 추출
            else
            {
                // 이미 제거된 것들 제거
                while(cases[min_pq.top()] != 1)
                {
                    min_pq.pop();
                }
                delete_num = min_pq.top();
                min_pq.pop();
            }
            cases[delete_num] = -1;
            // 추가한 개수만큼 추출한 경우에는 모두 비우기
            if(count == 0)
            {
                while(!min_pq.empty())
                {
                    min_pq.pop();
                }
                while(!max_pq.empty())
                {
                    max_pq.pop();
                }
            }
        }
    }

    int top_num;
    // 큐에 수가 남아있지 않은 경우
    if(count == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    // 큐에 수가 남아있음
    else
    {
        // 최댓값 찾기
        while(!max_pq.empty())
        {
            top_num = max_pq.top();
            if(cases[top_num] == 1)
            {
                answer.push_back(top_num);
                break;
            }
            max_pq.pop();
        }
        // 최솟값 찾기
        while(!min_pq.empty())
        {
            top_num = min_pq.top();
            if(cases[top_num] == 1)
            {
                answer.push_back(top_num);
                break;
            }
            min_pq.pop();
        }
        
    }

    return answer;
}