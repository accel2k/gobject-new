#include "@type-name@-@class-name@.h"

enum
{
  PROP_O,
  PROP_A
};

struct _@Type@@Class@Private
{
  gint                         prop_a;
};

static void    @type@_@class@_set_property             (GObject               *object,
                                                        guint                  prop_id,
                                                        const GValue          *value,
                                                        GParamSpec            *pspec);
static void    @type@_@class@_get_property             (GObject               *object,
                                                        guint                  prop_id,
                                                        GValue                *value,
                                                        GParamSpec            *pspec);
static void    @type@_@class@_object_constructed       (GObject               *object);
static void    @type@_@class@_object_finalize          (GObject               *object);

/* !!! Change G_TYPE_OBJECT to type of the base class. !!! */
G_DEFINE_TYPE_WITH_PRIVATE (@Type@@Class@, @type@_@class@, G_TYPE_OBJECT)

static void
@type@_@class@_class_init (@Type@@Class@Class *klass)
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
  @class@->priv = @type@_@class@_get_instance_private (@class@);
}

static void
@type@_@class@_set_property (GObject      *object,
                             guint         prop_id,
                             const GValue *value,
                             GParamSpec   *pspec)
{
  @Type@@Class@ *@class@ = @TYPE@_@CLASS@ (object);
  @Type@@Class@Private *priv = @class@->priv;

  switch (prop_id)
    {
    case PROP_A:
      priv->prop_a = g_value_get_int (value);
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
  @Type@@Class@Private *priv = @class@->priv;

  switch ( prop_id )
    {
    case PROP_A:
      g_value_set_int (value, priv->prop_a);
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
  @Type@@Class@Private *priv = @class@->priv;

  /* Remove this call then class is derived from GObject.
     This call is strongly needed then class is derived from GtkWidget. */
  G_OBJECT_CLASS (@type@_@class@_parent_class)->constructed (object);

  priv->prop_a = 1;
}

static void
@type@_@class@_object_finalize (GObject *object)
{
  @Type@@Class@ *@class@ = @TYPE@_@CLASS@ (object);
  @Type@@Class@Private *priv = @class@->priv;

  priv->prop_a = 0;

  G_OBJECT_CLASS (@type@_@class@_parent_class)->finalize (object);
}

void
@type@_@class@_set_a (@Type@@Class@ *@class@,
                      gint           a)
{
  @Type@@Class@Private *priv = @class@->priv;

  g_return_if_fail (@TYPE@_IS_@CLASS@ (@class@));

  priv->prop_a = a;
}

gint
@type@_@class@_get_a (@Type@@Class@ *@class@)
{
  @Type@@Class@Private *priv = @class@->priv;

  g_return_val_if_fail (@TYPE@_IS_@CLASS@ (@class@), -1);

  return priv->prop_a;
}
