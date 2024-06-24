make re;
make;

n=1
while [ $n -le 500 ]
do
	echo $n ":";
	ARG=`ruby -e "puts (1..$n).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l | sed 's/^[ \t]*//;s/[ \t]*$//'
	n=$(( n+1 ))
	echo "-----------------------------";
done


make fclean ;
