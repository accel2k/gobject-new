#!/bin/bash

usage() { echo "usage: $0 [-g] -t <TypeName> -c <ClassName> [-i <IfaceName>]"; exit 1; }

while getopts ":gt:c:i:" o; do
    case "${o}" in
        g)
            gui="1"
            ;;
        t)
            type="${OPTARG}"
            ;;
        c)
            class="${OPTARG}"
            ;;
        i)
            iface="${OPTARG}"
            ;;
        *)
            usage
            ;;
    esac
done
shift $((OPTIND-1))

if [ "${gui}" ]; then
    OUTPUT=$(zenity --forms \
                    --title="Add GObject Class" \
                    --text="Options" \
                    --separator="," \
                    --add-entry TypeName \
                    --add-entry ClassName \
                    --add-entry "IfaceName (optional)")

    accepted=$?
    if ((accepted != 0)); then
        echo "User canceled"
        exit 1
    fi

    type=$(awk -F, '{print $1}' <<<$OUTPUT)
    class=$(awk -F, '{print $2}' <<<$OUTPUT)
    iface=$(awk -F, '{print $3}' <<<$OUTPUT)
fi

if [ -z "${type}" ] || [ -z "${class}" ]; then
    usage
fi

if [ -z "${iface}" ]; then
  src="class"
else
  src="iface-class"
fi

type_l=`echo "${type}" | sed 's/.*/\L&/g'`
type_u=`echo "${type}" | sed 's/.*/\U&/g'`
type_n=`echo "${type}" | sed 's/_/-/g' | sed 's/.*/\L&/g'`
type=`echo "${type}" | sed 's/_//g'`

class_l=`echo "${class}" | sed 's/.*/\L&/g'`
class_u=`echo "${class}" | sed 's/.*/\U&/g'`
class_n=`echo "${class}" | sed 's/_/-/g' | sed 's/.*/\L&/g'`
class=`echo "${class}" | sed 's/_//g'`

iface_l=`echo "${iface}" | sed 's/.*/\L&/g'`
iface_u=`echo "${iface}" | sed 's/.*/\U&/g'`
iface_n=`echo "${iface}" | sed 's/_/-/g' | sed 's/.*/\L&/g'`
iface=`echo "${iface}" | sed 's/_//g'`

DIR="$(dirname "$(readlink -f "$0")")"
file_name="${type_n}-${class_n}"

cp "${DIR}/src/${src}.h" "${file_name}.h" || exit
cp "${DIR}/src/${src}.c" "${file_name}.c" || exit

sed "s:@Type@:${type}:g" -i "${file_name}.h"
sed "s:@type@:${type_l}:g" -i "${file_name}.h"
sed "s:@TYPE@:${type_u}:g" -i "${file_name}.h"
sed "s:@type-name@:${type_n}:g" -i "${file_name}.h"
sed "s:@Type@:${type}:g" -i "${file_name}.c"
sed "s:@type@:${type_l}:g" -i "${file_name}.c"
sed "s:@TYPE@:${type_u}:g" -i "${file_name}.c"
sed "s:@type-name@:${type_n}:g" -i "${file_name}.c"

sed "s:@Class@:${class}:g" -i "${file_name}.h"
sed "s:@class@:${class_l}:g" -i "${file_name}.h"
sed "s:@CLASS@:${class_u}:g" -i "${file_name}.h"
sed "s:@class-name@:${class_n}:g" -i "${file_name}.h"
sed "s:@Class@:${class}:g" -i "${file_name}.c"
sed "s:@class@:${class_l}:g" -i "${file_name}.c"
sed "s:@CLASS@:${class_u}:g" -i "${file_name}.c"
sed "s:@class-name@:${class_n}:g" -i "${file_name}.c"

sed "s:@Iface@:${iface}:g" -i "${file_name}.h"
sed "s:@IFACE@:${iface_u}:g" -i "${file_name}.h"
sed "s:@iface-name@:${iface_n}:g" -i "${file_name}.h"
sed "s:@Iface@:${iface}:g" -i "${file_name}.c"
sed "s:@iface@:${iface_l}:g" -i "${file_name}.c"
sed "s:@IFACE@:${iface_u}:g" -i "${file_name}.c"
sed "s:@iface-name@:${iface_n}:g" -i "${file_name}.c"
