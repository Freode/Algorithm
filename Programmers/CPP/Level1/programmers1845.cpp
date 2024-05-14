// Lv.1 - 1845번 : 폰켓몬 
// 작성자 : jeonghoe22

#include <vector>
#include <map>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    // 맵 생성
    map<int, int> kinds;
    
    // 해당 종류의 포켓몬이 있다고 설정
    for(int& num : nums)
    {
        kinds[num] = 1;
    }
    
    // 선택할 수 있는 종류의 수보다 현재 포켓몬의 종류가 많은 경우에
    // 선택할 수 있는 종류를 출력하고 그렇지 않은 경우에는 현재 포켓몬의 종류를 출력
    answer = (int)nums.size() / 2 < kinds.size() ? (int)nums.size() / 2 : kinds.size();
    
    return answer;
}