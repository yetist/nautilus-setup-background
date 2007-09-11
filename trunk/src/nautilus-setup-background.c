/*
 * nautilus-setup-background.c
 * This file is part of nautilus-setup-background
 *
 * Copyright (C) 2007 - yetist <yetist@gmail.com>.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifdef HAVE_CONFIG_H
 #include <config.h> /* for GETTEXT_PACKAGE */
#endif

#include "nautilus-setup-background.h"

#include <libnautilus-extension/nautilus-menu-provider.h>

#include <glib/gi18n-lib.h>
#include <gconf/gconf-client.h>
#include <libgnomevfs/gnome-vfs-utils.h>


static void nautilus_setup_background_instance_init (NautilusSetupBackground      *cvs);
static void nautilus_setup_background_class_init    (NautilusSetupBackgroundClass *class);

static GType background_type = 0;


static void
do_set_background (NautilusMenuItem *item, NautilusFileInfo *file_info)
{
    char* path;
    char* value;
    static GConfClient *client;

    path = gnome_vfs_get_local_path_from_uri(nautilus_file_info_get_uri(file_info));

    client = gconf_client_get_default ();

    value = gconf_client_get_string(client, "/desktop/gnome/background/picture_options", NULL);
    if (g_ascii_strcasecmp(value, "none") == 0)
        gconf_client_set_string(client, "/desktop/gnome/background/picture_options", "stretched", NULL);
    gconf_client_set_string(client, "/desktop/gnome/background/picture_filename", path, NULL);

}

GList *
nautilus_setup_background_get_file_items (NautilusMenuProvider *provider,
				       GtkWidget            *window,
				       GList                *files)
{
	NautilusMenuItem *item;

	if (g_list_length (files) != 1)
        {
            return NULL;
	}
        else
        {
            if (g_ascii_strncasecmp("image", nautilus_file_info_get_mime_type(files->data), 5) == 0)
            {
                const char *name= _("Set As _Wallpaper");
                const char *tooltip = _("Setup the image as wallpaper");
                item = nautilus_menu_item_new ("NautilusSetupBackground::setup_background", name, tooltip, NULL);

                g_signal_connect (item, "activate", G_CALLBACK (do_set_background), files->data);

                return g_list_append (NULL, item);
            }
            return NULL;
        }
}

static void
nautilus_setup_background_menu_provider_iface_init (NautilusMenuProviderIface *iface)
{
	iface->get_file_items = nautilus_setup_background_get_file_items;
}

static void 
nautilus_setup_background_instance_init (NautilusSetupBackground *cvs)
{
}

static void
nautilus_setup_background_class_init (NautilusSetupBackgroundClass *class)
{
}

GType
nautilus_setup_background_get_type (void) 
{
	return background_type;
}

void
nautilus_setup_background_register_type (GTypeModule *module)
{
	static const GTypeInfo info = {
		sizeof (NautilusSetupBackgroundClass),
		(GBaseInitFunc) NULL,
		(GBaseFinalizeFunc) NULL,
		(GClassInitFunc) nautilus_setup_background_class_init,
		NULL, 
		NULL,
		sizeof (NautilusSetupBackground),
		0,
		(GInstanceInitFunc) nautilus_setup_background_instance_init,
	};

	static const GInterfaceInfo menu_provider_iface_info = {
		(GInterfaceInitFunc) nautilus_setup_background_menu_provider_iface_init,
		NULL,
		NULL
	};

	background_type = g_type_module_register_type (module,
						     G_TYPE_OBJECT,
						     "NautilusSetupBackground",
						     &info, 0);

	g_type_module_add_interface (module,
				     background_type,
				     NAUTILUS_TYPE_MENU_PROVIDER,
				     &menu_provider_iface_info);
}
