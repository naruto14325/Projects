#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#define SIZE 3             //defining a standard size which would be further used to form a 3*3 board area
#define MAX 20    //defining a size for player's name

char board[SIZE][SIZE]; // Designing the Game board by using the size as the area

// Function to initialize the game board
void initialize_board() {
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            board[i][j] = ' '; // Fill the board with empty spaces
        }
    }
}
/*To print this board format
    |   |
  --|---|--
    |   |
  --|---|--
    |   |   
  */
// Function to print the game board
void print_board() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]); // Print each row of the board
        if (i < SIZE - 1) printf("---|---|---\n"); // Print horizontal dividing lines between rows
    }
    printf("\n");
}

/* 
Wanting to check if any of the following pattern has been made in the game

  X |   |         Similar to this pattern in any of the two diagonals     
  --|---|--
    | X |
  --|---|--
    |   | X  
      OR
  X |   |        Similar to this pattern in any of the 3 columns
  --|---|--
  X |   |
  --|---|--
  X |   |   

      OR
     X| X |X      Similar to this pattern in any of the 3 Rows
    --|---|--
      |   |
    --|---|--
      |   |     
  */
// Function to check if a player has won the game or not
bool check_win(char player) {
    for (int i = 0; i < SIZE; i++){
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || // Check rows to find any winning move
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)){ // Check columns to find any winning move
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || // Check diagonal 1 to find any winning move
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)){ // Check diagonal 2 to find any winning move
        return true;
    }
    return false;
}
/*
  Now we want to check if the game is a draw or not by checking that all nthe empty spaces has been filled and none of the above pattern has been formed by any of the two players
  
  X | O | X
  --|---|--
   X| X | O
  --|---|--  
   O| O | X
*/
// Function to check if the game is a draw
bool check_draw() {
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            if (board[i][j] == ' '){
                 return false; // If any cell is empty, the game is not a draw
            }
        }
    }
    return true; // If all cells are filled and no winner is found, the game is a draw
}

void tictac() {
    char player1[MAX], player2[MAX];
    char current_player = 'X';
    int row, col;

    printf("Enter name for Player 1: ");
    scanf("%s", player1);
    printf("Enter name for Player 2: ");
    scanf("%s", player2);

    initialize_board(); // Initialize the game board

    // Main game loop
    while (true) {
        print_board(); // Print the current state of the game board
        printf("Player %s's turn. Enter row and column (0-2): ", (current_player == 'X') ? player1 : player2);
        scanf("%d %d", &row, &col); // Prompt the current player to enter their move

        // Check if the input move is valid
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
            printf("Invalid move! Try again.\n");
            continue; // If the move is invalid, prompt the player to try again
        }

        // Place the current player's symbol on the game board
        board[row][col] = current_player;

        // Check if the current player has won the game
        if (check_win(current_player)) {
            print_board();
            printf("Player %s wins!\n", (current_player == 'X') ? player1 : player2);
            break; // If the current player wins, end the game
        }

        // Check if the game is a draw
        if (check_draw()) {
            print_board();
            printf("It's a draw!\n");
            break; // If the game is a draw, end the game
        }

        // Switch turns to the other player
        current_player = (current_player == 'X') ? 'O' : 'X';
    }

     // End the program
}

#define MAX_PLAYERS 4

int rollDice(int a){
    int max =6;
    int min=1;
    int p= min+rand()%(max-min+1);
    return p; 
}

