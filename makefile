# Learn it from here / Aprendi por aqui
# https://pt.wikibooks.org/wiki/Programar_em_C/Makefiles
# Really, this explanation in portuguese is wonderful. I can't found an equivalent in english. ;(
# but I explain what I used here in english o/

# CXX=g++-7 already set on travis

CXXFLAGS= -Wno-error -Wall -fmax-errors=0
TEG= $(wildcard ./TEG/*.cpp)
OTEG= $(TEG:.cpp=.o)
all: $(OTEG)

# %.o any file ending .o
# %.c any file ending .c
# %.o: %.c
# any file ending with .o will have dependency to the same file .c
# $@ name of the rule (%.o)
# $< name of the first dependency (%.c)

%.o: %.cpp
	$(CXX) -o $@ -c $^ $(CXXFLAGS)

clean:
	@rm -rf ./TEG/*.o
