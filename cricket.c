#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
//srand(time(NULL));
int shotnom(int n){
    int min=1;
    int max=13;
    int shot=min+rand()%(max-min+1);
    return shot;
}
int findMax(int arr[],int size){
    int max=arr[0];
    for(int i=1;i<size;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}
    

int main(){
    srand(time(NULL));
  //  printf("%d\n",shotnom(34));
    int teamA=0,teamB=0;
     system("cls");
    printf("let's play a 2 over cricket game\nur shots name\n(1) c = cover drive\n(2) p = pull shot\n(3) h = HELICOPTER SHOT\n(4) s = STRAIGHT DRIVE\n(5) r = REVERSE SWEEP\n(6) a = surya shot\n");
    //int c=1,p=2,h=3,s=4,r=5,a=6;
    int player1 =3,player2=3;
    char battersname[3][20]={"Rohit","kohli","dhoni"};
    char battersname2[3][20]={"sachin tendulkar","ganguli","yuvi"};
    int battingcard1[3];
    int battingcard2[3];
memset(battingcard1,0,sizeof(battingcard1));
memset(battingcard2,0,sizeof(battingcard2));


    
    char name1[42],name2[110];
    printf("every team has 3 players\nEnter team A captain  name\n");
    scanf("%s",name1);
    printf("Enter team B captain  name\n");
    scanf("%s",name2);


/********************toss function******************/
 system("cls");
printf("\n\n\tFlip the coin\nand choose head(1) or tail(0)\n");
int maxi =1;
int mini =0;
int toss=mini+rand()%(maxi-mini+1);
int t;
scanf("%d",&t);
if(t==toss){
    printf("\n->you won the toss you will bat first\n\n");
}
else if(t!=toss){
    printf("\n\n-->you lose the toss other will bat first\n\n");
}
/******************************************************/

char tosser[34];
printf("enter toss winner name\n");
scanf("%s",tosser);
//if(tosser[34]==name1[42]){
     system("cls");
    printf("\n\n\tget ready for the batting ");
    for(int i=0;i<4;i++){
        Sleep(1000);
        printf(".");
    }
    printf("\n");
    for(int i=1;i<=12;i++){
        for(int i=0;i<3;i++){
            Sleep(1200);
            printf(">");
        }
        //system("cls");
        if(player1 ==0){
            printf("your team is all out\n");
            break;
        }
        if(i==7){
            printf("frist over complete it's second over\n");
        }
        if(i==12){
            printf("play carefully it's last ball");
        }

       int c;
       printf("it's %d ball\n",i);
       printf("hit the shot(1 to 6)according table\n");
       scanf("%d",&c);
       int f=shotnom(7);
       printf("against threw %d\n",f);
       if((c-f) ==0){
        teamA+=6;
        printf("-->wow!! you hit the six..\n");
       }
       else if((c-f)==1||(f-c)==1){
        teamA+=4;
        printf("-->exellence you hit the four..\n");
       }
       else if((c-f)==2||(f-c)==2){
        teamA+=2;
        printf("-->you hit 2 runs\n");
       }
       else if((c-f)==3||(f-c)==3){
        printf("-->you are catch out !!\n");
        if(player1==3){
            battingcard1[0]=teamA;
        }
        else if(player1==2){
            battingcard1[1]=teamA-battingcard1[0];
        }
        if(player1==1){
            battingcard1[2]=teamA-battingcard1[0]-battingcard1[1];
        }
        player1=player1-1;
        printf("you have now %d player left",player1);
       }
       else if((c-f)==4||(f-c)==4){
        teamA+=1;
         printf("-->you hit 1 runs\n");
       }
       else if((c-f)==5||(f-c)==5){
        printf("-->you are run out !!\n");
         if(player1==3){
            battingcard1[0]=teamA;
        }
        else if(player1==2){
            battingcard1[1]=teamA-battingcard1[0];
        }
        if(player1==1){
            battingcard1[2]=teamA-battingcard1[0]-battingcard1[1];
        }
        player1=player1-1;
        printf("-->you have now %d player left",player1);
       }
       else if((c-f)==6||(f-c)==6){
        teamA+=4;
         printf("-->exellence you hit the four..\n");
       }
       else if((c-f)==7||(f-c)==7){
        teamA+=3;
         printf("-->great you hit the 3 run..\n");
       }
       else if((c-f)==8||(f-c)==8){
        printf("-->no run !!\n");
       }
       else if((c-f)==9||(f-c)==9){
        printf("-->you are Bold out\n");
         if(player1==3){
            battingcard1[0]=teamA;
        }
        else if(player1==2){
            battingcard1[1]=teamA-battingcard1[0];
        }
        if(player1==1){
            battingcard1[2]=teamA-battingcard1[0]-battingcard1[1];
        }
         player1=player1-1;
        printf("-->you have now %d player left",player1);
       }
       else if((c-f)==10||(f-c)==10){
        printf("-->no run\n");
       }
       else if((c-f)==11||(f-c)==11){
        teamA+=6;
        printf("-->wow!! you hit the six..\n");
       }
       else if((c-f)==12||(f-c)==12){
        teamA+=2;
     printf("-->you hit 2 runs\n");
       }
        if(player1==3){
            battingcard1[0]=teamA;
        }
        else if(player1==2){
            battingcard1[1]=teamA-battingcard1[0];
        }
        if(player1==1){
            battingcard1[2]=teamA-battingcard1[0]-battingcard1[1];
        }
       printf("\nplayers scorecard :\n");
       if(player1==3){
        printf("%s:%d\n",battersname[0],battingcard1[0]);
       }
       if(player1==2){
           printf("%s:%d\n%s:%d",battersname[0],battingcard1[0],battersname[1],battingcard1[1]);
       }
       if(player1==1 || player1==0){
        printf("%s:%d\n%s:%d\n%s:%d\n",battersname[0],battingcard1[0],battersname[1],battingcard1[1],battersname[2],battingcard1[2]);
       }
       printf("\nteamA score is now %d\n\n",teamA);
    }



printf("it's time now second team\nget ready!!\nTake A COFFEE(in 5 seconds.) \n\t");
 for(int i=0;i<1;i++){
    printf(".");
            Sleep(5000);
            
        }


    for(int i=1;i<=12;i++){
        for(int i=0;i<3;i++){
            Sleep(1200);
            printf(">");
        }
        if(player2 ==0){
            printf("-->your team is all out\n\n");
            break;
        }
        if(i==7){
            printf("-->frist over complete it's second over\n");
        }
        if(i==12){
            printf("-->play carefully it's last ball");
        }

       int c;
       printf("it's %d ball left\n",(13-i));
       printf("you need %d runs to win\n",(teamA+1-teamB));
       printf("hit the shot\n");
       scanf("%d",&c);
       int f=shotnom(7);
       printf("against threw %d\n",f);
       if((c-f)==0){
        teamB+=6;
        printf("--->wow!! you hit the six..\n");
       }
       else if((c-f)==1||(f-c)==1){
        teamB+=4;
        printf("-->exellence you hit the four..\n");
       }
       else if((c-f)==2||(f-c)==2){
        teamB+=2;
        printf("-->you hit 2 runs");
       }
       else if((c-f)==3||(f-c)==3){
        printf("-->you are catch out !!\n");
        if(player2==3){
            battingcard2[0]=teamB;
        }
        else if(player2==2){
            battingcard2[1]=teamB-battingcard2[0];
        }
        if(player2==1){
            battingcard2[2]=teamB-battingcard2[0]-battingcard2[1];
        }
        player2=player2-1;
        printf("-->you have now %d player left",player2);
       }
       else if((c-f)==4||(f-c)==4){
        teamB+=1;
         printf("-->you hit 1 runs");
       }
       else if((c-f)==5||(f-c)==5){
        printf("-->you are run out !!\n");
         if(player2==3){
            battingcard2[0]=teamB;
        }
        else if(player2==2){
            battingcard2[1]=teamB-battingcard2[0];
        }
        if(player2==1){
            battingcard2[2]=teamB-battingcard2[0]-battingcard2[1];
        }
         player2=player2-1;
        printf("-->you have now %d player left\n",player2);
       }
       else if((c-f)==6||(f-c)==6){
        teamB+=4;
        printf("-->exellence you hit the four..\n");
       }
       else if((c-f)==7||(f-c)==7){
        teamB+=3;
        printf("-->great you hit the thrias..\n");
       }
       else if((c-f)==8||(f-c)==8){
        printf("<---->no run !!\n");
        // player2=player2-1;
        //printf("you have now %d player left\n",player2);
       }
       else if((c-f)==9||(f-c)==9){
        printf("<---->you are Bold out\n");
         if(player2==3){
            battingcard2[0]=teamB;
        }
        else if(player2==2){
            battingcard2[1]=teamB-battingcard2[0];
        }
        if(player2==1){
            battingcard2[2]=teamB-battingcard2[0]-battingcard2[1];
        }
         player2=player2-1;
        printf("you have now %d player left",player2);
       }
       else if((c-f)==10||(f-c)==10){
        printf("---->no run\n");
       }
       else if((c-f)==11||(f-c)==11){
        teamB+=6;
        printf("--->wow!! you hit the six..\n");
       }
       else if((c-f)==12||(f-c)==12){
        teamB+=2;
        printf("---> you hit 2 run\n");
       }
        if(player2==3){
            battingcard2[0]=teamB;
        }
        else if(player2==2){
            battingcard2[1]=teamB-battingcard2[0];
        }
        if(player2==1){
            battingcard2[2]=teamB-battingcard2[0]-battingcard2[1];
        }
        printf("\n\nplayers scorecard :\n");
       if(player2==3){
        printf("%s:%d\n",battersname2[0],battingcard2[0]);
       }
       if(player2==2){
           printf("%s:%d\n%s:%d",battersname2[0],battingcard2[0],battersname2[1],battingcard2[1]);
       }
       if(player2==1 || player2==0){
        printf("%s:%d\n%s:%d\n%s:%d\n",battersname2[0],battingcard2[0],battersname2[1],battingcard2[1],battersname2[2],battingcard2[2]);
       }
       printf("\nteamB score is now %d\n\n",teamB);
       if (teamB>teamA){
   //printf("%s is winner of game and %s is looser of game",name1,name2);
   break;
   }
    }

/*************************finilising the result***************/
if(strcmp(tosser,name1)==0){
if(teamA>teamB){
   printf("%s is winner of game and %s is looser of game\n%s won by %druns\n",name1,name2,name1,(teamA-teamB));
   if(findMax(battingcard1,3)==battingcard1[0]){
       printf("\n->Rohit is man of the match.He scored %d runs",battingcard1[0]);
   }
   if(findMax(battingcard1,3)==battingcard1[1]){
       printf("\n->Kohli is man of the match.He scored %d runs",battingcard1[1]);
   }
   if(findMax(battingcard1,3)==battingcard1[2]){
       printf("\n->Dhoni is man of the match.He scored %d runs",battingcard1[2]);
   }
}
if (teamB>teamA){
   printf("%s is winner of game and %s is looser of game\n",name2,name1);
   if(findMax(battingcard2,3)==battingcard2[0]){
       printf("\n->Sachin is man of the match.He scored %d runs",battingcard2[0]);
   }
   if(findMax(battingcard2,3)==battingcard2[1]){
       printf("\n->Ganguli is man of the match.He scored %d runs",battingcard2[1]);
   }
   if(findMax(battingcard2,3)==battingcard2[2]){
       printf("\n->Yuvi is man of the match.He scored %d runs",battingcard2[2]);
   }
   }
if(teamA==teamB){
    printf("the game is tied and you both win the game\n");
    if(findMax(battingcard1,3)>findMax(battingcard2,3)){
        if(findMax(battingcard1,3)==battingcard1[0]){
       printf("\n->Rohit is man of the match.He scored %d runs",battingcard1[0]);
   }
   if(findMax(battingcard1,3)==battingcard1[1]){
       printf("\n->Kohli is man of the match.He scored %d runs",battingcard1[1]);
   }
   if(findMax(battingcard1,3)==battingcard1[2]){
       printf("\n->Dhoni is man of the match.He scored %d runs",battingcard1[2]);
   }
    }
    else{
          if(findMax(battingcard2,3)==battingcard2[0]){
       printf("\n->Sachin is man of the match.He scored %d runs",battingcard2[0]);
   }
   if(findMax(battingcard2,3)==battingcard2[1]){
       printf("\n->Ganguli is man of the match.He scored %d runs",battingcard2[1]);
   }
   if(findMax(battingcard2,3)==battingcard2[2]){
       printf("\n->Yuvi is man of the match.He scored %d runs",battingcard2[2]);
   }
    }
   }
}


if(strcmp(tosser,name2)==0){
 if(teamA>teamB){
   printf("%s is winner of game and %s is looser of game\nEnjoy you win the match by %d runs",name2,name1,(teamA-teamB));
if(findMax(battingcard1,3)==battingcard1[0]){
       printf("\n->Rohit is man of the match.He scored %d runs",battingcard1[0]);
   }
   if(findMax(battingcard1,3)==battingcard1[1]){
       printf("\n->Kohli is man of the match.He scored %d runs",battingcard1[1]);
   }
   if(findMax(battingcard1,3)==battingcard1[2]){
       printf("\n->Dhoni is man of the match.He scored %d runs",battingcard1[2]);
   }
}
if (teamB>teamA){
   printf("%s is winner2 of game and %s is looser of game",name2,name1);
   if(findMax(battingcard2,3)==battingcard2[0]){
       printf("\n->Sachin is man of the match.He scored %d runs",battingcard2[0]);
   }
   if(findMax(battingcard2,3)==battingcard2[1]){
       printf("\n->Ganguli is man of the match.He scored %d runs",battingcard2[1]);
   }
   if(findMax(battingcard2,3)==battingcard2[2]){
       printf("\n->Yuvi is man of the match.He scored %d runs",battingcard2[2]);
   }
   }
if(teamA==teamB){
    printf("the game is tied and you both win the game");
    if(findMax(battingcard1,3)>findMax(battingcard2,3)){
        if(findMax(battingcard1,3)==battingcard1[0]){
       printf("\n->Rohit is man of the match.He scored %d runs",battingcard1[0]);
   }
   if(findMax(battingcard1,3)==battingcard1[1]){
       printf("\n->Kohli is man of the match.He scored %d runs",battingcard1[1]);
   }
   if(findMax(battingcard1,3)==battingcard1[2]){
       printf("\n->Dhoni is man of the match.He scored %d runs",battingcard1[2]);
   }
    }
    else{
          if(findMax(battingcard2,3)==battingcard2[0]){
       printf("\n->Sachin is man of the match.He scored %d runs",battingcard2[0]);
   }
   if(findMax(battingcard2,3)==battingcard2[1]){
       printf("\n->Ganguli is man of the match.He scored %d runs",battingcard2[1]);
   }
   if(findMax(battingcard2,3)==battingcard2[2]){
       printf("\n->Yuvi is man of the match.He scored %d runs",battingcard2[2]);
   }
   }
}
/**************************************************************/
    return 0;
}
}
