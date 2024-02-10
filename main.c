#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // Include the time.h header for time functions
void newgame(int game,int totalpoints,char player1[50],char player2[50]);
int changeside=0;
void scorer();
int totalpoints;
void winnerprinter(char player[50]){
    int a;
for(int k=0;k<50000;k++){
     a=k;
    };
system("CLS");
printf("\t\t\t\t\t\t***%s WON!***",player);
}

void tornamentresult(char player1[50],char player2[50],char player3[50]){
    int player1finalscore, player2finalscore, player3finalscore;
    FILE* file;
    char Filename[50];

    sprintf(Filename, "%s.txt", player1);
    file = fopen(Filename, "r");
    fscanf(file, "%d", &player1finalscore);
    fclose(file);

    sprintf(Filename, "%s.txt", player2);
    file = fopen(Filename, "r");
    fscanf(file, "%d", &player2finalscore);
    fclose(file);

    sprintf(Filename, "%s.txt", player3);
    file = fopen(Filename, "r");
    fscanf(file, "%d", &player3finalscore);
    fclose(file);

    printf("\n\n\n");
    printf("%s:::%d\n", player1, player1finalscore);
    printf("%s:::%d\n", player2, player2finalscore);
    printf("%s:::%d\n", player3, player3finalscore);

    if(player1finalscore>player2finalscore && player1finalscore>player3finalscore){
        printf("\n%s Won.",player1);
        winnerprinter(player1);

    }else if(player2finalscore>player1finalscore && player2finalscore>player2finalscore){
            printf("\n%s Won.",player2);
            winnerprinter(player2);
    }else if(player3finalscore>player1finalscore && player3finalscore>player2finalscore){
                printf("\n%s Won.",player2);
                winnerprinter(player3);
    }
    int temp;
    if(player1finalscore==player2finalscore){
        printf("\nScores between %s and %s is drawn.",player1,player2);
        printf("\n\nPress 1 and Enter to play drawn match...");
            scanf("%d",&temp);
        newgame(4,5,player1,player2);
    }else if(player1finalscore==player3finalscore){
        printf("\nScores between %s and %s is drawn.",player1,player3);
        printf("\n\nPress 1 and Enter to play drawn match...");
            scanf("%d",&temp);
                newgame(4,5,player1,player3);
    }else if(player2finalscore==player3finalscore){
        printf("\nScores between %s and %s is drawn.",player3,player2);
        printf("\n\nPress 1 and Enter to play drawn match...");
            scanf("%d",&temp);
                newgame(4,5,player3,player2);
    }
exit(0);
}
void sidechecker(playerone,playertwo,totalpoints){
int tempp=playerone+playertwo;
if(tempp==totalpoints){
    printf("\n\nChange Side\n\n");
    changeside=1;
}

}

void timee(FILE *file) {
    // Get the current time
    time_t currentTime;
    struct tm *localTime;

    time(&currentTime);
    localTime = localtime(&currentTime);

    // Display the current time
    fprintf(file, "Current time: %02d:%02d:%02d\n",
            localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
}



int main() {
        FILE *file;
    char ch;  // Add a variable to store each character read from the file

    int choicee;
    do{

    printf("\n\n\nBadmintom Game Console\n");
    printf("1)New Game.\n");
    printf("2)New Tournament.\n");
    printf("3)All Statics\n");
    printf("4)All Tornament Record\n");
    printf("5)About Us.\n");
    printf("6)Exit\n");
    scanf("%d",&choicee);
    switch (choicee){
    case 1:
        system("CLS");
        int game;
        char player1[50],player2[50];
        printf("Enter Game Number:");
        scanf("%d",&game);
        printf("Enter Total Points:");
        scanf("%d",&totalpoints);
        printf("Enter Player1 Name:");
        scanf("%s",player1);
        printf("Enter Player2 Name:");
        scanf("%s",player2);
        newgame(game,totalpoints,player1,player2);
    break;

    case 2:
    system("CLS");
    tornament();
    break;

    case 3:
scorer();
    break;
case 4:
  exit(0);
    break;

    case 5:
   system("CLS");
    printf("\n\n\nMade By Mohammad Kumail Asghar.");
    break;



    default:
        exit(0);
    }
    }while(choicee!=5);
    return 0;
}

void newgame(int game,int totalpoints,char player1[50],char player2[50]){
 int gameno, scored,playerone=0,playertwo=0;
    FILE *file;
    char Filename[50];
printf("\n\n\nGame # %d",game);

    sprintf(Filename, "%d.txt", game);

    file = fopen(Filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s for writing\n", Filename);
        return 1;  // Return an error code
    }
    printf("\n\n\nStart the Game!\n\n\n");
    void timee(FILE *file);
printf("\n***%s VS %s***\n\n",player1,player2);
fprintf(file,"\n***%s VS %s***\n\n",player1,player2);

    do {
            scored=0;
if(changeside==0){
            printf("%s score:%d***%s score:%d.",player1,playerone,player2,playertwo);
        printf("\nWho Scored: ");
        scanf("%d", &scored);

        if (scored == 1) {
            timee(file);
            fprintf(file, "Player 1\n");
            playerone ++;
        } else if(scored == 2) {
            timee(file);
            fprintf(file, "Player 2\n");
            playertwo ++;
        }else if(scored==11){
            timee(file);
            fprintf(file, "Player 1==Foul\n");
            playerone --;

            }else if(scored==22){
            timee(file);
            fprintf(file, "Player 2==Foul\n");
            playertwo --;
            }else{
        printf("Wrong Entry\n");
        }
        }else if(changeside==1){
            printf("%s score:%d***%s score:%d.",player2,playertwo,player1,playerone);
        printf("\nWho Scored: ");
        scanf("%d", &scored);

        if (scored == 2) {
            timee(file);
            fprintf(file, "Player 1\n");
            playerone ++;
        } else if(scored == 1) {
            timee(file);
            fprintf(file, "Player 2\n");
            playertwo ++;
        }else if(scored==22){
            timee(file);
            fprintf(file, "Player 1==Foul\n");
            playerone --;

            }else if(scored==11){
            timee(file);
            fprintf(file, "Player 2==Foul\n");
            playertwo --;
            }else{
        printf("Wrong Entry\n");
        }
        }
        sidechecker(playerone,playertwo,totalpoints);

    } while (playerone != totalpoints && playertwo != totalpoints);
    if(playerone==totalpoints){
        printf("\n%s Won the Game.\n",player1);
        printf("\n\n%s ==== %d\n\n %s ==== %d\n\n",player1,playerone,player2,playertwo);

            fprintf(file,"\n\n%s Won the Game.\n\n",player1);
            fprintf(file,"%s ==== %d\n\n %s ==== %d",player1,playerone,player2,playertwo);


    }else if(playertwo==totalpoints){
            printf("\n%s Won the Game.",player2);
            printf("\n%s ==== %d\n\n %s ==== %d",player1,playerone,player2,playertwo);

            fprintf(file,"\n%s Won the Game.",player2);
            fprintf(file,"\n%s ==== %d\n\n %s ==== %d",player1,playerone,player2,playertwo);

}
int oldscore,newscore;
    fclose(file);
        sprintf(Filename, "%s.txt", player1);

    file = fopen(Filename, "r");
   if(fscanf(file, "%d", &oldscore) !=1){
    oldscore=0;
   }
    fclose(file);
    newscore=oldscore+playerone;
    file = fopen(Filename, "w");
    fprintf(file,"%d",newscore);
    fclose(file);

        sprintf(Filename, "%s.txt", player2);

    file = fopen(Filename, "r");
    if(fscanf(file, "%d", &oldscore) !=1){
    oldscore=0;
   }
      fclose(file);
    newscore=oldscore+playertwo;
    file = fopen(Filename, "w");

    fprintf(file,"%d",newscore);
    fclose(file);

    }

void scorer(){
    FILE *file;
    char ch,filename[50];
    for(int i=1;i<5;i++){
        printf("\n\n\nGame # %d.\n\n\n",i);
        sprintf(filename,"%d.txt",i);
    file = fopen(filename, "r");
while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }
        fclose(file);

       }
printf("\n\n\n\nAbbas Score:");
     file = fopen("abbas.txt", "r");
while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }

    // Close the file
    fclose(file);
