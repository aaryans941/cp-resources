if [ "$#" -ne 1 ]; then
    echo "Usage $0 <contest_id>"
    exit 2
fi;

for c in {A..F}; do
    ./clean.sh $1 $c
done;

