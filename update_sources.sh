#!/bin/bash

SRC_DIR="./src"
SRC_MK="Makefile"
# Change à true si tu es sous macOS
macOS=false 

# Vérifier si le répertoire source existe
if [[ ! -d "$SRC_DIR" ]]; then
    echo "Erreur : le répertoire source '$SRC_DIR' n'existe pas."
    exit 1
fi

# Trouver les fichiers sources
if [[ $macOS == true ]]; then
    SRC_FILES=$(find "$SRC_DIR" -type f \( -name "*.c" -o -name "*.m" \))
else
    SRC_FILES=$(find "$SRC_DIR" -type f -name "*.c")
fi

# Vérifier s'il y a des fichiers sources
if [[ -z "$SRC_FILES" ]]; then
    echo "Aucun fichier source trouvé dans '$SRC_DIR'."
    exit 1
fi

# Construire la ligne SRC_FILES
SRC_LINE="SRCS := \\"
SRC_LINE+="$(echo "$SRC_FILES" | sed 's|^\./||' | sed 's| |\\ |g' | tr '\n' ' \\\\\n\t')"

# Debugging (optionnel)
DEBUG=false
if [[ $DEBUG == true ]]; then
    printf "SRCS:\n%s\nSRC_LINE:\n%s\n" "$SRC_FILES" "$SRC_LINE"
fi

# Vérifier si le fichier src.mk existe
if [[ -f "$SRC_MK" ]]; then
    if [[ $macOS == true ]]; then
        sed -i ".bak" "/^SRCS :=/c\\$SRC_LINE" "$SRC_MK" && rm -f "$SRC_MK.bak"
    else
        sed -i "/^SRCS :=/c\\$SRC_LINE" "$SRC_MK"
    fi
    echo "Le fichier '$SRC_MK' a été mis à jour."
else
    echo "Erreur : le fichier '$SRC_MK' n'existe pas."
    exit 1
fi
