#include<stdio.h>
#include<stdbool.h>

void main()
   {
      int choice;
      while (true){
         printf("\nEnter your choice : [ 1.FCFS 2.SJF 3.Priority 4.RR 5.Exit]\n");
         scanf("%d",&choice);
         
         //////////////////////////////////////////////////////////////////////////////////////////
         if (choice == 1){
            int limit,tot_wt=0,tot_tat=0;
	    float avg_wt,avg_tat;
	    printf("Enter the number of processes :");
	    scanf("%d",&limit);
	    int P[limit],BT[limit],WT[limit],TAT[limit];
	    printf("Enter the Processes and their corresponding Burst Time \n");
	    for (int i=0;i<limit;i++)
	       {
		scanf("%d",&P[i]);
		scanf("%d",&BT[i]);
	       }
	       
	    //Calculating Waiting Time and Turn Around Time
	    for (int i=0;i<limit;i++)
	       {
		if (i==0)
		   {
		    WT[i]=0;
		    TAT[i]=BT[i];
		    tot_tat=TAT[i];
		   }
		else
		   {
		    WT[i]=WT[i-1]+BT[i-1];         //or TAT[i-1];
		    tot_wt+=WT[i];
		    
		    TAT[i]=TAT[i-1]+BT[i];         //or WT[i]+BT[i]
		    tot_tat+=TAT[i];
		   }
	       }
	    avg_wt=tot_wt/(float)limit;
	    avg_tat=tot_tat/(float)limit;
	    
	    //Gantt Chart
	    printf("\nGantt chart\n");
	     for (int i =0 ; i<limit; i++){
		printf("|  P%d  ",P[i]);
	     }
	     printf("|\n");
	     for (int i =0 ; i<limit; i++){
		printf("%d      ",WT[i]);
	     }
	     printf("%d\n\n",TAT[limit -1]);
	    
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
         
         /////////////////////////////////////////////////////////////////////////////////////////
         else if(choice == 2){
            int limit,tot_wt=0,tot_tat=0,temp;
	    float avg_wt,avg_tat;
	    printf("Enter the number of processes :");
	    scanf("%d",&limit);
	    int P[limit],BT[limit],WT[limit],TAT[limit];
	    printf("Enter the Processes and their corresponding Burst Time \n");
	    for (int i=0;i<limit;i++)
	       {
		scanf("%d",&P[i]);
		scanf("%d",&BT[i]);
	       }
	    
	    
	    //Sorting BT in asc order
	    for (int i =0 ; i<limit; i++){
		for (int j =i+1 ; j<limit; j++){
		   if (BT[i] > BT[j]){
		      temp = BT[i];
		      BT[i] = BT[j];
		      BT[j] = temp;
		      
		      temp = P[i];
		      P[i] = P[j];
		      P[j] = temp;
		   }
		}
	    }
	    
	       
	    //Calculating Waiting Time and Turn Around Time
	    for (int i=0;i<limit;i++)
	       {
		if (i==0)
		   {
		    WT[i]=0;
		    TAT[i]=BT[i];
		    tot_tat=TAT[i];
		   }
		else
		   {
		    WT[i]=WT[i-1]+BT[i-1];         //or TAT[i-1];
		    tot_wt+=WT[i];
		    
		    TAT[i]=TAT[i-1]+BT[i];         //or WT[i]+BT[i]
		    tot_tat+=TAT[i];
		   }
	       }
	    avg_wt=tot_wt/(float)limit;
	    avg_tat=tot_tat/(float)limit;
	    
	    //Gantt Chart
	    printf("\nGantt chart\n");
	     for (int i =0 ; i<limit; i++){
		printf("|  P%d  ",P[i]);
	     }
	     printf("|\n");
	     for (int i =0 ; i<limit; i++){
		printf("%d      ",WT[i]);
	     }
	     printf("%d\n\n",TAT[limit -1]);
	    
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
         
         //////////////////////////////////////////////////////////////////////////////
         else if(choice == 3){
            int limit,tot_wt=0,tot_tat=0,temp;
	    float avg_wt,avg_tat;
	    printf("Enter the number of processes :");
	    scanf("%d",&limit);
	    int P[limit],BT[limit],WT[limit],TAT[limit],Pri[limit];
	    printf("Enter the Processes and their corresponding Burst Time & Priority\n");
	    for (int i=0;i<limit;i++)
	       {
		scanf("%d",&P[i]);
		scanf("%d",&BT[i]);
		scanf("%d",&Pri[i]);
	       }
	    
	    //Sorting according to Priority
	    for (int i=0;i<limit;i++)
	       {
		for (int j=i+1;j<limit;j++)
		   {
		    if (Pri[j]<Pri[i])
		       {
		        //Swapping the processes according to their priority
		        temp=Pri[i];
		        Pri[i]=Pri[j];
		        Pri[j]=temp;
		        
		        temp=BT[i];
		        BT[i]=BT[j];
		        BT[j]=temp;
		        
		        temp=P[i];
		        P[i]=P[j];
		        P[j]=temp;
		       }
		   }
	       }
	       
	    //Calculating Waiting Time and Turn Around Time
	    for (int i=0;i<limit;i++)
	       {
		if (i==0)
		   {
		    WT[i]=0;
		    TAT[i]=BT[i];
		    tot_tat=TAT[i];
		   }
		else
		   {
		    WT[i]=WT[i-1]+BT[i-1];
		    tot_wt+=WT[i];
		    
		    TAT[i]=TAT[i-1]+BT[i];
		    tot_tat+=TAT[i];
		   }
	       }
	    avg_wt=tot_wt/(float)limit;
	    avg_tat=tot_tat/(float)limit;
	    
	    //Gantt Chart
	    printf("\nGantt chart\n");
	     for (int i =0 ; i<limit; i++){
		printf("|  P%d  ",P[i]);
	     }
	     printf("|\n");
	     for (int i =0 ; i<limit; i++){
		printf("%d      ",WT[i]);
	     }
	     printf("%d\n\n",TAT[limit -1]);
	    
	    //Displaying Results
	    printf("Process    BT   Priority   WT   TAT\n");
	    for (int i=0;i<limit;i++)
	       {
		printf("    %d      %d       %d       %d    %d\n",P[i],BT[i],Pri[i],WT[i],TAT[i]);
	       }
	    printf("Total waiting time = %d\n",tot_wt);
	    printf("Total turn around time = %d\n\n",tot_tat);
	    
	    printf("Average WT = %f\n",avg_wt);
	    printf("Average TAT = %f\n",avg_tat);
         }
         
         //////////////////////////////////////////////////////////////////////////////
         else if (choice == 4){
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
	    int arr[50] , k = 1;
	    arr[0] = 0;
	    
	    printf("Gantt Chart\n ");
	    while(completed<limit)
	       {
	       for (int i=0;i<limit;i++)
		 {
		 //----------------------------------------------
		  if (remaining_BT[i] > 0) 
		     {
		      if(remaining_BT[i]>TQ)
		         {
		          printf(" P%d |",P[i]);
		          remaining_BT[i]=remaining_BT[i] - TQ;
		          total=total+TQ;
		         }
		      else
		         {
		          printf(" P%d |",P[i]);
		          total=total+remaining_BT[i];
		      	  WT[i]=total-BT[i];
		          TAT[i]=total;
		          remaining_BT[i]=0;
		          completed++;
		         }
		      arr[k] = total;
		      k++;
		     }
		 //----------------------------------------------
		  }
	      }
	      printf("\n");
	      for (int j=0;j<k;j++){
		 printf("%d    ",arr[j]);
	      }
	      printf("\n\n");
	      
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
         else{
            break;
         }
      }
   }
   
   
   
   
   