void playGame( char play[][20],int size, int num_players) {
    int positions[MAX_PLAYERS];
    memset(positions, 0, sizeof(positions));  // Initializes the positions of all players to 0
//memset is a function in c used to fill a block of memory with a particular value .declared in string.h

    int winner = -1; // Variable to store the index of the winning player, initialized to -1


    while (winner == -1) { // Continue looping until a winner is found
        for (int i = 0; i < num_players; i++) {
            char c;
          //  printf("enter ur name 1st word to play : ");
            scanf("%c",&c);
            getchar();

           
           // printf("%s's turn. Press Enter to roll the dice...\n", play[i]);
            // Wait for Enter key press
            int dice = rollDice(12);
            printf("%s rolled a %d\n", play[i], dice);

            positions[i] += dice;

            if (positions[i] == 100) {
                winner = i;
                break;
            } else if (positions[i] > 100) {
                printf("Oops! %s rolled too high. Try again.\n", play[i]);
                positions[i] -= dice;
            } else {
                switch (positions[i]) {
                    case 1: positions[i] = 38;  printf("%s climbed a ladder from 1 to 38\n", play[i]); break;
                    case 4: positions[i] = 14;  printf("%s climbed a ladder from 4 to 14\n", play[i]); break;
                    case 8: positions[i] = 30; printf("%s climbed a ladder from 8 to 30\n", play[i]); break;
                    case 21: positions[i] = 42; printf("%s climbed a ladder from 21 to 42\n", play[i]); break;
                    case 28: positions[i] = 76; printf("%s climbed a ladder from 28 to 76\n", play[i]); break;
                    case 50: positions[i] = 67; printf("%s climbed a ladder from 50 to 67\n", play[i]); break;
                    case 71: positions[i] = 92; printf("%s climbed a ladder from 71 to 92\n", play[i]); break;
                    case 80: positions[i] = 99; printf("%s climbed a ladder from 80 to 99\n", play[i]); break;
                    case 32: positions[i] = 10; printf("Oh no! %s got bitten by a snake from 32 to 10\n", play[i]); break;
                    case 36: positions[i] = 6; printf("Oh no! %s got bitten by a snake from 36 to 6\n", play[i]); break;
                    //case 57: positions[i] = 86; printf("%s climbed a ladder from 57 to 86\n", players[i]); break;
                    case 48: positions[i] = 26; printf("Oh no! %s got bitten by a snake from 48 to 26\n", play[i]); break;
                    case 62: positions[i] = 18; printf("oh no! %s got bitten by a snake from 62 to 18\n", play[i]); break;
                    case 88: positions[i] = 24; printf("Oh no! %s got bitten by a snake from 88 to 24\n", play[i]); break;
                    case 95: positions[i] = 56; printf("Oh no! %s got bitten by a snake from 95 to 56\n", play[i]); break;
                    case 97: positions[i] = 78; printf("Oh no! %s got bitten by a snake from 98 to 78\n", play[i]); break;
                    default: printf("%s is now at position %d\n", play[i], positions[i]); break;
                }
            }

            if (winner != -1)
                break;
        }
    }

    printf("%s wins the game!\n", play[winner]);
}

int num_players;

// Function to roll a dice

// Function to simulate the game
int SnakeAndLadder() {
    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to Snake and Ladder Game!\n");
    printf("Rules:\n");
    printf("1. Roll the dice by pressing Enter.\n");
    printf("2.Enter ur name 1st word to play :\n");
    printf("3. Climb ladders to move forward.\n");
    printf("4. Beware of snakes, they'll pull you down.\n");
    printf("5. Reach 100 to win!\n");
    printf("6.do not try to cheat by wrong input\n");

    printf("Enter number of players (up to %d): ", MAX_PLAYERS);
    //int num_players;
    scanf("%d", &num_players);
    if (num_players < 2 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting...\n");
        return 1;
    }
    char play[num_players][20];
    
    for (int i = 0; i < num_players; i++) {
        printf("Enter name for player %d: ", i + 1);
      
        scanf("%s", play[i]);
    
    }
    int size=sizeof(play)/sizeof(play[0]);
   
    playGame( play,size, num_players);

    return 0;
}

void showHangman(int);

