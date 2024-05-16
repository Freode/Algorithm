// Lv.2 - 12909번 : 올바른 괄호 
// 작성자 : jeonghoe22(최정호)

#include<string>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    int count = 0;
    for(char& each : s)
    {
        // )일 때, -1 증가
        if(each == ')')
        {
            count-=1;
        }
        // (일 때, 1 증가
        else
        {
            count+=1;
        }
        
        // 음수로 진입하는 순간 거짓으로 판단
        if(count < 0)
        {
            answer = false;
            break;
        }
    }
    
    // 결과값이 양수여도 거짓으로 판단
    if(count > 0)
    {
        answer = false;
    }

    return answer;
}