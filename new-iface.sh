#!/bin/bash

usage() { echo "usage: $0 [-g] -t <TypeName> -i <IfaceName>"; exit 1; }

while getopts ":gt:i:" o; do
    case "${o}" in
        g)
            gui="1"
            ;;
        t)
            type="${OPTARG}"
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
                    --title="Add GObject Interface" \
                    --text="Options" \
                    --separator="," \
                    --add-entry TypeName \
                    --add-entry IfaceName)

    accepted=$?
    if ((accepted != 0)); then
        echo "User canceled"
        exit 1
    fi

    type=$(awk -F, '{print $1}' <<<$OUTPUT)
    iface=$(awk -F, '{print $2}' <<<$OUTPUT)
fi

if [ -z "${type}" ] || [ -z "${iface}" ]; then
    usage
fi

type_l=`echo "${type}" | sed 's/.*/\L&/g'`
type_u=`echo "${type}" | sed 's/.*/\U&/g'`
type_n=`echo "${type}" | sed 's/_/-/g' | sed 's/.*/\L&/g'`
type=`echo "${type}" | sed 's/_//g'`

iface_l=`echo "${iface}" | sed 's/.*/\L&/g'`
iface_u=`echo "${iface}" | sed 's/.*/\U&/g'`
iface_n=`echo "${iface}" | sed 's/_/-/g' | sed 's/.*/\L&/g'`
iface=`echo "${iface}" | sed 's/_//g'`

DIR="$(dirname "$(readlink -f "$0")")"
file_name="${type_n}-${iface_n}"

cp "${DIR}/src/iface.h" "${file_name}.h" || exit
cp "${DIR}/src/iface.c" "${file_name}.c" || exit

sed "s:@Type@:${type}:g" -i "${file_name}.h"
sed "s:@type@:${type_l}:g" -i "${file_name}.h"
sed "s:@TYPE@:${type_u}:g" -i "${file_name}.h"
sed "s:@Type@:${type}:g" -i "${file_name}.c"
sed "s:@type@:${type_l}:g" -i "${file_name}.c"
sed "s:@TYPE@:${type_u}:g" -i "${file_name}.c"
sed "s:@type-name@:${type_n}:g" -i "${file_name}.c"

sed "s:@Iface@:${iface}:g" -i "${file_name}.h"
sed "s:@iface@:${iface_l}:g" -i "${file_name}.h"
sed "s:@IFACE@:${iface_u}:g" -i "${file_name}.h"
sed "s:@Iface@:${iface}:g" -i "${file_name}.c"
sed "s:@iface@:${iface_l}:g" -i "${file_name}.c"
sed "s:@IFACE@:${iface_u}:g" -i "${file_name}.c"
sed "s:@iface-name@:${iface_n}:g" -i "${file_name}.c"
