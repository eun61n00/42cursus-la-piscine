#!bin/bash

printf "\t#Architecture: "
		uname -a

printf "\t#CPU physical: "
		nproc

printf "\t#vCPU: "
		cat /proc/cpuinfo | grep processor | wc -l

printf "\t#Memory Usage: "
		free -m | grep Mem | awk '{printf "%d/%dMB (%.2f%%)\n", $3, $2, $3 / $2 * 100}'

printf "\t#Disk Usage: "
		df -a -BM | grep /dev/mapper | awk '{used += $3}END{print used}' | tr -d '\n'
		printf "/"
		df -a -BM | grep /dev/mapper | awk '{used += $4}{available += $4}END{printf "%d", used + available}' | tr -d '\n'
		printf "MB ("
		df -a -BM | grep /dev/mapper | awk '{used += $4}{available += $4}END{printf "%d%%)\n", used / (used + available) * 100}'

printf "\t#CPU load: "
		mpstat | grep all | awk '{printf "%.2f%%\n", 100-$13}'

printf "\t#Lash boot: "
		who -b | awk '{printf $3" "$3"\n"}'

printf "\t#LVM used: "
		if [ "$(lsblk | grep lvm | wc -l)" -gt 0 ]
			then
					printf "yes\n"
			else
					printf "no\n"
			fi

printf "\t#Connections TCP: "
		ss | grep -i tcp | wc -l | tr -d '\n'
		pintf " ESTABLISED"

printf "\t#User log: "
		whoami | wc -l

printf "\t#Network: IP "
		hostname -I | tr -d '\n'
		printf "("
		ip link | grep link/ether | awk '{print $2}' | tr -d '\n'
		printf ")\n"

printf "\t#Sudo: "
		journalctl _COMM=sudo | grep COMMAND | wc -l | tr -d '\n'
		ptinf " cmd\n"

exit 0
