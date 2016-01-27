PAPER = paper
TEX = paper.tex
BIB = paper.bib
DVI = paper.dvi
PS = paper.ps
PDF = paper.pdf
FIG = 

$(PAPER): $(TEX) $(BIB) $(FIG)
	latex $(TEX)
	bibtex $(PAPER)
	latex $(TEX)
	latex $(TEX)
	dvipdfm -o $(PDF) $(DVI)
	#dvips -t letter -Ppdf -Go $(DVI)
	#ps2pdf14 $(PS) $(PDF)

.SUFFIXES: .bmp .eps
.bmp.eps:
	convert $< $@
