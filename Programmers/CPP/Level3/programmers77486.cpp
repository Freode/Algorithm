// Lv.3 - 77486번 : 다단계 칫솔 판매
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// amount <= 100 : 10'000 -> 1'000 -> 100 -> 10 -> 1

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer = vector<int>(enroll.size(), 0);
    
    unordered_map<string, int> umap_idx;
    for(int idx = 0; idx < enroll.size(); idx++)
    {
        umap_idx[enroll[idx]] = idx;
    }
    
    for(int idx = 0; idx < seller.size(); idx++)
    {
        int cur_idx = umap_idx[seller[idx]];
        int cur_amount = amount[idx] * 100;
        
        while(true)
        {
            int add_amount = cur_amount - cur_amount / 10;
            answer[cur_idx] += add_amount;
            cur_amount = cur_amount / 10;
            
            if(cur_amount == 0)
                break;
            
            if(referral[cur_idx] == "-")
                break;
            
            cur_idx = umap_idx[referral[cur_idx]];
        }
    }
    
    return answer;
}