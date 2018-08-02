TREEHEADER=include/ptree.h
TREESRC=ptree.cc
TREEOBJS=ptree.o
PTOBJS=ptgen/java/javaptgen.a
TTOBJS=treeTra/libvgen.a

# VGENOBJS=${TREEOBJS} treeTra/libvgen.a

OBJS=${VGENOBJS} ptgen/java/javaptgen.a

HEADERS=ptgen/java/jrelevantNodes.h ptgen/java/jatomicNodes.h ptgen/java/jparentNodes.h ptgen/java/jcontextualNodes.h

CC=g++
CXX=g++
CPPFLAGS+=-Iinclude -ItreeTra -Iptgen/java

TARGET=autorefactor

${TREEOBJS}:${TREESRC} ${TREEHEADER}
	$(CXX) -o $@ $(CPPFLAGS) -c -DJAVA ${TREESRC}

vecgen:${OBJS} ${HEADERS} ptgen/java/main.cc
	$(CXX) $(CPPFLAGS) -c -DJAVA ptgen/java/main.cc
	$(CXX) -o $@ main.o $(OBJS) $(TREEOBJS) $(PTOBJS) $(TTOBJS)

refactorguide:${OBJS} refactorguide.cpp
	${CXX} $(CPPFLAGS) -c refactorguide.cpp -o refactorguide.o

autorefactor:${OBJS} autorefactor.o refactorguide.o ${HEADERS} autorefactor.cpp
	$(CXX) $(CPPFLAGS) -c autorefactor.cpp
	$(CXX) $(CPPFLAGS) autorefactor.o refactorguide.o ${OBJS} ${TREEOBJS} ${PTOBJS} ${TTOBJS}

