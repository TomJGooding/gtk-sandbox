#include "glib-object.h"
#include <gtk/gtk.h>

static void on_activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *box;
    GtkWidget *label;

    window = gtk_application_window_new(app);
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 12);
    gtk_window_set_child(GTK_WINDOW(window), box);

    //////////////////////////////////////////
    // Font style classes available in GTK 4
    label = gtk_label_new("Large Title");
    gtk_widget_add_css_class(label, "large-title");
    gtk_box_append(GTK_BOX(box), label);

    label = gtk_label_new("Title 1");
    gtk_widget_add_css_class(label, "title-1");
    gtk_box_append(GTK_BOX(box), label);

    label = gtk_label_new("Title 2");
    gtk_widget_add_css_class(label, "title-2");
    gtk_box_append(GTK_BOX(box), label);

    label = gtk_label_new("Title 3");
    gtk_widget_add_css_class(label, "title-3");
    gtk_box_append(GTK_BOX(box), label);

    label = gtk_label_new("Title 4");
    gtk_widget_add_css_class(label, "title-4");
    gtk_box_append(GTK_BOX(box), label);

    label = gtk_label_new("Heading");
    gtk_widget_add_css_class(label, "heading");
    gtk_box_append(GTK_BOX(box), label);

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char *argv[]) {
    GtkApplication *app = gtk_application_new(
        "com.github.TomJGooding.css-examples", G_APPLICATION_DEFAULT_FLAGS
    );
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);

    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
