#include "@type-name@-@iface-name@.h"

G_DEFINE_INTERFACE (@Type@@Iface@, @type@_@iface@, G_TYPE_OBJECT);

static void
@type@_@iface@_default_init (@Type@@Iface@Interface *iface)
{
}

void
@type@_@iface@_set_a (@Type@@Iface@ *@iface@,
                      gint           a)
{
  if (@TYPE@_@IFACE@_GET_IFACE (@iface@)->set_a)
    @TYPE@_@IFACE@_GET_IFACE (@iface@)->set_a (@iface@, a);
}

gint
@type@_@iface@_get_a (@Type@@Iface@ *@iface@)
{
  if (@TYPE@_@IFACE@_GET_IFACE (@iface@)->get_a)
    return @TYPE@_@IFACE@_GET_IFACE (@iface@)->get_a (@iface@);

  return 0;
}
