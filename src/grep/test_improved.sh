#!/bin/bash

COUNTER_SUCCESS=0
COUNTER_FAIL=0
DIFF_RES=""
S21_GREP=s21_grep.txt
GREP_OLD=grep.txt
FILE1=s21_grep.c
FILE2=s21_grep.h
FILE3=Makefile
PATTERN=pattern
LOG=log.txt
rm $LOG

for var in v c l n h i
do
    for var2 in v c l n h i
    do
        for var3 in v c l n h i
        do
            if [ $var != $var2 ] && [ $var2 != $var3 ] && [ $var != $var3 ]
            then
                TEST1="for $FILE1 $FILE2 $FILE3 -$var -$var2 -$var3"
                ./s21_grep $TEST1 > $S21_GREP
                grep $TEST1 > $GREP_OLD
                DIFF_RES="$(diff -s $S21_GREP $GREP_OLD)"
                if [ "$DIFF_RES" == "Files $S21_GREP and $GREP_OLD are identical" ]
                    then
                    (( COUNTER_SUCCESS++ ))
                    else
                    echo "$TEST1" >> $LOG
                    (( COUNTER_FAIL++ ))
                fi
              rm $S21_GREP $GREP_OLD

              TEST2="for $FILE1 -$var -$var2 -$var3"
              ./s21_grep $TEST2 > $S21_GREP
              grep $TEST2 > $GREP_OLD
              DIFF_RES="$(diff -s $S21_GREP $GREP_OLD)"
              if [ "$DIFF_RES" == "Files $S21_GREP and $GREP_OLD are identical" ]
                then
                  (( COUNTER_SUCCESS++ ))
                else
                  echo "$TEST2" >> $LOG
                  (( COUNTER_FAIL++ ))
              fi
              rm $S21_GREP $GREP_OLD

              TEST3="-e for -e ^int $FILE1 $FILE2 $FILE3 -$var -$var2 -$var3"
              ./s21_grep $TEST3 > $S21_GREP
              grep $TEST3 > $GREP_OLD
              DIFF_RES="$(diff -s $S21_GREP $GREP_OLD)"
              if [ "$DIFF_RES" == "Files $S21_GREP and $GREP_OLD are identical" ]
                then
                  (( COUNTER_SUCCESS++ ))
                else
                  echo "$TEST3" >> $LOG
                  (( COUNTER_FAIL++ ))
              fi
              rm $S21_GREP $GREP_OLD

              TEST4="-e for -e ^int $FILE1 -$var -$var2 -$var3"
              ./s21_grep $TEST4 > $S21_GREP
              grep $TEST4 > $GREP_OLD
              DIFF_RES="$(diff -s $S21_GREP $GREP_OLD)"
              if [ "$DIFF_RES" == "Files $S21_GREP and $GREP_OLD are identical" ]
                then
                  (( COUNTER_SUCCESS++ ))
                else
                  echo "$TEST4" >> $LOG
                  (( COUNTER_FAIL++ ))
              fi
              rm $S21_GREP $GREP_OLD

              TEST5="-e regex -e ^print $FILE1 -$var -$var2 -$var3 -f $PATTERN"

              ./s21_grep $TEST5 > $S21_GREP
              grep $TEST5 > $GREP_OLD
              DIFF_RES="$(diff -s $S21_GREP $GREP_OLD)"
              if [ "$DIFF_RES" == "Files $S21_GREP and $GREP_OLD are identical" ]
                then
                  (( COUNTER_SUCCESS++ ))
                else
                  echo "$TEST5" >> $LOG
                  (( COUNTER_FAIL++ ))
              fi
              rm $S21_GREP $GREP_OLD

              TEST6="-e while -e void $FILE1 $FILE3 -$var -$var2 -$var3 -f $PATTERN"
              ./s21_grep $TEST6 > $S21_GREP
              grep $TEST6 > $GREP_OLD
              DIFF_RES="$(diff -s $S21_GREP $GREP_OLD)"
              if [ "$DIFF_RES" == "Files $S21_GREP and $GREP_OLD are identical" ]
                then
                  (( COUNTER_SUCCESS++ ))
                else
                  echo "$TEST6" >> $LOG
                  (( COUNTER_FAIL++ ))
              fi
              rm $S21_GREP $GREP_OLD

              TEST7="-e while -e void $FILE1 $FILE3 -$var$var2$var3 -f $PATTERN"
              ./s21_grep $TEST7 > $S21_GREP
              grep $TEST7 > $GREP_OLD
              DIFF_RES="$(diff -s $S21_GREP $GREP_OLD)"
              if [ "$DIFF_RES" == "Files $S21_GREP and $GREP_OLD are identical" ]
                then
                  (( COUNTER_SUCCESS++ ))
                else
                  echo "$TEST7 / $DIFF_RES" >> $LOG
                  (( COUNTER_FAIL++ ))
              fi
              rm $S21_GREP $GREP_OLD

              TEST8="-e for $FILE1 -e ^int $FILE2 -$var $FILE3 -$var2 -$var3"
              ./s21_grep $TEST8 > $S21_GREP
              grep $TEST8 > $GREP_OLD
              DIFF_RES="$(diff -s $S21_GREP $GREP_OLD)"
              if [ "$DIFF_RES" == "Files $S21_GREP and $GREP_OLD are identical" ]
                then
                  (( COUNTER_SUCCESS++ ))
                else
                  echo "$TEST8" >> $LOG
                  (( COUNTER_FAIL++ ))
              fi
              rm $S21_GREP $GREP_OLD
            fi
        done
    done
done

echo "SUCCESS: $COUNTER_SUCCESS"
echo "FAIL: $COUNTER_FAIL"
