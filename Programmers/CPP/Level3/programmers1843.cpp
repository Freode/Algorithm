// Lv.3 - 1843번 : 사칙연산
// 작성자 : jeonghoe22(최정호)

#include <vector>
#include <string>
#include <limits>

using namespace std;

// [start][end] = start~end까지 최댓/최솟값

int solution(vector<string> arr)
{
    int answer = -1;
    int size = (arr.size() + 1) >> 1;
    
    vector<vector<int>> dp_max(size, vector<int>(size, numeric_limits<int>::min()));
    vector<vector<int>> dp_min(size, vector<int>(size, numeric_limits<int>::max()));
    
    for(int idx = 0; idx < size; idx++)
    {
        int value = stoi(arr[idx << 1]);
        dp_max[idx][idx] = value;
        dp_min[idx][idx] = value;
    }
    
    // 길이
    for(int len = 1; len < size; len++)
    {
        // 검사 구간
        for(int start = 0; start < size - len; start++)
        {
            int end = start + len;
            
            // 검사 지점
            for(int idx = start; idx < end; idx++)
            {
                string oper = arr[(idx << 1) + 1];
                
                // 덧셈
                // 1. 최대 : 최대 + 최대
                // 2. 최소 : 최소 + 최소
                if(oper == "+")
                {
                    dp_max[start][end] = max(dp_max[start][end], dp_max[start][idx] + dp_max[idx + 1][end]);
                    dp_min[start][end] = min(dp_min[start][end], dp_min[start][idx] + dp_min[idx + 1][end]);
                }
                // 뺄셈 - 최솟값 유지하기
                // 1. 최대 : 최대 - 최소
                // 2. 최소 : 최소 - 최대
                else
                {
                    dp_max[start][end] = max(dp_max[start][end], dp_max[start][idx] - dp_min[idx + 1][end]);
                    dp_min[start][end] = min(dp_min[start][end], dp_min[start][idx] - dp_max[idx + 1][end]);
                }
            }
        }
    }
    
    answer = dp_max[0][size - 1];
    
    return answer;
}