#OBJS specifies which files to compile as part of the
#monksquest project.
OBJS = src/main.cpp src/Game.cpp hdrs/Game.h

#OBJ_NAME specifies the name of our final executable
OBJ_NAME = monksquest
#This is the target that compiles our executable
all: $(OBJS)
				g++ $(OBJS) -Werror -pedantic -lSDL2 -o bin/$(OBJ_NAME)