CFLAGS = `pkg-config --cflags gtk4`
LDLIBS = `pkg-config --libs gtk4` 

listbox: listbox.c
	$(CC) $(CFLAGS) $< $(LDLIBS) -o $@
