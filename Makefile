.PHONY: clean all
TREEHEADER=include/ptree.h
TREESRC=ptree.cc
TREEOBJS=ptree.o
PTOBJS=ptgen/java/javaptgen.a
TTOBJS=treeTra/libvgen.a

# VGENOBJS=${TREEOBJS} treeTra/libvgen.a

OBJS=${VGENOBJS} ptgen/java/javaptgen.a

HEADERS=ptgen/java/jrelevantNodes.h ptgen/java/jatomicNodes.h ptgen/java/jparentNodes.h ptgen/java/jcontextualNodes.h autorefactor.h

CC=g++
CXX=g++
CPPFLAGS+=-Iinclude -ItreeTra -Iptgen/java

TARGET=autorefactor

all:ptree treeutil ${TARGET}

ptree:${TREEHEADER} ${TREESRC}
	$(CXX) $(CPPFLAGS) -c ${TREESRC} -DJAVA -o ${TREEOBJS} 

treeutil:${OBJS} ${HEADERS} treeutil.cpp
	${CXX} $(CPPFLAGS) -c treeutil.cpp -o treeutil.o

fileioutil: ${OBJS} treeutil.o ${HEADERS} fileioutil.cpp
	${CXX} $(CPPFLAGS) -c fileioutil.cpp -o fileioutil.o

autorefactor:${OBJS} autorefactor.o treeutil.o fileioutil.o ${HEADERS} autorefactor.cpp
	$(CXX) -o autorefactor $(CPPFLAGS) -c -g autorefactor.cpp
	$(CXX) -o autorefactor $(CPPFLAGS) -g autorefactor.o treeutil.o fileioutil.o ${OBJS} ${TREEOBJS} ${PTOBJS} ${TTOBJS}

clean:
	rm -f *.o
	rm -f *.out
	rm ./autorefactor
