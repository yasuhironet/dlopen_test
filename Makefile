app = dlopen_test
lib = libbgp1.so libbgp2.so libbgp3.so

CFLAGS = -Wall # -ansi -pedantic
LDFLAGS = -ldl

all: $(app) $(lib)

.c.o:
	$(CC) -c $<

clean:
	rm -f $(app) $(lib)

$(app): $(app).o data.o
	$(CC) -fPIC $(CFLAGS) $(LDFLAGS) -o $@ $< data.o

lib%.so: %.c
	$(CC) -shared -fPIC $(CFLAGS) -o $@ $<

