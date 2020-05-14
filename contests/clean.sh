if [ "$#" -eq 0 ] ; then
   echo "Usage : $0 <contest_id> [ list_of_problems_to_remove ]"
 
   exit 2
fi


if [[ -d $1 && $# -gt 1 ]]; then
    for c in "${@:2}"; do
        rm -v $1/$c.cpp
#        if [ $? -ne 0 ]; then
#                break;
#        fi;
    done;
    rem=$(ls $1/*.cpp | wc -l)
    if [ $rem -eq 0 ]; then
        rm -r -v $1
    fi;
fi;

