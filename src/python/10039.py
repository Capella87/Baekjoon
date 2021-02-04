# 백준 10039번 문제 : 평균 점수
# https://www.acmicpc.net/problem/10039
# 알고리즘 분류 : 수학, 사칙연산

def GetMean(list1, num=5):
    total = 0
    for i in range(0, num):
        if list1[i] < 40:
            total += 40
        else:
            total += list1[i]
    return int(total / num)

people = []
num = 5
for i in range(0, num):
    people.append(int(input()))
print(GetMean(people))
