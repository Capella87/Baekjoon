// 백준 11053번 문제 : 가장 긴 증가하는 부분 수열
// https://www.acmicpc.net/problem/11053
// 알고리즘 분류 : 다이나믹 프로그래밍

import java.util.*;
import java.io.*;

public class Main
{
    static int[] arr;
    static int[] lis;
    static int lastLis = 0;
    
    public static int lowerBound(int left, int right, int target)
    {
        while (left < right)
        {
            int mid = (left + right) / 2;
            
            if (lis[mid] < target) left = mid + 1;
            else right = mid;
        }
        
        return right;
    }
    
    public static void main(String[] args) throws IOException
    {
        var br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());
        arr = new int[n];
        lis = new int[n];
        
        var st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < n; i++)
            arr[i] = Integer.parseInt(st.nextToken());
        lis[0] = arr[0];
        
        for (int i = 1; i < n; i++)
        {
            if (lis[lastLis] < arr[i]) lis[++lastLis] = arr[i];
            else lis[lowerBound(0, lastLis, arr[i])] = arr[i];
        }
        
        System.out.println(lastLis + 1);
    }
}