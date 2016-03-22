#ifndef __@TYPE@_@CLASS@_H__
#define __@TYPE@_@CLASS@_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define @TYPE@_TYPE_@CLASS@             (@type@_@class@_get_type ())
#define @TYPE@_@CLASS@(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), @TYPE@_TYPE_@CLASS@, @Type@@Class@))
#define @TYPE@_IS_@CLASS@(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), @TYPE@_TYPE_@CLASS@))
#define @TYPE@_@CLASS@_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), @TYPE@_TYPE_@CLASS@, @Type@@Class@Class))
#define @TYPE@_IS_@CLASS@_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), @TYPE@_TYPE_@CLASS@))
#define @TYPE@_@CLASS@_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), @TYPE@_TYPE_@CLASS@, @Type@@Class@Class))

typedef struct _@Type@@Class@ @Type@@Class@;
typedef struct _@Type@@Class@Class @Type@@Class@Class;

struct _@Type@@Class@Class
{
  GObjectClass parent_class;
};

GType                  @type@_@class@_get_type         (void);

void                   @type@_@class@_set_a            (@Type@@Class@ *@class@,
                                                        gint           a);

gint                   @type@_@class@_get_a            (@Type@@Class@ *@class@);

G_END_DECLS

#endif /* __@TYPE@_@CLASS@_H__ */