printf("\nKumail Score:");
file = fopen("kumail.txt", "r");
while ((ch = fgetc(file)) != EOF) {
        // Process the character (you can print it or do something else)
        printf("%c", ch);
    }

    // Close the file
    fclose(file);
printf("\nRizwan' Score:");

    file = fopen("rizwan.txt", "r");
while ((ch = fgetc(file)) != EOF) {
        // Process the character (you can print it or do something else)
        printf("%c", ch);
    }

    // Close the file
    fclose(file);

}



void tornament(){
    char player1[50],player2[50],player3[50];
    int firstgame=0,secondgame=0;
printf("Enter Player 1 Name:");
scanf("%s",player1);
printf("Enter Player 2 Name:");
scanf("%s",player2);
printf("Enter Player 3 Name:");
scanf("%s",player3);
printf("Enter Total Point:");
scanf("%d",&totalpoints);


for(int i=0;i<50;i++){

do{
        system("CLS");
srand(time(NULL));
int random=rand();
printf("\nFirst Match\n");
if(random%2==0){
    printf("%s",player1);
    firstgame=1;
}else if(random%4==0){
    printf("%s",player2);
    firstgame=2;
}else{
    printf("%s",player3);
    firstgame=3;
}
printf(" VS ");
srand(time(NULL));
random=rand();
if(random%3==0){
    printf("%s",player1);
    secondgame=1;
}else if(random%2==0){
    printf("%s",player2);
    secondgame=2;
}else{
    printf("%s",player3);
    secondgame=3;
}
}while(firstgame==secondgame);
}
int game=1;
if((firstgame==1 && secondgame==2) || (firstgame==1 && secondgame==3)){
                if(secondgame==2){
                newgame(game++,totalpoints,player1,player2);
                newgame(game++,totalpoints,player2,player3);
                newgame(game++,totalpoints,player1,player3);
                }
              if(secondgame==3){
                newgame(game++,totalpoints,player1,player2);
                newgame(game++,totalpoints,player2,player3);
                newgame(game++,totalpoints,player1,player3);
                }
        }
else if((firstgame==2 && secondgame==1) || (firstgame==2 && secondgame==3)){
   if(secondgame==1){
                newgame(game++,totalpoints,player2,player1);
                newgame(game++,totalpoints,player1,player3);
                newgame(game++,totalpoints,player2,player3);
                }
              if(secondgame==3){
                newgame(game++,totalpoints,player2,player3);
                newgame(game++,totalpoints,player1,player3);
                newgame(game++,totalpoints,player1,player2);
                }

  }else if((firstgame==3 && secondgame==1) || (firstgame==3 && secondgame==2)){
        if(secondgame==1){
                newgame(game++,totalpoints,player3,player1);
                newgame(game++,totalpoints,player1,player2);
                newgame(game++,totalpoints,player2,player3);
                }
              if(secondgame==2){
                newgame(game++,totalpoints,player2,player3);
                newgame(game++,totalpoints,player1,player3);
                newgame(game++,totalpoints,player2,player1);
                }
}
tornamentresult(player1,player2,player3);














}

