import java.util.*;
class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {

        Deque<Integer> bridge = new ArrayDeque<>();
        // 다리 길이만큼 0으로 채워 시작 (빈 칸)
        for (int i = 0; i < bridge_length; i++) bridge.offer(0);

        int time = 0;
        int sum = 0;      // 현재 다리 위 트럭 무게 합
        int idx = 0;      // 다음에 올릴 트럭 인덱스
        while(idx<truck_weights.length || sum>0){
            time++;

            int out = bridge.poll()    ;
            sum -=out;

            if(idx< truck_weights.length){
                int next = truck_weights[idx];
                if(sum + next <= weight){
                    bridge.offer(next);
                    sum+=next;
                    idx++;
                }else{
                    bridge.offer(0);
                }
            }else{
                bridge.offer(0);
            }

        }
        int answer = 0;
        return time;
    }
}