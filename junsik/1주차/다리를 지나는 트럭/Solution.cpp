#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    //1칸당 1초라고 생각하면서 풀기
    //선입선출 필요할듯?
    
    int answer = 0; //시간으로 계산
    int cur_weight = 0;
    int idx = 0;
    queue<int> bridge_truck;
    
    //큐 안에는 다리 길이만큼 0으로 채우기
    for(int i = 0; i<bridge_length; i++){
        bridge_truck.push(0);
    }
    
    while(idx < truck_weights.size()){
        answer++; //시간 흐르기
        
        cur_weight -= bridge_truck.front();
        bridge_truck.pop();
        
        if(cur_weight + truck_weights[idx] <= weight){
            bridge_truck.push(truck_weights[idx]);
            cur_weight += truck_weights[idx];
            idx++;
        }
        
        else{
            bridge_truck.push(0);
        }
    }
    
    answer += bridge_length;
    
    return answer;
}