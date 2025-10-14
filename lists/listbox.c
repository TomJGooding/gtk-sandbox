#include <gtk/gtk.h>
#include <stdio.h>

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "ListBox Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 300);

    GtkWidget *scroll = gtk_scrolled_window_new();

    gtk_window_set_child(GTK_WINDOW(window), scroll);

    GtkWidget *listbox = gtk_list_box_new();

    for (int i = 0; i <= 100; i++) {
        char str[4];
        sprintf(str, "%d", i);
        GtkWidget *label = gtk_label_new(str);
        gtk_list_box_append(GTK_LIST_BOX(listbox), label);
    }

    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scroll), listbox);

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char *argv[]) {
    GtkApplication *app = gtk_application_new(
        "com.github.TomJGooding.listbox", G_APPLICATION_DEFAULT_FLAGS
    );
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
