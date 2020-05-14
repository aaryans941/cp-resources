if [ "$#" -ne 1 ]; then
    echo "Usage $0 <contest_id>"
    exit 2
fi;

rm -rf $1/
