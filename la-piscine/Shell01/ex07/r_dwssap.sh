cat /etc/passwd | grep -v '^#' | awk 'NR%2==0' | awk -F: '{print $1}' | rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | tr '\n' Z | sed "s/Z/,Z/g" | tr Z ' ' | sed 's/, $/./' | tr -d '\n'
