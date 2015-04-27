all: Gungnir

Gungnir: Gungnir.c
	gcc -g -o Gungnir Gungnir.c -lpthread
clean:
	rm -f Gungnir /Gungnir