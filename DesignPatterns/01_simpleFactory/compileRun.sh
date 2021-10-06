g++ $* -std=c++11
if [ $? != 0 ]
then
    exit
fi

./a.out

