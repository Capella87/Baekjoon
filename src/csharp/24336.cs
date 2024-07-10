// 백준 24336번 문제 : 가희와 무궁화호
// https://www.acmicpc.net/problem/24336
// 알고리즘 분류 : 수학, 구현, 자료 구조, 문자열, 해시를 사용한 집합과 맵

// We'll soon be arriving at Hwanggan station.
// Please make sure to take all your belongings with you when leaving the train. Thank you!

using System.Text;

string[] input = Console.ReadLine().Split(' ');
var stationInfo = new Dictionary<string, double>
{
    { "Seoul", 0.0 },
	{ "Yeongdeungpo", 9.1 },
	{ "Anyang", 23.9 },
	{ "Suwon", 41.5 },
	{ "Osan", 56.5 },
	{ "Seojeongri", 66.5 },
	{ "Pyeongtaek", 75.0 },
	{ "Seonghwan", 84.4 },
	{ "Cheonan", 96.6 },
	{ "Sojeongni", 107.4 },
	{ "Jeonui", 114.9 },
	{ "Jochiwon", 129.3 },
	{ "Bugang", 139.8 },
	{ "Sintanjin", 151.9 },
	{ "Daejeon", 166.3 },
	{ "Okcheon", 182.5 },
	{ "Iwon", 190.8 },
	{ "Jitan", 196.4 },
	{ "Simcheon", 200.8 },
	{ "Gakgye", 204.6 },
	{ "Yeongdong", 211.6 },
	{ "Hwanggan", 226.2 },
	{ "Chupungnyeong", 234.7 },
	{ "Gimcheon", 253.8 },
	{ "Gumi", 276.7 },
	{ "Sagok", 281.3 },
	{ "Yangmok", 289.5 },
	{ "Waegwan", 296.0 },
	{ "Sindong", 305.9 },
	{ "Daegu", 323.1 },
	{ "Dongdaegu", 326.3 },
	{ "Gyeongsan", 338.6 },
	{ "Namseonghyeon", 353.1 },
	{ "Cheongdo", 361.8 },
	{ "Sangdong", 372.2 },
	{ "Miryang", 381.6 },
	{ "Samnangjin", 394.1 },
	{ "Wondong", 403.2 },
	{ "Mulgeum", 412.4 },
	{ "Hwamyeong", 421.8 },
	{ "Gupo", 425.2 },
	{ "Sasang", 430.3 },
	{ "Busan", 441.7 }
};

int n = int.Parse(input[0]);
int q = int.Parse(input[1]);
var sb = new StringBuilder();
var mugunghwaHo = new Dictionary<string, (int Arrival, int Departure)>();
for (int i = 0; i < n; i++)
{
    var entry = Console.ReadLine()!.Split();
    int arrival = (entry[1] == "-:-") ? -1 : ParseTime(entry[1]);
    int departure = (entry[2] == "-:-") ? -1 : ParseTime(entry[2]);
    mugunghwaHo.Add(entry[0], (arrival, departure));
}
for (int i = 0; i < q; i++)
{
    var querys = Console.ReadLine()!.Split();
    sb.Append($"{GetScheduledSpeed(querys[0], querys[1])}\n");
}
Console.Write(sb.ToString());

int ParseTime(string time)
{
    int hour = Convert.ToInt32(time.Substring(0, 2));
    return (hour * 60) + Convert.ToInt32(time.Substring(3, 2));
}

int SubtractTime(int a, int b)
{
    if (a > b) b += 1440;
    return b - a;
}

double GetDistance(string departure, string destination)
{
    return Math.Abs(stationInfo[destination] - stationInfo[departure]);
}

double GetScheduledSpeed(string departure, string arrival)
{
    double distance = GetDistance(departure, arrival);
    double t = SubtractTime(mugunghwaHo[departure].Departure, mugunghwaHo[arrival].Arrival);
    return (distance / t) * 60.0;
}
