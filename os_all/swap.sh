echo "enter two no"
read a b
echo "initially a=$a b=$b"
a=`expr $a + $b`
b=`expr $a - $b`
a=`expr $a - $b`
echo "finally a=$a b=$b"
