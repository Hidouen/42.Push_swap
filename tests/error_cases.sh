#!/bin/bash

EXEC="./push_swap"

RED="\e[31m"
GREEN="\e[32m"
YELLOW="\e[33m"
BLUE="\e[34m"
MAGENTA="\e[35m"
CYAN="\e[36m"
WHITE="\e[0m"

PAD=40

function OK { echo -e "$GREEN[OK]$WHITE" ;}
function KO { echo -e "$RED[KO]$WHITE" ;}

# No args
function checkNoArgs
{
	printf $CYAN
	printf "#################################################################\n"
	printf "#                         CHECK NO ARGS                         #\n"
	printf "#################################################################\n"
	printf $WHITE

	printf "%-*s:" $PAD "$EXEC"
	$EXEC > /dev/null 2>&1
	if [[ $? -eq 0 ]] ; then OK ; else KO ; fi

	printf "%-*s:" $PAD "$EXEC \"\""
	$EXEC "" > /dev/null 2>&1
	if [[ $? -eq 0 ]] ; then OK ; else KO ; fi

	printf "%-*s:" $PAD "$EXEC \"           \""
	$EXEC "           " > /dev/null 2>&1
	if [[ $? -eq 0 ]] ; then OK ; else KO ; fi

	printf "%-*s:" $PAD "$EXEC \"   \" \"     \""
	$EXEC "   " "     " > /dev/null 2>&1
	if [[ $? -eq 0 ]] ; then OK ; else KO ; fi
}

# Not digital
function checkNotDigital
{
	printf $CYAN
	printf "################################################################\n"
	printf "#                    CHECK NOT DIGITAL ARGS                    #\n"
	printf "################################################################\n"
	printf $WHITE

	printf "%-*s: " $PAD "$EXEC abc"
	$EXEC abc 2>&1 | grep --quiet "Error" > /dev/null 2>&1
	if [[ $? -eq 0 ]] ; then OK ; else KO ; fi

	printf "%-*s: " $PAD "$EXEC 1 2 3%*"
	$EXEC 1 2 3%* 2>&1 | grep --quiet "Error" > /dev/null 2>&1
	if [[ $? -eq 0 ]] ; then OK ; else KO ; fi

	printf "%-*s: " $PAD "$EXEC 1 2 3 lol"
	$EXEC 1 2 3 lol 2>&1 | grep --quiet "Error" > /dev/null 2>&1
	if [[ $? -eq 0 ]] ; then OK ; else KO ; fi

	printf "%-*s: " $PAD "$EXEC \"-\" \"5 42\""
	$EXEC "-" "5 42" 2>&1 | grep --quiet "Error" > /dev/null 2>&1
	if [[ $? -eq 0 ]] ; then OK ; else KO ; fi

	printf "%-*s: " $PAD "$EXEC \"1 2\" \"3\" \"@#$%^\""
	$EXEC "1 2" "3" "@#$%^" 2>&1 | grep --quiet "Error" > /dev/null 2>&1
	if [[ $? -eq 0 ]] ; then OK ; else KO ; fi
}

# Values higher than INT_MAX or lower than INT_MIN
function checkOverLimitsInt
{
	printf $CYAN
	printf "################################################################\n"
	printf "#                       CHECK INT LIMITS                       #\n"
	printf "################################################################\n"
	printf $WHITE

	printf "%-*s: " $PAD "$EXEC 2147483648"
	$EXEC 2147483648 2>&1 | grep --quiet "Error" > /dev/null 2>&1
	if [[ $? -eq 0 ]] ; then OK ; else KO ; fi

	printf "%-*s: " $PAD "$EXEC \"   -2147483649\""
	$EXEC "   -2147483649" 2>&1 | grep --quiet "Error" > /dev/null 2>&1
	if [[ $? -eq 0 ]] ; then OK ; else KO ; fi

	printf "%-*s: " $PAD "$EXEC \"4294967295   \""
	$EXEC "4294967295   " 2>&1 | grep --quiet "Error" > /dev/null 2>&1
	if [[ $? -eq 0 ]] ; then OK ; else KO ; fi

	printf "%-*s: " $PAD "$EXEC \"  -9223372036854775808  \""
	$EXEC "  -9223372036854775808  " 2>&1 | grep --quiet "Error" > /dev/null 2>&1
	if [[ $? -eq 0 ]] ; then OK ; else KO ; fi

	printf "%-*s: " $PAD "$EXEC -18446744073709551615"
	$EXEC "-18446744073709551615" 2>&1 | grep --quiet "Error" > /dev/null 2>&1
	if [[ $? -eq 0 ]] ; then OK ; else KO ; fi
}

function checkNotUniq
{
	printf $CYAN
	printf "#################################################################\n"
	printf "#                      CHECK NOT UNIQ ARGS                      #\n"
	printf "#################################################################\n"
	printf $WHITE

	printf "%-*s: " $PAD "$EXEC 1 2 3 4 5 6 7 8 9 1"
	$EXEC 1 2 3 4 5 6 7 8 9 1 2>&1 | grep --quiet "Error" > /dev/null 2>&1
	if [[ $? -eq 0 ]] ; then OK ; else KO ; fi

	printf "%-*s: " $PAD "$EXEC \"-001 02\" \"3 4 5 6 7 8 9\" -1"
	$EXEC "-001 2" "3 4 5 6 7 8 9" -1 2>&1 | grep --quiet "Error" > /dev/null 2>&1
	if [[ $? -eq 0 ]] ; then OK ; else KO ; fi

	printf "%-*s: " $PAD "$EXEC \"-000\" \"+0\""
	$EXEC "-000" "+0" 2>&1 | grep --quiet "Error" > /dev/null 2>&1
	if [[ $? -eq 0 ]] ; then OK ; else KO ; fi
}

make push_swap

checkNoArgs
checkNotDigital
checkOverLimitsInt
checkNotUniq

exit 0
