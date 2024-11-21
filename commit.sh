#!/bin/sh
git add .
read -p "enter the extra message : " msg
sh "readme script.sh"
git commit -m " `date +\"%d %b\"` $msg "
git push origin main
echo "Done with the script"
read -p "exiting " u
