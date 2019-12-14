#include<bits/stdc++.h>
#include<windows.h>
#define cl system("cls")
using namespace std;
const int N=100010;
int n,ans1,ans2,ans3,ans4,cnt=0;
int s1[N],s2[N],aa[N],bb[N],cc[N],dd[N];
void print()
{
	for(int i=1;i<=cnt;i++) cout<<aa[i]<<" "<<bb[i]<<" "<<cc[i]<<" "<<dd[i]<<"    "<<s1[i]<<"A"<<s2[i]<<"B"<<"\n";
}
bool check(int a,int b,int c,int d)
{
	int sum1=0,sum2=0;
	aa[++cnt]=a;
	bb[cnt]=b;
	cc[cnt]=c;
	dd[cnt]=d;
	if(a==ans1) sum1++; 
	if(b==ans2) sum1++; 
	if(c==ans3) sum1++; 
	if(d==ans4) sum1++; 
	if(a==ans2) sum2++; 
	else if(a==ans3) sum2++; 
	else if(a==ans4) sum2++; 
	if(b==ans1) sum2++; 
	else if(b==ans3) sum2++; 
	else if(b==ans4) sum2++; 
	if(c==ans2) sum2++; 
	else if(c==ans1) sum2++; 
	else if(c==ans4) sum2++; 
	if(d==ans2) sum2++; 
	else if(d==ans3) sum2++; 
	else if(d==ans1) sum2++; 
	if(sum1==4&&sum2==0) return 1;
	s1[cnt]=sum1,s2[cnt]=sum2;
	print();
	return 0;
}
int main()
{
	while(1)
	{
		srand(time(NULL));
		int t;
		cout<<"输入玩家人数";
		cin>>n;
		cl;
		cout<<"输入：\n";
		Sleep(100); 
		cout<<"1.请出题者随机出4个数\n";
		Sleep(100);
		cout<<"2.系统随机出4个数\n";
		cin>>t;
		cl;
		if(t==1) cin>>ans1>>ans2>>ans3>>ans4;
		else 
		do{
			ans1=rand()%9+1,ans2=rand()%9+1,ans3=rand()%9+1,ans4=rand()%9+1;
		}while(ans1==ans2||ans2==ans3||ans3==ans4||ans1==ans3||ans1==ans4||ans2==ans4);
		cout<<ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4<<" ";
		int f=1;
		while(f)
		{
			for(int i=1;i<=n;i++)
			{
				cout<<"请玩家"<<i<<"号 输入你猜测的数:";
				int a,b,c,d;
				cin>>a>>b>>c>>d;
				cl;
				if(check(a,b,c,d))
				{
					cout<<"玩家"<<i<<"号获胜！";
					Sleep(1000);
					f=0;
					break; 
				}				
			} 
		}
		cl;
	}
	return 0;
}

