#include <gtk/gtk.h>

#include "todoapp.h"

int main(int argc, char *argv[]) {
    TodoApp *app = todo_app_new();
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
