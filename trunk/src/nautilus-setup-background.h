/*
 * nautilus-setup-background.h
 *
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

#ifndef NAUTILUS_SETUP_BACKGROUND_H
#define NAUTILUS_SETUP_BACKGROUND_H

#include    <glib-object.h>

G_BEGIN_DECLS

#define NAUTILUS_TYPE_SETUP_BACKGROUND              (nautilus_setup_background_get_type ())
#define NAUTILUS_SETUP_BACKGROUND(obj)              (G_TYPE_CHECK_INSTANCE_CAST ((obj), NAUTILUS_TYPE_SETUP_BACKGROUND, NautilusSetupBackground))
#define NAUTILUS_IS_SETUP_BACKGROUND(obj)           (G_TYPE_CHECK_INSTANCE_TYPE ((obj), NAUTILUS_TYPE_SETUP_BACKGROUND))

typedef struct _NautilusSetupBackground             NautilusSetupBackground;
typedef struct _NautilusSetupBackgroundClass        NautilusSetupBackgroundClass;

struct _NautilusSetupBackground
{
  GObject      parent;
};

struct _NautilusSetupBackgroundClass
{
  GObjectClass     parent_class;
};

GType      nautilus_setup_background_get_type           (void) G_GNUC_CONST;
void       nautilus_setup_background_register_type      (GTypeModule *module);

G_END_DECLS

#endif
