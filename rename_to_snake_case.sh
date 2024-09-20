#!/bin/bash

upper_camel_to_snake() {
    local input="$1"

    echo "$input" | sed -r 's/([a-z])([A-Z])/\1_\2/g' | tr '[:upper:]' '[:lower:]'
}

if [ $# -ne 1 ]; then
    echo "Usage: $0 /path/to/directory"
    exit 1
fi

TARGET_DIR="$1"

if [ ! -d "$TARGET_DIR"]; then  
    echo "Error: '$TARGET_DIR' is not a directory"
    exit 1
fi

cd "$TARGET_DIR" || { echo "Failed to access directory"; exit 1; }

for file in *; do
    if [ -d "$file" ]; then
        continue
    fi

    filename="${file%.*}"
    extension="${file##*.}"

    if [[ "$filename" =~ ^([A-Z][a-z]+)+$ ]]; then      
        snake_filename=$(upper_camel_to_snake "$filename")

        if [[ "$filename" != "$extension" ]]; then
            new_name="${snake_filename}.${extension}"
        else
            new_name="${snake_filename}"
        fi

        if [ -e "$new_name" ]; then
            echo "Skipping '$file' -> '$new_name': target file already exists"
        else    
            mv "$file" "$new_name"
            echo "Renamed: '$file' -> '$new_name'"
        fi
    fi
done

echo "Renaming process completed"