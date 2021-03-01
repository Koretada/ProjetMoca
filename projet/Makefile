CC=gcc
CFLAGS=-Wall -fprofile-arcs -ftest-coverage -g -I include
EXEC=bin/main
OBJDIR=obj
INCLDIR=include
DYNLIB=lib/lib_dyn/libbindec.so
STATLIB=lib/lib_stat/libbindec.a

SRCOTHERSDIR=src/src_others
LIB=src/src_lib
LIBDIR=lib/lib_dyn
LIBSTATUS=dyn

SRCLIB=$(wildcard $(LIB)/*.c)
OBJSLIB=$(SRCLIB:$(LIB)/%.c=$(OBJDIR)/%.o)

SRCOTHERS=$(wildcard $(SRCOTHERSDIR)/*.c)
OBJSOTHERS=$(SRCOTHERS:$(SRCOTHERSDIR)/%.c=$(OBJDIR)/%.o)

AFL=1

ifeq (($AFL),1)
CC=afl-gcc
endif

ifeq ($(LIBSTATUS),stat)
LDFLAGS=-L lib/lib_stat/ -lbindec -lgcov --coverage
all: $(STATLIB) $(EXEC) 
endif

ifeq ($(LIBSTATUS),dyn)
DYNFLAG=-fPIC -lgcov
LDFLAGS=-L $(LIBDIR) -Wl,-rpath,$(LIBDIR)/,-Bdynamic -lbindec -lgcov --coverage
all: $(DYNLIB) $(EXEC)
endif

#DYNAMIQUE
$(OBJDIR)/%.o:$(LIB)/%.c
	$(CC) $(CFLAGS) $(DYNFLAG) -c $< -o $@

$(OBJDIR)/%.o:$(SRCOTHERSDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(DYNLIB): $(OBJSLIB)
	$(CC) -shared -o $@ $(OBJSLIB) -lgcov

$(EXEC): $(OBJSOTHERS) $(OBJSLIB)
	$(CC) $(OBJDIR)/*.o -o $@ $(LDFLAGS)

$(STATLIB): $(OBJSLIB)
	ar r $@ $^

gcov:
	gcov -b -c $(SRCLIB) -o $(OBJDIR)
	gcov -b -c $(SRCOTHERS) -o $(OBJDIR)
	mv *.gcov testcouv

clean: 
	-rm obj/*.o $(EXEC) $(DYNLIB) $(STATLIB) obj/*.gcov obj/*.gcno obj/*.gcda testcouv/*

