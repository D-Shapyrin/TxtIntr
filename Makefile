.PHONY: all debug release clean

# RELEASE_FLAGS = -O2 -Wall -DNDEBUG
# DEBUG_FLAGS   = -g -O0 -Wall
RELEASE_EXEC  = 2
DEBUG_EXEC    = 2-dbg
SOURCE        = 2

all: debug release

debug: $(DEBUG_EXEC)

$(DEBUG_EXEC): 2.cpp
	g++ $(DEBUG_FLAGS) 2.cpp -o $(DEBUG_EXEC) 

release: $(RELEASE_EXEC)

$(RELEASE_EXEC): 2.cpp
	g++ $(RELEASE_FLAGS) 2.cpp -o $(RELEASE_EXEC)

clean:
	rm -f $(RELEASE_EXEC) $(DEBUG_EXEC)
	del *.o $(RELEASE_EXEC) $(DEBUG_EXEC)