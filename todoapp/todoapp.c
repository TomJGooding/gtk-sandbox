#include "todoapp.h"

#include <gtk/gtk.h>

#include "todoappwin.h"

struct _TodoApp {
    GtkApplication parent;
};

G_DEFINE_TYPE(TodoApp, todo_app, GTK_TYPE_APPLICATION);

static void todo_app_init(TodoApp *app) {}

static void todo_app_activate(GApplication *app) {
    TodoAppWindow *window = todo_app_window_new(TODO_APP(app));
    gtk_window_present(GTK_WINDOW(window));
}

static void todo_app_class_init(TodoAppClass *class) {
    G_APPLICATION_CLASS(class)->activate = todo_app_activate;
}

TodoApp *todo_app_new(void) {
    return g_object_new(
        TODO_TYPE_APP,
        "application-id",
        "com.github.TomJGooding.todoapp",
        "flags",
        G_APPLICATION_DEFAULT_FLAGS,
        NULL
    );
}
