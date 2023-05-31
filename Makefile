CC := gcc
CFLAGS += -g
SRC := src
TARGET := calculator
TEST := tests

FILES = calculator.c
SOURCES = $(patsubst %, $(SRC)/%, $(FILES))
OBJECTS = $(patsubst %.c, $(SRC)/%.o, $(FILES))

$(SRC)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS) $(SRC)/main.c
	$(CC) -o $(TARGET) $(LDFLAGS) $(OBJECTS) $(SRC)/main.c


all: $(TARGET) $(TEST_TARGET)


clean:
	rm -f $(TARGET) $(TEST_TARGET) $(OBJECTS)

docker: clean
	docker buildx build --platform linux/amd64 -t calculator .
