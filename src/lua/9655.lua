-- 백준 9655번 문제 : 돌 게임
-- https://www.acmicpc.net/problem/9655
-- 알고리즘 분류 : 수학, 다이나믹 프로그래밍, 게임 이론

-- This code requires Lua 5.3 or later.

n = tonumber(io.read("*n"))
-- Lua 5.1 does not support bitwise operators natively.
quotientByThree = n // 3
remainderByThree = n % 3

if (quotientByThree % 2 == 1 and remainderByThree ~= 1) or (quotientByThree % 2 == 0 and remainderByThree == 1) then
    print("SK")
else
    print("CY")
end
