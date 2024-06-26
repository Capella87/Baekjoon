// 백준 2239번 문제 : 스도쿠
// https://www.acmicpc.net/problem/2239
// 알고리즘 분류 : 구현, 백트래킹

using System.Text;

var sudokuBoard = new int[9, 9];
for (int i = 0; i < 9; i++)
{
    var temp = Console.ReadLine();
    for (int j = 0; j < 9; j++)
        sudokuBoard[i, j] = (int)temp![j] - (int)'0';
}
SolveSudokuRecursive();
PrintSudoku(sudokuBoard);

bool IsValidSudoku(int row, int col, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (sudokuBoard[row, i] == num) return false;
        if (sudokuBoard[i, col] == num) return false;
        if (sudokuBoard[((row / 3) * 3) + (i / 3), (col / 3 * 3) + (i % 3)] == num)
            return false;
    }
    return true;
}

bool SolveSudokuRecursive(int row = 0, int col = 0)
{
    if (col == 9)
    {
        row++;
        col = 0;
    }
    if (row == 9) return true;
    if (sudokuBoard[row, col] != 0) return SolveSudokuRecursive(row, col + 1);

    for (int i = 1; i <= 9; i++)
    {
        if (IsValidSudoku(row, col, i))
        {
            sudokuBoard[row, col] = i;
            if (SolveSudokuRecursive(row, col + 1)) return true;
            sudokuBoard[row, col] = 0;
        }
    }
    return false;
}

void PrintSudoku(int[,] board)
{
    var sb = new StringBuilder();
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            sb.Append(board[i, j]);
        sb.Append('\n');
    }
    Console.Write(sb.ToString());
}
