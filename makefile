# -*- Mode: makefile  -*-
#
# RESUMEN:      
# USO:        make <make-target>
#
# AUTHOR:       Jose Antonio Garcia 
# ORG:          UDC          
# E-MAIL:       jagrodriguez@udc.es
#
# ORIG-DATE:    15 de Marzo de 2013   
#
# Makefile 
#
# make -f makefile.x
#
# suffix .cpp sufijos de las fuentes de c++
.SUFFIXES: .cpp

# Indicar compilador de C++
CXX=g++ 
# Indicar precompilador gcc
CC=gcc
# Opciones de compilacion
CXXFLAGS=  -g -O2  
CXXLIBS = -L./
CXXINC= -I./ -I ./include -I./Eigen
# Inidicar el directorio de fuentes
VPATH = sources 
# Indicar el directorio para escribir los objetos
ODIR=./build

# Fuentes que vamos a compilar
# OBJS = point.o main.o

SOURCES= main.cpp point.cpp pelfin.cpp
# Lista de objetos a crear: se compila un objeto .o para cada fuente .cpp
OBJECTS= $(SOURCES:%.cpp=$(ODIR)/%.o)

all: finite_element.exe install

# Enlazamos los objetos (usamos g++ como linker)
finite_element.exe: $(OBJECTS)
	$(CXX) -o  $@ $(OBJECTS) $(CXXLIBS)

# Creacion de objetos	
$(ODIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CXXINC) -c $< -o $@
	
.PHONY:	clean
clean: 
	rm -f  $(OBJECTS)/*.o *~ finite_element.exe ./bin/finite_element.exe

install:
	mv -f  finite_element.exe ./bin/finite_element.exe