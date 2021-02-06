/**
 * Assignment: life
 * Name: TODO
 * PID: TODO
 * Class: UCSD CSE30-WI21
 *
 */
#include "sim.h"

#define CIMP
extern void asm_doRow(belem *, belem *, belem *, uint32_t);

/**
 * process one row of the board
 */
static void doRow(belem *dest, belem *srcStart, belem * srcEnd, uint32_t cols){
    int neighbors;
    belem* currentCell = srcStart;
    while(currentCell != srcEnd + 1){
      neighbors = *(currentCell - cols) + 
                  *(currentCell - cols - 1) +
                  *(currentCell - cols + 1) +
                  *(currentCell + cols) +
                  *(currentCell + cols - 1) +
                  *(currentCell + cols + 1) +
                  *(currentCell + 1) +
                  *(currentCell - 1);
      if(*(currentCell) == 1){
        if(neighbors == 2 || neighbors == 3)
            *dest = 1;
        else
            *dest = 0;
      }
      else{
        if(neighbors == 3)
          *dest = 1;
        else 
          *dest = 0;
      }
      currentCell++;
      dest++;
    }
}


/**
 * perform a simulation for "steps" generations
 *
 * for steps
 *   calculate the next board
 *   swap current and next
 */
void simLoop(boards_t *self, uint32_t steps){
  uint32_t i;
  uint32_t j;
  for(i = 0; i < steps; i ++){
    for(j = 1; j < self->numRows-1; j ++){
        doRow(self->nextBuffer + 1 + self->numCols * j, 
              self->currentBuffer + 1 + self->numCols * j, 
              self->currentBuffer + self->numCols - 2 + self->numCols * j, 
              self->numCols);
    }
    swapBuffers(self);
    self->gen++;
  }
}




