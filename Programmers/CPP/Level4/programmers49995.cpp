// Lv.4 - 49995번 : 쿠키 구입 
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>

// 2'000 * 2'000 = 4'000'000 * 2'000 = 8'000'000'000
// 단순 누적합은 아님
// l ~ m, m+1 ~ r
// 1 <= l <= 1'999
// 2 <= r <= 2'000

// 1 <= m <= 1'999
// left, right -> 2'000 * 2'000

using namespace std;

int solution(vector<int> cookie) 
{
    int answer = 0;
    int size = cookie.size();
    
    // 누적합 구하기
    vector<int> sums = vector<int>(size + 1, 0);
    for(int i = 1; i <= size; i++)
    {
        sums[i] = sums[i-1] + cookie[i-1]; 
    }
    
    // 기준점 m에 대한 검사
    for(int m = 1; m < size; m++)
    {
        int left = m;
        int right = m + 1;
        
        // 양쪽 확장
        while(left >= 1 && right <= size)
        {
            int sum_left = sums[m] - sums[left-1];
            int sum_right = sums[right] - sums[m];
            
            if(sum_left == sum_right)
            {
                answer = max(answer, sum_left);
                --left;
                ++right;
            }
            else if(sum_left < sum_right)
            {
                --left;
            }
            // sum_left > sum_right
            else
            {
                ++right;
            }
        }
    }
    
    return answer;
}