all: main product clock
main: main.cpp product clock
	g++ -pedantic-errors -g -fdiagnostics-color=always main.cpp product clock -o main
product: product.h product.cpp
	g++ -pedantic-errors -g -fdiagnostics-color=always -c product.cpp -o product
clock: clock.h clock.cpp
	g++ -pedantic-errors -g -fdiagnostics-color=always -c clock.cpp -o clock