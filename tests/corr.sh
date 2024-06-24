make re;
#norminette includes/*.h srcs/*/*.c

echo "example of one display"
ARG=`ruby -e "puts (1..1).to_a.shuffle.join(' ')"`; echo $ARG ; sleep 1.5 ; ./push_swap $ARG
echo
echo "example on 3:"
ARG=`ruby -e "puts (1..3).to_a.shuffle.join(' ')"`; echo $ARG ; sleep 1.5 ; ./push_swap $ARG
echo
echo "example on 5:"
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; echo $ARG ; sleep 1.5 ; ./push_swap $ARG
echo
echo "example on 6:"
ARG=`ruby -e "puts (1..6).to_a.shuffle.join(' ')"`; echo $ARG ; sleep 1.5 ; ./push_swap $ARG
echo
echo "example on 50:"
ARG=`ruby -e "puts (1..50).to_a.shuffle.join(' ')"`; echo $ARG ; sleep 1.5 ; ./push_swap $ARG
echo
echo "example on 10 sorted:"
ARG="0 1 2 3 4 5 6 7 8 9" ; echo $ARG ; sleep 1.5 ; ./push_swap $ARG
echo

echo "number of operations for 3:"

n=1
while [ $n -le 20 ]
do
    ARG=`ruby -e "puts (1..3).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l | sed 's/^[ \t]*//;s/[ \t]*$//'
n=$(( n+1 ))
done
echo

echo "number of operations for 5:"

n=1
while [ $n -le 20 ]
do
    ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l | sed 's/^[ \t]*//;s/[ \t]*$//'
n=$(( n+1 ))
done
echo

echo "number of operations for 100:"

n=1
while [ $n -le 20 ]
do
    ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l | sed 's/^[ \t]*//;s/[ \t]*$//'
n=$(( n+1 ))
done
echo

echo "number of operations for 500:"
m=1
while [ $m -le 20 ]
do
    ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l | sed 's/^[ \t]*//;s/[ \t]*$//'
m=$(( m+1 ))
done
echo