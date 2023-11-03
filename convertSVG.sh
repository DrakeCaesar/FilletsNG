#!/bin/bash

# Ensure the input file exists
if [ ! -f "fillets-curves.svg" ]; then
    echo "The file 'fillets-curves.svg' does not exist."
    exit 1
fi

# Use grep to extract lines that contain "M ", then use sed to perform the replacements
# and output the results to list.txt
cat fillets-curves.svg | grep -E "M " | \
sed -e 's/       d="M /BezierCurve(/g' \
    -e 's/ C /, /g' \
    -e 's/"/)/' \
    -e 's/,/, /g' \
    -e 's/  / /g' \
    -e 's/ /, /g' \
    -e 's/,,/,/g' \
    > list.txt

echo "The transformations have been completed and saved to list.txt."
