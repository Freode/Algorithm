// Lv.2 - 42842번 : 카펫 
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    // 모든 약수 찾기
    vector<int> aliquots;
    for(int i = 1; i <= (int)(sqrt(yellow)); i++)
    {
        if(yellow % i == 0)
        {
            aliquots.push_back(i);
        }
    }

    // 모든 약수에 대한 검사
    int check_brown = 0;
    for(int& aliquot : aliquots)
    {
        // 갈색 테두리 길이 = 2 * 노랑 세로 + 2 * 노랑 가로 + 모서리 4개
        check_brown = (aliquot * 2) + (yellow / aliquot * 2) + 4;
        
        // 찾은 경우
        if(check_brown == brown)
        {
            // 가로 길이가 더 길고 모서리 부분 길이까지 포함
            answer.push_back(yellow / aliquot + 2);
            answer.push_back(aliquot + 2);
            break;
        }
    }

    return answer;
}