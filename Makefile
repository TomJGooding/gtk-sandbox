CFLAGS = `pkg-config --cflags gtk4`
LDLIBS = `pkg-config --libs gtk4` 

builder: builder.c
	$(CC) $(CFLAGS) $< $(LDLIBS) -o $@

hello: hello.c
	$(CC) $(CFLAGS) $< $(LDLIBS) -o $@
