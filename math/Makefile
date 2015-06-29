TEX_SRCS=rings-vs-fields.tex

PDFS=$(TEX_SRCS:.tex=.pdf)

all: clean $(PDFS)
	@echo "TeXs: $(TEX_SRCS)"

%.pdf: %.tex
	@echo "TeX compiling $< -> $*.pdf"
	texi2pdf $<
	rm $*.log
	rm $*.aux

pdf: *.pdf

clean:
	rm -f *.log *.aux
	rm -f *.bbl
	rm -f *.bcf
	rm -f *.blg
	rm -f *.run.xml
	rm -f $(PDFS)
