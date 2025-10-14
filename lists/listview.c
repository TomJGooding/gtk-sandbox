#include <glib-object.h>
#include <gtk/gtk.h>
#include <stdio.h>

//////////////////////////////////////////////////////////////////////////////
// The ListView widget displays data from a model.
//
// The ListStore model only accepts GObjects, so first we create a simple
// custom GObject initialized with a number.

#define T_TYPE_INTEGER (t_integer_get_type())
G_DECLARE_FINAL_TYPE(TInteger, t_integer, T, INTEGER, GObject)

struct _TInteger {
    GObject parent;
    int value;
};

G_DEFINE_TYPE(TInteger, t_integer, G_TYPE_OBJECT)

static void t_integer_class_init(TIntegerClass *class) {
    // This does nothing but needs to be defined for registration
}

static void t_integer_init(TInteger *self) {
    // This does nothing but needs to be defined for registration
}

TInteger *t_integer_new(int value) {
    TInteger *int_obj = g_object_new(T_TYPE_INTEGER, NULL);
    int_obj->value = value;
    return int_obj;
}

//////////////////////////////////////////////////////////////////////////////
// Example application with a ListView to display 100,000 items.
//
// A ListBox would struggle with this since it creates one widget per item!

static void setup_listitem(
    GtkSignalListItemFactory *self, GtkListItem *listitem, gpointer user_data
) {
    GtkWidget *label = gtk_label_new(NULL);
    gtk_list_item_set_child(listitem, label);
}

static void bind_listitem(
    GtkSignalListItemFactory *self, GtkListItem *listitem, gpointer user_data
) {
    TInteger *int_obj = gtk_list_item_get_item(listitem);
    char str[7];
    // Am I supposed to use a getter here...?
    sprintf(str, "%d", int_obj->value);

    GtkWidget *label = gtk_list_item_get_child(listitem);
    gtk_label_set_text(GTK_LABEL(label), str);
}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "ListView Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 300);

    GtkWidget *scroll = gtk_scrolled_window_new();
    gtk_window_set_child(GTK_WINDOW(window), scroll);

    // Create ListStore model with 100,000 objects
    GListStore *store = g_list_store_new(T_TYPE_INTEGER);
    for (int i = 0; i <= 100000; i++) {
        g_list_store_append(store, t_integer_new(i));
    }

    // The factory creates widgets for items from the list model
    GtkListItemFactory *factory = gtk_signal_list_item_factory_new();
    g_signal_connect(factory, "setup", G_CALLBACK(setup_listitem), NULL);
    g_signal_connect(factory, "bind", G_CALLBACK(bind_listitem), NULL);

    // Finally create the listview using the factory, allowing only single
    // items to be selectable
    GtkWidget *listview = gtk_list_view_new(
        GTK_SELECTION_MODEL(gtk_single_selection_new(G_LIST_MODEL(store))),
        factory
    );

    // Every ListView has to be a direct child of ScrolledWindow
    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scroll), listview);

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char *argv[]) {
    GtkApplication *app = gtk_application_new(
        "com.github.TomJGooding.listview", G_APPLICATION_DEFAULT_FLAGS
    );
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
