#!/bin/bash

# Usage: ./compare_pihole.sh list1.txt list2.txt output.txt

LIST1="$1"
LIST2="$2"
OUTPUT="$3"

echo "=== Removed domains ==="

# Print domains that will be removed (present in both)
grep -xFf "$LIST1" "$LIST2"

echo "======================="

# Create cleaned list (remove matches)
grep -vxFf "$LIST1" "$LIST2" > "$OUTPUT"

echo "Done. Cleaned list saved to $OUTPUT"