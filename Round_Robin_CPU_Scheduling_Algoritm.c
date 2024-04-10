#include<stdio.h>

void main(){
int i, numberOfProcesses, sum=0, Process_Executed=0, temp, quantum_time;
int turn_around_time[3], burst_time[3], remaining_burst_time[3], waiting_time[3];
float avg_tat=0,avg_wt=0;

printf("Enter total number of process in the system:\t");
scanf("%d", &numberOfProcesses);

for(i=0; i<numberOfProcesses; i++){
printf("\nEnter Burst time of the Process P%d:\t", i);
scanf("%d", &burst_time[i]);
remaining_burst_time[i] = burst_time[i];
}

printf("\nEnter the Time Quantum for the process:\t");
scanf("%d", &quantum_time);
printf("\nProcess No\tBurst Time\tTurn Around Time\tWaiting Time\n");

while(1){
for(Process_Executed=0, i=0; i<numberOfProcesses; i++){
temp = quantum_time;
if(remaining_burst_time[i]==0){
Process_Executed++;
continue;
}

if(remaining_burst_time[i] > quantum_time){
remaining_burst_time[i] = remaining_burst_time[i] - quantum_time;
}
else
if(remaining_burst_time[i]>=0){
temp = remaining_burst_time[i];
remaining_burst_time[i]=0;
}
sum = sum + temp;
turn_around_time[i]= sum;
}
if(numberOfProcesses==Process_Executed){
break;
}
}
for(i=0;i<numberOfProcesses;i++){
waiting_time[i] = turn_around_time[i] - burst_time[i];
avg_wt = avg_wt + waiting_time[i];
avg_tat = avg_tat + turn_around_time[i];
printf("P%d\t\t%d\t\t%d\t\t\t%d\n",i,burst_time[i],turn_around_time[i],waiting_time[i]);
}
avg_wt = avg_wt/numberOfProcesses;
printf("\nAverage waiting time = %f",avg_wt);
}