import java.util.*;
class Solution {
    /*
     */

    public int solution(String dirs) {
        Set<String> set = new HashSet<>();
        int answer = 0;
        int x =0;
        int y= 0;
        for(char c : dirs.toCharArray()){
            int nx =x;
            int ny =y;
            if(c == 'U'){
                ny++;
            }else if(c =='D'){
                ny--;
            }else if(c == 'R'){
                nx++;
            }else if(c == 'L'){
                nx--;
            }
            // 범위 밖이면 이동하지 않음
            if (nx < -5 || nx > 5 || ny < -5 || ny > 5) {
                continue;
            }

            // 현재 -> 다음
            String road1 = x + "," + y + "," + nx + "," + ny;

            // 다음 -> 현재
            String road2 = nx + "," + ny + "," + x + "," + y;

            if(!set.contains(road1)){
                answer++;
                set.add(road1);
                set.add(road2);
            }

            x =nx;
            y=ny;
        }

        return answer;
    }
}