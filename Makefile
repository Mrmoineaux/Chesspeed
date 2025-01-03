# Nom de l'exécutable
EXEC = Echecs

# Compilateur
CXX = g++

# Options de compilation
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -g -I./include

# Liste des fichiers source (main.cpp et Piece.cpp sont dans src/)
SRCS = src/main.cpp src/Piece.cpp

# Dossier pour les fichiers objets
BUILD_DIR = build

# Objets générés (dans le dossier build sans sous-dossier "src")
OBJS = $(patsubst src/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Règle par défaut (cible par défaut)
all: $(BUILD_DIR) $(EXEC)

# Création de l'exécutable uniquement si les fichiers objets ont changé
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilation des fichiers .cpp en .o (dans le dossier build)
$(BUILD_DIR)/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Création du dossier build
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Nettoyage des fichiers générés
clean:
	rm -f $(BUILD_DIR)/*.o $(EXEC)

# Nettoyage approfondi (si des fichiers temporaires sont générés)
fclean: clean
	rm -rf $(BUILD_DIR) *~ *.bak

# Recompilation complète (clean + all)
re: fclean all
