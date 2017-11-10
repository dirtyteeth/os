echo "enter no to find fibnocii"
read n
ans=1
if [ $n -eq 0 ] 
then
echo "fibnocci series of $n is: $ans"
elif [ $n -eq 1 ]
then
echo "fibnocci series of $n is: $ans $ans"
else
echo "fibnocci series of $n is: \n$ans \n$ans  "
a0=1
a1=1
i=2
while [ $i -le $n ]
do
ans=`expr $a0 + $a1`
a0=$a1
a1=$ans
echo  "$ans "
i=`expr $i + 1`
done
fi


