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

${TREEOBJS}:${TREESRC} ${TREEHEADER}
	$(CXX) -o $@ $(CPPFLAGS) -c -DJAVA ${TREESRC}

treeutil:${OBJS} ${HEADERS} treeutil.cpp
	${CXX} $(CPPFLAGS) -c treeutil.cpp -o treeutil.o

autorefactor:${OBJS} autorefactor.o treeutil.o ${HEADERS} autorefactor.cpp
	$(CXX) -o autorefactor $(CPPFLAGS) -c -g autorefactor.cpp
	$(CXX) -o autorefactor $(CPPFLAGS) -g autorefactor.o treeutil.o ${OBJS} ${TREEOBJS} ${PTOBJS} ${TTOBJS}

.PHONY: clean
clean:
	rm -f *.o
	rm -f *.out
