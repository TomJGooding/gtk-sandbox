CFLAGS = `pkg-config --cflags gtk4`
LDLIBS = `pkg-config --libs gtk4` 

SRCS = main.c todoapp.c todoappwin.c
BUILT_SRC = resources.c

OBJS = $(BUILT_SRC:.c=.o) $(SRCS:.c=.o)

all: todoapp

resources.c: todoapp.gresource.xml window.ui
	glib-compile-resources $< --target=$@ --sourcedir=. --generate-source

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

todoapp: $(OBJS)
	$(CC) $(OBJS) $(LDLIBS) -o $@

clean:
	rm -f $(BUILT_SRC)
	rm -f $(OBJS)
	rm -f todoapp
