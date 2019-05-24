#include<iostream>
using namespace std;

 //int main()
 //{   
	// int a, b, c, d;    
	// int A, B, C;    
	// while(cin>>a>>b>>c>>d)    
	// {        
	//	 A=(a+c)/2;        
	//     B=(b+d)/2;        
	//	 C=(d-b)/2;        
	//	 if(A-B==a && B-C==b && A+B==c && B+C==d)        
	//	 {            
	//		 cout<<A<<" "<<B<<" "<<C<<endl;        
	//	 }        
 //        else        
	//	 {            
	//           cout<<"NULL"<<endl;        
 //        }    
	// }    
	// return 0;
 //}


//int main()
//{ 
//	int n1, n2, n3, n4, A1, B1, C1; 
//	int A, B, C; 
//	scanf("%d %d %d %d", &n1, &n2, &n3, &n4); 
//	A = (n1 + n3) / 2; 
//	B = (n2 + n4) / 2; 
//	C = n4 - B; 
//	A1 = (int)A; 
//	B1 = (int)B; 
//	C1 = (int)C; 
//   if ((A1 == A) && (B1 == B) && (C1 == C) && (A1 >= 0) && (B1 >= 0) && (C1 >= 0))  
//	   printf("%d %d %d", A1, B1, C1); 
//   else 
//	   printf("No"); 
//   return 0; 
//}

//int main()
//{
//	int n1, n2, n3, n4, A1, B1, C1;
//	int A, B, C;
//	while (cin >> n1 >> n2 >> n3 >> n4)
//	{
//		A = (n1 + n3) / 2;
//		B = (n2 + n4) / 2;
//		C = n4 - B;
//		A1 = (int)A;
//		B1 = (int)B;
//		C1 = (int)C;
//		if ((A1 == A) && (B1 == B) && (C1 == C) && (A1 >= 0) && (B1 >= 0) && (C1 >= 0))
//			cout << A << " " << B << " " << C << endl;
//		else
//			cout << "NULL" << endl;
//	}
//	return 0;
//}


#include <stdio.h> 
//int main()
//{
//	char a[10] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', 0 }, *p; int i;
//	i = 7;
//	p = a + i;
//	printf("%s\n", p - 3);
//	return 0;
//}
//int func()
//{
//	int i, j, k = 0;
//	for (i = 0, j = -1; j = 0; i++, j++)
//	{
//		k++;
//	}
//	return k;
//}
//int main()
//{
//	int b = 10;
//	//const int *a = &b; //前两个是一样的， 不能被修改的。
//	//int const *a = &b;
//	int *const a = &b;
//	a = 20;
//	printf("%d\n", a);
//}

#include <iostream>
//#include <vector>
//using namespace std;
//int main(void)
//{
//	vector<int>array;
//	array.push_back(100);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(500);
//	vector<int>::iterator itor;
//	for (itor = array.begin(); itor != array.end(); itor++)
//	{
//		cout << *itor << " ";
//		//cout << endl;;
//		
//		if (*itor == 300)
//		{
//			itor = array.erase(itor);
//			cout << *itor << " " ;
//		}
//	
//	}
//	/*for (itor = array.begin(); itor != array.end(); itor++)
//	{
//		cout << *itor << " ";
//	}*/
//	cout << endl;
//	return 0;
//}
//#include<iostream>
//#include<vector>
//#include<map>;
//using namespace std;
//
//int main()
//{
//	vector<int> v;
//	int n;
//	while (cin >> n)
//	{
//		v.push_back(n);
//		//cout <<" ";
//
//		map<int, int> countmap;
//		for (int i = 0; i < v.size(); i++)
//		{
//			cout << countmap[v[i]];
//			//cout << countmap[v[i]++];
//		}
//
//		for (int j = 0; j < v.size(); j++)
//		{
//			 
//			if (countmap[v[j]] > v.size() / 2)
//			{
//				cout << v[j];
//			}
//		}
//	}
//	system("pause");
//	return 0;
//}