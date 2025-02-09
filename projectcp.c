#include <stdio.h>

char board[5][5] = {{' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' '}};

char boardBack[5][5] = {{' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' '}};

int column, row;
int turn = 1;
int start = 1;
char player = '1';

int count1 = 0;
int count2 = 0;

void displayBoard();
void moveAgent(int row,int column, char player);
int checkWin();

void checkLastOne();
void moveAgentLastOne(int row,int column, char player);


int main(void){

    board[0][1] = 'J';
    board[0][2] = 'Q';
    board[0][3] = 'K';

    board[4][1] = 'J';
    board[4][2] = 'Q';
    board[4][3] = 'K';

    boardBack[0][1] = '1';
    boardBack[0][3] = '1';
    boardBack[0][2] = '1';

    boardBack[4][1] = '2';
    boardBack[4][2] = '2';
    boardBack[4][3] = '2';


    while (start == 1) {

        displayBoard();
        printf("Player %c, select agent\n",player);

        printf("Enter the row [1-5]: ");
        scanf("%d", &row);

        printf("Enter the column [1-5]: ");
        scanf("%d", &column);
        
        checkLastOne();
        if(count1 <= 1){
            moveAgentLastOne(row-1,column-1,player);
        }
        else if(count2 <= 1){
            moveAgentLastOne(row-1,column-1,player);
        }else{
            moveAgent(row-1,column-1,player);
        }

        // printf(checkWin());
        if(checkWin() == 1){
            printf("!!!! Plyer %c WIN !!!!",player);
            displayBoard();
            start = 0;
        }

        if(player == '2')
            player = '1';
        else
            player ='2';
    }

}


void displayBoard() {

    printf("\n  ____________________\n");
    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {

            if(j == 0){
                int num = i+1;
                printf("%d| %c ",num, board[i][j]);
            }
            else{
                printf("| %c ", board[i][j]);

            }

        }

        printf("|");
        printf("\n  ____________________\n");

    }
    printf("  1   2   3   4   5\n");

}


void moveAgent(int row,int column, char player) {

    int movement = 0;

        if (boardBack[row][column] == player) {

            printf("\n1)Up\n2)Left\n3)Right\n4)Down\nSelect your movement :");
            scanf("%d", &movement);

            switch (movement) {
                case 1:
                    
                    if(board[row-1][column] == ' ' || 
                    (board[row-1][column] == 'K' && board[row][column] == 'J') || 
                    (board[row-1][column] == 'J' && board[row][column] == 'Q') || 
                    (board[row-1][column] == 'Q' && board[row][column] == 'K')){
                            
                        board[row-1][column] = board[row][column];
                        board[row][column] = ' ';
                        boardBack[row-1][column] = boardBack[row][column];
                        boardBack[row][column] = ' ';
                        turn++;  
                    }
                    else if(board[row-1][column] == board[row][column] ){
                        board[row-1][column] = ' ';
                        board[row][column] = ' ';
                        boardBack[row-1][column] = ' ';
                        boardBack[row][column] = ' ';
                    }
                    else{
                        printf("!!! Please select again !!!\n\n");
                    }

                    break;

                case 2:

                    if(board[row][column-1] == ' ' || 
                    (board[row][column-1] == 'K' && board[row][column] == 'J') || 
                    (board[row][column-1] == 'J' && board[row][column] == 'Q') || 
                    (board[row][column-1] == 'Q' && board[row][column] == 'K')){
                        
                        board[row][column-1] = board[row][column];
                        board[row][column] = ' ';
                        boardBack[row][column-1] = boardBack[row][column];
                        boardBack[row][column] = ' ';
                        turn++;    
                        
                    }

                    else if(board[row][column-1] == board[row][column] ){
                        board[row][column-1] = ' ';
                        board[row][column] = ' ';
                        boardBack[row][column-1] = ' ';
                        boardBack[row][column] = ' ';
                    }

                    else{
                        printf("\n!!! Please select again !!!\n");
                    }
                    break;

                case 3:

                    if(board[row][column+1] == ' ' || 
                    (board[row][column+1] == 'K' && board[row][column] == 'J') || 
                    (board[row][column+1] == 'J' && board[row][column] == 'Q') || 
                    (board[row][column+1] == 'Q' && board[row][column] == 'K')){

                            board[row][column+1] = board[row][column];
                            board[row][column] = ' ';
                            boardBack[row][column+1] = boardBack[row][column];
                            boardBack[row][column] = ' ';
                            turn++;      
                    }
                    else if(board[row][column+1] == board[row][column] ){
                        board[row][column+1] = ' ';
                        board[row][column] = ' ';
                        boardBack[row][column+1] = ' ';
                        boardBack[row][column] = ' ';
                    }

                    else{
                        printf("!!! Please select again !!!\n\n");
                    }
                    break;

                case 4:

                    if(board[row+1][column] == ' ' || 
                    (board[row+1][column] == 'K' && board[row][column] == 'J') || 
                    (board[row+1][column] == 'J' && board[row][column] == 'Q') || 
                    (board[row+1][column] == 'Q' && board[row][column] == 'K')){

                            board[row+1][column] = board[row][column];
                            board[row][column] = ' ';
                            boardBack[row+1][column] = boardBack[row][column];
                            boardBack[row][column] = ' ';
                            turn++;   
                    }

                    else if(board[row+1][column] == board[row][column] ){
                        board[row+1][column] = ' ';
                        board[row][column] = ' ';
                        boardBack[row+1][column] = ' ';
                        boardBack[row][column] = ' ';
                    }

                    else{
                        printf("!!! Please select again !!!\n\n");
                    }
                    break;
                
                }
        }

        else{
            printf("Not your agent please select again !!!\n");
        }
}


void moveAgentLastOne(int row,int column, char player) {

    int movement = 0;

        if (boardBack[row][column] == player) {

            printf("\n1)Up\n2)Left\n3)Right\n4)Down\n5)Up Right\n6)Up Left\n7)Down Right\n8)Down Left\nSelect your movement :");
            scanf("%d", &movement);

            switch (movement) {
                case 1:
                    
                    if(board[row-1][column] == ' ' || 
                    (board[row-1][column] == 'K' && board[row][column] == 'J') || 
                    (board[row-1][column] == 'J' && board[row][column] == 'Q') || 
                    (board[row-1][column] == 'Q' && board[row][column] == 'K')){
                            
                        board[row-1][column] = board[row][column];
                        board[row][column] = ' ';
                        boardBack[row-1][column] = boardBack[row][column];
                        boardBack[row][column] = ' ';
                        turn++;  
                    }
                    else if(board[row-1][column] == board[row][column] ){
                        board[row-1][column] = ' ';
                        board[row][column] = ' ';
                        boardBack[row-1][column] = ' ';
                        boardBack[row][column] = ' ';
                    }
                    else{
                        printf("!!! Please select again !!!\n\n");
                    }

                    break;

                case 2:

                    if(board[row][column-1] == ' ' || 
                    (board[row][column-1] == 'K' && board[row][column] == 'J') || 
                    (board[row][column-1] == 'J' && board[row][column] == 'Q') || 
                    (board[row][column-1] == 'Q' && board[row][column] == 'K')){
                        
                        board[row][column-1] = board[row][column];
                        board[row][column] = ' ';
                        boardBack[row][column-1] = boardBack[row][column];
                        boardBack[row][column] = ' ';
                        turn++;    
                        
                    }

                    else if(board[row][column-1] == board[row][column] ){
                        board[row][column-1] = ' ';
                        board[row][column] = ' ';
                        boardBack[row][column-1] = ' ';
                        boardBack[row][column] = ' ';
                    }

                    else{
                        printf("\n!!! Please select again !!!\n");
                    }
                    break;

                case 3:

                    if(board[row][column+1] == ' ' || 
                    (board[row][column+1] == 'K' && board[row][column] == 'J') || 
                    (board[row][column+1] == 'J' && board[row][column] == 'Q') || 
                    (board[row][column+1] == 'Q' && board[row][column] == 'K')){

                            board[row][column+1] = board[row][column];
                            board[row][column] = ' ';
                            boardBack[row][column+1] = boardBack[row][column];
                            boardBack[row][column] = ' ';
                            turn++;      
                    }
                    else if(board[row][column+1] == board[row][column] ){
                        board[row][column+1] = ' ';
                        board[row][column] = ' ';
                        boardBack[row][column+1] = ' ';
                        boardBack[row][column] = ' ';
                    }

                    else{
                        printf("!!! Please select again !!!\n\n");
                    }
                    break;

                case 4:

                    if(board[row+1][column] == ' ' || 
                    (board[row+1][column] == 'K' && board[row][column] == 'J') || 
                    (board[row+1][column] == 'J' && board[row][column] == 'Q') || 
                    (board[row+1][column] == 'Q' && board[row][column] == 'K')){

                            board[row+1][column] = board[row][column];
                            board[row][column] = ' ';
                            boardBack[row+1][column] = boardBack[row][column];
                            boardBack[row][column] = ' ';
                            turn++;   
                    }

                    else if(board[row+1][column] == board[row][column] ){
                        board[row+1][column] = ' ';
                        board[row][column] = ' ';
                        boardBack[row+1][column] = ' ';
                        boardBack[row][column] = ' ';
                    }

                    else{
                        printf("!!! Please select again !!!\n\n");
                    }
                    break;
                
                case 5:
                    
                    if(board[row-1][column+1] == ' ' || 
                    (board[row-1][column+1] == 'K' && board[row][column] == 'J') || 
                    (board[row-1][column+1] == 'J' && board[row][column] == 'Q') || 
                    (board[row-1][column+1] == 'Q' && board[row][column] == 'K')){
                            
                        board[row-1][column+1] = board[row][column];
                        board[row][column] = ' ';
                        boardBack[row-1][column+1] = boardBack[row][column];
                        boardBack[row][column] = ' ';
                        turn++;  
                    }
                    else if(board[row-1][column+1] == board[row][column] ){
                        board[row-1][column+1] = ' ';
                        board[row][column] = ' ';
                        boardBack[row-1][column+1] = ' ';
                        boardBack[row][column] = ' ';
                    }
                    else{
                        printf("!!! Please select again !!!\n\n");
                    }

                    break;

                case 6:

                    if(board[row-1][column-1] == ' ' || 
                    (board[row-1][column-1] == 'K' && board[row][column] == 'J') || 
                    (board[row-1][column-1] == 'J' && board[row][column] == 'Q') || 
                    (board[row-1][column-1] == 'Q' && board[row][column] == 'K')){
                        
                        board[row-1][column-1] = board[row][column];
                        board[row][column] = ' ';
                        boardBack[row-1][column-1] = boardBack[row][column];
                        boardBack[row][column] = ' ';
                        turn++;    
                        
                    }

                    else if(board[row-1][column-1] == board[row][column] ){
                        board[row-1][column-1] = ' ';
                        board[row][column] = ' ';
                        boardBack[row-1][column-1] = ' ';
                        boardBack[row][column] = ' ';
                    }

                    else{
                        printf("\n!!! Please select again !!!\n");
                    }
                    break;

                case 7:

                    if(board[row+1][column+1] == ' ' || 
                    (board[row+1][column+1] == 'K' && board[row][column] == 'J') || 
                    (board[row+1][column+1] == 'J' && board[row][column] == 'Q') || 
                    (board[row+1][column+1] == 'Q' && board[row][column] == 'K')){

                            board[row+1][column+1] = board[row][column];
                            board[row][column] = ' ';
                            boardBack[row+1][column+1] = boardBack[row][column];
                            boardBack[row][column] = ' ';
                            turn++;      
                    }
                    else if(board[row+1][column+1] == board[row][column] ){
                        board[row+1][column+1] = ' ';
                        board[row][column] = ' ';
                        boardBack[row+1][column+1] = ' ';
                        boardBack[row][column] = ' ';
                    }

                    else{
                        printf("!!! Please select again !!!\n\n");
                    }
                    break;

                case 8:

                    if(board[row+1][column-1] == ' ' || 
                    (board[row+1][column-1] == 'K' && board[row][column] == 'J') || 
                    (board[row+1][column-1] == 'J' && board[row][column] == 'Q') || 
                    (board[row+1][column-1] == 'Q' && board[row][column] == 'K')){

                            board[row+1][column-1] = board[row][column];
                            board[row][column] = ' ';
                            boardBack[row+1][column-1] = boardBack[row][column];
                            boardBack[row][column] = ' ';
                            turn++;   
                    }

                    else if(board[row+1][column-1] == board[row][column] ){
                        board[row+1][column-1] = ' ';
                        board[row][column] = ' ';
                        boardBack[row+1][column-1] = ' ';
                        boardBack[row][column] = ' ';
                    }

                    else{
                        printf("!!! Please select again !!!\n\n");
                    }
                    break;
                
                }
        }

        else{
            printf("Not your agent please select again !!!\n");
        }
}


int  checkWin(){
    int count = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j] == 'J' ||
                board[i][j] == 'Q' ||
                board[i][j] == 'K') {
                count++;
            }
        }
    }
    return count;
}

void  checkLastOne(){
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (boardBack[i][j] == '1') {
                count1++;
            }
            else if(boardBack[i][j] == '2'){
                count2++;

            }
        }
    }
    printf("%d",count1);
    printf("%d",count2);
}