#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm> 

using namespace std;
int a[55];
long long ans[55][15][2];
int flag[55][15];
int main()
{    
	int n,k,d;  
	cin>>n; 
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	cin>>k>>d;   
	memset(ans,0,sizeof(ans));
	memset(flag,0,sizeof(flag));  
	for(int i=1;i<=n;i++)
	{        
		ans[i][1][0]=a[i]; 
		ans[i][1][1]=a[i];       
		flag[i][1]=1;    
	}    
	for(int i=1;i<=n;i++)   
	{    
		for(int j=1;j<=k;j++)   
		{      
			if(flag[i][j]!=1)     
				continue;      
			for(int p=i+1;p<=n&&p<=i+d;p++) 
			{        
				if(flag[p][j+1]==1)   
				{
					ans[p][j+1][0]= max(ans[p][j+1][0],max(ans[i][j][0]*a[p],ans[i][j][1]*a[p])); 
					ans[p][j+1][1]=min(ans[p][j+1][1],min(ans[i][j][0]*a[p],ans[i][j][1]*a[p])); 
				}           
				else   
				{      
					ans[p][j+1][0]=max(ans[i][j][0]*a[p],ans[i][j][1]*a[p]);   
					ans[p][j+1][1]=min(ans[i][j][0]*a[p],ans[i][j][1]*a[p]);   
					flag[p][j+1]=1;       
				}       
			}     
		}  
	} 
	long long sum=ans[k][k][0]; 
	for(int i=k+1;i<=n;i++) 
		sum=max(sum,ans[i][k][0]);  
	cout<<sum<<endl;   
	return 0;
}