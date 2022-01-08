tex_srcs := $(wildcard *.tex)
png_out := $(tex_srcs:.tex=.png)
all: $(png_out)
	
%.png: %.tex
	latex $<
	dvipng -D 300 -bg Transparent -T tight -o $@ $<.dvi `basename $< .tex`.dvi
clean:
	rm -rf *.aux *.dvi *.png *.log
