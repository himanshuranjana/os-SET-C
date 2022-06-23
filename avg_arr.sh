echo "enter no of elements"

read n

sum=0
arr=()
for(( i=0;i<$n;i++ ))
do
	echo "Enter val"
	read arr[$i]
	sum=$((sum+arr[i]))
done

sum=$((sum/n))

echo "average = $sum"