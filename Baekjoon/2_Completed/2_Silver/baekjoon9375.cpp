// 실버 3 - 9375번 : 패션왕 신해빈
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int simulate()
{
    // 의상 수 n
    int n;
    cin >> n;

    unordered_map<string, int> umap;
    vector<int> clothes;

    string name, kind;
    int kind_case = 1;
    for(int i = 0; i < n; i++)
    {
        cin >> name >> kind;

        // 새로운 옷 종류
        if(umap[kind] == 0)
        {
            umap[kind] = kind_case;
            kind_case++;
            clothes.push_back(1);
        }
        // 기존 옷 종류
        else
        {
            clothes[umap[kind] - 1]++;
        }
    }

    // 조합
    int result = 1;
    for(int i = 0; i < kind_case-1; i++)
    {
        result *= (clothes[i] + 1);
    }

    return result - 1;

}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 테스트 케이스 입력
    int T;
    cin >> T;

    for(int i = 0; i < T; i++)
    {
        cout << simulate() << "\n";
    }
}