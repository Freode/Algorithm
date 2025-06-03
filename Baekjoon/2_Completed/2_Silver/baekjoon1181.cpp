// 실버 5 - 1181번 : 단어 정렬
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

vector<string> g_words;

void inputData(const int N)
{
    g_words.reserve(N);
    unordered_map<string, bool> useWord;

    string input;
    for(int i = 0; i < N; i++)
    {
        cin >> input;
        
        if(useWord[input] == true)
            continue;
        
        g_words.push_back(input);
        useWord[input] = true;
    }
}

void sortData(const int N)
{
    sort(g_words.begin(), g_words.end(), [](const string& a, const string& b)
    {
        // 길이가 다르면, 더 짧은 순서대로 정렬
        if(a.length() != b.length())
            return a.length() < b.length();

        // 길이가 같다면, 사전순으로 정렬
        return a < b;
    });
}

void printData(const int N)
{
    for(const string& word : g_words)
        cout << word << "\n";
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 단어 개수 N
    int N;
    cin >> N;

    inputData(N);
    sortData(N);
    printData(N);
}