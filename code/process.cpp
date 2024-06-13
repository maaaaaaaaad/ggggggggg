#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> que;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
    
    int len = priorities.size();
    for(int i = 0; i < len; i++) {
        que.push({priorities[i], i});
        pq.push({priorities[i], i});
    }

    while(!pq.empty()) {
        
        pair<int, int> max = pq.top();
        pair<int, int> top = que.front();
        
        que.pop();
        
        if(max.first == top.first) {
            pq.pop();
            answer++;
            
            if(top.second == location)
                break;
            
        } else
            que.push(top);  
    }
    return answer;
}