BIN=./self
SOURCE=self.c

all: c

clean:
	rm $(BIN) || :

c: clean
	clear; gcc $(SOURCE) -std=gnu99 -o $(BIN);

check: c
	$(eval RESULT := $(shell mktemp))
	$(BIN) >$(RESULT); diff -rupN $(SOURCE) $(RESULT);
