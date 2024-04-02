for file in *.c; do
    gcc "$file" -o "${file%.*}"
done