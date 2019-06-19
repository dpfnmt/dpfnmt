//#include<iostream>
//#include<string>
//
//using namespace std;
//
//int main()
//{
//	string s;
//	while (cin >> s)
//	{
//		int v[256] = { 0 };
//		for (auto& e : s)
//		{
//			v[e]++;
//		}
//		int i = 0;
//		for (i = 0; i < s.size(); i++)
//		{
//			if (v[s[i]] == 1)
//			{
//				cout << s[i] << endl;
//				break;
//			}
//		}
//		if (i >= s.size())
//		{
//			cout << -1 << endl;
//		}
//	}
//	return 0;
//}
//#include<vector>
//#include<iostream>
//using namespace std;
//
//int GCD(int a, int b)
//{
//	int c;
//	while (c = a % b)
//	{
//		a = b;
//		b = c;
//	}
//	return b;
//}
//int main()
//{
//	int n, power;
//	vector<int> num;
//	while (cin >> n >> power)
//	{
//		num.resize(n);
//		for (int i = 0; i < n; i++)
//		{
//			cin >> num[i];
//		}
//		for (int k = 0; k < n; k++)
//		{
//			if (num[k] < power)
//			{
//				power += num[k];
//			}
//			else
//			{
//				power += GCD(power, num[k]);
//			}
//		}
//		cout << power << endl;
//	}
//	return 0;
//}

class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		sort(gifts.begin(), gifts.end());
		//超过一半的数排序之后必然排在中间
		int middle = gifts[n / 2];
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			//统计排在中间的数的个数
			if (gifts[i] == middle)
			{
				count++;
			}
		}
		//如果个数大于一半，则存在超过一半的数
		if (count > n / 2)
			return middle;
		else
			return 0;
	}
};