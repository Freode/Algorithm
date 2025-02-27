// 골드 4 - 7662번 : 이중 우선순위 큐
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 입력
    int T;
    cin >> T;

    int k, num;
    char oper;
    // 테스트 케이스 반복
    for(int i = 0; i < T; i++)
    {
        // 연산 개수 입력
        cin >> k;

        priority_queue<int> pri_max;
        priority_queue<int, vector<int>, greater<int>> pri_min;

        // 최댓값, 최솟값 뺀 개수
        int size = 0;

        // 이미 삭제된 정보들 입력
        unordered_map<int, int> maps;

        for(int j = 0; j < k; j++)
        {
            cin >> oper >> num;

            // 입력
            if(oper == 'I')
            {
                pri_max.push(num);
                pri_min.push(num);
                maps[num]++;
                size++;
            }
            // 삭제 - 단, 큐에 있는 경우
            else if(oper == 'D' && size != 0)
            {
                size--;
                // size = 0, 모두 빌 경우
                if(size == 0)
                {
                    while(!pri_max.empty())
                    {
                        maps[pri_max.top()] = 0;
                        pri_max.pop();
                    }
                    while(!pri_min.empty())
                    {
                        maps[pri_min.top()] = 0;
                        pri_min.pop();
                    }
                }
                // 최댓값 삭제
                else if(num == 1)
                {
                    // 이미 제거된 숫자인지 먼저 확인
                    while(maps[pri_max.top()] == 0)
                    {
                        pri_max.pop();
                    }
                    if(pri_max.empty())
                    {
                        size = 0;
                        continue;
                    }
                    maps[pri_max.top()]--;
                    pri_max.pop();
                    
                }
                // 최솟값 삭제
                else
                {
                    // 이미 제거된 숫자인지 먼저 확인
                    while(maps[pri_min.top()] == 0)
                    {
                        pri_min.pop();
                    }
                    if(pri_min.empty())
                    {
                        size = 0;
                        continue;
                    }
                    maps[pri_min.top()]--;
                    pri_min.pop();
                }

            }
        }

        // size = 0
        if(size == 0)
        {
            cout << "EMPTY\n";
        }
        else
        {
            // 남아 있는 수 중에서 최댓값 찾기
            while(maps[pri_max.top()] == 0)
            {
                pri_max.pop();
            }

            // 남아 있는 수 중에서 최솟값 찾기
            while(maps[pri_min.top()] == 0)
            {
                pri_min.pop();
            }

            cout << pri_max.top() << " " << pri_min.top() << "\n";
        }
    }
}
