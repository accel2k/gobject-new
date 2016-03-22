#include "@type-name@-@iface-name@.h"

G_DEFINE_INTERFACE (@Type@@Iface@, @type@_@iface@, G_TYPE_OBJECT)

static void
@type@_@iface@_default_init (@Type@@Iface@Interface *iface)
{
}

void
@type@_@iface@_set_a (@Type@@Iface@ *@iface@,
                      gint           a)
{
  @Type@@Iface@Interface *iface;

  g_return_if_fail (@TYPE@_IS_@IFACE@ (@iface@));

  iface = @TYPE@_@IFACE@_GET_IFACE (@iface@);
  if (iface->set_a != NULL)
    (* iface->set_a) (@iface@, a);
}

gint
@type@_@iface@_get_a (@Type@@Iface@ *@iface@)
{
  @Type@@Iface@Interface *iface;

  g_return_val_if_fail (@TYPE@_IS_@IFACE@ (@iface@), 0);

  iface = @TYPE@_@IFACE@_GET_IFACE (@iface@);
  if (iface->get_a != NULL)
    return (* iface->get_a) (@iface@);

  return 0;
}
