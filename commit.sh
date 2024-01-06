#!/bin/sh
git add .
read -p "enter the extra message : " msg
./.git/hooks/pre-commit
git commit -m " updating daily code `date +\"%d %b\"` $msg "
git push origin main
echo "Done with the script"
read -p "exiting " u
