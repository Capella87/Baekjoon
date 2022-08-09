// 백준 1965번 문제 : 상자넣기
// https://www.acmicpc.net/problem/1965
// 알고리즘 분류 : 다이나믹 프로그래밍

import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int max = -1;
        var st = new StringTokenizer(br.readLine(), " ");
        int[] arr = new int[n];
        int[] cache = new int[n];
        
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i]) {
                    cache[i] = Math.max(cache[i], cache[j]);
                }
            }
                max = Math.max(max, ++cache[i]);
        }
        System.out.println(max);
    }
}