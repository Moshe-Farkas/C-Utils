# dirs:
OUT_DIR := out
LIB_DIR := lib
SRC_DIR := src
INCLUDE_DIR := include

CFLAGS := -Wall

EXE_FILE := prog
LIB_FILE := hashmap.a

$(EXE_FILE): lib $(OUT_DIR)/main.o
	gcc $(CFLAGS) $(OUT_DIR)/main.o -L $(LIB_DIR) -l:$(LIB_FILE) -I $(INCLUDE_DIR) -o $(EXE_FILE)


lib: $(OUT_DIR)/hashmap.o
	ar rc $(LIB_DIR)/$(LIB_FILE) $(OUT_DIR)/hashmap.o


$(OUT_DIR)/hashmap.o: $(SRC_DIR)/hashmap.c
	gcc $(CFLAGS) -c $(SRC_DIR)/hashmap.c -I $(INCLUDE_DIR) -o $(OUT_DIR)/hashmap.o


$(OUT_DIR)/main.o: main.c
	gcc $(CFLAGS) -c main.c -I $(INCLUDE_DIR) -o $(OUT_DIR)/main.o


clean:
	rm -r $(EXE_FILE) $(OUT_DIR)/*