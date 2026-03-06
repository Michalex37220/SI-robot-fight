#!/bin/bash


# Script de compilation du projet pour linux

# Configuration (facile à modifier)
BOARD="esp32:esp32:esp32c6"
SKETCH_DIR="."

echo "🔧 Démarrage de la compilation..."
echo "📌 Carte sélectionnée : $BOARD"

# Vérifier si arduino-cli est installé
if ! command -v arduino-cli &> /dev/null
then
    echo "❌ Erreur : arduino-cli n'est pas installé."
    echo "➡️  Installe-le ici : https://arduino.github.io/arduino-cli/"
    exit 1
fi

# Lancer la compilation
arduino-cli compile --fqbn "$BOARD" "$SKETCH_DIR"

# Vérifier le résultat
if [ $? -eq 0 ]; then
    echo "✅ Compilation terminée avec succès !"
else
    echo "❌ La compilation a échoué."
    exit 1
fi

