#include<stdio.h>
#include <stdlib.h>
#define N 100
int check=0;
int rpro=0;
int counter=0;
void Level2_Round_Robin();
struct level1_process{
	int arrival_t,burst_t,priority,process_id,current_burst_t;
};
void Level_2_Ready_Queue(struct level1_process queue);
struct level2_process2{
	int arrival_t2,burst_t2,priority_2,process_id2;
}process_2[N];
int main(){
	int total_processes,time,i,l,m;
        int j=0,k=1,count=0,flag=0;
	printf("Enter no. of processes :");
	scanf("%d",&total_processes);
	struct level1_process process[total_processes];
for(i=0;i<total_processes;i++)//loop for getting processes details
    {		printf("Enter process id\n ");
			scanf("%d",&process[i].process_id);
			printf("Enter arrival time of %d :",process[i].process_id);
			scanf("%d",&process[i].arrival_t);
                        printf("Enter priority of %d :",process[i].process_id);
                        scanf("%d",&process[i].priority);
			printf("Enter burst time of %d :",process[i].process_id);
			scanf("%d",&process[i].burst_t);
                        process[i].current_burst_t=process[i].burst_t;//to store the burst time of current process
			system("clear");//clears the screen
			}
                 printf("Gantt chart for level 1 priority scheduling :\n");
			int flag1=0;
		for(i=0;i<total_processes;i++){
		int burst_td=process[i].current_burst_t;
		int iterator=0;
		k=1;
			for(j=0;j<burst_td;j++)
                        {
			if(i==0 && process[i].arrival_t!=0){
					for(l=0;l<process[i].arrival_t;l++){
							count++	;
											}
			time=process[i].arrival_t;
			printf("|%d\tprocess[%d]\t%d|",0,0,time);
				}
			else if(i==0 && process[i].arrival_t==0 && iterator==0){
				for(l=0;l<process[i+1].arrival_t;l++){
					count++;
					process[i].burst_t--;
				}
			flag1=1;
				printf("|%d\tprocess[%d]\t%d|",process[i].arrival_t,process[i].process_id,count);
				time=process[i].arrival_t+count;
}
if(i==(total_processes-1)){
				if(counter==1);
				for(m=0;m<process[i].burst_t;m++){
					count++;
		         	}
				printf("|%d\tprocess[%d]\t%d|",time,process[i].process_id,count);
	break;}
	if( count!=0 && ((count%2)==0) && (process[k+i].priority>process[i].priority))//compare the priorities
        {
					printf("|%d\tprocess[%d]\t%d|",time,process[i].process_id,count);
					time=count;
					count++;
					process[i].burst_t--;
					flag++;
					k++;
					iterator=1;
					continue;
				}
				else if( count!=0 && ((count%2)==0) && (process[i+k].priority < process[i].priority)){//compare the priorities
				if(k==2){
				printf("|%d\tprocess[%d]\t%d|",time,process[i].process_id,count);
				check++;
				Level_2_Ready_Queue(process[i+1]);//preempt the process with low pririty to level 2 
				i=i+1;
				iterator=1;
				time=count;
				count++;
				process[i+1].burst_t--;
				counter=1;
					break;
				}
					if(flag1!=1){
					printf("|%d\tprocess[%d]\t%d|",time,process[i].process_id,count);//printing the first queue
					}flag1=0;
					if(process[i].burst_t>0){
						check++;
							Level_2_Ready_Queue(process[i]);}//preempt the process with low pririty to level 2 
				iterator=1;
				time=count;
				count++;
				process[i+1].burst_t--;
				counter=1;
					break;
					}
				else
				{
				flag++;
				process[i].burst_t--;
				count++;
				iterator=1;
                 		}
 			}
		}
	Level2_Round_Robin();//it will execute the preempted process
}
void Level_2_Ready_Queue(struct level1_process queue){
process_2[rpro].burst_t2=queue.burst_t;
process_2[rpro].arrival_t2=queue.arrival_t;
process_2[rpro].priority_2=queue.priority;
process_2[rpro].process_id2=queue.process_id;
        rpro++;
}
void Level2_Round_Robin(){

  int i, end, total = 0, x, counter = 0, Time_Quantum,l,m;
      int waiting_time = 0, Turnaround_Time = 0, Arrival_Time[15], Burst_Time[15], temp[15];
      float Average_waiting_time, Average_Turnaround_Time;
      end=check;
      x = end;
      for(i = 0; i <end ; i++)
      {
            Arrival_Time[i]=process_2[i].arrival_t2;
            Burst_Time[i]=process_2[i].burst_t2;
            temp[i] = Burst_Time[i];
      }
          printf("\n\n");
      printf("\nEnter Time Quantum for level 2 in multiples of 2:\t");
      scanf("%d", &Time_Quantum);
      printf("Following are the burst time,waiting time and turnaround time of proceeses  preemepted from level 1 to level 2");
      printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n");
 for(total = 0, i = 0; x != 0;)
      {
            if(temp[i] <= Time_Quantum && temp[i] > 0)
            {
                  total = total + temp[i];
                  temp[i] = 0;
                  counter = 1;
            }
            else if(temp[i] > 0)
            {
                  temp[i] = temp[i] - Time_Quantum;
                  total = total + Time_Quantum;
            }
            if(temp[i] == 0 && counter == 1)
            {
                  x--;
            printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", process_2[i].process_id2, Burst_Time[i],total - Arrival_Time[i] - Burst_Time[i], total - Arrival_Time[i]);
                  waiting_time = waiting_time + total - Arrival_Time[i] - Burst_Time[i];
                  Turnaround_Time = Turnaround_Time + total - Arrival_Time[i];
                  counter = 0;
            }
            if(i == end - 1)
            {
                  i = 0;
            }
            else if(Arrival_Time[i + 1] <= total)
            {
                  i++;
            }
            else
            {
                  i = 0;
            }
      }
      Average_waiting_time = waiting_time * 1.0 / end;
      Average_Turnaround_Time = Turnaround_Time * 1.0 / end;
      printf("\n\nAverage Waiting Time of processes entered in level 2:\t%f", Average_waiting_time);
      printf("\nAvg Turnaround Time of processes entered in level 2:\t%f\n", Average_Turnaround_Time);
}
