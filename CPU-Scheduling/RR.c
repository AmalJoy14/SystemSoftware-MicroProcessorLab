#include<stdio.h>
void main()
   {
    int limit,tot_wt=0,tot_tat=0,TQ,total=0,completed=0;
    float avg_wt,avg_tat;
    printf("Enter the number of processes :");
    scanf("%d",&limit);
    printf("Enter the time quantum : ");
    scanf("%d",&TQ);
    int P[limit],BT[limit],WT[limit],TAT[limit],remaining_BT[limit];
    printf("Enter the Processes and their corresponding Burst Time \n");
    for (int i=0;i<limit;i++)
       {
        scanf("%d",&P[i]);
        scanf("%d",&BT[i]);
        remaining_BT[i]=BT[i];
       }
    
    printf("Gantt Chart\n");
    printf("0 ");
    while(completed<limit)
       {
       for (int i=0;i<limit;i++)
         {
         //----------------------------------------------
          if (remaining_BT[i] > 0) 
             {
              if(remaining_BT[i]>TQ)
                 {
                  printf("P%d ",P[i]);
                  remaining_BT[i]=remaining_BT[i] - TQ;
                  total=total+TQ;
                 }
              else
                 {
                  printf("P%d ",P[i]);
                  total=total+remaining_BT[i];
              	  WT[i]=total-BT[i];
                  TAT[i]=total;
                  remaining_BT[i]=0;
                  completed++;
                 }
              printf("%d ",total);
             }
         //----------------------------------------------
          }
      }
      printf("\n");
      
    //Calculating Waiting Time and Turn Around Time
    for (int i=0;i<limit;i++)
       {
        tot_wt+=WT[i];
        tot_tat+=TAT[i];
       }
    
    avg_wt=tot_wt/(float)limit;
    avg_tat=tot_tat/(float)limit;
    
    
    //Displaying Results
    printf("Process   BT   WT   TAT\n");
    for (int i=0;i<limit;i++)
       {
        printf("  %d       %d    %d    %d\n",P[i],BT[i],WT[i],TAT[i]);
       }
    printf("Total waiting time = %d\n",tot_wt);
    printf("Total turn around time = %d\n\n",tot_tat);
    
    printf("Average WT = %f\n",avg_wt);
    printf("Average TAT = %f\n",avg_tat);
   }
