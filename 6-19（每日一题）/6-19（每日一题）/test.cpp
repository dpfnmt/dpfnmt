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
		//����һ���������֮���Ȼ�����м�
		int middle = gifts[n / 2];
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			//ͳ�������м�����ĸ���
			if (gifts[i] == middle)
			{
				count++;
			}
		}
		//�����������һ�룬����ڳ���һ�����
		if (count > n / 2)
			return middle;
		else
			return 0;
	}
};