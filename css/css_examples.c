#include <gtk/gtk.h>

static void on_startup(GtkApplication *app, gpointer user_data) {
    // Add custom CSS for taller progress bars
    GdkDisplay *display = gdk_display_get_default();
    GtkCssProvider *provider = gtk_css_provider_new();
    gtk_css_provider_load_from_string(
        provider, "progressbar > trough, progress { min-height: 1em; }"
    );
    gtk_style_context_add_provider_for_display(
        display,
        GTK_STYLE_PROVIDER(provider),
        GTK_STYLE_PROVIDER_PRIORITY_APPLICATION
    );
}

static void on_activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *box;
    GtkWidget *label;
    GtkWidget *grid;
    GtkWidget *button;
    GtkWidget *progress_bar;

    window = gtk_application_window_new(app);
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 12);
    gtk_widget_set_halign(box, GTK_ALIGN_CENTER);
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

    label = gtk_label_new("Body default");
    gtk_box_append(GTK_BOX(box), label);

    //////////////////////////////////////////
    // Button CSS classes
    grid = gtk_grid_new();
    gtk_grid_set_column_spacing(GTK_GRID(grid), 6);
    gtk_box_append(GTK_BOX(box), grid);

    button = gtk_button_new_with_label("Default");
    gtk_grid_attach(GTK_GRID(grid), button, 0, 0, 1, 1);

    button = gtk_button_new_with_label("Destructive");
    gtk_widget_add_css_class(button, "destructive-action");
    gtk_grid_attach(GTK_GRID(grid), button, 1, 0, 1, 1);

    button = gtk_button_new_with_label("Suggested");
    gtk_widget_add_css_class(button, "suggested-action");
    gtk_grid_attach(GTK_GRID(grid), button, 2, 0, 1, 1);

    button = gtk_button_new_from_icon_name("list-add");
    gtk_widget_add_css_class(button, "circular");
    gtk_grid_attach(GTK_GRID(grid), button, 3, 0, 1, 1);

    //////////////////////////////////////////
    // Example custom styled progress bars (see startup handler above)
    progress_bar = gtk_progress_bar_new();
    gtk_box_append(GTK_BOX(box), progress_bar);

    progress_bar = gtk_progress_bar_new();
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress_bar), 0.5);
    gtk_box_append(GTK_BOX(box), progress_bar);

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char *argv[]) {
    GtkApplication *app = gtk_application_new(
        "com.github.TomJGooding.css-examples", G_APPLICATION_DEFAULT_FLAGS
    );
    g_signal_connect(app, "startup", G_CALLBACK(on_startup), NULL);
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);

    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
