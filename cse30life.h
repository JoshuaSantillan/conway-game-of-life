//! CSE30-WI21
//! cse30life functions
//! functions to support life!

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>
#include <stdbool.h>

/**
 * time funcs
 */
//! start a time measurement
extern void startMeas();

//! stop a time measurement
extern void stopMeas();

//! get elapsed seconds
extern double getSecs();

/**
 *  predefined shapes
 */
//! create a glider
extern void glider(unsigned char *buf, uint32_t cols, uint32_t v, uint32_t h);   

//! create a toad
extern void toad(unsigned char *buf, uint32_t cols, uint32_t v, uint32_t h); 

//! create an acorn
extern void acorn(unsigned char *buf, uint32_t cols, uint32_t v, uint32_t h); 

//! create an oscillator horiz orient
extern void oscillator(unsigned char *buf, uint32_t cols, uint32_t v, uint32_t h);

//! create an oscillator vertical 
extern void oscillatorV(unsigned char *buf, uint32_t cols, uint32_t v, uint32_t h); 

/**
 * board plotting/printing
 */
//! print the board to the screen as ascii
extern void printAsciiBoard(unsigned char *buf, uint32_t rows, uint32_t cols, uint32_t gen);

//! create a new graphics window
extern int createWindow(uint32_t scale, uint32_t rows, uint32_t cols);

//! close the graphics window
extern int closeWindow();  // close the window

//! print the board to a window
extern void plotBoard(unsigned char *buf, uint32_t rows, uint32_t cols);

//! dump board to a file
extern void dumpBoard(unsigned char *buf, uint32_t rows, uint32_t cols, const char *dumpFileName);

