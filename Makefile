app = dlopen_test
lib = libbgp1.so libbgp2.so

CFLAGS = -Wall # -ansi -pedantic
LDFLAGS = -ldl

all: $(app) $(lib)

clean:
	rm -f $(app) $(lib)

$(app): $(app).c
	$(CC) -fPIC $(CFLAGS) $(LDFLAGS) -o $@ $<

lib%.so: %.c
	$(CC) -shared -fPIC $(CFLAGS) -o $@ $<