int hangman()
{
    char hangmanWord[100], tempWord[100];       /*hangmanWord[] array for the original word and tempWord[] array to get the alphabet from user and compare it with original word*/
    char hangmanOutput[100];                    /*This array will show the remaining blanks and correct inputs*/
    int wrongTry = 6 , matchFound = 0;          /*player will get 5 chance, so we use wrongTry as chance counter*/
                                                /**matchFound to search the alphabet, if the alphabet from user does not exist
                                                in the original word it will remain 0, upon finding the word, matchFound will
                                                be set as 1**/
    int counter = 0 , position = 0, winner, length , i;
    char alphabetFromUser;

    system("cls");                              /*for clearing the screen*/
    printf("\n\n Enter any word in small case and hit >>ENTER<<");
    printf("\n\n\t Enter HERE ==>  ");
    scanf("%s",hangmanWord);                    /*get the string from opponent*/
    printf("\n\n Now give the COMPUTER to your friend and see if he/she can CRACK it!!!");
    printf("\n\n\tHIT >>ENTER<<");
    getchar();                                  /*hold the computer screen*/
    length = strlen(hangmanWord);               /*get the length of the word*/

    system("cls");

    printf("\n\n !!!!!!!!!!!!!!!!!!!Welcome to the HANGMAN GAME!!!!!!!!!!!!!!!!!\n\n\n");   /*Brief description of the game*/
    printf("\n\n You will get 5 chances to guess the right word");
    printf("\n\n So help the Man and get...set...GO..!!");

    getchar();

    printf("\n\n\tHIT >>ENTER<< ");

    getchar();

    system("cls");

        printf("\n\t||===== ");                 /*show the HANGMAN*/
	printf("\n\t||    | ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");

    printf("\n\n     The word has %d alphabets \n\n",length);  /*tell the user how many alphabets the word has*/
    for( i = 0; i < length ; i++)
    {
        hangmanOutput[i] = '_';
        hangmanOutput[length] = '\0';
    }

    for(i = 0 ; i < length ; i++)
    {
        printf(" ");
        printf("%c",hangmanOutput[i]);        /*Show the Word With n(length of the original word) number of underscores (_)*/

    }
    while(wrongTry != 0)                        /*while loop for exiting the program when no try left*/
    {
        matchFound = 0;
        printf("\n\n   enter any alphabet from a to z and please use small case!!");
        printf("\n\n\t Enter HERE ==> ");

	    fflush(stdin);

	    scanf("%c",&alphabetFromUser);            /*get alphabet from user*/
    if(alphabetFromUser < 'a' || alphabetFromUser > 'z') /*In case player gives input other than 'a' to 'z' the console will ask again*/
    {
        system("cls");
        printf("\n\n\t Wrong input TRY AGAIN ");
        matchFound = 2;
    }
    fflush(stdin);
    if (matchFound != 2)
    {
        for(counter=0;counter<length;counter++)    /*for loop to check whether player input alphabet exists or not in the word*/
	    {
		    if(alphabetFromUser==hangmanWord[counter])
		     {
		       matchFound = 1;
                     }//end of if()
            }//end of for()

	   if(matchFound == 0)                      /*in case of wrong guess*/
	    {
     	      printf("\n\t :( You have %d tries left ",--wrongTry);
	          getchar();
              showHangman(wrongTry);
              getchar();
	    }//end of if()

	   else
	   {
	     for(counter = 0; counter < length; counter++)
             {
     	         matchFound = 0;
                 if(alphabetFromUser == hangmanWord[counter])
	          {
     		     position = counter ;
     		     matchFound = 1;
	          }//end of if
    	      if(matchFound == 1)
	          {
                 for(i = 0 ; i < length ; i++)
                 {
                      if( i == position)
                  	  {
                          hangmanOutput[i] = alphabetFromUser; /*Put the alphabet at right position*/
                      }
                      else if( hangmanOutput[i] >= 'a' && hangmanOutput[i] <= 'z' ) /** If the position already occupied
                                                                                  by same alphabet then no need to
                                                                                  fill again EASY!! and continue */
                      {
                          continue;
                  	  }

                      else
                      {
                          hangmanOutput[i] = '_';            /** Put a blank at not guessed alphabet position **/
                      }
                }
                tempWord[position] = alphabetFromUser;      /*put the alphabet in another char array to check with the original word*/
                tempWord[length] = '\0';                    /*put the NULL character at the end of the temp string*/
                winner = strcmp(tempWord,hangmanWord);      /*upon True comparison it will return 0*/

                if(winner == 0)                             /*if the player guessed the whole word right then he/she is the WINNER*/
                {
                    printf("\n\n\t \t YAHOO!!!!! You are the WINNER !!!!!");
                    printf("\n\n\t The Word was %s ",hangmanWord);
                    printf("\n\n\n\n\t\tEASY HUH???\n\n");
                    getchar();
                    return 0;
                }//end of inner if
	       }//end of outer if
	    }//end of for loop
      }//end of else
     }// end of if(matchFound != 2) condition

    printf("\n\n\t");
    for(i = 0 ; i < length ; i++)
      {
          printf(" ");
          printf("%c",hangmanOutput[i]);                /*Show the original Word With blanks and right Input alphabet*/
      }

    getchar();
    }//end of while loop

      if(wrongTry <= 0)                                 /*if the player can not guess the whole word in 5 chaces*/
      {
          printf("\n\n\t The Word was %s ",hangmanWord);
          printf("\n\n\t The man is dead you IDIOT!!!!!");
	      printf("\n\n\t Better luck next!!!");

      }
getchar();
return 0;
}//end of main();



void showHangman(int choice)                            /*This function show the hangman after each wrong try*/
 {

     switch(choice)
     {

     case 0:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||   / %c",'\\');
	printf("\n\t||      ");
	break;
     case 1:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||     %c",'\\');
	printf("\n\t||      ");
	break;
     case 2:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
     case 3:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
     case 4:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO ",'\\');
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
     case 5:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||    O ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
      }//end of switch-case
      return;
 }
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
 #define NUM_QUESTIONS 13
