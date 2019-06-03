//#include <iostream>
//#include <vector>
//#include <climits>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//
//int main(){
//	int N, M;
//	while (cin >> N >> M){
//		vector<int> steps(M + 1, INT_MAX);
//		steps[N] = 0;
//		for (int i = N; i <= M; i++){
//			if (steps[i] == INT_MAX){
//				continue;
//			}
//			for (int j = 2; (j*j) <= i; j++){
//				if (i%j == 0){
//					if (i + j <= M){
//						steps[i + j] = min(steps[i] + 1, steps[i + j]);
//					}
//					if (i + (i / j) <= M){
//						steps[i + (i / j)] = min(steps[i] + 1, steps[i + (i / j)]);
//					}
//
//				}
//
//			}
//		}
//		if (steps[M] == INT_MAX){
//			steps[M] = -1;
//		}
//		cout << steps[M] << endl;
//	}
//	return 0;
//}


#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() 
{    
	string str;    
	while (getline(cin, str)) 
	{        
		bool flag = false;        
		vector<string> vec;        
		string row;        
		for (int i = 0; i < str.size(); i++) 
		{            
			if (flag) 
			{
				//ÔÚÀ¨ºÅÄÚ                
				if (str[i] != '\"') 
					row += str[i];                
				else 
					flag = false;            
			} 
			else 
			{                
				if (str[i] == ' ') 
				{                   
					vec.push_back(row);                    
					row = "";                
				} 
				else if (str[i] == '\"') 
					flag = true;               
				else row += str[i];           
			}       
		}        
		vec.push_back(row);       
		cout << vec.size() << endl;        
		for (auto i : vec) 
			cout << i << endl;    
	}    
	return 0;
}