#include "@type-name@-@class-name@.h"

enum
{
  PROP_O,
  PROP_A
};

struct _@Type@@Class@
{
  GObject                      parent_instance;

  gint                         prop_a;
};

static void    @type@_@class@_interface_init           (@Type@@Iface@Interface *iface);
static void    @type@_@class@_set_property             (GObject                *object,
                                                        guint                   prop_id,
                                                        const GValue           *value,
                                                        GParamSpec             *pspec);
static void    @type@_@class@_get_property             (GObject                *object,
                                                        guint                   prop_id,
                                                        GValue                 *value,
                                                        GParamSpec             *pspec);
static void    @type@_@class@_object_constructed       (GObject                *object);
static void    @type@_@class@_object_finalize          (GObject                *object);

G_DEFINE_TYPE_WITH_CODE (@Type@@Class@, @type@_@class@, G_TYPE_OBJECT,
                         G_IMPLEMENT_INTERFACE (@TYPE@_TYPE_@IFACE@, @type@_@class@_interface_init));

static void @type@_@class@_class_init (@Type@@Class@Class *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->set_property = @type@_@class@_set_property;
  object_class->get_property = @type@_@class@_get_property;

  object_class->constructed = @type@_@class@_object_constructed;
  object_class->finalize = @type@_@class@_object_finalize;

  g_object_class_install_property (object_class, PROP_A,
    g_param_spec_int ("param-a", "ParamA", "Parameter A", G_MININT32, G_MAXINT32, 0,
                      G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
}

static void
@type@_@class@_init (@Type@@Class@ *@class@)
{
}

static void
@type@_@class@_set_property (GObject      *object,
                             guint         prop_id,
                             const GValue *value,
                             GParamSpec   *pspec)
{
  @Type@@Class@ *@class@ = @TYPE@_@CLASS@ (object);

  switch (prop_id)
    {
    case PROP_A:
      @class@->prop_a = g_value_get_int (value);
      break;

    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
    }
}

static void
@type@_@class@_get_property (GObject    *object,
                             guint       prop_id,
                             GValue     *value,
                             GParamSpec *pspec)
{
  @Type@@Class@ *@class@ = @TYPE@_@CLASS@ (object);

  switch ( prop_id )
    {
    case PROP_A:
      g_value_set_int (value, @class@->prop_a);
      break;

    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
    }
}

static void
@type@_@class@_object_constructed (GObject *object)
{
  @Type@@Class@ *@class@ = @TYPE@_@CLASS@ (object);
}

static void
@type@_@class@_object_finalize (GObject *object)
{
  @Type@@Class@ *@class@ = @TYPE@_@CLASS@ (object);

  @class@->prop_a = 0;

  G_OBJECT_CLASS (@type@_@class@_parent_class)->finalize (object);
}

void
@type@_@class@_set_a (@Type@@Iface@ *@iface-name@,
                      gint           a)
{
  @Type@@Class@ *@class@ = @TYPE@_@CLASS@ (@iface-name@);

  @class@->prop_a = a;
}

gint
@type@_@class@_get_a (@Type@@Iface@ *@iface-name@)
{
  @Type@@Class@ *@class@ = @TYPE@_@CLASS@ (@iface-name@);
  return @class@->prop_a;
}

static void
@type@_@class@_interface_init (@Type@@Iface@Interface *iface)
{
  iface->set_a = @type@_@class@_set_a;
  iface->get_a = @type@_@class@_get_a;
}