TARGET = test

CXX = g++

INCLUDE_PATHS = -IC:\Users\danie\Documents\projects\AbyssEngine\AbyssEngine\header \
	-IC:\Things\libs\include

LIBRARY_PATHS = -LC:\Things\libs\lib\Abyss \
	-LC:\Things\libs\lib\SFML
	
CXXFLAGS = -Wall

COMMON := -g

CXXFLAGS += $(COMMON) 

LINKER = g++

# -l e usado para
# sfml-graphics.lib;sfml-window.lib;sfml-system.lib;freetype.lib;opengl32.lib;
#kernel32.lib;user32.lib;gdi32.lib;winspool.lib;comdlg32.lib;advapi32.lib;shell32.lib;
#ole32.lib;oleaut32.lib;uuid.lib;odbc32.lib;odbccp32.lib;

LFLAGS = $(COMMON) \
	-lmingw32 \
	-labyssmath \
	-lsfml-graphics \
	-lsfml-window \
	-lsfml-system \
	-lfreetype

SRCDIR = src
OBJDIR = obj
BINDIR = bin

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
DIRS := $(OBJDIR) $(BINDIR)
rm = rm -f

$(BINDIR)/$(TARGET): $(OBJECTS)
	$(LINKER) $(OBJECTS) -o $@ $(LIBRARY_PATHS) $(LFLAGS)
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE_PATHS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

$(DIRS):
	mkdir $@

.PHONY: clean
clean:
	$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"