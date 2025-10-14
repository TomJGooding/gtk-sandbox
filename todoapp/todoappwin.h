#pragma once

#include <gtk/gtk.h>

#include "todoapp.h"

#define TODO_TYPE_APP_WINDOW (todo_app_window_get_type())
G_DECLARE_FINAL_TYPE(
    TodoAppWindow, todo_app_window, TODO, APP_WINDOW, GtkApplicationWindow
)

TodoAppWindow *todo_app_window_new(TodoApp *app);
