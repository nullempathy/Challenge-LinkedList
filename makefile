APPS = ./apps/
BIN = ./bin/
INCLUDE = ./include/
LIB = ./lib/
OBJ = ./obj/
SRC = ./src/

FLAGS = -O3 -Wall
LIBS = -led -L $(LIB) 





all: \
	libed \
	myapps


libed: \
	$(OBJ)float_array.o \
	$(OBJ)enaChallenge.o
	ar -rcs $(LIB)libed.a $(OBJ)*.o


myapps: clean_apps \
	$(BIN)test_float_array \
	$(BIN)enaChallengeApp


$(OBJ)%.o: $(SRC)%.c $(INCLUDE)%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@


$(BIN)%: $(APPS)%.c
	gcc $(FLAGS) $< $(LIBS) -I $(INCLUDE) -o $@


run:
	$(BIN)enaChallengeApp


clean:
	rm -rf $(BIN)* $(LIB)* $(OBJ)*


clean_apps: 
	rm -rf $(BIN)*
