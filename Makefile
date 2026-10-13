CC = gcc
CFLAGS = -Wall -pthread -O2
OBJS = main.o account.o worker.o
 
bankvault: $(OBJS)
	$(CC) $(CFLAGS) -o bankvault $(OBJS)
 
%.o: %.c account.h worker.h
	$(CC) $(CFLAGS) -c $<
 
clean:
	rm -f *.o bankvault
 



#  in MSYS2 : cd "/c/Users/Shivashish Yadav/Desktop/MCA_PLACEMENT/BankVault"
# then :   make
# in terminal : 
# in terminal : ./bankvault          - this one is buggy version
# in terminal : ./bankvault safe