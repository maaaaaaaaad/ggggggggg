#include <string>
#include <vector>
#include <cmath>
#include <queue>
#define MAX 101

using namespace std;

int cnt;
vector<int> info[MAX];

void bfs(int v1, int v2) {
    queue<int> q;
    vector<bool> visited(MAX);
    
    q.push(v1);
    visited[v1] = true;
    visited[v2] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int i=0; i<info[node].size(); i++) {
            int node2 = info[node][i];
                                                 
            if (visited[node2]) continue;
            
            cnt++;
            q.push(node2);
            visited[node2] = true;
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = MAX;
    
    for (auto wire: wires) {
        info[wire[0]].push_back(wire[1]);
        info[wire[1]].push_back(wire[0]);
    }
    
    for (auto wire: wires) {
        cnt = 1;
        int v1 = wire[0];
        int v2 = wire[1];
       
        bfs(v1, v2);
        answer = min(answer, abs(2 * cnt - n));
   }
    
    return answer;
}