# Setting C++ compiler and flags
CPP = g++ 
CPPFLAGS= --std=c++11 

CPPLIBS = 

##############################################################################

# Sources

# Setting library files and dir
LDIR = lib
_LIB = 

LIB = $(parsubst %, $(LDIR)/%, $(_LIB))

# Setting src files and dir
SDIR = src
_SRC = ArrayFiFo.cpp \
			 ArrayLiFo.cpp \
			 ArrayList.cpp \
			 Exception.cpp \
			 HashedCollection.cpp \
			 LinkedFiFo.cpp \
			 LinkedLiFo.cpp \
			 LinkedList.cpp 

SRC = $(patsubst %, $(SDIR)/%, $(_SRC))

##############################################################################

# Objects

ODIR = obj
_OBJ = $(_SRC:.cpp=.o)
_OBJ += $(_LIB:.cpp=.o)
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

##############################################################################
			######################################################

BIN = test.out

all: $(ODIR) $(BIN)
	
$(ODIR): 
	mkdir -p $(ODIR)

$(BIN): test.cpp $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) $(CPPLIBS) test.cpp -o $(BIN)


##############################################################################
			######################################################

$(ODIR)/Exception.o: $(SDIR)/Exception.cpp $(SDIR)/Exception.hpp
	$(CPP) $(CPPFLAGS) $(CPPLIBS) -c $< -o $@

$(ODIR)/LinkedLiFo.o: $(SDIR)/LinkedLiFo.cpp $(SDIR)/LinkedLiFo.hpp $(ODIR)/LinkedList.o 
	$(CPP) $(CPPFLAGS) $(CPPLIBS) -c $< -o $@

$(ODIR)/LinkedFiFo.o: $(SDIR)/LinkedFiFo.cpp $(SDIR)/LinkedFiFo.hpp $(ODIR)/LinkedList.o 
	$(CPP) $(CPPFLAGS) $(CPPLIBS) -c $< -o $@

$(ODIR)/HashedCollection.o: $(SDIR)/HashedCollection.cpp $(SDIR)/HashedCollection.hpp $(ODIR)/LinkedList.o 
	$(CPP) $(CPPFLAGS) $(CPPLIBS) -c $< -o $@

$(ODIR)/ArrayLiFo.o: $(SDIR)/ArrayLiFo.cpp $(SDIR)/ArrayLiFo.hpp $(ODIR)/ArrayList.o 
	$(CPP) $(CPPFLAGS) $(CPPLIBS) -c $< -o $@

$(ODIR)/ArrayFiFo.o: $(SDIR)/ArrayFiFo.cpp $(SDIR)/ArrayFiFo.hpp $(ODIR)/ArrayList.o 
	$(CPP) $(CPPFLAGS) $(CPPLIBS) -c $< -o $@

$(ODIR)/%.o: $(SDIR)/%.cpp $(SDIR)/%.hpp $(ODIR)/Exception.o
	$(CPP) $(CPPFLAGS) $(CPPLIBS) -c $< -o $@

##############################################################################

run: build
	$(EXEC) ./$(BIN)

RM = rm -rf

clean:
	$(RM) $(ODIR) $(BIN) 

.PHONY: clean

##############################################################################

