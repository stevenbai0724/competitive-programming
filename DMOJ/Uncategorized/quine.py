a='a=%s%s%s;print(a%%(chr(39),a,chr(39)))';print(a%(chr(39),a,chr(39)))
b='b={}{}{};print(b.format(chr(39),b,chr(39)))';print(b.format(chr(39),b,chr(39)))
c='c=%r;print(c%%c)';print(c%c)
#https://en.wikipedia.org/wiki/Quine_(computing) (delete this line )
