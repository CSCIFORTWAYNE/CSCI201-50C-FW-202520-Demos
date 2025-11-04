all: main product
main: main.cpp product
	g++ -pedantic-errors -g -fdiagnostics-color=always main.cpp product -o main
product: product.h product.cpp
	g++ -pedantic-errors -g -fdiagnostics-color=always -c product.cpp -o product