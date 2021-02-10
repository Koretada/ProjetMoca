CC=gcc
CFLAGS=-Wall -g -I include
SRCDIR=src/src_others
EXEC=bin/main
OBJDIR=obj
INCLDIR=include
DYNLIB=lib/lib_dyn/libbindec.so
STATLIB=lib/lib_stat/libbindec.a
LIBSTATUS=dyn
SRCLIB=src/src_lib
LIBDIR=lib/lib_dyn

ifeq ($(LIBSTATUS),stat)
LDFLAGS=-L lib/lib_stat/ -lbindec
all: $(STATLIB) $(EXEC) 
endif

ifeq ($(LIBSTATUS),dyn)
DYNFLAG=-fPIC
LDFLAGS=-L $(LIBDIR) -Wl,-rpath,./$(LIBDIR)/,-Bdynamic -lbindec
all: $(DYNLIB) $(EXEC)
endif

$(OBJDIR)/maillon.o: $(SRCLIB)/maillon.c $(INCLDIR)/maillon.h $(INCLDIR)/structure.h
	$(CC) $(CFLAGS) $(DYNFLAG) -c $< -o $@

$(OBJDIR)/word.o: $(SRCLIB)/word.c $(INCLDIR)/maillon.h $(INCLDIR)/word.h
	$(CC) $(CFLAGS) $(DYNFLAG) -c $< -o $@

$(OBJDIR)/dico.o: $(SRCDIR)/dico.c $(INCLDIR)/maillon.h $(INCLDIR)/word.h $(INCLDIR)/dico.h 
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/main.o: $(SRCDIR)/main.c $(INCLDIR)/maillon.h $(INCLDIR)/word.h $(INCLDIR)/dico.h
	$(CC) $(CFLAGS) -c $< -o $@

$(DYNLIB): $(OBJDIR)/maillon.o $(OBJDIR)/word.o 
	$(CC) -shared -o $@ $^

$(STATLIB): $(OBJDIR)/maillon.o $(OBJDIR)/word.o
	ar r $@ $^

$(EXEC): $(OBJDIR)/maillon.o $(OBJDIR)/word.o $(OBJDIR)/dico.o $(OBJDIR)/main.o
	$(CC) $(OBJDIR)/*.o -o $@ $(LDFLAGS)

clean: 
	-rm obj/*.o $(EXEC) $(DYNLIB) $(STATLIB)

