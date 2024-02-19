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
    for(int i = 0; i < n; i++)
    {
        counts = 0;
        while(counts != k)
        {
            next++;
            if(next == n)
            {
                next = 0;
            }
            if(inputs[next] != 0)
            {
                counts++;
            }
        }

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