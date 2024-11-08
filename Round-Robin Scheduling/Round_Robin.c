#include<stdio.h>  

void main()  
{  
    int i, num_processes, sum=0, completed=0, quantum, waiting_time=0, turnaround_time=0;  
    int arrival_time[10], burst_time[10], remaining_bt[10];  
    float avg_waiting_time, avg_turnaround_time;  

    printf("Total number of processes in the system: ");  
    scanf("%d", &num_processes);  
    completed = num_processes;  

    for(i=0; i<num_processes; i++)  
    {  
        printf("\nEnter the Arrival and Burst time of Process[%d]\n", i+1);  
        printf("Arrival time: ");  
        scanf("%d", &arrival_time[i]);  
        printf("Burst time: ");  
        scanf("%d", &burst_time[i]);  
        remaining_bt[i] = burst_time[i];  
    }  

    printf("Enter the Time Quantum: ");  
    scanf("%d", &quantum);  

    printf("\nProcess No\tBurst Time\tTurnaround Time\tWaiting Time\n");  

    for(sum=0, i=0; completed != 0; )  
    {  
        if(remaining_bt[i] <= quantum && remaining_bt[i] > 0)  
        {  
            sum += remaining_bt[i];  
            remaining_bt[i] = 0;  
            completed--;  
            printf("Process[%d]\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], sum - arrival_time[i], sum - arrival_time[i] - burst_time[i]);  

            waiting_time += sum - arrival_time[i] - burst_time[i];  
            turnaround_time += sum - arrival_time[i];  
        }  
        else if(remaining_bt[i] > 0)  
        {  
            remaining_bt[i] -= quantum;  
            sum += quantum;    
        }  

        if(i == num_processes - 1)  
        {  
            i = 0;  
        }  
        else if(arrival_time[i + 1] <= sum)  
        {  
            i++;  
        }  
        else  
        {  
            i = 0;  
        }  
    }  

    avg_waiting_time = (float)waiting_time / num_processes;  
    avg_turnaround_time = (float)turnaround_time / num_processes;  

    printf("\nAverage Turnaround Time: %f", avg_turnaround_time);  
    printf("\nAverage Waiting Time: %f", avg_waiting_time);  
}  
