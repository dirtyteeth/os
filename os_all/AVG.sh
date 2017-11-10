echo "enter no of data to find Average"
read n
i=0
sum=0
prod=1
while [ $i -lt $n ] 
do
read x
sum=`expr $sum + $x`
prod=`expr $prod \* $x`
i=`expr $i + 1`
done
avg=`expr $sum / $n`
echo "average =$avg\nproduct=$prod"
