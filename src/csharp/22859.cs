// 백준 15988번 문제 : HTML 파싱
// https://www.acmicpc.net/problem/22859
// 알고리즘 분류 : 구현, 문자열, 파싱, 정규 표현식

// Pretty verbose code..

using System.Text;

var html = Console.ReadLine();
int croppedLen = html.Length - 7;
int idx = 6;
var sb = new StringBuilder();
TagTypeEnum tagType = TagTypeEnum.Opening;
TagNameEnum tag = TagNameEnum.Others;
bool isSpaceStarted = false;
(string, string)? pr = null;

while (idx < croppedLen)
{
    if (html[idx] == '<')
    {
        idx = ParseTag(html, idx, out tagType, out tag, out pr);

        if (tagType == TagTypeEnum.Opening)
        {
            switch (tag)
            {
                case TagNameEnum.P:
                    // Remove spaces
                    while (idx < croppedLen && html[idx] == ' ')
                        idx++;
                    isSpaceStarted = false;
                    break;
                case TagNameEnum.Div:
                    sb.AppendLine($"{pr.Value.Item1} : {pr.Value.Item2}");
                    break;
                case TagNameEnum.Others:
                    break;
            }
        }
        else
        {
            switch (tag)
            {
                case TagNameEnum.P:
                    isSpaceStarted = false;
                    sb.Append('\n');
                    break;
            }
        }
        continue;
    }

    if (html[idx] == ' ')
    {
        while (idx < croppedLen && html[idx] == ' ')
            idx++;
        if (!isSpaceStarted)
            isSpaceStarted = true;
    }
    else
    {
        if (isSpaceStarted)
        {
            isSpaceStarted = false;
            sb.Append(' ');
        }

        sb.Append(html[idx++]);
    }
}

Console.Write(sb.ToString());

int ParseTag(string code, int idx, out TagTypeEnum tagType, out TagNameEnum tagName, out (string, string)? property)
{
    tagType = TagTypeEnum.Opening;
    tagName = TagNameEnum.Others;
    if (idx >= code.Length)
    {
        tagName = TagNameEnum.NotATag;
        property = null;
        tagType = TagTypeEnum.NotATag;

        return idx;
    }

    if (code[++idx] == '/')
    {
        tagType = TagTypeEnum.Closing;
        property = null;
        ++idx;
    }

    int parseStartIdx = idx;
    while (idx < code.Length && code[idx] != ' ' && code[idx] != '>')
    {
        idx++;
    }

    string tag = code.Substring(parseStartIdx, idx - parseStartIdx);

    if (tag == "p")
    {
        tagName = TagNameEnum.P;
    }
    else if (tag == "div")
    {
        tagName = TagNameEnum.Div;
    }
    else tagName = TagNameEnum.Others;

    while (idx < code.Length && code[idx] == ' ')
        idx++;

    if (tagType == TagTypeEnum.Closing || (tagName != TagNameEnum.Div && tagType == TagTypeEnum.Opening))
    {
        property = null;
        return idx + 1;
    }

    // Parse a property
    parseStartIdx = idx;
    while (idx < code.Length && code[idx] != '=')
    {
        idx++;
    }
    string prop = code.Substring(parseStartIdx, idx - parseStartIdx);
    idx += 2;

    parseStartIdx = idx;
    while (idx < code.Length && code[idx] != '"')
    {
        idx++;
    }
    string v = code.Substring(parseStartIdx, idx - parseStartIdx);

    while (code[idx] != '>')
        idx++;
    property = (prop, v);

    return idx + 1;
}

enum TagNameEnum
{
    P,
    Div,
    Others,
    NotATag,
}

enum TagTypeEnum
{
    Init,
    Opening,
    Closing,
    NotATag
}
