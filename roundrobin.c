#include<stdio.h> 
int main() 
{ 
      int i, total_proc, total = 0, rem_proc, count = 0, time_quantum; 
      int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], rem_burst_time[10]; 
      float average_wait_time, average_turnaround_time;
      printf("\nEnter Total Number of Processes:"); 
      scanf("%d", &total_proc); 
      rem_proc = total_proc; 
      for(i = 0; i < total_proc; i++) 
      {
            printf("\nEnter Process[%d]'s\n", i + 1);
            printf("Arrival Time:");
            scanf("%d", &arrival_time[i]);
            printf("Burst Time:");
            scanf("%d", &burst_time[i]); 
            rem_burst_time[i] = burst_time[i];
      } 
      printf("\nEnter Time Quantum:"); 
      scanf("%d", &time_quantum); 
      printf("\nProcess\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(total = 0, i = 0; rem_proc != 0;) 
      { 
            if(rem_burst_time[i] <= time_quantum && rem_burst_time[i] > 0) 
            { 
                  total = total + rem_burst_time[i]; 
                  rem_burst_time[i] = 0; 
                  count = 1; 
            } 
            else if(rem_burst_time[i] > 0) 
            { 
                  rem_burst_time[i] = rem_burst_time[i] - time_quantum; 
                  total = total + time_quantum; 
            } 
            if(rem_burst_time[i] == 0 && count == 1) 
            { 
                  rem_proc--; 
                  printf("\nP%d\t\t%d\t\t %d\t\t\t %d", i + 1, burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
                  wait_time = wait_time + total - arrival_time[i] - burst_time[i]; 
                  turnaround_time = turnaround_time + total - arrival_time[i]; 
                  count = 0; 
            } 
            if(i == total_proc - 1) 
                  i = 0; 
            else if(arrival_time[i + 1] <= total) 
                  i++;
            else 
                  i = 0;
      } 
      average_wait_time = wait_time * 1.0 / total_proc;
      average_turnaround_time = turnaround_time * 1.0 / total_proc;
      printf("\n\nAverage Waiting Time:\t%f", average_wait_time); 
      
      
      
      printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time); 
      return 0; 
}
