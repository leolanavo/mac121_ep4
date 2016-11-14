BIN  := ep4
TARF := EP4
TEX  := relatorio.tex

CC  := gcc
RM  := rm -f
MV  := mv
TAR := tar -cvf 

CFLAGS := -Wall -ansi -pedantic -O2

OBJDIR := obj
SRCDIR := src
BINDIR := .
INCDIR := include
TXTDIR := txt
LTXDIR := relatorio

SRC := $(wildcard $(SRCDIR)/*.c)
OBJ := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

# main target

.PHONY: all
all: $(BINDIR)/$(BIN)

# build rules

$(BINDIR)/$(BIN): $(OBJ) | $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/%.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# directory creation rules

$(OBJDIR) $(BINDIR) $(SRCDIR) $(INCDIR) $(LTXDIR) $(TXTDIR):
	mkdir -p $@

# phony targets for automation

.PHONY: init
init: | $(SRCDIR) $(INCDIR) $(LTXDIR) $(TXTDIR)
	git init

.PHONY: clean
clean:
	$(RM) $(OBJDIR)/*.o
	$(RM) $(LTXDIR)/*.dvi
	$(RM) $(LTXDIR)/*.aux
	$(RM) $(LTXDIR)/*.log

.PHONY: latex
latex:
	pdflatex $(LTXDIR)/$(TEX)

.PHONY: organize
organize:
	-$(MV) *.o $(OBJDIR)
	-$(MV) *.c $(SRCDIR)
	-$(MV) *.h $(INCDIR)
	-$(MV) *.txt $(TXTDIR)
	-$(MV) *.dvi $(LTXDIR)
	-$(MV) *.aux $(LTXDIR)
	-$(MV) *.tex $(LTXDIR)
	-$(MV) *.pdf $(LTXDIR)
	-$(MV) *.log $(LTXDIR)

.PHONY: tar
tar: clean
	$(TAR) $(TARF).tar /$(SRCDIR) /$(LTXDIR) /$(INCDIR) Makefile
