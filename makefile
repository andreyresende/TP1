run: dominios.cpp entidades.cpp main.cpp
	g++ -g -c dominios.cpp && g++ -g -c entidades.cpp && g++ -o main main.cpp dominios.o entidades.o && ./main
clean:
	rm dominios.o && rm entidades.o && rm main