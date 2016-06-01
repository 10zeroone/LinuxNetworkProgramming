#TODO 7: Makefile 작성
#TODO 12: Makefile의 OBJS 매크로에 isbuitin.o 추가
#TODO 17: runcommand.o 추가
#TODO 24: redirect.o 추가
OBJS = main.o parsing.o isbuiltin.o runcommand.o redirect.o
SRCS = $(OBJS:.o=.c)

labshell: $(OBJS)
	$(CC) -o $@ $(OBJS)
.c.o: $(SRCS)
	$(CC) -c $<
	
clean:
	rm $(OBJS) labshell