// 10827102¨H¬f¿Ä   10827111°K¥»¸Û 
#include <algorithm>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int gnum = 1;
void swap(int &a, int &b)
{
 int temp;
 temp = a;
 a = b;
 b = temp;
}
void Recursive(int work[],int head,int howmanynum)
{
 if(head != howmanynum)
 {
  for( int i = head; i <= howmanynum;i++)
  {           // åŸ·è¡Œnæ¬¡ 
   swap(work[head],work[i]);
   Recursive(work,head+1,howmanynum); // å„ªå…ˆè§£å…¶ä»–ä»»å‹™  
   swap(work[head],work[i]);
  }
 }
 else 
 {
  printf("[%d]",gnum); // ç¬¬n(gnum)å€‹
  gnum++;
  for(int i=1;i <= howmanynum;i++) printf("%d ",work[i]);
  printf("\n");
  
 }
}

void combine( int place, int number, int all, int choice, int save[] ) {
  int a=number;
  if(place == choice + 1){
  	Recursive(save,1,choice);
  } // ±Æ¦C 
  else  {
    for(a = number; a<=all ; a++) {
      save[place] = a;
      combine(place+1, a+1, all, choice, save);
    }
  }
}

int main()
{ 
 int head = 1;
 int finalnum;
 int whichmission;
 bool error = true;
 char ch = '\0';
 int howmanynum;  // å…±è¦æ±‚è¦å¹¾å€‹æ•¸oråˆ°n
 clock_t start,end; 
 printf("** Permutation Generator **\n");
 printf("* 0. Quit                 *\n");
 printf("* 1. N number from 1...N  *\n");
 printf("* 1. M number from input  *\n");
 printf("***************************\n");
 printf("Input a choice(0, 1, 2, 3): ");
 cin >> whichmission;
 while(whichmission != 0)
 {
  gnum = 1;
  if(whichmission == 1)
  {
   printf("\n");
   printf("Input a number: ");
   cin >> howmanynum; // ¨¾§b 
   scanf("%c", &ch);
   if ( ch == '\n' || ch == '\t' || ch == ' ' ) error = false;
   while( cin.fail() || error == true ) {
   	 	//printf("\n'%d'\n", input_num);
   	 	cin.clear();
   		cin.sync();
   		//printf("\n'%c'\n", ch);
   	 	printf("\nInput a number: ");
   	 	cin >> howmanynum;
   	 	scanf("%c", &ch);
   	 	if ( ch == '\n' || ch == '\t' || ch == ' ' ) error = false;
   	 	else error = true;
	 } // while ¦³¿ù»~ªº¿é¤J ´N­n­«¨Ó
   
   while( howmanynum <= 0 ) {
   	printf("\n### It is NOT in [1,999999] ###\n");
   	printf("\nInput a number: ");
   	cin >> howmanynum;
   	cin.clear();
   	cin.sync();
   }
   
     int work[howmanynum+1] = {0};
     for(int i = 1;i <= howmanynum;i++) work[i] = i;
 
     // printf("%d",finalnum); // test
     // printf("%d",work[1]); // test
     start = clock();
     Recursive(work,head,howmanynum);
     end = clock();
     printf("Mission 1: %d permutations\n", gnum-1);
   printf("L = %d \n",howmanynum);
   error = true;
  }
  else if(whichmission == 2)
  {
   printf("\n");
   printf("Input a number: ");
   cin>>howmanynum;
   scanf("%c", &ch);
   if ( ch == '\n' || ch == '\t' || ch == ' ' ) error = false;
   while( cin.fail() || error == true ) {
   	 	//printf("\n'%d'\n", input_num);
   	 	cin.clear();
   		cin.sync();
   		//printf("\n'%c'\n", ch);
   	 	printf("\nInput a number: ");
   	 	cin >> howmanynum;
   	 	scanf("%c", &ch);
   	 	if ( ch == '\n' || ch == '\t' || ch == ' ' ) error = false;
   	 	else error = true;
	 } 
   
   while(howmanynum < 2 || howmanynum > 9)
   {            //ä»‹æ–¼2~9 
    printf("\n");
    printf("### It is Not in[2,9] ###\n");
    printf("\n");
    printf("Input a number: ");
    scanf("%d",howmanynum);
   }
   int input_num = 0;
   int still_need = howmanynum;
   bool repeat = false;
   error = true;
   int work[howmanynum+1] = {0};
   for(int i = 1;i <= howmanynum;i++) {
   	 printf("\nInput a number: ");
   	 cin >> input_num;
   	 scanf("%c", &ch);
   	 //printf("'%c'", ch);
   	 if ( ch == '\n' || ch == '\t' || ch == ' ' ) error = false;
   	 while( cin.fail() || error == true ) {
   	 	//printf("\n'%d'\n", input_num);
   	 	cin.clear();
   		cin.sync();
   		//printf("\n'%c'\n", ch);
   	 	printf("\nInput a number: ");
   	 	cin >> input_num;
   	 	scanf("%c", &ch);
   	 	if ( ch == '\n' || ch == '\t' || ch == ' ' ) error = false;
   	 	else error = true;
	 } // while ¦³¿ù»~ªº¿é¤J ´N­n­«¨Ó 
   	
   	
   	 while( input_num <= 0 ) {
   	 	printf("\n### It is NOT in [1,999999] ###\n");
   	 	printf("\nInput a number: ");
   	 	cin >> input_num;
   	 	cin.clear();
   		cin.sync();
	 }
	 
	 
     for( int a = 1 ; a <= howmanynum ; a++ ) {
     	if ( work[a] == input_num ) {
     		repeat = true;
			i--;
			printf("\n### Duplicate! Still need %d numbers! ###\n", still_need) ;
		}
	 }
	 
	 if ( repeat == false ) {
	 	work[i] = input_num;
	 	still_need--;
	 }
	 repeat = false;
	 error = true;
   } // for
   start = clock();
   Recursive(work,head,howmanynum);
   end = clock();
   printf("Mission 2: %d permutations\n", gnum-1);
   printf("T = %d ms\n",end - start);
  }
  else if(whichmission == 3) {
  	int choice = 0;
  	printf("\nInput a number: ");
	scanf("%d", &choice);
	while(choice <= 0) {
		printf("\n### It is NOT in [1,9] ###\n");
		printf("\nInput a number: ");
		scanf("%d", &choice);
	}
	int save[choice+1] = {0};
	
     start = clock();
     combine( 1, 1, 9, choice, save );
     end = clock();
     printf("Mission 3: %d permutations\n", gnum-1);
     printf("T = %d ms\n",end - start);
  	
  }
  else if(whichmission != 0) 
  {
   printf("\n");
   printf("Command does not exist!\n");
  }
  
  printf("\n");
  printf("** Permutation Generator **\n");
  printf("* 0. Quit                 *\n");
  printf("* 1. N number from 1...N  *\n");
  printf("* 1. M number from input  *\n");
  printf("***************************\n");
  printf("Input a choice(0, 1, 2, 3): ");
  cin >> whichmission;
  if (cin.fail()) break;
 }
 
 system("pause");
 return 0;
}
