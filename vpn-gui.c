/*
 * gcc -Wall -g vpn-gui.c -o vpn-gui `pkg-config --cflags --libs gtk+-3.0`
 */

#include <gtk/gtk.h> 

/* my vpn script */
static char *vpn_cmd = "bash -c '/home/benny/.local/bin/wwu-vpn >> /home/benny/.log/vpn &'"; 
static GtkWidget *menu, 
          *toggle_item, 
          *quit_item;
static GtkStatusIcon *icon; 

static gboolean button_press_cb(GtkStatusIcon *icon, GdkEventButton *ev, gpointer user_data);
static void command_send(GtkMenuItem *item, gpointer data);
static void init();

/* is vpn connected or not? */
static enum {OFF = 0, ON = 1} status;


/* which menu option is choosen? */
static void command_send(GtkMenuItem *item, gpointer data)
{
  switch(GPOINTER_TO_INT(data)) {
    case 0:
      if(status == ON)  {
        g_spawn_command_line_async(vpn_cmd, NULL);
        status = OFF;
        gtk_status_icon_set_from_icon_name(icon, "window-close");
      }
      else  {
        g_spawn_command_line_async(vpn_cmd, NULL);
        status = ON;
        gtk_status_icon_set_from_icon_name(icon, "network-idle");
      }
      break;
    case 1:
      if(status == ON)  {
        g_spawn_command_line_async(vpn_cmd, NULL);
      }
      gtk_main_quit();
    default:
      break;
  }
}


static void init() 
{
  status = OFF;
  icon = gtk_status_icon_new_from_icon_name("window-close");
  g_signal_connect(icon,"button-press-event", G_CALLBACK(button_press_cb), NULL); 
  menu = gtk_menu_new(); 

  // Create Items
  toggle_item = gtk_menu_item_new_with_label("Toogle VPN");
  quit_item  = gtk_menu_item_new_with_label("Quit");

  /* gtk_image_menu_item_set_image(GTK_IMAGE_MENU_ITEM(toggle_item), gtk_image_new_from_stock(GTK_STOCK_NETWORK, GTK_ICON_SIZE_MENU)); */
  g_signal_connect(G_OBJECT(toggle_item),"activate", G_CALLBACK(command_send), GINT_TO_POINTER( 0 ));
  g_signal_connect(G_OBJECT(quit_item), "activate", G_CALLBACK(command_send), GINT_TO_POINTER(1));
  gtk_menu_shell_append(GTK_MENU_SHELL(menu), toggle_item); 
  gtk_menu_shell_append(GTK_MENU_SHELL(menu), quit_item); 

  gtk_widget_show_all(menu);
}


gboolean button_press_cb(GtkStatusIcon *icon, GdkEventButton *ev, gpointer user_data) 
{  
  if(ev->button == 1) {
    gtk_menu_popup(GTK_MENU(menu), NULL, NULL, NULL, NULL, ev->button, ev->time); 
    return FALSE;
  }
}


gint main(gint argc, gchar **argv) 
{ 
  gtk_init(&argc, &argv); 
  init();
  gtk_main(); 

  return 0; 
}

