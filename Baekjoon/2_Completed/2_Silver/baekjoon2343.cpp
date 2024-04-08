// 실버 1 - 2343번 : 기타 레슨
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력 
    int N, M;
    cin >> N >> M;

    int left = 0, right = 0, pivot = 0, count = 1, max = 0;
    vector<int> inputs(N, 0);
    vector<int> bluerays(M, 0);
    for(int& each : inputs)
    { 
        cin >> each; 
        right += each;
        // 강의 중에서 가장 긴 값을 최솟값으로 설정
        if(left < each){ left = each; }
    }

    // 블루레이 개수가 1일때는 그냥 출력하도록 하기
    if(M == 1)
    {
        pivot = right;
    }
    // 블루레이 개수는 강의 수만큼 최대로 존재할 수 있으므로
    // 최솟값은 강의 중에서 가장 큰 값
    // 최댓값은 전체합
    // 기준은 2가지 
    // 1. 블루레이 개수를 모두 사용할 경우
    // 2. 마지막 블루레이 크기가 pivot을 넘기는지 확인 여부
    else
    {
        while(left <= right)
        {
            pivot = (left + right) / 2;
            // 각 블루레이마다 강좌 넣기
            max = 0;
            bluerays.clear();
            bluerays.push_back(0);
            count = 1;
            for(int& each : inputs)
            {
                // 
                if(bluerays[count-1] + each <= pivot)
                {
                    bluerays[count-1] += each;
                }
                else
                {
                    // 블루레이 중 최댓값 찾기
                    if(bluerays[count-1] > max){ max = bluerays[count-1]; }
                    count++;
                    bluerays.push_back(each);
                }
            }

            // 마지막 블루레이의 크기 검사
            if(bluerays[count-1] > max){ max = bluerays[count-1]; }

            // 가능한 경우인지 확인
            // 1. 카운트 개수 판단
            // 블루레이 개수가 부족한(부족하거나 같은) 경우에는 한 개의 블루레이 허용 크기를 줄여야 함.
            if(count <= M){ right = pivot - 1; }
            // 블루레이 개수가 많은 경우에는 한 개의 블루레이 허용 크기를 늘려야 함.
            else if(count > M){ left = pivot + 1; }

            // 블루레이 개수가 같거나 큰 경우 -> 블루레이 크기를 둘 다 줄일 수 있을거라고 판단 가능하므로
            // 아래 코드는 생략할 수 있음.

            // 블루레이 개수가 같은 경우 판단
            // else
            // {        
            //     // 2. 블루레이 중 최대 크기 검사
            //     // 최대 크기가 기준치보다 작은 경우에는 블루레이 허용 크기를 줄여도 됨.
            //     if(max < pivot){ right = pivot - 1; }
            //     // 최대 크기가 기준치보다 큰 경우에는 블루레이 허용 크기를 키워도 됨.
            //     else if(max > pivot){ left = pivot + 1;}
            //     // 목표값을 찾은 경우 - 가능한 크기 중에서 최소를 구하는 것이므로 left
            //     else { left = pivot; break; }
            // }
        }
    }

    // 출력
    cout << left << "\n";

}