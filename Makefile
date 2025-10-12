CFLAGS = `pkg-config --cflags gtk4`
LDLIBS = `pkg-config --libs gtk4` 

hello: hello.c
	$(CC) $(CFLAGS) $< $(LDLIBS) -o $@
