// Lv.4 - 1882번 : 단어 퍼즐
// 작성자 : jeonghoe22(최정호)


#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> strs, string t)
{
    const int max_value = 20'001;
    unordered_map<string, bool> umap;
    
    for(const string& str : strs)
        umap[str] = true;
    
    vector<int> dp = vector<int>(t.size() + 1, max_value);
    dp[0] = 0;
    
    for(int i = 1; i <= t.size(); i++)
    {
        for(int length = 1; length <= 5; length++)
        {
            if(i - length < 0)
                continue;
            
            string check = t.substr(i - length, length);
            
            if(umap[check] == false)
                continue;
            
            dp[i] = min(dp[i], dp[i - length] + 1);
        }
    }
    
    int answer = (dp[t.size()] == max_value) ? -1 : dp[t.size()];

    return answer;
}