#source ~monniaud/env.sh
CC=gcc
CFLAGS=-Wall -g -I include -I${KLEE}include
LDFLAGS=
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

AFL=0
USE_KLEE=1
AS=0
COV=0

ifdef args
USE_KLEE=0
AFL=0
AS=0
COV=0
LIBSTATUS=stat
CC+= -pg
endif

ifeq ($(AS),1)
ASFLAGS=-fsanitize=address
endif

ifeq ($(AFL),1)
CC=afl-gcc
endif

ifeq ($(USE_KLEE),1)
CC=wllvm
CFLAGS+=-DKLEE
LDFLAGS+=-L ${KLEE}lib/ -lkleeRuntest
ifeq ($(LIBSTATUS),dyn)
LIBSTATUS=stat
endif
endif

ifeq ($(LIBSTATUS),stat)
LDFLAGS=-L lib/lib_stat/ -lbindec
ifeq ($(USE_KLEE),1)
LDFLAGS+=-L ${KLEE}lib/ -lkleeRuntest
endif
all: $(STATLIB) $(EXEC) 
endif

ifeq ($(LIBSTATUS),dyn)
DYNFLAG=-fPIC -lgcov
LDFLAGS=-L $(LIBDIR) -Wl,-rpath,$(LIBDIR) -Bdynamic -lbindec
all: $(DYNLIB) $(EXEC)
endif

ifeq ($(COV),1)
CFLAGS+=-fprofile-arcs -ftest-coverage
LDFLAGS+=-lgcov --coverage
endif


$(OBJDIR)/%.o:$(LIB)/%.c
	$(CC) $(CFLAGS) $(DYNFLAG) -c $< -o $@

$(OBJDIR)/%.o:$(SRCOTHERSDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(DYNLIB): $(OBJSLIB)
	$(CC) -shared -o $@ $(OBJSLIB) -lgcov

$(EXEC): $(OBJSOTHERS) $(OBJSLIB)
	$(CC) $(OBJDIR)/*.o -o $@ $(LDFLAGS) $(ASFLAGS)

$(STATLIB): $(OBJSLIB)
	ar r $@ $^

aflrun: 
	cp $(LIB)/* $(SRCOTHERSDIR)/* $(INCLDIR)/* afl
 
gcov:
	gcov -b -c $(SRCLIB) -o $(OBJDIR)
	gcov -b -c $(SRCOTHERS) -o $(OBJDIR)
	mv *.gcov testcouv

profiling : $(STATLIB) $(EXEC)
	./bin/main $(args)
	gprof ./bin/main
clean: 
	-rm -r obj/*.o $(EXEC) $(DYNLIB) $(STATLIB) obj/*.gcov obj/*.gcno obj/*.gcda testcouv/* bin/klee* bin/*.bc

