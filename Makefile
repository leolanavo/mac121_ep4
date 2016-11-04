BIN := ep4

OBJ := tabelaSimbolo.o tabelaSimbolo_VD.o readWord.o tabelaSimbolo_VO.o stableVec.o auxFunctions.o #tabelaSimbolo_LD.o tabelaSimbolo_LO.o tabelaSimbolo_AB.o

TAR := EP4

OBJDIR := obj
SRCDIR := src
BINDIR := .
INCDIR := include
TXTDIR := txt
LTXDIR := latex

CC := gcc
CFLAGS := -Wall -ansi -pedantic -g

#formulas for making binaries

$(BINDIR)/$(BIN): $(patsubst %.o, $(OBJDIR)/%.o, $(OBJ))
	$(CC) $(CFLAGS) -o $@ $^

#general formulas for making objects

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/%.h
	$(CC) $(CFLAGS) -c -o $@ $<


#general commands for automation

clean:
	rm -f $(OBJDIR)/*.o
	rm -f $(BINDIR)/*
	rm -f $(LTXDIR)/*.dvi
	rm -f $(LTXDIR)/*.aux
	rm -f $(LTXDIR)/*.log

latex:
	pdflatex $(LTXDIR)/relatorio.tex

configure:
	mkdir -p $(OBJDIR)
	mkdir -p $(SRCDIR)
	mkdir -p $(BINDIR)
	mkdir -p $(INCDIR)
	mkdir -p $(TXTDIR)
	mkdir -p $(LTXDIR)

organize:
	-mv *.o $(OBJDIR)
	-mv *.c $(SRCDIR)
	-mv *.h $(INCDIR)
	-mv *.txt $(TXTDIR)
	-mv *.dvi $(LTXDIR)
	-mv *.aux $(LTXDIR)
	-mv *.tex $(LTXDIR)
	-mv *.pdf $(LTXDIR)
	-mv *.log $(LTXDIR)

tar: clean
	tar -cvf $(TAR).tar /$(SRCDIR) /$(LTXDIR) /$(INCDIR) Makefile
