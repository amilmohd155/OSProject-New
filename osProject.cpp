#include<bits/stdc++.h>
using namespace std;
class process{
	public:
		int start,burst,id,wait,tat;
		float priority;
    process() {
    priority=0;}
};
bool arrivalTime(process p1,process p2)
{
	return p1.start < p2.start;
}

bool priority(process p1, process p2) {
    return p1.priority < p2.priority;
}


int main()
{
	int n;
	n = 4;
	cout<<"Enter the number of processes\n";
	cin>>n;

	process *p=new process[n];

	for(int i=0;i<n;i++)
	{
		cout<<"arrival and burst time of Process "<<i+1<<"\n";
		cin>>p[i].start>>p[i].burst;
		p[i].id=i+1;

	}
	sort(p, p+n, arrivalTime);

	int j = 1;
	int k = 0;
	int time = 0;

    time += p[0].burst;
    p[0].tat = time - p[0].start;
    p[0].wait = p[0].tat - p[0].burst;
    p[0].priority = 0;


    while(j < n) {

        process pr = p[j];

        if(time >= pr.start) {

            for(int k = j; k < n; ++k) {
                p[k].wait = time - p[k].start;
                p[k].priority = 1 + ((float)p[k].wait / (float)p[k].burst);

            }

            int bigIndex=max_element(p+j,p+n,priority)-p;
            time += p[bigIndex].burst;
            p[bigIndex].tat = time - p[bigIndex].start;
            p[bigIndex].wait = p[bigIndex].tat - p[bigIndex].burst;


            j++;
            continue;

        }
        else {
            ++j;
            continue;
        }

    }
    cout<<"Time"<<time;
    int sumTat = 0;
    int sumWt = 0;
    for(int i = 0; i < n; ++i) {
        sumTat += p[i].tat;
        sumWt += p[i].wait;
    }
    cout<<"Average TurnAroundTime::"<<(float)sumTat/(float)n<<endl;
    cout<<"Average WaitingTime::"<<(float)sumWt/(float)n<<endl;

}
