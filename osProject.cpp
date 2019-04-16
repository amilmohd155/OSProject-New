#include<bits/stdc++.h>
using namespace std;
class process{
	public:
		int start,end,priority,id;		
};
bool comp(process p1,process p2)
{
	return (p1.start<p2.start) || (p1.start==p2.start && p1.priority<p2.priority);
}
bool comp2(process p1,process p2)
{
	return  p1.priority<p2.priority;
}

int main()
{
	int n;
	cout<<"Enter the number of processes\n";
	cin>>n;
	
	process *p=new process[n];
	
	vector<process>q;
	
	int max_start=0;
	for(int i=0;i<n;i++)
	{
		cout<<"Start and End time of Process "<<i+1<<"\n";
		cin>>p[i].start>>p[i].end;
		p[i].id=i+1;
		p[i].priority=p[i].end-p[i].start;
		
		if(p[i].start>max_start)
		max_start=p[i].start;
		
		q.push_back(p[i]);
	}
	sort(p,p+n,comp);	
	
	int j=0;
	int time=0;
	
	while(j<n)
	{
			int turn_around=p[j].end-p[j].start;
		if(time>=p[j].start)
		{
			process pr=p[j];
			
			
			
			cout<<"Process "<<p[j].id<<" is getting executed from time "<<time<<" to "<<time+turn_around<<"\n";
			j++;
		
		
		
			for(int k=0;k<turn_around;k++)
			{
				for(int i=j+1;i<n;i++)
				{
					if(time>p[i].start)
					p[i].priority--;
				}
				time++;
			}
		}
		else
		{
			cout<<"Process "<<p[j].id<<" is getting executed from time "<<time<<" to "<<time+turn_around<<"\n";
			j++;
		}
		
		sort(p+j,p+n,comp);
		
		if(time>max_start)
		sort(p+j,p+n,comp);
	}

	
	
	
}