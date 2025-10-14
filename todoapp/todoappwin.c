#include "todoappwin.h"

#include <gtk/gtk.h>

#include "todoapp.h"

struct _TodoAppWindow {
    GtkApplicationWindow parent;
};

G_DEFINE_TYPE(TodoAppWindow, todo_app_window, GTK_TYPE_APPLICATION_WINDOW);

static void todo_app_window_init(TodoAppWindow *window) {
    gtk_widget_init_template(GTK_WIDGET(window));
}

static void todo_app_window_class_init(TodoAppWindowClass *class) {
    gtk_widget_class_set_template_from_resource(
        GTK_WIDGET_CLASS(class), "/org/gtk/todoapp/window.ui"
    );
}

TodoAppWindow *todo_app_window_new(TodoApp *app) {
    return g_object_new(TODO_TYPE_APP_WINDOW, "application", app, NULL);
}
