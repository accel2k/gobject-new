# GObject class and interfaces generator

This project contains scripts for creating template code for classes and interfaces of the GObject library used in Glib/GTK+. new-iface.sh used to create an interface template, and new-object.sh to create a class (with interface, if necessary).

To declare an interface named GtkInterface, you must specify the following parameters to the script:

```
$ ./new-iface.sh -t Gtk -i Interface
```

To declare a class named GtkClass, you must specify the following parameters to the script:

```
$ ./new-object.sh -t Gtk -c Class
```

If a class should implement an interface add -i parameter:

```
$ ./new-object.sh -t Gtk -c Class -i Interface
```

If the class name consists of several words (ex. GtkSuperClass), these words should be separated by an underscore:

```
$ ./new-object.sh -t Gtk -c Super_Class
```

You can also run whose scripts in interactive mode with zenity programm:

```
$ ./new-iface.sh -g
$ ./new-object.sh -g
```
