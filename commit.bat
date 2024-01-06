git add .
echo " Enter the message : "
set -p msg

setlocal
for /f %%I in ('wmic os get localdatetime /format:list ^| find "="') do set "%%I"
set "YYYY=%localdatetime:~0,4%"
set /a "MM=1%localdatetime:~4,2% - 100"
set "DD=%localdatetime:~6,2%"
for /f "tokens=%MM%" %%I in ("JAN FEB MAR APR MAY JUN JUL AUG SEP OCT NOV DEC") do set "month=%%I"

echo %DD%-%month%-%YYYY%

git commit -m " updating daily code %DD%-%month% %msg% "
git push origin main
echo "Done with the script \n exiting"
set -p u
