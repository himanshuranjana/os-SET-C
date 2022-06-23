echo "Enter a number"
read no  
i=1
ans=0
for i in 1 2 3 4 5 .. no  
do
        if [[ $((no%i)) -eq 0  ]]  
        then
            ans=$((ans + i))
            
fi
i=`expr $i + 1`
done

if [ $no -eq $ans ]  
then
        echo "$no is perfect"
        else
        echo "$no is NOT perfect"
fi