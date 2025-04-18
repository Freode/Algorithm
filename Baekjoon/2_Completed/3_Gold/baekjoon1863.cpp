// 골드 4 - 1863번 : 스카이라인 쉬운거
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

// 높이가 높아지면, 유지
// 높이가 낮아지면, 반환

// 반례
// 5
// 1 1
// 2 2
// 3 3
// 4 4
// 5 1
// output : 5

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 줄 n개
    int n;
    cin >> n;

    // 스카이라인 좌표 입력
    int x, y;
    stack<int> heights;
    int result = 0, cutting_height = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;

        if(heights.empty() == false)
        {
            int cur_height = heights.top();
            // 높이가 높아지면, 추가
            if(cur_height < y)
            {
                heights.push(y);
            }
            // 높이가 낮아지면, pop 및 새로운 건물의 개수 추가
            else
            {
                // 높이가 더욱 더 낮아지는 경우는 계속 빼야함.
                while(cur_height > y)
                {
                    heights.pop();
                    result++;
                    
                    // 더 검사해야하는 경우가 존재
                    if(heights.empty() == false)
                        cur_height = heights.top();
                    else
                        break;
                }

                // 새로운 높이면, 추가
                if(y != 0 && (heights.empty() || (heights.empty() == false && heights.top() != y)))
                {
                    heights.push(y);
                }
            }
        }

        // 현재 새로운 스카이라인일 때, 높이가 0이 아니라면, 추가
        else if(y != 0)
        {
            heights.push(y);
        }
    }

    // 아직 처리 안된 스택 크기만큼 건물 추가 가능
    result += heights.size();

    cout << result << "\n";
}