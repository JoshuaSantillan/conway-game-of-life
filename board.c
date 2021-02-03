/**
 * Assignment: life
 * Name :TODO
 * PID: TODO
 * Class: UCSD CSE30-WI21
 *
 */
#include "cse30life.h"
#include "board.h"


/**
 * create a new board
 *
 * - malloc a boards structure
 * - set the generation to 0
 * - open the file (if it doesn't exist, return a NULL pointer
 * - read the first line which is the number of rows
 * - read the second line which is the number of cols
 * - set the # of rows and # of cols in the boards structure
 * - malloc bufferA and bufferB 
 * - Set currentBuffer and nextBuffer
 * - clear both board buffers
 * - read the file until done.  each row contains a row and a columns separted by
 *   white space
 *     for each line, set the cell in the current buffer
 * - ensure that no border cells are set to alive
 * - close the file
 * - return the boards pointer if successfull or NULL ptr otherwise
 */
boards_t * createBoard(char *initFileName){
  // TODO: 
}



/**
 * delete a board
 */
void deleteBoard(boards_t **bptrPtr){
  // TODO:
}

/**
 * set all the belems in both buffers to 0
 */
void clearBoards(boards_t *self){
  // TODO:
}

/**
 * swap the current and next buffers
 */
void swapBuffers(boards_t *self){
  // TODO:
}


/**
 * get a cell index
 */
int getIndex(boards_t *self, int row, int col){
  // TODO:
}
  
