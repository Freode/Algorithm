// Lv.2 - 42586번 : 기능개발 
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int seq = 0, last_dates = 0;
    for(int i = 0; i < (int)progresses.size(); i++)
    {
        // 걸릴 일 수
        progresses[i] = (100 - progresses[i]) % speeds[i] == 0 ? (100 - progresses[i]) / speeds[i] : (100 - progresses[i]) / speeds[i] + 1;
        // 현재 작업의 완료일이 한 번에 배포될 수 있는지 검사
        if(last_dates >= progresses[i])
        {
            seq++;
        }
        // 한 번에 배포될 수 없는 경우, 추가하고 초기화
        else
        {
            if(last_dates != 0){ answer.push_back(seq); }
            last_dates = progresses[i];
            seq = 1;
        }
    }
    
    // 마지막 순서 더하기
    answer.push_back(seq);
    
    return answer;
}