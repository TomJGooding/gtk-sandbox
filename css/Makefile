CFLAGS = `pkg-config --cflags gtk4`
LDLIBS = `pkg-config --libs gtk4`

css-examples: css_examples.c
	$(CC) $(CFLAGS) $< $(LDLIBS) -o $@
