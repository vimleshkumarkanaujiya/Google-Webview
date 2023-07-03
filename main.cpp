#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

// Signal handler for the "destroy" event of the main window
static void destroy(GtkWidget* widget, gpointer data)
{
    gtk_main_quit();
}

// Signal handler for the "clicked" event of the home button
static void home_button_clicked(GtkButton* button, gpointer data)
{
    WebKitWebView* webView = WEBKIT_WEB_VIEW(data);
    webkit_web_view_load_uri(webView, "https://www.google.com");
}

// Signal handler for the "clicked" event of the back button
static void back_button_clicked(GtkButton* button, gpointer data)
{
    WebKitWebView* webView = WEBKIT_WEB_VIEW(data);
    webkit_web_view_go_back(webView);
}

// Signal handler for the "clicked" event of the forward button
static void forward_button_clicked(GtkButton* button, gpointer data)
{
    WebKitWebView* webView = WEBKIT_WEB_VIEW(data);
    webkit_web_view_go_forward(webView);
}

int main(int argc, char* argv[])
{
    // Initialize GTK
    gtk_init(&argc, &argv);

    // Create the main window
    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);

    // Create the web view
    WebKitWebView* webView = WEBKIT_WEB_VIEW(webkit_web_view_new());

    // Create the home button with icon
    GtkWidget* homeButton = gtk_button_new();
    GtkWidget* homeImage = gtk_image_new_from_file("res/home.png");
    gtk_button_set_image(GTK_BUTTON(homeButton), homeImage);
    g_signal_connect(homeButton, "clicked", G_CALLBACK(home_button_clicked), webView);

    // Create the back button with icon
    GtkWidget* backButton = gtk_button_new();
    GtkWidget* backImage = gtk_image_new_from_file("res/previous.png");
    gtk_button_set_image(GTK_BUTTON(backButton), backImage);
    g_signal_connect(backButton, "clicked", G_CALLBACK(back_button_clicked), webView);

    // Create the forward button with icon
    GtkWidget* forwardButton = gtk_button_new();
    GtkWidget* forwardImage = gtk_image_new_from_file("res/next.png");
    gtk_button_set_image(GTK_BUTTON(forwardButton), forwardImage);
    g_signal_connect(forwardButton, "clicked", G_CALLBACK(forward_button_clicked), webView);

    // Create a box to hold the buttons
    GtkWidget* buttonBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_pack_start(GTK_BOX(buttonBox), homeButton, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(buttonBox), backButton, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(buttonBox), forwardButton, FALSE, FALSE, 0);

    // Create a box to hold the web view and button box
    GtkWidget* box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_pack_start(GTK_BOX(box), buttonBox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), GTK_WIDGET(webView), TRUE, TRUE, 0);

    // Set the box as the main container of the window
    gtk_container_add(GTK_CONTAINER(window), box);

    // Load a webpage
    webkit_web_view_load_uri(webView, "https://www.google.com");

    // Show all the widgets
    gtk_widget_show_all(window);

    // Run the GTK main loop
    gtk_main();

    return 0;
}
