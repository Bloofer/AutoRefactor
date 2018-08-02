TREEHEADER=include/ptree.h
TREESRC=include/ptree.cpp
TREEOBJS=include/ptree.o
PTOBJS=ptgen/javaptgen.a
TTOBJS=treeTra/libvgen.a

# VGENOBJS=${TREEOBJS} treeTra/libvgen.a

OBJS=${VGENOBJS} ptgen/javaptgen.a

HEADERS=ptgen/jrelevantNodes.h ptgen/jatomicNodes.h ptgen/jparentNodes.h ptgen/jcontextualNodes.h

CC=g++
CXX=g++
CPPFLAGS+=-Iinclude -ItreeTra

TARGET=autorefactor

autorefactor:${OBJS} ${HEADERS} autorefactor.cpp
	$(CXX) $(CPPFLAGS) -o $@ autorefactor.o $(TREEOBJS) $(PTOBJS) $(TTOBJS)

