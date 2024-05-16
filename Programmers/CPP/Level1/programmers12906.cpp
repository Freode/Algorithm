// Lv.1 - 12906번 : 같은 숫자는 싫어 
// 작성자 : jeonghoe22(최정호)

#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    // 첫 숫자 추가
    answer.push_back(arr[0]);
    // 첫 숫자 제외하고 검사
    for(int i = 1; i < (int)arr.size(); i++)
    {
        // 출력할 벡터의 마지막 숫자와 현재 검사 숫자가 다른 경우에만 추가
        if(answer[(int)answer.size()-1] != arr[i])
        {
            answer.push_back(arr[i]);
        }
    }

    return answer;
}