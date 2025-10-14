CFLAGS = `pkg-config --cflags gtk4`
LDLIBS = `pkg-config --libs gtk4` 

listview: listview.c
	$(CC) $(CFLAGS) $< $(LDLIBS) -o $@

listbox: listbox.c
	$(CC) $(CFLAGS) $< $(LDLIBS) -o $@
