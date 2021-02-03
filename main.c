/**
 * Assignment: life
 * Name : TODO
 * PID : TODO
 * Class: UCSD CSE30-WI21
 *
 */

#include "cse30life.h"
#include "board.h"
#include "sim.h"
#include "assert.h"


typedef struct options {
	char *initFileName;
	int graphicsMode;
	int graphicsScale;
} options_t;


/**
 * help printing routine
 * print descrption of all the options as well as interactive commands.
 */
void printHelp(const char *name){
  printf("Usage %s initialconfiguration\n", name);
  printf("\t-g# : graphics mode (with # scale factor)\n");
  printf("\n");
  printf("Interactive commands:\n");
  printf("\td filename : dump the current state to filename\n");
  printf("\tn N  : run the simulation N steps without displaying intermediate results\n");
  printf("\ts N  : run the simulation N steps displaying intermediate results\n");
  printf("\tq : quit\n");
  exit(1);
}


/**
 * parse the input options
 *
 */
void parseOpts(int argc, char **argv, options_t *userOptsP) {
	int opt;
	userOptsP->graphicsMode = 0;
	while((opt = getopt(argc, argv, "g::")) != -1) {
		switch (opt) {
		case ('g'):
			userOptsP->graphicsMode = 1;
			userOptsP->graphicsScale = optarg? atoi(optarg) : 2;
			break;
		default:
			printHelp(argv[0]);
			exit(EXIT_FAILURE);
			break;
		}
	}
}

/**
 * main - parse options, call functions.
 *
 * - parse the command line options.
 * - create the board structure
 * - call loadboard() to load initial map. If no loadboard file is specified, loadboard
 *   provides a simple default.
 * - if in graphicsMode, create an window to display the simulation
 * - plot the initial board
 * - while !done
 *     get a command from the user
 *     simulate for the specified number of cycles
 *     display
 */
int main(int argc, char **argv) {
	boards_t *boards;
	options_t userOpts;

	parseOpts(argc, argv, &userOpts);

	if (argv[optind] == NULL){
		fprintf(stderr, "must provide an initial file name\n");
		exit(1);
	}

	if ((boards = createBoard(argv[optind])) == NULL) {
		fprintf(stderr, "Can't oopen file %s\n", argv[optind]);
		exit(1);
	}

	if (userOpts.graphicsMode) {
		createWindow(userOpts.graphicsScale, boards->numRows, boards->numCols);
	}

	printf("simulating life board %d rows %d cols\n",
		boards->numRows, boards->numCols);
	fflush(stdout);

	int done=0;
	int stepSize = 1;  // number of steps that sim(..) will simulate <= quanta
	int quanta = 1;    // total number of steps to simulate
	const int ibufSize = 128;

	while (!done) {
		char ibuf[ibufSize];
		if (userOpts.graphicsMode) {
			// this has to be here twice to ensure latest position is displayed
			plotBoard(boards->currentBuffer, boards->numRows, boards->numCols);
			plotBoard(boards->currentBuffer, boards->numRows, boards->numCols);
		} else {
			printAsciiBoard(boards->currentBuffer, boards->numRows, boards->numCols, boards->gen);
		}

		printf("cmd(d filename, s [#], n [#], q) : ");
		fflush(stdout);

		fgets(ibuf, ibufSize, stdin);
		fflush(stdout);
		
		if (ibuf[0] == 'q') {
			done = 1;
			break;
		} else if (ibuf[0] == 's') {
			sscanf(ibuf, "%*s %d", &quanta);
			stepSize = 1;
		} else if (ibuf[0] == 'n') {
			sscanf(ibuf, "%*s %d", &quanta);
			stepSize = quanta;
		} else if (ibuf[0] == 'd') {
			char dumpFileName[ibufSize];
			sscanf(ibuf, "%*s %s", dumpFileName);
			dumpBoard(boards->currentBuffer, boards->numRows, boards->numCols, dumpFileName);
			continue;
		}

		/**
		 * main simulation loop
		 *   simulate for quanta steps, display every stepSize
		 */
		for (int i=0; i<quanta; i += stepSize) {
			startMeas();
			simLoop(boards, stepSize);
			stopMeas();
			printf("speed gen/s = %08.2f  gen = %10d\n", (double)stepSize/getSecs(), boards->gen);
			fflush(stdout);

			if (userOpts.graphicsMode) {
				plotBoard(boards->currentBuffer, boards->numRows, boards->numCols);
			} else {
				printAsciiBoard(boards->currentBuffer, boards->numRows, boards->numCols, boards->gen);
			}
		}
		fflush(stdout);
	}

	if (userOpts.graphicsMode)
		closeWindow();

	deleteBoard(&boards);
	assert(boards == NULL);

	exit(EXIT_SUCCESS);
} 
