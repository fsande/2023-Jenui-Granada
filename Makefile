# -----------------------
# Paper para Jenui 2023
# 
# by F. de Sande <fsande@ull.es>
# date: Dec 28 2022
# ---
##### User configurable options #####
LATEX    = latex
BIBTEX   = bibtex
PDFLATEX = pdflatex
DVIPS    = dvips
L2HTML   = latex2html
PLOT     = gnuplot
SRC      = Jenui2023.tex
MASSRC   = Jenui2023.tex
DVI	     = $(SRC:.tex=.dvi)
BIB	     = ../../bibtex/BIBLIOGRAFIA.bib
PS	     = $(SRC:.tex=.ps)
SRCSIN   = $(SRC:.tex=)
### End User configurable options ###

default: pdf

all:
	$(MAKE) ps

pdf: $(SRC) 
	$(PDFLATEX) $(SRC) && $(MAKE) bib && $(PDFLATEX) $(SRC) && $(PDFLATEX) $(SRC);
	
html: $(PS)
	$(L2HTML) -dir HTML -split 4 -local_icons -long_titles 20 $(SRC)

ps: $(DVI)
	$(DVIPS) -o $(PS) $(DVI)
#	$(LATEX) $(SRC) && $(MAKE) bib && $(LATEX) $(SRC) && $(DVIPS) -o $(PS) $(DVI);

bib: $(SRC) $(BIB) 
	$(BIBTEX) $(SRCSIN)

clean:
	$(RM) *~ *.dvi *.bbl *.aux *.toc *.lof *.lot *.log *.blg *.out *~ basura* HTML/*

push:
	rm *~; git pull; git add . ; git commit -m "Text improvement"; git push

delete:
	$(MAKE) clean; $(RM) *~ $(SRCSIN).pdf $(SRCSIN).ps

%.dvi: %.tex
	$(LATEX) $(SRC) && $(MAKE) bib && $(LATEX) $(SRC) && $(LATEX) $(SRC)
	

# end
# --
