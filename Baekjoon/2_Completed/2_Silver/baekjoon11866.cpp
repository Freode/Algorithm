// 실버 5 - 11866번 : 요세푸스 문제 0
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    int k, n;
    cin >> n >> k;

    vector<int> inputs(n);
    for(int i = 0; i < n; i++)
    {
        inputs[i] = i + 1;
    }

    vector<int> outputs;
    int next = -1;
    int counts = 0;

    // 요세푸스 순열
    for(int i = 0; i < n; i++)
    {
        counts = 0;
        // 다음 순서 번호 찾기
        while(counts != k)
        {
            next++;
            // 범위를 벗어났을 경우, 처음으로 이동
            if(next == n)
            {
                next = 0;
            }
            // 아직 방문하지 않은 경우, 순서 증가
            if(inputs[next] != 0)
            {
                counts++;
            }
        }

        // 다음으로 방문해야할 곳에 방문
        outputs.push_back(inputs[next]);
        inputs[next] = 0;
    }

    // 출력
    cout << "<";
    for(int i = 0; i < outputs.size(); i++)
    {
        cout << outputs[i];
        if(i != (int)outputs.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << ">\n";

}