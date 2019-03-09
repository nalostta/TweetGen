CC	=	gcc
NDEBUG	=	-DNDEBUG #Comment/remove the definition of this variable to see the debug codes
CFLAGS	=	-g	-Wall -Werror -I. $(NDEBUG)
PATHS	=	-I	$(INC)/	-I	$(SRC)/	-I	$(LIB)/
DEPS	=	dbg.h	milestone-12.h	milestone-10.h	milestone-6.h	milestone-5.h
OBJS	=	FinalProject.o	milestone-2.o	milestone-3.o	milestone-4.o	milestone-4_main.o	milestone-5.o	milestone-6.o	milestone-6_main.o	milestone-7.o	milestone-7_main.o	milestone-8.o	milestone-8_main.o	milestone-9.o	milestone-10.o	milestone-10_main.o	milestone-12.o	milestone-13.o	RecRevtest.o
EXEC	=	ArrayProgram.exe	DictionaryProgram.exe	FinalProject.exe	GensortTest.exe	RecRevTest.exe	StringProgram.exe	TokenizeTest.exe
LIBRARIES	=	mathf	stringf	gensortf	linkedf	dictf

FINLIB	=	stringf	linkedf	dictf

OBJ	=	objects
SRC	=	source
INC	=	include
LIB	=	libraries
BIN =	bin

#RESULTS	=	grep -s PASS results.txt

.PHONY:	clean
.PHONY:	static
.PHONY:	dynamic
.PHONY:	final
.PHONY:	test
.PHONY:	all

$(OBJ)/%.o:	$(SRC)/%.c	$(INC)/%.h
	$(CC)	$(CFLAGS)	$(PATHS)	-c	-o	$@	$<

#-------------------------------------------------------------------------------------
all	:	static	dynamic	final	test	$(BIN)/StringProgram.exe	$(BIN)/ArrayProgram.exe	$(BIN)/DictionaryProgram.exe

#-------------------------------------------------------------------------------------	
test	:	$(BIN)/TokenizeTest.exe	$(BIN)/RecRevTest.exe	$(BIN)/GensortTest.exe

$(BIN)/TokenizeTest.exe	:	$(OBJ)/milestone-6_main.o	$(INC)/milestone-6.h $(INC)/milestone-5.h	$(LIB)/stringf.a
	$(CC)	$(CFLAGS)	$(PATHS)	-o	$@	$(OBJ)/milestone-6_main.o	-static $(LIB)/stringf.a

$(OBJ)/milestone-6_main.o	:	$(SRC)/milestone-6_main.c	$(INC)/milestone-6.h
	$(CC)	$(CFLAGS)	$(PATHS)	-c	-o	$@	$<
	
$(BIN)/RecRevTest.exe	:	$(OBJ)/RecRevtest.o	$(LIB)/linkedf.a	
	$(CC)	$(CFLAGS)	$(PATHS)	-o	$@	$<	-static	$(LIB)/linkedf.a
	
$(OBJ)/RecRevtest.o	:	$(SRC)/RecRevtest.c	$(INC)/milestone-9.h	$(INC)/milestone-13.h
	$(CC)	$(CFLAGS)	$(PATHS)	-o	$@	-c	$<
	
$(BIN)/GensortTest.exe	:	$(OBJ)/milestone-8_main.o	$(OBJ)/milestone-8.o	$(INC)/milestone-8.h
	$(CC)	$(CFLAGS)	$(PATHS)	-o	$@	$(OBJ)/milestone-8_main.o	$(OBJ)/milestone-8.o
	
$(OBJ)/milestone-8_main.o	:	$(SRC)/milestone-8_main.c	$(INC)/milestone-8.h
	$(CC)	$(CFLAGS)	$(PATHS)	-c	-o	$@	$<

#-------------------------------------------------------------------------------------
final	:	$(BIN)/FinalProject.exe	$(patsubst	%f,$(LIB)/%f.a,$(FINLIB))

$(BIN)/FinalProject.exe	:	$(OBJ)/FinalProject.o	$(patsubst	%f,$(LIB)/%f.a,$(FINLIB))
	$(CC)	$(CFLAGS)	$(PATHS) -o	$@	-static	$< $(patsubst	%f,./$(LIB)/%f.a,$(FINLIB))

$(OBJ)/FinalProject.o	:	$(SRC)/FinalProject.c	$(INC)/dbg.h
	$(CC)	$(CFLAGS)	$(PATHS)	-c	-o	$@	$<


	

#-------------------------------------------------------------------------------------
static	:	$(patsubst	%f,$(LIB)/%f.a,$(LIBRARIES))

$(LIB)/mathf.a	:	$(OBJ)/milestone-2.o $(INC)/milestone-2.h
	ar rcs	$@	$<
	
$(LIB)/stringf.a	:	$(OBJ)/milestone-6.o	$(OBJ)/milestone-5.o	$(INC)/milestone-6.h	$(INC)/milestone-5.h
	ar rcs	$@	$(patsubst %.o,%.o,$^)
	
