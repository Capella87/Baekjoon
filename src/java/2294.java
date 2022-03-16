// 백준 2294번 문제 : 동전 2
// https://www.acmicpc.net/problem/2294
// 알고리즘 분류 : 다이나믹 프로그래밍

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    private static int[] coins;
    private static int[] cache;
    private static int n;
    
    private static int getMinimum(int k)
    {
        if (cache[k] != 0 || k == 0) return cache[k];
        
        cache[k] = -1;
        for (int i = 0; i < n; i++)
        {
            if (k < coins[i]) continue;
            int received = getMinimum(k - coins[i]);
            if (received == -1) continue;
            int temp = received + 1;
            if (cache[k] == -1 || cache[k] > temp) cache[k] = temp;
        }
        
        return cache[k];
    }
    
	public static void main(String[] args) throws IOException
	{
	    var br = new BufferedReader(new InputStreamReader(System.in));
	    
	    String[] first = br.readLine().split(" ");
	    n = Integer.parseInt(first[0]);
	    int k = Integer.parseInt(first[1]);
	    
	    coins = new int[n];
	    cache = new int[k + 1];
	    for (int i = 0; i < n; i++)
	        coins[i] = Integer.parseInt(br.readLine());
	    System.out.println(getMinimum(k));
	}
}