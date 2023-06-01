CC := gcc
CFLAGS += -g 
SRC := src
TARGET := calculator
TEST := tests

FILES = calculator.c
SOURCES = $(patsubst %, $(SRC)/%, $(FILES))
OBJECTS = $(patsubst %.c, $(SRC)/%.o, $(FILES))

TEST_SOURCE = $(TEST)/test_driver.c
TEST_OBJECT = $(TEST)/test_driver.o
TEST_TARGET = $(TEST)/test_driver
TEST_CASES = $(shell find $(TEST)/testsuite -type f)

$(SRC)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS) $(SRC)/main.c
	$(CC) -o $(TARGET) $(LDFLAGS) $(OBJECTS) $(SRC)/main.c

$(TEST)/%.o: $(TEST)/%.c
	$(CC) $(CFLAGS) -I $(SRC) -c $< -o $@

$(TEST_TARGET): $(TEST_OBJECT) $(OBJECTS)
	$(CC) $(CFLAGS) -I $(SRC) $^ -o $@  

$(TEST_TARGET)_gcov: $(TEST_OBJECT) $(OBJECTS)
	$(CC) $(CFLAGS) -I src $^ $(LDFLAGS) -o $@

all: $(TARGET) $(TEST_TARGET)

coverage: clean_build 
	make $(TEST_TARGET)_gcov "CFLAGS=--coverage" LDFLAGS="-lgcov --coverage"

clean_build:
	rm -f $(SRC)/*.o $(TEST)/*.o
	rm -f $(TEST_TARGET)_gcov
	find . -name "*.gcno" | xargs rm -f 
	find . -name "*.gcda" | xargs rm -f 

clean: clean_build
	rm -f $(TARGET) $(TEST_TARGET)

docker: clean
	docker buildx build --platform linux/amd64 -t calculator .
