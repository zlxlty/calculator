#Author: Tianyi Lu

objs = main.o func.o getch.o getop.o stack.o

cal : $(objs)
	gcc -o cal $(objs) -lm

$(objs) : calc.h

.PHONY : clean_objs clean_all

clean_objs :
	rm $(objs)

clean_all :
	rm cal $(objs)
