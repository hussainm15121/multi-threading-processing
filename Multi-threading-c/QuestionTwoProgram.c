/*******************************************************
* PURPOSE: IMPLEMENT USERNAME AND PASSWORD FUNCTION	 *
* AUTHOR: HUSSAIN MEHDI		 		 *
********************************************************/

#include <stdio.h>
#include <string.h>
#include <signal.h>
  
void sigintHandler(int sig_num)
{
    signal(SIGINT, sigintHandler);
    printf("\n Reverting to Original Setting \n");
    fflush(stdout);
}

void main()
{
	int exit =0;
	signal(SIGINT, sigintHandler);
	while(exit<1)
	{
   char password[6], username[25], ch;
   int i,k;
   int count=0;
   printf("Username: ");
   scanf("%c", username);		//using scanf to get user input
   
   
   printf("Password (5 CHARACTERS): ");	//print on screen
   
   for (k = 0; k < 5; k++)
   {
    ch= getchar();
    password[count] = ch;
    count++;
    printf("*");
   }
	password[i] = '\0';
 
   printf("\n Entered password is:");
   for (i = 0; i < 5; i++)
   {
        printf("%c", password[i]);
   }
   }

}
