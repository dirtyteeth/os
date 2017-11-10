echo "enter no to check even or odd"
read a
a=`expr $a % 2`
if [ $a -eq 0 ]
then
echo "given no is even\n"
else
echo "given no is odd"
fi
