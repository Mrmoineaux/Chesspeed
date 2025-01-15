# Nom de l'exécutable
EXEC = Echecs

# Compilateur
CXX = g++

# Options de compilation
CXXFLAGS = -Wall -Wextra -std=c++17 -g -F./include #-F/Library/Framework

# Framework SDL2
FRAMEWORKS = -framework SDL2

# Liste des fichiers source
SRCS = src/main.cpp src/Init_app.cpp

# Dossier pour les fichiers objets
BUILD_DIR = build

# Objets générés
OBJS = $(patsubst src/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Règle par défaut
all: $(BUILD_DIR) $(EXEC)

# Création de l'exécutable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(FRAMEWORKS) -Wl,-rpath,./include


# Compilation des fichiers .cpp
$(BUILD_DIR)/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Création du dossier build
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Nettoyage
clean:
	rm -f $(BUILD_DIR)/*.o $(EXEC)

fclean: clean
	rm -rf $(BUILD_DIR) *~ *.bak

re: fclean all
