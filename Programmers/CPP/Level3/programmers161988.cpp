// Lv.3 - 161988번 : 연속 펄스 부분 수열의 합
// 작성자 : jeonghoe22(최정호)


#include <string>
#include <vector>

using namespace std;
using ll = long long;

long long solution(vector<int> sequence) {
    
    int size = sequence.size();
    vector<ll> seq1(size, 0);
    vector<ll> seq2(size, 0);
    
    // 2가지 경우에 대한 배열
    for(int i = 0; i < size; i++)
    {
        if(i % 2 == 0)
        {
            seq1[i] = sequence[i];
            seq2[i] = -sequence[i];
        }
        else
        {
            seq1[i] = -sequence[i];
            seq2[i] = sequence[i];   
        }
    }
    
    ll cur1 = seq1[0];
    ll cur2 = seq2[0];
    ll answer = max(cur1, cur2);
    
    for(int i = 1; i < size; i++)
    {
        // 초기화 or 누적
        cur1 = max(cur1 + seq1[i], seq1[i]);
        cur2 = max(cur2 + seq2[i], seq2[i]);
        
        answer = max(answer, max(cur1, cur2));
    }
    
    return answer;
}