$(LIB)/gensortf.a	:	$(OBJ)/milestone-8.o	$(INC)/milestone-8.h
	ar rcs $@	$<
	
$(LIB)/linkedf.a	:	$(OBJ)/milestone-13.o	$(OBJ)/milestone-9.o	$(INC)/milestone-13.h	$(INC)/milestone-9.h
	ar rcs $@	$(OBJ)/milestone-13.o	$(OBJ)/milestone-9.o
	
$(LIB)/dictf.a	:	$(OBJ)/milestone-12.o	$(OBJ)/milestone-10.o	$(OBJ)/milestone-5.o	$(INC)/milestone-12.h	$(INC)/milestone-10.h	$(INC)/milestone-5.h
	ar	rcs	$@  $(patsubst %.o,%.o,$^)
	
	
	
#-------------------------------------------------------------------------------------
dynamic	:	$(patsubst	%f,$(LIB)/%f.dll,$(LIBRARIES))

$(LIB)/mathf.dll	:	$(OBJ)/milestone-2.o $(INC)/milestone-2.h
	$(CC) $(PATHS) -shared -fPIC -o $@	$<
	
$(LIB)/stringf.dll	:	$(OBJ)/milestone-6.o	$(OBJ)/milestone-5.o	$(INC)/milestone-6.h	$(INC)/milestone-5.h
	$(CC) $(PATHS) -shared -fPIC -o $@	$(patsubst %.o,%.o,$^)
	
$(LIB)/gensortf.dll	:	$(OBJ)/milestone-8.o	$(INC)/milestone-8.h
	$(CC) $(PATHS) -shared -fPIC -o $@	$<
	$(CC) $(PATHS) -shared -fPIC -o $@	$<
	
$(LIB)/linkedf.dll	:	$(OBJ)/milestone-13.o	$(OBJ)/milestone-9.o	$(INC)/milestone-13.h	$(INC)/milestone-9.h
	$(CC) $(PATHS) -shared -fPIC -o $@	$(OBJ)/milestone-13.o	$(OBJ)/milestone-9.o
	
$(LIB)/dictf.dll	:	$(OBJ)/milestone-12.o	$(OBJ)/milestone-10.o	$(OBJ)/milestone-5.o	$(INC)/milestone-12.h	$(INC)/milestone-10.h	$(INC)/milestone-5.h
	$(CC) $(PATHS) -shared -fPIC -o $@	$(patsubst %.o,%.o,$^)

	
	
#-------------------------------------------------------------------------------------
$(BIN)/ArrayProgram.exe	:	$(OBJ)/milestone-4_main.o	$(OBJ)/milestone-4.o	$(OBJ)/milestone-3.o	$(INC)/milestone-12.h	$(INC)/milestone-4.h	$(INC)/milestone-3.h	$(LIB)/dictf.a
	$(CC)	$(CFLAGS)	$(PATHS)	-o	$@	$(patsubst %.o,%.o,$^) -static $(LIB)/dictf.a
	
$(OBJ)/milestone-4_main.o	:	$(SRC)/milestone-4_main.c
	$(CC)	$(PATHS)	$(CFLAGS)	-c	-o	$@	$<

	
	
#-------------------------------------------------------------------------------------
$(BIN)/StringProgram.exe	:	$(OBJ)/milestone-7_main.o	$(OBJ)/milestone-7.o	$(OBJ)/milestone-5.o	$(INC)/milestone-7.h	$(INC)/milestone-5.h
	$(CC)	$(CFLAGS)	$(PATHS)	-o	$@	$(patsubst %.o,%.o,$^)
	
$(OBJ)/milestone-7_main.o	:	$(SRC)/milestone-7_main.c
	$(CC)	$(PATHS)	$(CFLAGS)	-c	-o	$@	$<
	
	
#-------------------------------------------------------------------------------------
$(BIN)/DictionaryProgram.exe	:	$(OBJ)/milestone-10_main.o	$(OBJ)/milestone-12.o	$(OBJ)/milestone-10.o	$(OBJ)/milestone-5.o	$(INC)/milestone-12.h	$(INC)/milestone-10.h	$(INC)/milestone-5.h
	$(CC)	$(PATHS)	$(CFLAGS)	-o	$@	$(patsubst %.o,%.o,$^)
	
$(OBJ)/milestone-10_main.o	:	$(SRC)/milestone-10_main.c	$(INC)/milestone-12.h
	$(CC)	$(PATHS)	$(CFLAGS)	-c	-o	$@	$<
	
	
	
clean:
	rm -f $(patsubst %.o,$(OBJ)/%.o,$(OBJS))	
	rm	-f	$(patsubst %f,$(LIB)/%f.a,$(LIBRARIES))	
	rm	-f	$(patsubst %f,$(LIB)/%f.dll,$(LIBRARIES))
	rm	-f	$(patsubst %.exe,$(BIN)/%.exe,$(EXEC))	