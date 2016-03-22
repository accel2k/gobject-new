#ifndef __@TYPE@_@IFACE@_H__
#define __@TYPE@_@IFACE@_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define @TYPE@_TYPE_@IFACE@            (@type@_@iface@_get_type ())
#define @TYPE@_@IFACE@(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), @TYPE@_TYPE_@IFACE@, @Type@@Iface@))
#define @TYPE@_IS_@IFACE@(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), @TYPE@_TYPE_@IFACE@))
#define @TYPE@_@IFACE@_GET_IFACE(obj)  (G_TYPE_INSTANCE_GET_INTERFACE ((obj), @TYPE@_TYPE_@IFACE@, @Type@@Iface@Interface))

typedef struct _@Type@@Iface@ @Type@@Iface@;
typedef struct _@Type@@Iface@Interface @Type@@Iface@Interface;

struct _@Type@@Iface@Interface
{
  GTypeInterface       g_iface;

  void                 (*set_a)                (@Type@@Iface@         *@iface@,
                                                gint                   a);

  gint                 (*get_a)                (@Type@@Iface@         *@iface@);
};

GType @type@_@iface@_get_type                  (void);

void @type@_@iface@_set_a                      (@Type@@Iface@         *@iface@,
                                                gint                   a);

gint @type@_@iface@_get_a                      (@Type@@Iface@         *@iface@);

G_END_DECLS

#endif /* __@TYPE@_@IFACE@_H__ */
