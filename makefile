double_base_palin: double_base_palin.o
	gcc -o double_base_palin -g double_base_palin.o
double_base_palin.o: double_base_palin.c
	gcc -g -c -Wall double_base_palin.c
clean:
	rm -f *.o double_base_palin  
