// Lv.3 - 42884번 : 단속카메라
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 시작 ~ 종료 : 어디든 카메라만 있으면 됨.
// 종료 시점 기준으로 오름차순 정렬 -> 처음의 종료 시점에 카메라 설치 -> 그 라인 다 제거
// 반복하기


int solution(vector<vector<int>> routes) 
{
    // 종료 시점 기준 오름차순
    sort(routes.begin(), routes.end(), 
        [](const vector<int>& a, const vector<int>& b)
         {
             return a[1] < b[1];
         }
    );
    
    int answer = 0;
    int loc = -30'001;
    for(const vector<int>& route : routes)
    {
        if(loc < route[0])
        {
            ++answer;
            loc = route[1];
        }
    }
    
    return answer;
}