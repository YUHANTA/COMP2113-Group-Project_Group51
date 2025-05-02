flags = -lsupc++ -pedantic-errors -std=c++11

menu.o: menu.cpp menu.h
	g++ $(flags) -c $<

Threeaimode.o: Threeaimode.cpp Threeaimode.h main.h menu.h
	g++ $(flags) -c $<

save_load_game.o: save_load_game.cpp save_load_game.h main.h
	g++ $(flags) -c $<

main.o: main.cpp main.h save_load_game.h Threeaimode.h menu.h
	g++ $(flags) -c $<

game: main.o save_load_game.o Threeaimode.o menu.o
	g++ $(flags) $^ -o $@

clean:
	rm -rf *.o game save.dat

tar:
	tar -czvf game.tgz *.cpp *.h

.PHONY: clean tar
