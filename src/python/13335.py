# 백준 13335번 문제 : 트럭
# https://www.acmicpc.net/problem/13335
# 알고리즘 분류 : 구현, 자료 구조, 시뮬레이션, 큐

from collections import deque
import sys


def solution(bridge_length: int, weight: int, truck_weights: list[int], trucks: int):
    elapsed = 0
    current_weight = 0
    bridge = deque()
    ord = 0
    passed = 0
    estimated_time_to_pass = deque()
    
    while passed < trucks:
        if len(estimated_time_to_pass) > 0 and estimated_time_to_pass[0] == elapsed:
            current_weight -= bridge.popleft()
            estimated_time_to_pass.popleft()
            passed += 1

        if ord < trucks and len(bridge) < bridge_length and truck_weights[ord] + current_weight <= weight:
            bridge.append(truck_weights[ord])
            estimated_time_to_pass.append(elapsed + bridge_length)
            current_weight += truck_weights[ord]
            ord += 1
        elapsed += 1
        
    return elapsed

n, w, l = map(int, sys.stdin.readline().split())
trucks = list(map(int, sys.stdin.readline().split()))

print(solution(w, l, trucks, n))
