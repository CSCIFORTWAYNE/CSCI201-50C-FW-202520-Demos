all: main 
main: main.cpp drink clock drinkExcept
	g++ -pedantic-errors -g -fdiagnostics-color=always main.cpp drink drinkExcept clock -o main
clock: clock.h clock.cpp
	g++ -pedantic-errors -g -fdiagnostics-color=always -c clock.cpp -o clock
drink: drink.h drink.cpp
	g++ -pedantic-errors -g -fdiagnostics-color=always -c drink.cpp -o drink
drinkExcept: drinkExcept.h drinkExcept.cpp
	g++ -pedantic-errors -g -fdiagnostics-color=always -c drinkExcept.cpp -o drinkExcept