//#include<iostream>
//#include<string.h>
//using namespace std;
//int a[20][20] = {0},res = 0,m,n;//注意是全局变量，多组数据时要在最后初始化
//void dfs(int x,int y)
//{    
//	if(a[x][y]==1||x<0||x>=m||y<0||y>=n)//递归的边界条件    
//		return ;   
//	res++;  //结果增加1   
//	a[x][y] = 1;//置1代表已经走过  
//	dfs(x-1,y);//分别对应上   
//	dfs(x+1,y);//下    
//	dfs(x,y-1);//左  
//	dfs(x,y+1);//右相邻格子  
//}
//int main()
//{  
//	while(~scanf("%d %d",&m,&n))  
//	{     
//		getchar();//为什么要getchar()?因为第一行9 6后面还有一个换行符  
//		int x,y;      
//		char c;     
//		for(int i=0;i<m;i++)    
//		{           
//			for(int j=0;j<n;j++)  
//			{             
//				scanf("%c",&c);      
//				if(c=='@')            
//				{               
//					x = i;          
//					y = j;           
//				}
//				else
//				{    
//					if(c=='#')            
//						a[i][j] = 1;  
//				}       
//			}           
//			getchar();//同样的，吃掉每行最后一个换行符  
//		}      
//		dfs(x,y);     
//		printf("%d\n",res);   
//		res = 0;      
//		memset(a,0,sizeof(a));//全局变量初始化 
//	}    
//	return 0;
//}


//#include <iostream>
//#include <iomanip>
//#include<cstring>
//
//using namespace std;
//int has[25][25];//有无蘑菇
//double dp[25][25];//能够到达每个格子的概率 
//int main()
//{   
//	int n, m, k;   
//	while(cin >> n >> m >> k)
//	{       
//		int i, j;   
//		memset(has, 0, sizeof(has));   
//		memset(dp, 0, sizeof(dp));   
//		int x, y;     
//		for(i = 0; i < k; ++i)
//		{          
//			cin >> x >> y;   
//			has[x][y] = 1;   
//		}       
//		for(i = 1; i <= n; ++i)
//		{        
//			for(j = 1; j <= m; ++j)
//			{          
//				if(i == 1 && j == 1) 
//				{
//					dp[1][1] = 1; continue;
//				}       
//				if(has[i][j]) 
//				{
//					dp[i][j] = 0; continue;
//				}              
//				if(i == n && j == m) 
//				{
//					dp[i][j] = dp[i-1][j] + dp[i][j-1]; continue;
//				}             
//				if(i == n) {
//					dp[i][j] = dp[i-1][j]*0.5 + dp[i][j-1]; continue;
//				}          
//				if(j == m) {
//					dp[i][j] = dp[i-1][j] + dp[i][j-1]*0.5; continue;
//				}              
//				if(i == 1) {
//					dp[i][j] = dp[i][j-1]*0.5; continue;
//				}              
//				if(j == 1) {
//					dp[i][j] = dp[i-1][j]*0.5; continue;
//				}            
//				dp[i][j] = dp[i][j-1]*0.5 + dp[i-1][j]*0.5;     
//			}     
//		}       
//		cout << fixed << setprecision(2) << dp[n][m] << endl; 
//	}   
//	return 0;
//}
