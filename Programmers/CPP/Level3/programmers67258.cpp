// Lv.3 - 67258번 : 보석 쇼핑
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer = {0, 100'001};
    
    set<string> s;
    for(const string& gem : gems)
        s.insert(gem);
    
    int size = s.size();
    int left = 0, right = 0;
    int kind = 0;
    unordered_map<string, int> umap;
    
    while(left < gems.size() && right < gems.size())
    {
        ++umap[gems[right]];
        
        // 새로운 보석 추가
        if(umap[gems[right]] == 1)
            ++kind;
        
        // 보석 종류가 모두 있으면, 범위를 줄여서 재확인 (왼쪽에서만 한 칸 밀기)
        while(kind == size)
        {    
            
            if((answer[1] - answer[0] > right - left))
            {
                answer[0] = left + 1;
                answer[1] = right + 1;
            }
            
            --umap[gems[left]];
            if(umap[gems[left]] == 0)
                --kind;

            ++left;
        }
        
        ++right;

    }
    
    return answer;
}