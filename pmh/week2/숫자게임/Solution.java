import java.util.*;
class Solution {
    /*
    A보다 큰수중 최솟값

    */
    public int solution(int[] A, int[] B) {

        int answer = 0;
        Arrays.sort(A);
        Arrays.sort(B);
        int idx =0;
        for(int i=0;i<A.length;i++){
            if(A[idx]<B[i]){
                idx++;
                answer++;
            }

        }




        return answer;
    }
}