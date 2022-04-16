ifconfig | grep 'ether ' | awk -F\t '{print $2}' | awk -F'ether' '{print $2}' | tr -d ' '
