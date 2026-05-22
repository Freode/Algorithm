// Lv.3 - 77886번 : 110 옮기기
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    
    for(const string& str : s)
    {
        string nums = "";
        int count = 0;
        
        for(const char& c : str)
        {
            nums += c;
            
            int size = nums.size();
            if(size >= 3 && nums[size-3] == '1' && nums[size-2] == '1' && nums[size-1] == '0')
            {
                nums.pop_back();
                nums.pop_back();
                nums.pop_back();
                count++;
            }
        }
        
        int zero_idx = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == '0')
                zero_idx = i;
        }
        
        string add = "";
        for(int i = 0; i < count; i++)
            add += "110";
        
        // 제일 앞에 110을 넣는게 유리
        if(zero_idx == -1)
        {
            nums = add + nums;
        }
        // 기존에 있는 수에서 마지막 0 위치에 110을 넣는게 유리
        else
        {
            nums = nums.substr(0, zero_idx + 1) + add + nums.substr(zero_idx + 1);
        }
        
        answer.push_back(nums);
    }
    
    return answer;
}