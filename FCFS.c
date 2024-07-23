#include<stdio.h>
void main(){
    int limit,tot_wt = 0 , tot_tat = 0;
    float avg_wt,avg_tat;
    printf("Enter the number of processes:");
    scanf("%d",&limit);
    int P[limit],BT[limit],WT[limit],TAT[limit];
    
    printf("\nEnter the processes and their Burst time:\n");
    for (int i =0 ; i<limit; i++){
        scanf("%d",&P[i]);
        scanf("%d",&BT[i]);
    }
    
     for (int i =0 ; i<limit; i++){
        if (i==0){
           WT[i] = 0;
           TAT[i] = BT[i];
           tot_tat = TAT[i];
        }
        else{
           WT[i] = WT[i-1] + BT[i-1];
           tot_wt += WT[i];
           
           TAT[i] = TAT[i-1] + BT[i];
           tot_tat += TAT[i];
        }
     }
     
     printf("\n Process  BT \t WT \t TAT\n");
     for (int i =0 ; i<limit; i++){
        printf(" %d \t %d \t %d \t %d\n",P[i],BT[i],WT[i],TAT[i]);
     }
     
     printf("\nGantt chart\n");
     for (int i =0 ; i<limit; i++){
        printf("|  P%d  ",P[i]);
     }
     printf("|\n");
     for (int i =0 ; i<limit; i++){
        printf("%d      ",WT[i]);
     }
     printf("%d\n\n",TAT[limit -1]);
     
     printf("Total waiting time = %d\n",tot_wt);
     printf("Total turn around time = %d\n",tot_tat);
     
     avg_wt = tot_wt/(float)limit;
     avg_tat = tot_tat/(float)limit;
     
     printf("Average waiting time = %f\n",avg_wt);
     printf("Average turn around time = %f\n",avg_tat);
}
