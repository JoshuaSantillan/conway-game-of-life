/**
 * Assignment: life
 * Name : Joshua Santillan
 * PID: A16620670
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
	boards_t* board = malloc(sizeof(boards_t));
	board->gen = 0;
	
	FILE *file;
	if((file = fopen(initFileName, "r")) == NULL)
		return NULL;
	fscanf(file, "%d", &(board->numRows));
	fscanf(file, "%d", &(board->numCols));
	
	board->bufferA = (belem*)malloc(sizeof(belem) * board->numRows * board->numCols);
	board->bufferB = (belem*)malloc(sizeof(belem) * board->numRows * board->numCols);
	board->currentBuffer = board->bufferA;	
	board->nextBuffer = board->bufferB;

	clearBoards(board);

	int cell_x, cell_y;
	int index; 
	while(fscanf(file, "%d %d", &cell_x, &cell_y) > 0){
		index =	getIndex(board, cell_x, cell_y);
		board->currentBuffer[index] = 1;
	}
	uint32_t i;
	for(i = 0; i < board->numCols; i++){
		index =	getIndex(board, 0, i);
		board->currentBuffer[index] = 0;
	}	
	for(i = 0; i < board->numCols; i++){
		index =	getIndex(board, board->numRows-1, i);
		board->currentBuffer[index] = 0;
	}	
	for(i = 0; i < board->numRows; i++){
		index =	getIndex(board, i, 0);
		board->currentBuffer[index] = 0;
	}	
	for(i = 0; i < board->numRows; i++){
		index =	getIndex(board, i, board->numCols-1);
		board->currentBuffer[index] = 0;
	}
	
	fclose(file);
	return board;
}



/**
 * delete a board
 */
void deleteBoard(boards_t **bptrPtr){
	free((*bptrPtr)->bufferA);
	free((*bptrPtr)->bufferB);
	free(*bptrPtr);
	*bptrPtr = NULL;
}

/**
 * set all the belems in both buffers to 0
 */
void clearBoards(boards_t *self){
	uint32_t i;
	uint32_t j;
	for(i = 0; i < self->numCols; i++){
		for(j = 0; j < self->numRows; j++){
			self->bufferA[getIndex(self,j,i)] = 0;
			self->bufferB[getIndex(self,j,i)] = 0;
		}
	}
}

/**
 * swap the current and next buffers
 */
void swapBuffers(boards_t *self){
	belem *temp = self->currentBuffer;
	self->currentBuffer = self->nextBuffer;
	self->nextBuffer = temp;
}


/**
 * get a cell index
 */
int getIndex(boards_t *self, int row, int col){
	return row * self->numCols + col;
}
  