typedef struct {
    char question[100];
    char options[4][700];
    int answer;
} Quiz;
Quiz quizzes[NUM_QUESTIONS] = {
    {" who wrote the Novel Five Point Someone ?", {"R.K. Narayan", "Jiddu Krishnamurti", "Chetan Bhagat", "Vikram Seth"}, 3},
    {"who is the first man to moon??", {"Neil Armstrong", "Yuri Gagarin", "Sunita Williams", "Kalpana Chawla"}, 1},
    {"who is the music director who won the oscar award for best orginal music for movie RRR in 2023?", {"Chandrabose", "Kaala Bhairava ", "M.M. Keeravani", "Amit Trivedi"}, 3},
    {"Which planet in which diamonds fall as rain according to scientist  as the  saturn Planet?", {"Venus", "Mars", "Jupiter", "uranus"}, 3},
    {"Who painted the Girl With A Pearl Earring ?", {"Vincent van Gogh", "Pablo Picasso", "Leonardo da Vinci", "Johannes Vermeer"}, 4},
    {"What year did the Titanic sink?",{"1912","1921","1989","1972"},1},
    {"What is the capital of Australia?",{"Washington DC","Canberra","Canada","Tokyo"},2}   ,
    {"Which is the only cricket team to win an ICC title in all three formats?",{"west indes","australia","New Zealand","Pakistan"},2},
    {"Which party observed the “Black Day” on July 3, 1947 against Partition of India?",{" Indian National Congress","Forward Bloc","Hindu Mahasabha","Communist Party of India"},3},
{"Which state is associated with the ‘Electronic Knowledge Network’?",{"Karnataka","Assam ","Bihar","Gujarat"},3},
{"Who was the first woman to win a Nobel Prize?",{"Marie Curie","Ada Lovelace","Rosalind Franklin","Jane Goodall"},1},
{"who is Indian mathematician known for his extraordinary contributions to number theory?",{"Abdul kalam ","Srinivasa Ramanujan ","CV raman ","SN_bose"},2},
{"Who invented Radio?",{"Nikola Tesla","Guglielmo Marconi","William Dubilier","Reginald Fessenden"},2}
};
//Shuffle Function: used to randomize the order of questions 
void shuffle(int *array, int n) {
    if (n >= 1) {
        int i;
        for (i = 0; i < n - 1; i++) {
            int j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}
void quiz() {
    srand(time(NULL));

    int score = 0;
    int answer;
    int order[NUM_QUESTIONS];

    for (int i = 0; i <NUM_QUESTIONS; i++) {
        order[i] = i;
    }

    shuffle(order, NUM_QUESTIONS);

    printf("Welcome to the Quiz!\n");

    for (int i = 0; i < 5; i++) {
        Quiz quiz = quizzes[order[i]];//Global Quiz Array

        printf("Question %d: %s\n", i + 1, quiz.question);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, quiz.options[j]);
        }
        printf("Enter your answer (1-4): ");
        scanf("%d", &answer);

        if(answer == quiz.answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", quiz.options[quiz.answer - 1]);
        }
    }

    printf("Your final score is %d out of %d.\n", score,5);
}
int Cricket(){
    
    srand(time(NULL));
     
  //  printf("%d\n",shotnom(34));
    int teamA=0,teamB=0;
     system("cls");
    // system("cls");
        printf("\t\t\t\n\n\n\n\nWelcome to the cricket game\t\t\n\n\n");
        printf("Press Enter>>");
       getchar();
       getchar();
       system("cls");
    printf("let's play a 2 over cricket game\nur shots name\n(1) c = cover drive\n(2) p = pull shot\n(3) h = HELICOPTER SHOT\n(4) s = STRAIGHT DRIVE\n(5) r = REVERSE SWEEP\n(6) a = surya shot\n");
     printf("Press Enter>>");
       getchar();
     system("cls");
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


/*toss function*/
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
//

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

/*finilising the result*/
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
//
    return 0;
}
}
int main()
{
   // printf("Enter your ch")
   int num;
   printf("Enter the choices: \n 1 for Tic Tac Toe game \n 2 for hangman game \n 3 for Quiz game \n 4 for cricket game \n 5 for Snake and Ladder game \n");
   scanf("%d" , &num);
   switch(num)
   {
    case 1:
    {  system("cls");
        printf("Welcome in the Tic Tac Toe game!!\n");
           getchar();
        system("cls");
        tictac();

        break;
    }
    case 2:
    {
    
        hangman();
        break;
    }
    case 3:
    {
        quiz();
        break;
    }
    case 4:
    {  

    Cricket();
        break;
    }
    case 5:
    {
        SnakeAndLadder();
        break;
    }
    default:
    {
        printf("Enter The Right Choice :");
        break;
    }
   }
    return 0;

}