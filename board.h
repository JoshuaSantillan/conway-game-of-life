/**
 * Assignment: life
 * Name:TODO
 * PID :TODO
 * Class: UCSD CSE30-WI21
 *
 */
#ifndef _BOARD_H
#define _BOARD_H
#include "cse30life.h"

// we can change the board type to different sizes to see how this affects the speed.
// DO NOT CHANGE - libcse30life library assumes unsigned char
typedef unsigned char belem;


typedef struct boards boards_t;
struct boards {
	belem *bufferA;			// pointer to first life board buffer
	belem *bufferB;			// pointer to ansecond life board buffer
	uint32_t numRows;		// number of rows in the life board
	uint32_t numCols;		// number of cols in the life board
	belem *currentBuffer;	// pointer to the current life board's buffer 
	belem *nextBuffer;		// pointer to the next iteration's board buffer
	uint32_t gen;			// generation number   
};

extern boards_t *createBoard(char *filename);		// create a board structure
extern void deleteBoard(boards_t **);				// delete a board structure
extern void clearBoards(boards_t *self);			// clear the boards (current and next)
extern void swapBuffers(boards_t *self);			// swap the board current and next
extern void simStep(boards_t *self, uint32_t steps);		// simulate one step


extern void setSim(boards_t *self, void (*sim)(boards_t *self, uint32_t steps));
//extern void setSim(boards_t *self, void (*sim)(belem *, belem *, uint32_t, uint32_t, uint32_t));


extern int getIndex(boards_t *self, int row, int col);	// get index of (row,col) in 1D buffer

#endif // _BOARD_H
