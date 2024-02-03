// 실버 4 - 1764번 : 듣보잡
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <unordered_map>
#include <string>
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

    unordered_map<string, int> name_list(N + M);

    string name;
    int duplication_count = 0;
    // 사람 이름 입력
    for(int i = 0; i < N; i++)
    {
        cin >> name;
        name_list[name] = 1;
    }
    // 보도 못한 사람 입력
    for(int i = 0; i < M; i++)
    {
        cin >> name;
        auto iter = name_list.find(name);
        // 중복인 경우
        if(iter != name_list.end())
        {
            name_list[name] = 2;
            duplication_count++;
        }
    }

    // 사전순으로 정리
    vector<string> duplication_name;
    for(auto iter : name_list)
    {
        if(iter.second == 2)
        {
            duplication_name.push_back(iter.first);
        }
    }
    sort(duplication_name.begin(), duplication_name.end());

    // 중복인 경우 출력
    cout << duplication_count << "\n";
    for(string &each : duplication_name)
    {
        cout << each << "\n";
    }
}