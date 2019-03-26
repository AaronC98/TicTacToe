#include <stdio.h>
#include <stdlib.h>

//Initialising board squares for the game board.
char boardSquare[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

//Creating stack. Stack adapted from Lab 3.
struct stack {
  int maxsize;
  int top;
  int *items;
};

//Initalise stack.
struct stack* newStack(int capacity) {
  struct stack *pt = (struct stack*)malloc(sizeof(struct stack));

  pt->maxsize = capacity;
  pt->top = -1;
  pt->items = (int*)malloc(sizeof(int) * capacity);

  return pt;
}

//Get size of stack. Used in testing to check that stack was populating.
int size(struct stack *pt) {
  return pt->top + 1;
}

//Check if stack is empty.
int isEmpty(struct stack *pt) {
  return size(pt) == 0;
}

//Check if stack is full.
int isFull(struct stack *pt) {
  return size(pt) == pt->maxsize;
}

//Push function for the stack. Add item to the top of the stack.
void push(struct stack *pt, int x) {
  if (isFull(pt)) {
    printf("Stack is full. Couldn't push item onto stack.");
  }

  pt->top++;
  pt->items[pt->top] = x;
}

//Pop function for the stack. Remove item from the top of the stack.
int *pop(struct stack *pt) {
  int *data ;
  if (isEmpty(pt)) {
    printf("Stack is empty. Cannot pop from stack.\n");
  }

  data = &pt->items[pt->top];
  pt->top--;
  return data;
}


void printBoard();
int createWinConditions();

//Print the board.
void printBoard()
  {
    printf("\n\nTic Tac Toe\n\n");

    //Print lines representing the board and set the values inside the 'squares' to the value inside the boardSquare array.
    printf("      |      |    \n");
    printf("  %c   |   %c  |   %c\n", boardSquare[1], boardSquare[2], boardSquare[3]);
    printf("______|______|______\n");
    printf("      |      |      \n");
    printf("  %c   |   %c  |   %c\n", boardSquare[4], boardSquare[5], boardSquare[6]);
    printf("______|______|______\n");
    printf("      |      |      \n");
    printf("  %c   |   %c  |   %c\n", boardSquare[7], boardSquare[8], boardSquare[9]);
    printf("      |      |      \n\n");
  }

//Check for win conditions.
int checkWinConditions() {
  //Checking for each possible win condition.
  if ((boardSquare[1] == boardSquare[2] && boardSquare[2] == boardSquare[3]) ||
      (boardSquare[4] == boardSquare[5] && boardSquare[5] == boardSquare[6]) ||
      (boardSquare[7] == boardSquare[8] && boardSquare[8] == boardSquare[9]) ||
      (boardSquare[1] == boardSquare[4] && boardSquare[4] == boardSquare[7]) ||
      (boardSquare[2] == boardSquare[5] && boardSquare[5] == boardSquare[8]) ||
      (boardSquare[3] == boardSquare[6] && boardSquare[6] == boardSquare[9]) ||
      (boardSquare[1] == boardSquare[5] && boardSquare[5] == boardSquare[9]) ||
      (boardSquare[3] == boardSquare[5] && boardSquare[5] == boardSquare[7]))
        return 1;
  else if (boardSquare[1] != '1' && boardSquare[2] != '2' && boardSquare[3] != '3' && boardSquare[4] != '4'
  && boardSquare[5] != '5' && boardSquare[6] != '6' && boardSquare[7] != '7' && boardSquare[8] != '8' && boardSquare[9] != '9')
    return 0;
else
  //Continue with the game.
  return -1;
}

int getMove()
{

int player = 1, i, choice;

char piece;

//Instance of stack.
struct stack *pt = newStack(9);

do {

//Call printBoard function.
printBoard();

//Use modulo 2 to set the value of player to 1 and 2.
player = (player % 2) ? 1 : 2;

  //Get user input.
  printf("Player %d, please enter your move (1-9). Enter 10 to undo your move.\n");
  scanf("%d", &choice);


  int *item = NULL;

  //Using ? operand to set the value of piece to 'X' or 'O' depending on whether it's Player 1 or 2.
  piece = (player == 1) ? 'X' : 'O';

  //If the user's choice is 1 (or 2, 3 etc.), fill boardSquare with their piece and push the choice to the stack. Increment the player.
  if (choice == 1 && boardSquare[1] == '1') {
    boardSquare[1] = piece;
    push (pt, choice);
    player++;
  }
  else if (choice == 2 && boardSquare[2] == '2') {
    boardSquare[2] = piece;
    push (pt, choice);
    player++;
  }
  else if (choice == 3 && boardSquare[3] == '3') {
    boardSquare[3] = piece;
    push (pt, choice);
    player++;
  }
  else if (choice == 4 && boardSquare[4] == '4') {
    boardSquare[4] = piece;
    push (pt, choice);
    player++;
  }
  else if (choice == 5 && boardSquare[5] == '5') {
    boardSquare[5] = piece;
    push (pt, choice);
    player++;
  }
  else if (choice == 6 && boardSquare[6] == '6') {
    boardSquare[6] = piece;
    push (pt, choice);
    player++;
  }
  else if (choice == 7 && boardSquare[7] == '7') {
    boardSquare[7] = piece;
    push (pt, choice);
    player++;
  }
  else if (choice == 8 && boardSquare[8] == '8') {
    boardSquare[8] = piece;
    push (pt, choice);
    player++;
  }
  else if (choice == 9 && boardSquare[9] == '9') {
    boardSquare[9] = piece;
    push (pt, choice);
    player++;
  }
  //If the user's choice is 10, undo i.e. pop the last item off the top of the stack and return the item to its original value in the boardSquare.
  else if(choice == 10) {
    item = pop(pt);
    player--;


    if(*item == 1)
    {
      boardSquare[*item] = '1';
    }
    else if(*item == 2)
    {
      boardSquare[*item] = '2';
    }
    else if(*item == 3)
    {
      boardSquare[*item] = '3';
    }
    else if(*item == 4)
    {
      boardSquare[*item] = '4';
    }
    else if(*item == 5)
    {
      boardSquare[*item] = '5';
    }
    else if(*item == 6)
    {
      boardSquare[*item] = '6';
    }
    else if(*item == 7)
    {
      boardSquare[*item] = '7';
    }
    else if(*item == 8)
    {
      boardSquare[*item] = '8';
    }
    else if(*item == 9)
    {
      boardSquare[*item] = '9';
    }
  }
  //The move is invalid i.e. the space is taken. Decrease the player count and get another move.
  else
  {
    printf("Invalid move. Make sure you're entering a number between 1 and 9 and the move hasn't already been made.");
    player--;
  }
  //Check the win conditions against the user's move.
  i = checkWinConditions();

//While the game is to be continued.
} while(i == - 1);

//Print the board for another move.
printBoard();

//If a win condition has been met.
if (i == 1) {
  //Congratulate the player. Decrease the player counter as it automatically increased by one after each move.
  printf("Congratulations Player %d, you won!", --player);
}
else {
  //The game was a draw as no win conditions were met.
  printf("The game was a draw.");
}
return 0;
}

//Main function
int main()
{
  getMove();
}
