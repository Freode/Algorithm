// Lv.3 - 43162번 : 네트워크 
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <queue>

using namespace std;

// 네트워크 연결 여부 확인
void CheckNetwork(vector<vector<int>>& computers, vector<bool>& b_is_visits, int num)
{
    // 검사 위치 방문 설정
    b_is_visits[num] = true;
    
    // 연결된 컴퓨터끼리 모두 방문했다고 설정
    queue<int> que_num;
    que_num.push(num);
    
    int check = 0;
    // BFS
    while(que_num.empty() == false)
    {
        check = que_num.front();
        for(int i = 0; i < (int)computers.size(); i++)
        {
            // 연결된 컴퓨터이면서 방문하지 않았을 때, 추가 검사
            if(computers[check][i] == 1 && b_is_visits[i] == false)
            {
                b_is_visits[i] = true;
                que_num.push(i);
            }
        }
        que_num.pop();
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<bool> b_is_visits(n, false);
    // n번째 컴퓨터까지 검사
    for(int i = 0; i < n; i++)
    {
        // 현재 방문하지 않은 컴퓨터는 어느 네트워크에도 속하지 않으므로 
        // 네트워크 수를 하나 증가
        if(b_is_visits[i] == false)
        {
            answer++;
            CheckNetwork(computers, b_is_visits, i);
        }
    }
    
    return answer;
}