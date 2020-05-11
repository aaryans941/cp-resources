if [ "$#" -eq 0 ] ; then
   echo "Usage : $0 <contest_id> [ list_of_problems_to_add , by default {A..F} ]"
 
   exit 2
fi

if [ "$#" -eq 1 ]; then
    
    mkdir $1
    if [ $? -ne 0 ]; then 
        exit 1; 
    fi;

    for c in {A..F}; do
         cp -v --no-clobber ~/cp-resources/template.cpp $1/$c.cpp
    done;
else
    if [[ -d $1 ]]; then
        # do nothing
        touch tmpmp
        rm tmpmp
    else
        mkdir $1
    fi;
    for c in "${@:2}"; do
         cp -v --no-clobber ~/cp-resources/template.cpp $1/$c.cpp
    done;
fi
touch $1/input.txt $1/output.txt

