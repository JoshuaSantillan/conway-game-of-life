EXE = life
OBJS = main.c board.c sim.c
LIBS = -lplot -lcse30life
CFLAGS := -O0 -g --std=gnu99 -L/home/linux/ieng6/cs30wi21/public/local/x86/lib
C_DEBUG_FLAGS := -O0 -g --std=gnu99 -L/home/linux/ieng6/cs30wi21/public/local/x86/lib

.PHONY: clean

$(EXE): $(OBJS) 
	gcc -Wall -Wextra -o $@ $(CFLAGS) $(OBJS) $(LIBS)

no_warnings: $(OBJS)
	gcc -o $(EXE) $(CFLAGS) $(OBJS) $(LIBS)

debug: $(OBJS)
	gcc -o $(EXE) $(C_DEBUG_FLAGS) $(OBJS) $(LIBS)

clean :
	rm $(EXE)

