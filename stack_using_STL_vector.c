/* https://programmers.co.kr/learn/courses/30/lessons/42586 */

#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;    
    for(int i=0, cnt=0, prev=0;i<progresses.size();i++)
    {
        int day = ceil((100.0-progresses[i])/speeds[i]);        
        if(day>prev)
        {
            answer.push_back(1);
            prev = day;
            cnt = 0;
        }
        else
        {
            answer[answer.size()-1]++;
        }
        cnt++;
    }
    return answer;
}
