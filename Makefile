# dirs:
OUT_DIR := out
LIB_DIR := lib
SRC_DIR := src
INCLUDE_DIR := include

CFLAGS := -Wall


# libs
H_MAP_LIB := hashmap.a
L_LIST_LIB := linkedlist.a
QUEUE_LIB := queue.a
STACK_LIB := stack.a
VECTOR_LIB := vector.a


EXE_FILE := prog

$(EXE_FILE): libs $(OUT_DIR)/main.o
	gcc $(CFLAGS) $(OUT_DIR)/main.o -L $(LIB_DIR) \
		-l:$(H_MAP_LIB)                           \
		-l:$(QUEUE_LIB)                           \
		-l:$(STACK_LIB)                           \
		-l:$(VECTOR_LIB)                          \
		-I $(INCLUDE_DIR) -o $(EXE_FILE)


libs: hashmaplib queuelib stacklib vectorlib


hashmaplib: buildhashmaplib
	ar rc $(LIB_DIR)/$(H_MAP_LIB) $(OUT_DIR)/hashmap.o
buildhashmaplib: $(SRC_DIR)/hashmap.c
	gcc $(CFLAGS) -c $(SRC_DIR)/hashmap.c -I $(INCLUDE_DIR) -o $(OUT_DIR)/hashmap.o


queuelib:	buildqueuelib
	ar rc $(LIB_DIR)/$(QUEUE_LIB) $(OUT_DIR)/queue.o
buildqueuelib: $(SRC_DIR)/queue.c
	gcc $(CFLAGS) -c $(SRC_DIR)/queue.c -I $(INCLUDE_DIR) -o $(OUT_DIR)/queue.o 


stacklib: buildstacklib
	ar rc $(LIB_DIR)/$(STACK_LIB) $(OUT_DIR)/stack.o
buildstacklib: $(SRC_DIR)/stack.c
	gcc $(CFLAGS) -c $(SRC_DIR)/stack.c -I $(INCLUDE_DIR) -o $(OUT_DIR)/stack.o 


vectorlib: buildvectorlib
	ar rc $(LIB_DIR)/$(VECTOR_LIB) $(OUT_DIR)/vector.o
buildvectorlib: $(SRC_DIR)/vector.c
	gcc $(CFLAGS) -c $(SRC_DIR)/vector.c -I $(INCLUDE_DIR) -o $(OUT_DIR)/vector.o 


$(OUT_DIR)/main.o: main.c
	gcc $(CFLAGS) -c main.c -I $(INCLUDE_DIR) -o $(OUT_DIR)/main.o


clean:
	rm -r $(EXE_FILE) $(OUT_DIR)/*

cleanlibs:
	rm -r $(LIB_DIR)/*