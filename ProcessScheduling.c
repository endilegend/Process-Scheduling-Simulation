
 #include <stdio.h>
 #include <stdbool.h>
 #include <stdlib.h>
 #include <time.h>
 #include <string.h>
 
 // Process struct
 struct Process
 {
     char processName[50];
     int pid;
     int priority;
     int runTime;
     int remainingTime;
 };
 
 // PID generator
 int pIDGenerator()
 {
     return 1000 + rand() % (4000 - 1000 + 1);
 }
 
 int main()
 {
     struct Process processes[110];
     // buckets for each prioritry
     int p0[100];
     int p1[100];
     int p2[100];
     int p3[100];
     int p4[100];
     int p5[100];
     int p6[100];
     int p7[100];
     int p8[100];
     int p9[100];
     int p10[100];
 
     char pName[50];
     int priority, runtime;
 
     // keep track of how many indexes have been used
     int zeros = 0;
     int ones = 0;
     int twos = 0;
     int threes = 0;
     int fours = 0;
     int fives = 0;
     int sixes = 0;
     int sevens = 0;
     int eights = 0;
     int nines = 0;
     int tens = 0;
 
     // Dispatcher
     strcpy(processes[0].processName, "Dispatcher");
     processes[0].pid = 6787;
     processes[0].priority = 0;
     processes[0].runTime = 4;
     processes[0].remainingTime = 4;
 
     // Gathers input
     for (int i = 1; i < 110; i++)
     {
         printf("Enter the process details: ");
         char pName[50];
 
         scanf("%s", pName);
         if (strcmp(pName, "Q") == 0)
         {
             break;
         }
         scanf("%d %d", &priority, &runtime);
         strcpy(processes[i].processName, pName);
         processes[i].pid = pIDGenerator();
         processes[i].priority = priority;
         processes[i].runTime = runtime;
         processes[i].remainingTime = runtime;
 
         // Enters input into right bucket
         if (priority == 0)
         {
             p0[zeros] = i;
             zeros++;
         }
         else if (priority == 1)
         {
             p1[ones] = i;
             ones++;
         }
         else if (priority == 2)
         {
             p2[twos] = i;
             twos++;
         }
         else if (priority == 3)
         {
             p3[threes] = i;
             threes++;
         }
         else if (priority == 4)
         {
             p4[fours] = i;
             fours++;
         }
         else if (priority == 5)
         {
             p5[fives] = i;
             fives++;
         }
         else if (priority == 6)
         {
             p6[sixes] = i;
             sixes++;
         }
         else if (priority == 7)
         {
             p7[sevens] = i;
             sevens++;
         }
         else if (priority == 8)
         {
             p8[eights] = i;
             eights++;
         }
         else if (priority == 9)
         {
             p9[nines] = i;
             nines++;
         }
         else if (priority == 10)
         {
             p10[tens] = i;
             tens++;
         }
     }
 
     printf("PROCESSNAME \tPID \tPRIORITY \tREMAININGTIME\n");
     int currPro;
     printf("\n");
     printf("\n");
     // Increases priortiy after every loop
     int pIncrease;
 
     // goes over every bucket and after a process has completed its 5 clocks with the processor OR upon its completion,
     // increases the priority of all the remaining processes by 1
     // (applies to all loops below)
     for (int i = 0; i < zeros;)
     {
         currPro = p0[i];
         if (processes[currPro].priority - pIncrease <= 0)
         {
             processes[currPro].priority = 0;
         }
         else
         {
             processes[currPro].priority = processes[currPro].priority - pIncrease;
         }
         for (int x = 0; x < 5 && processes[currPro].remainingTime > 0; x++)
         {
             processes[currPro].remainingTime -= 1;
             printf("%s \t%d \t%d \t%d\n", processes[currPro].processName, processes[currPro].pid, processes[currPro].priority, processes[currPro].remainingTime);
         }
         for (int j = 0; j < 4; j++)
         {
             processes[0].remainingTime -= 1;
             printf("%s \t%d \t%d \t%d\n", processes[0].processName, processes[0].pid, processes[0].priority, processes[0].remainingTime);
         }
         processes[0].remainingTime = 4;
         pIncrease += 1;
         if (processes[currPro].remainingTime == 0)
         {
             i++;
         }
     }
 
     for (int i = 0; i < ones;)
     {
         currPro = p1[i];
         if (processes[currPro].priority - pIncrease <= 0)
         {
             processes[currPro].priority = 0;
         }
         else
         {
             processes[currPro].priority = processes[currPro].priority - pIncrease;
         }
         for (int x = 0; x < 5 && processes[currPro].remainingTime > 0; x++)
         {
             processes[currPro].remainingTime -= 1;
             printf("%s \t%d \t%d \t%d\n", processes[currPro].processName, processes[currPro].pid, processes[currPro].priority, processes[currPro].remainingTime);
         }
         for (int j = 0; j < 4; j++)
         {
             processes[0].remainingTime -= 1;
             printf("%s \t%d \t%d \t%d\n", processes[0].processName, processes[0].pid, processes[0].priority, processes[0].remainingTime);
         }
         processes[0].remainingTime = 4;
         pIncrease += 1;
         if (processes[currPro].remainingTime == 0)
         {
             i++;
         }
     }
 
     for (int i = 0; i < twos;)
     {
         currPro = p2[i];
         if (processes[currPro].priority - pIncrease <= 0)
         {
             processes[currPro].priority = 0;
         }
         else
         {
             processes[currPro].priority = processes[currPro].priority - pIncrease;
         }
         for (int x = 0; x < 5 && processes[currPro].remainingTime > 0; x++)
         {
             processes[currPro].remainingTime -= 1;
             printf("%s \t%d \t%d \t%d\n", processes[currPro].processName, processes[currPro].pid, processes[currPro].priority, processes[currPro].remainingTime);
         }
         for (int j = 0; j < 4; j++)
         {
             processes[0].remainingTime -= 1;
             printf("%s \t%d \t%d \t%d\n", processes[0].processName, processes[0].pid, processes[0].priority, processes[0].remainingTime);
         }
         processes[0].remainingTime = 4;
         pIncrease += 1;
         if (processes[currPro].remainingTime == 0)
         {
             i++;
         }
     }
 
     for (int i = 0; i < threes;)
     {
         currPro = p3[i];
         if (processes[currPro].priority - pIncrease <= 0)
         {
             processes[currPro].priority = 0;
         }
         else
         {
             processes[currPro].priority = processes[currPro].priority - pIncrease;
         }
         for (int x = 0; x < 5 && processes[currPro].remainingTime > 0; x++)
         {
             processes[currPro].remainingTime -= 1;
             printf("%s \t%d \t%d \t%d\n", processes[currPro].processName, processes[currPro].pid, processes[currPro].priority, processes[currPro].remainingTime);
         }
         for (int j = 0; j < 4; j++)
         {
             processes[0].remainingTime -= 1;
             printf("%s \t%d \t%d \t%d\n", processes[0].processName, processes[0].pid, processes[0].priority, processes[0].remainingTime);
         }
         processes[0].remainingTime = 4;
         pIncrease += 1;
         if (processes[currPro].remainingTime == 0)
         {
             i++;
         }
     }
 
     for (int i = 0; i < fours;)
     {
         currPro = p4[i];
         if (processes[currPro].priority - pIncrease <= 0)
         {
             processes[currPro].priority = 0;
         }
         else
         {
             processes[currPro].priority = processes[currPro].priority - pIncrease;
         }
         for (int x = 0; x < 5 && processes[currPro].remainingTime > 0; x++)
         {
             processes[currPro].remainingTime -= 1;
             printf("%s \t%d \t%d \t%d\n", processes[currPro].processName, processes[currPro].pid, processes[currPro].priority, processes[currPro].remainingTime);
         }
         for (int j = 0; j < 4; j++)
         {
             processes[0].remainingTime -= 1;
             printf("%s \t%d \t%d \t%d\n", processes[0].processName, processes[0].pid, processes[0].priority, processes[0].remainingTime);
         }
         processes[0].remainingTime = 4;
         pIncrease += 1;
         if (processes[currPro].remainingTime == 0)
         {
             i++;
         }
     }
 
     for (int i = 0; i < fives;)
     {
         currPro = p5[i];
         if (processes[currPro].priority - pIncrease <= 0)
         {
             processes[currPro].priority = 0;
         }
         else
         {
             processes[currPro].priority = processes[currPro].priority - pIncrease;
         }
         for (int x = 0; x < 5 && processes[currPro].remainingTime > 0; x++)
         {
             processes[currPro].remainingTime -= 1;
             printf("%s \t%d \t%d \t%d\n", processes[currPro].processName, processes[currPro].pid, processes[currPro].priority, processes[currPro].remainingTime);
         }
         for (int j = 0; j < 4; j++)
         {
             processes[0].remainingTime -= 1;
             printf("%s \t%d \t%d \t%d\n", processes[0].processName, processes[0].pid, processes[0].priority, processes[0].remainingTime);
         }
         processes[0].remainingTime = 4;
         pIncrease += 1;
         if (processes[currPro].remainingTime == 0)
         {
             i++;
         }
     }
 
     for (int i = 0; i < sixes;)
     {
         currPro = p6[i];
         if (processes[currPro].priority - pIncrease <= 0)
         {
             processes[currPro].priority = 0;
         }
         else
         {
             processes[currPro].priority = processes[currPro].priority - pIncrease;
         }
         for (int x = 0; x < 5 && processes[currPro].remainingTime > 0; x++)
         {
             processes[currPro].remainingTime -= 1;
             printf("%s \t%d \t%d \t%d\n", processes[currPro].processName, processes[currPro].pid, processes[currPro].priority, processes[currPro].remainingTime);
         }
         for (int j = 0; j < 4; j++)
         {
             processes[0].remainingTime -= 1;
             printf("%s \t%d \t%d \t%d\n", processes[0].processName, processes[0].pid, processes[0].priority, processes[0].remainingTime);
         }
         processes[0].remainingTime = 4;
         pIncrease += 1;
         if (processes[currPro].remainingTime == 0)
         {
             i++;
         }
     }
 
     for (int i = 0; i < sevens;)
     {
         currPro = p7[i];
         if (processes[currPro].priority - pIncrease <= 0)
         {
             processes[currPro].priority = 0;
         }
         else
         {
             processes[currPro].priority = processes[currPro].priority - pIncrease;
         }
         for (int x = 0; x < 5 && processes[currPro].remainingTime > 0; x++)
         {
             processes[currPro].remainingTime -= 1;
             printf("%s \t%d \t%d \t%d\n", processes[currPro].processName, processes[currPro].pid, processes[currPro].priority, processes[currPro].remainingTime);
         }
         for (int j = 0; j < 4; j++)
         {
             processes[0].remainingTime -= 1;
             printf("%s \t%d \t%d \t%d\n", processes[0].processName, processes[0].pid, processes[0].priority, processes[0].remainingTime);
         }
         processes[0].remainingTime = 4;
         pIncrease += 1;
         if (processes[currPro].remainingTime == 0)
         {
             i++;
         }
     }
 
     for (int i = 0; i < eights;)
     {
         currPro = p8[i];
         if (processes[currPro].priority - pIncrease <= 0)
         {
             processes[currPro].priority = 0;
         }
         else
         {
             processes[currPro].priority = processes[currPro].priority - pIncrease;
         }
         for (int x = 0; x < 5 && processes[currPro].remainingTime > 0; x++)
         {
             processes[currPro].remainingTime -= 1;
             printf("%s \t%d \t%d \t%d\n", processes[currPro].processName, processes[currPro].pid, processes[currPro].priority, processes[currPro].remainingTime);
         }
         for (int j = 0; j < 4; j++)
         {
             processes[0].remainingTime -= 1;
             printf("%s \t%d \t%d \t%d\n", processes[0].processName, processes[0].pid, processes[0].priority, processes[0].remainingTime);
         }
         processes[0].remainingTime = 4;
         pIncrease += 1;
         if (processes[currPro].remainingTime == 0)
         {
             i++;
         }
     }
 
     for (int i = 0; i < nines;)
     {
         currPro = p9[i];
         if (processes[currPro].priority - pIncrease <= 0)
         {
             processes[currPro].priority = 0;
         }
         else
         {
             processes[currPro].priority = processes[currPro].priority - pIncrease;
         }
         for (int x = 0; x < 5 && processes[currPro].remainingTime > 0; x++)
         {
             processes[currPro].remainingTime -= 1;
             printf("%s \t%d \t%d \t%d\n", processes[currPro].processName, processes[currPro].pid, processes[currPro].priority, processes[currPro].remainingTime);
         }
         for (int j = 0; j < 4; j++)
         {
             processes[0].remainingTime -= 1;
             printf("%s \t%d \t%d \t%d\n", processes[0].processName, processes[0].pid, processes[0].priority, processes[0].remainingTime);
         }
         processes[0].remainingTime = 4;
         pIncrease += 1;
         if (processes[currPro].remainingTime == 0)
         {
             i++;
         }
     }
 
     for (int i = 0; i < tens;)
     {
         currPro = p10[i];
         if (processes[currPro].priority - pIncrease <= 0)
         {
             processes[currPro].priority = 0;
         }
         else
         {
             processes[currPro].priority = processes[currPro].priority - pIncrease;
         }
         for (int x = 0; x < 5 && processes[currPro].remainingTime > 0; x++)
         {
             processes[currPro].remainingTime -= 1;
             printf("%s \t%d \t%d \t%d\n", processes[currPro].processName, processes[currPro].pid, processes[currPro].priority, processes[currPro].remainingTime);
         }
         for (int j = 0; j < 4; j++)
         {
             processes[0].remainingTime -= 1;
             printf("%s \t%d \t%d \t%d\n", processes[0].processName, processes[0].pid, processes[0].priority, processes[0].remainingTime);
         }
         processes[0].remainingTime = 4;
         pIncrease += 1;
         if (processes[currPro].remainingTime == 0)
         {
             i++;
         }
     }
 
     return 0;
 }
 