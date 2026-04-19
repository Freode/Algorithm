// Lv.3 - 131129번 : 카운트 다운 
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>

using namespace std;

// 다트 점수 종류
// 싱글 : 1 ~ 20
// 더블 : 1*2 ~ 2*20
// 트리플 : 1*3 ~ 2*30
// 불 : 50
// 총 61가지 = 중복 존재

// dp[점수] = [다트 개수, 싱글 or 불 개수]

// 100'000 * 61 

struct Num
{
    int val = 0;
    int count = 0;
};

vector<int> solution(int target) {
    
    vector<Num> scores;
    scores.reserve(50);
    
    // 싱글
    for(int i = 1; i <= 20; i++)
        scores.push_back({i, 1});
    
    // 불
    scores.push_back({50, 1});
    
    // 더블 & 트리플
    for(int i = 11; i <= 20; i++)
        scores.push_back({i << 1, 0});
    
    for(int i = 7; i <= 20; i++)
    {
        if(i * 3 <= 40 && i % 2 == 0)
            continue;
        
        scores.push_back({i * 3, 0});
    }
    
    vector<Num> nums = vector<Num>(100'001);
    for(int i = 1; i <= 100'000; i++)
    {
        for(const Num& score : scores)
        {
            if(i - score.val < 0)
                continue;
            
            Num num = nums[i - score.val];
            ++num.val;
            num.count += score.count;
            
            if(nums[i].val == 0 || num.val < nums[i].val || (num.val == nums[i].val && num.count > nums[i].count))
                nums[i] = num;
        }
    }
    
    vector<int> answer;
    
    answer = {nums[target].val, nums[target].count};
    
    return answer;
}