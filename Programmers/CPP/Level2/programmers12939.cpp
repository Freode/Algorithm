// Lv.2 - 12939번 : 최댓값과 최솟값
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";

    // 스페이스 바 기준으로 분해할 문자열 스트림 생성
    istringstream iss(s);
    vector<int> nums;

    int min, max;
    string num = "";
    // 스페이스 바(공백) 기준으로 분해
    while(iss >> num)
    {
        nums.push_back(stoi(num));

        // 길이가 1일 때
        if(nums.size() == 1)
        {
            min = nums[0];
            max = nums[0];
        }
        else
        {
            // 최솟값 초기화
            if(min > nums[nums.size() - 1])
            {
                min = nums[nums.size() - 1];
            }
            // 최댓값 초기화
            if(max < nums[nums.size() - 1])
            {
                max = nums[nums.size() - 1];
            }
        }
    }

    // 반환 형식 맞추기
    answer = to_string(min) + " " + to_string(max);

    return answer;
}