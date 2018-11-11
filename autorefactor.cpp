#include "autorefactor.h"

/*
 * ====================================================
 * =============== FILE I/O FUNCTIONS =================
 * ====================================================
 */

// maybe replace with merging the code to refactor_guide?
void readFile(char* alarmFile){

    ifstream cfile(alarmFile);
    cfile >> n;

    CloneData tmpCdata;

    /*
     * 알람 포맷 
     * n                    // 중복 쌍의 갯수. 현재 구현은 2개쌍에 대한 패치
     * clone1_path from to  // 중복1의 파일 위치 / 중복 시작 라인 / 중복 끝 라인
     * clone2_path from to  // 중복2의 파일 위치 / 중복 시작 라인 / 중복 끝 라인
     */

    for(int i=0; i<n; i++){
        cfile >> tmpCdata.fileName >> tmpCdata.from >> tmpCdata.to;
        tmpCdata.cloneSize = tmpCdata.to - tmpCdata.from + 1;

        ifstream ccode(tmpCdata.fileName.c_str());
        int line = 1;
        string temp;
        while (line <= tmpCdata.to) {
            getline(ccode, temp);
            if (line >= tmpCdata.from) tmpCdata.cloneSnippet.push_back(temp);
            line++; 
        }

        cloneDatas.push_back(tmpCdata);
        tmpCdata.fileName = "";
        tmpCdata.from = tmpCdata.to = tmpCdata.cloneSize = 0;
        tmpCdata.cloneSnippet.clear();
    }

}

int getFileLine(string fileName){

    int cnt = 0;
    ifstream iFile(fileName.c_str());
    string line;

    while(getline(iFile, line)){
        cnt++;
    }

    return cnt;

}



/*
 * ====================================================
 * ============ STRING UTILITY FUNCTIONS ==============
 * ====================================================
 */

bool strAreSame(string s1, string s2){

    if(strOnlySpaces(s1) && strOnlySpaces(s2)) return true;
    else if(strOnlySpaces(s1) || strOnlySpaces(s2)) return false;

    dtl::Diff< char, string > strDiff(s1, s2);
    strDiff.compose();
    return (strDiff.getEditDistance() == 0);

}

bool strOnlySpaces(string str){
    // checks if certain string has only spaces
    // this function is for checking white space in the program code
    if(str.find_first_not_of(" \t\r\n") != std::string::npos) return false;
    else return true;
}

string int2str(int n){
    ostringstream ss;
    ss << n;
    return ss.str();
}

int intMin(int a, int b){
    return a < b ? a : b;
}

bool intVecContains(vector<int> &iv, int i){
// returns true if vector contains the element
    return ( find(iv.begin(), iv.end(), i) != iv.end() );
}

bool strVecExists(vector<string> &sv, string s){
    for(int i=0; i<sv.size(); i++){
        if(sv.at(i) == s) return true;
    }
    return false;
}

int ssPairVecSndExists(vector< pair<string, string> > &sv, string s){
    // if found, return index. if not found, return -1
    for(int i=0; i<sv.size(); i++){
        if(sv.at(i).second == s) return i;
    }
    return -1;
}

bool cmpSsPairVec(vector< pair<string, string> > &sv1, vector< pair<string, string> > &sv2){
    // returns true if all elements are true;
    // NOTE: all elements must be sorted in same order
    // TODO : sort before compare?
    bool same = true;
    if(sv1.size() != sv2.size()) return false;
    else {
        for(int i=0; i<sv1.size(); i++){
            same &= ( sv1.at(i).first==sv2.at(i).first ) && ( sv1.at(i).second==sv2.at(i).second );
        }
    }
    return same;
}



/*
 * ====================================================
 * =========== COMMUNAL FUNCTIONS FOR ALL =============
 * ====================================================
 */

void patchCaller(Caller c, string fname, string newFname, int flag){
    // CallGraph에서 찾은 Caller의 Path와 함수 이름을 이용하여, 함수 내 Callee의 원래 이름을 새로운 이름으로 바꿔준다.
    // TODO: 일단은 Callee 함수의 이름만으로 찾는 것 구현. 추후에 Callee Obj 이름 찾아서 이름이 호출하는 함수 위치 패치로 바꿔야할지도?
    // TODO: 일단은 Caller 호출부가 하나인 케이스에 대해 구현. 추후 여러 호출에 대한 구현도 고려 확장할 것.

    bool isCallerConst;
    if(c.callerObjectFtnName == "<init>") isCallerConst = true;
    else isCallerConst = false;

    // Caller 파일 열고, Caller 트리 파싱해서 노드 벡터로 가져옴.
    ifstream pfile(c.realPath.c_str());
    string line;
    vector<string> tempCode;
    int lineCnt = 0; // line counter
    int cdeclLine = 0;
    while(getline(pfile, line)) {
        tempCode.push_back(line);
        lineCnt++;
        if(string::npos!=line.find("class "+c.callerObjectName)) cdeclLine = lineCnt;
    }

    if(cdeclLine == 0) {
        cerr << "Error getting class decl line for ndVec offset usage." << endl;
        return;
    }

    // Caller 노드 벡터 오프셋 가져오기.
    // 실제 파일 패치 적용 위함.
    vector<NodeData> ndVec;
    getPtreeVec(c.realPath, ndVec);

    // 클래스 선언부 라인 가져오기
    bool nodeFnd = false;
    int ptreeCline = 0;
    for(int i=0; i<ndVec.size(); i++){
        if(nodeFnd && ndVec.at(i).isTerminal) {
            ptreeCline = ndVec.at(i).lineNo;
            break;
        } else if(ndVec.at(i).nodeId == 182) nodeFnd = true;
    }

    if(!nodeFnd || ptreeCline == 0) {
        cerr << "Error getting class decl line in ndVec for getting line offset." << endl;
        return;
    }

    int lineOffset; // 파스트리 파일 라인과 실제 파일 라인 넘버가 상이할 경우 대비한 오프셋.
                    // offset = 실제 파일 라인 - 파스 트리 파일 라인
    lineOffset = cdeclLine - ptreeCline;

    if(isCallerConst){

    // =========================================================
    // ======== Caller 위치가 생성자인 경우 (<init>) ===============
    // =========================================================

        // ndVec에서 모은 Const 노드 벡터를 각각 쪼갬.
        // pair.first : Const 노드 벡터, pair.second : Constructor 인자 갯수
        vector< pair< vector<NodeData>, int > > constNdVec = getConstNdVecFromNdVec(ndVec, c.callerObjectName); 
        
        // TODO: 노드 벡터내 method invocation 찾고, 해당 라인(오프셋 뺀) 구하기

        vector<NodeData> cndVec;
        bool cFnd = false;
        for(int i=0; i<constNdVec.size(); i++){
            if(constNdVec.at(i).second == c.argNum) {
                cndVec = constNdVec.at(i).first;
                cFnd = true;
            }
        }

        if(!cFnd) {
            cerr << "Error finding constructor in the constNdVec." << endl;
            return;
        }

        // TODO: method invocation 찾고 파일 라인 찾아서 대치. 이 부분 모듈화 해서 빼기()
        vector<NodeData> tNdVec = getFtnCallTNdVecFromNdVec(cndVec, fname);
        if(tNdVec.empty()) {
            cerr << "Error finding method invocation line in cndVec." << endl;
            return;
        }

        // 1. 함수 bracket ()쌍 내부 인자들 모으기
        int bopen = 0;
        string args = "";
        for(int i=0; i<tNdVec.size(); i++){
            if(tNdVec.at(i).label == "("){
                bopen++;
            } else if(tNdVec.at(i).label == ")"){
                bopen--;
                if(bopen == 0) break;
            } else if(bopen > 0){
                args += tNdVec.at(i).label;
            }
        }   
        //cout << args << endl;

        // 2. 함수 호출 string 내 .ftn(args) 부분을 .newFtn(args, flag)로 대치
        int ftnCallLine = tNdVec.front().lineNo + lineOffset;
        // 실제 파일 내 함수 호출 라인(Caller가 호출하는 Callee 함수 부분)
        string patchLine = tempCode.at(ftnCallLine-1);

        size_t fpos = patchLine.find("."+fname);
        if(fpos == string::npos) {
            cerr << "Error finding method invocation token in the patch code line." << endl;
            return;
        }
        // TODO: 함수 패칭시 bclose 찾을 때, 인자 내부에 ftn call 있는 것 고려하여 구현 확장해야함.
        size_t bpos = patchLine.find(")", fpos);
        if(bpos == string::npos) {
            cerr << "Error finding method bracket closure token in the patch code line." << endl;
            return;
        }

        string newPatchLine = "";
        newPatchLine += patchLine.substr(0, fpos);
        newPatchLine += "." + newFname + "(" + args + "," + int2str(flag) + ")";
        newPatchLine += patchLine.substr(bpos+1);

        tempCode.at(ftnCallLine-1) = newPatchLine;
        // 새로운 함수 이름으로 패치된 코드 삽입.
        testPrintCode(tempCode);

    } else {

    // =========================================================
    // ============ Caller 위치가 일반 함수인 경우 ==================
    // =========================================================

        string ff = "setString";
        int l1 = getFtnPtLineFromNdVec(ndVec, ff);
        vector<NodeData> fndVec;
        getFtnSubtree(c.realPath, ff, fndVec);
        int l2 = getFtnPtLineFromNdVec(fndVec, ff);
        int flineOffset = l1 - l2;
        // 새로 파싱한 ftn ndVec과 기존 ndVec의 라인 오프셋. 이걸 ndVec의 오프셋에 더해서 ftn ndVec의 오프셋을 구함.

        // TODO: method invocation 찾고 파일 라인 찾아서 대치. 이 부분 모듈화 해서 빼기()
        vector<NodeData> tNdVec = getFtnCallTNdVecFromNdVec(fndVec, fname);
        if(tNdVec.empty()) {
            cerr << "Error finding method invocation line in cndVec." << endl;
            return;
        }

        // 1. 함수 bracket ()쌍 내부 인자들 모으기
        int bopen = 0;
        string args = "";
        for(int i=0; i<tNdVec.size(); i++){
            if(tNdVec.at(i).label == "("){
                bopen++;
            } else if(tNdVec.at(i).label == ")"){
                bopen--;
                if(bopen == 0) break;
            } else if(bopen > 0){
                args += tNdVec.at(i).label;
            }
        }   
        //cout << args << endl;

        // 2. 함수 호출 string 내 .ftn(args) 부분을 .newFtn(args, flag)로 대치
        int ftnCallLine = tNdVec.front().lineNo + lineOffset + flineOffset; // TODO: fix line offset.
        // 실제 파일 내 함수 호출 라인(Caller가 호출하는 Callee 함수 부분)
        string patchLine = tempCode.at(ftnCallLine-1);

        size_t fpos = patchLine.find("."+fname);
        if(fpos == string::npos) {
            cerr << "Error finding method invocation token in the patch code line." << endl;
            return;
        }
        // TODO: 함수 패칭시 bclose 찾을 때, 인자 내부에 ftn call 있는 것 고려하여 구현 확장해야함.
        size_t bpos = patchLine.find(")", fpos);
        if(bpos == string::npos) {
            cerr << "Error finding method bracket closure token in the patch code line." << endl;
            return;
        }

        string newPatchLine = "";
        newPatchLine += patchLine.substr(0, fpos);
        newPatchLine += "." + newFname + "(" + args + "," + int2str(flag) + ")";
        newPatchLine += patchLine.substr(bpos+1);

        tempCode.at(ftnCallLine-1) = newPatchLine;
        // 새로운 함수 이름으로 패치된 코드 삽입.
        testPrintCode(tempCode);

    }




} 

int getLineOffset(vector<NodeData> &ndVec, string &ftnName, int from){

    int lineOffset;

    vector< pair<NodeData, int> > tempVec = findNodeByLabel(ndVec, ftnName);
    bool found = false;
    for(int i=0; i<tempVec.size(); i++){
        if(tempVec.at(i).second > 1){
            if(ndVec.at(tempVec.at(i).second - 2).nodeId == 187){ 
                lineOffset = from - tempVec.at(i).first.lineNo;
                found = true;
            }
        }
    }

    return lineOffset;

}

void parseClassMemVars(string fileName){
// parse import class vars and class member vars

    vector<NodeData> ndVec;
    getPtreeVec(fileName, ndVec);

    int imptCnt = 0;
    for(int i=0; i<ndVec.size(); i++){
        if(ndVec.at(i).nodeId == 125) imptCnt++;
    }

    //cout << imptCnt << endl;

    bool found = false;
    int cnt = 0;
    for(int i=0; i<ndVec.size(); i++){
        if(ndVec.at(i).nodeId == 83) found = true;
        if(found){
            if(ndVec.at(i).label == ";") {
                importClassVec.push_back(ndVec.at(i-1).label);
                cnt++;
                found = false;
            }
        }
        if(cnt == imptCnt) break;
    }

    int classMems = 0;
    for(int i=0; i<ndVec.size()-1; i++){
        if(ndVec.at(i).nodeId == 88 && ndVec.at(i+1).nodeId == 143) classMems++;
    }

    found = false;
    bool typeChk = false;
    bool nameChk = false;
    string memType, memName;
    cnt = 0;
    for(int i=0; i<ndVec.size(); i++){
        if(ndVec.at(i).nodeId == 123) found = true;
        if(ndVec.at(i).nodeId == 65) nameChk = true;
        if(found && ndVec.at(i).isTerminal && !typeChk){
            memType = ndVec.at(i).label;
            typeChk = true;
        } else if(found && ndVec.at(i).isTerminal && typeChk && !nameChk){
            memType += ndVec.at(i).label;
        } else if(found && ndVec.at(i).isTerminal && typeChk && nameChk){
            memName = ndVec.at(i).label;
            classMemVarVec.push_back(pair<string, string>(memType, memName));
            cnt++;
            found = typeChk = nameChk = false;
        }
        if(cnt == classMems) break;
    }

}

bool compFtype(FtnType &f1, FtnType &f2){

    //testPrintFtnType(f1);
    //testPrintFtnType(f2);

    if(f1.ftnArgs.size() != f1.ftnArgs.size()) return false;

    bool same = true;
    same &= (f1.returnType == f2.returnType);
    for(int i=0; i<f1.ftnArgs.size(); i++){
        same &= (f1.ftnArgs.at(i).first == f2.ftnArgs.at(i).first) && (f1.ftnArgs.at(i).second == f2.ftnArgs.at(i).second);
    }
    for(int i=0; i<f1.exceptions.size(); i++){
        same &= (f1.exceptions.at(i) == f2.exceptions.at(i));
    }
    return same;

}

string getFnameInScope(int frt, int bck, vector<FtnData> &fdVec){
    bool found = false;
    int idx;
    for(int i=0; i<fdVec.size(); i++){
        if(frt >= fdVec.at(i).from && frt <= fdVec.at(i).to && 
           bck >= fdVec.at(i).from && bck <= fdVec.at(i).to) {
               found = true;
               idx = i;   
            }
    }

    if(found) return fdVec.at(idx).ftnName;
    else {
        cerr << "Error : clone scope is not inside the ftn def part." << endl;
        return "";
    }

}

clone_type getCloneType(){

    if(cloneDatas.size() < 2){
        cerr << "Clone datas not parsed. Abort process." << endl;
        return ERR;
    }

    CloneData c1, c2;
    c1 = cloneDatas.front();
    c2 = cloneDatas.back();

    vector<FtnData> fdVec;
    getAllFtnData(c1.fileName, fdVec);
    // 1. CloneData 내 알람 정보의 중복이 함수 정의부에 속하는 지 확인. 벗어난 경우 종료.

    if(fdVec.empty()) {
        cerr << "Error : ftn data vector is empty." << endl;
        return ERR;
    }

    FtnType f1, f2;
    f1.ftnName = getFnameInScope(c1.from, c1.to, fdVec);
    f2.ftnName = getFnameInScope(c2.from, c2.to, fdVec);
    cloneDatas.front().ftnName = f1.ftnName;
    cloneDatas.back().ftnName = f2.ftnName;

    if(f1.ftnName == "" || f2.ftnName == "") {
        cerr << "Error : clone scope is not inside the ftn def part." << endl;
        return ERR;
    }

    vector<NodeData> ndVec1;
    vector<NodeData> ndVec2;
    getFtnSubtree(c1.fileName, f1.ftnName, ndVec1);
    getFtnSubtree(c2.fileName, f2.ftnName, ndVec2);
    parseFtnType(c1.fileName, f1.ftnName, f1, ndVec1);
    parseFtnType(c2.fileName, f2.ftnName, f2, ndVec2);

    cout << "Parsing method type..." << endl;
    cout << "========= Clone Ftn #1 =========" << endl;
    testPrintFtnType(f1);
    cout << endl << "========= Clone Ftn #2 =========" << endl;
    testPrintFtnType(f2);
    cout << endl;

    cloneFtnTypes.push_back(f1);
    cloneFtnTypes.push_back(f2);

    if (compFtype(f1, f2)) return T2;
    else return T1;

}

void reportResult(){

    cout << "\n======= Reporting Results =======" << endl;
    cout << "Original Loc : " << beforePatchLoc << endl;
    cout << "Patched Loc : " << afterPatchLoc << endl;
    cout << "Reduced Loc : " << reducedLoc << endl;
    //cout << "Patched Ftn : " << endl; // TODO: fill this
    cout << "=================================" << endl;

}



/*
 * ====================================================
 * ======= FUNCTIONS FOR TYPE 1(EXTRACT METHOD) =======
 * ====================================================
 */

pair<int, int> getCommonPart(CloneData &c1, CloneData &c2, FtnType &f1, FtnType &f2, bool &normalCompletion){

    // 1. EM 구간 정하기 (휴리스틱 - 구간 일정 크기보다 작으면 알고리즘 종료하기. ex 10라인 미만은 em 크게 의미 x)
    // 1.1. 일단 syntatic하게 비교해서 아예 같은 구간 먼저 찾아내기.
    // 1.2. 함수 내 중복 부분 중 bracket(for문, if문) 큰 구간 찾고 적용 가능 한 구간 설정(이때 구간에 return문 제외)
    // 1.3. 앞 쪽 선언된 지역 변수가 있는데 구간 밖에서 사용되면 그 부분 제외

    pair<int, int> cp;

    // compare two clone datas
    vector<int> diffInt;

    vector<string>::iterator it1 = c1.cloneSnippet.begin();
    vector<string>::iterator it2 = c2.cloneSnippet.begin();
    int idx = 0;

    // 2. put diff part offset line in the vector (this should except first/last line - b.c. ftn decl & closure)
    for(; it1 != c1.cloneSnippet.end() && it2 != c2.cloneSnippet.end(); ++it1, ++it2){
        if (!strAreSame((*it1), (*it2)) && idx != 0) diffInt.push_back(idx);
        ///cout << (*it1) << endl << (*it2) << endl;
        idx++;
    }

    int lineOffset1, lineOffset2; // 파스트리 파일 라인과 실제 파일 라인 넘버가 상이할 경우 대비한 오프셋.
                                  // offset = 실제 파일 라인 - 파스 트리 파일 라인
    vector<NodeData> ndVec1;
    vector<NodeData> ndVec2;
    getFtnSubtree(c1.fileName, f1.ftnName, ndVec1);
    getFtnSubtree(c2.fileName, f2.ftnName, ndVec2);
    lineOffset1 = getLineOffset(ndVec1, f1.ftnName, c1.from);
    lineOffset2 = getLineOffset(ndVec2, f2.ftnName, c2.from);

    vector< pair<NodeData, int> > returnVec1 = findNodeByLabel(ndVec1, "return");
    vector< pair<NodeData, int> > returnVec2 = findNodeByLabel(ndVec2, "return");
    
    int diffFrontRet1 = returnVec1.front().first.lineNo + lineOffset1 - c1.from;
    int diffFrontRet2 = returnVec2.front().first.lineNo + lineOffset2 - c1.from;

    if (diffInt.back() > diffFrontRet1 || diffInt.back() > diffFrontRet2) {
        normalCompletion = false;
        return pair<int, int>(0, 0);
    }
    // error case

    int frt, rear;
    frt = diffInt.back();
    rear = intMin(diffFrontRet1, diffFrontRet2) - 1;

    pair<int, int> tmpPair1 = pair<int, int>(frt + c1.from - lineOffset1, rear + c1.from - lineOffset1);
    pair<int, int> tmpPair2 = pair<int, int>(frt + c2.from - lineOffset2, rear + c2.from - lineOffset2);
    pair<int, int> scp1 = findBiggestBracketInScope(ndVec1, tmpPair1, normalCompletion);
    pair<int, int> scp2 = findBiggestBracketInScope(ndVec2, tmpPair2, normalCompletion);
    if (!normalCompletion) {
        return pair<int, int>(0, 0);
    }

    if (scp1.first == 0 && scp1.second == 0) {
        normalCompletion = false;
        return pair<int, int>(0, 0);
    }
    if (scp2.first == 0 && scp2.second == 0) { 
        normalCompletion = false;
        return pair<int, int>(0, 0);
    }
    // if there is no bracket in the scope

    if (scp1.second - scp1.first != scp2.second - scp2.first) {
        normalCompletion = false;
        return pair<int, int>(0, 0);
    }
    // error case : cannot find the scope
 
    cp.first = scp1.first - c1.from + lineOffset1;
    cp.second = scp1.second - c1.from + lineOffset1;
    return cp;

}

vector< pair<string, string> > getSeVarSet(CloneData &c1, CloneData &c2, FtnType &f1, FtnType &f2, pair<int, int> &scope, bool &normalCompletion){
// 사이드 이펙트에 영향을 받는 scope 위쪽 함수 변수 셋 모으기

    vector< pair<string, string> > seVarSet;

    int lineOffset1, lineOffset2; // 파스트리 파일 라인과 실제 파일 라인 넘버가 상이할 경우 대비한 오프셋.
                                  // offset = 실제 파일 라인 - 파스 트리 파일 라인
    vector<NodeData> ndVec1;
    vector<NodeData> ndVec2;
    getFtnSubtree(c1.fileName, f1.ftnName, ndVec1);
    getFtnSubtree(c2.fileName, f2.ftnName, ndVec2);
    lineOffset1 = getLineOffset(ndVec1, f1.ftnName, c1.from);
    lineOffset2 = getLineOffset(ndVec2, f2.ftnName, c2.from);

    vector< pair<string, string> > varBelowScope1;
    vector< pair<string, string> > varBelowScope2;

    // 3.1. LOCAL 뽑을 범위 계산하기 (from : 함수 정의부 + 1, to : Scope.front - 1)
    // 파스 트리 파일 라인 = 실제 파일 라인 - offset
    int locScopeFrt1 = c1.from + scope.first - lineOffset1;
    int locScopeRear1 = c1.to - lineOffset1;
    pair<int, int> locScope1 = pair<int, int>(locScopeFrt1, locScopeRear1);
    varBelowScope1 = findPrmtvLocVarInScope(ndVec1, locScope1);
    // varBelowScope is only primitive type

    //printNodeVector(ndVec1);
    //cout << endl << locScope1.first << "  " << locScope1.second << endl;

    int locScopeFrt2 = c2.from + scope.first - lineOffset2;
    int locScopeRear2 = c2.to - lineOffset2;
    pair<int, int> locScope2 = pair<int, int>(locScopeFrt2, locScopeRear2);
    varBelowScope2 = findPrmtvLocVarInScope(ndVec2, locScope2);
    // varBelowScope is only primitive type

    if (varBelowScope1.size() == 0 || varBelowScope2.size() == 0) {
        cout << "No side-effected variables are found. return empty SeVarSet." << endl;
        return seVarSet;
    }

    // 4. USED : 구간 내 사용된 변수 이름 모으기
    // TODO: refactor this and extract to function
    vector<string> usedVars1;
    int brktScopeFrt1 = c1.from + scope.first - lineOffset1;
    int brktScopeRear1 = c1.from + scope.second - lineOffset1;
    for(int i=0; i<ndVec1.size(); i++){
        if(ndVec1.at(i).nodeId == 39){
            if(i>5 && ndVec1.at(i-1).label != "." && ndVec1.at(i-5).nodeId != 123 && ndVec1.at(i+1).label != "Exception" 
                && ndVec1.at(i+1).isTerminal && !strVecExists(usedVars1, ndVec1.at(i+1).label)
                && ndVec1.at(i+1).lineNo >= brktScopeFrt1 && ndVec1.at(i+1).lineNo <= brktScopeRear1 ) usedVars1.push_back(ndVec1.at(i+1).label);
        }
    }
    vector< pair<string, string> > seVarSet1;
    for(int i=0; i<usedVars1.size(); i++){
        int idx = ssPairVecSndExists(varBelowScope1, usedVars1.at(i));
        if (idx != -1){
            seVarSet1.push_back(varBelowScope1.at(idx));
        }
    }
    
    // prune for primitive type vars (to return)

    vector<string> usedVars2;
    int brktScopeFrt2 = c2.from + scope.first - lineOffset2;
    int brktScopeRear2 = c2.from + scope.second - lineOffset2;
    for(int i=0; i<ndVec2.size(); i++){
        if(ndVec2.at(i).nodeId == 39){
            if(i>5 && ndVec2.at(i-1).label != "." && ndVec2.at(i-5).nodeId != 123 && ndVec2.at(i+1).label != "Exception" 
                && ndVec2.at(i+1).isTerminal && !strVecExists(usedVars2, ndVec2.at(i+1).label)
                && ndVec2.at(i+1).lineNo >= brktScopeFrt2 && ndVec2.at(i+1).lineNo <= brktScopeRear2 ) usedVars2.push_back(ndVec2.at(i+1).label);
        }
    }
    vector< pair<string, string> > seVarSet2;
    for(int i=0; i<usedVars2.size(); i++){
        int idx = ssPairVecSndExists(varBelowScope2, usedVars2.at(i));
        if (idx != -1){
            seVarSet2.push_back(varBelowScope2.at(idx));
        }
    }

    // prune for primitive type vars (to return)

    if(!cmpSsPairVec(seVarSet1, seVarSet2)) {
        cerr << "Error : em arguments doesn't match between two clone parts." << endl;
        normalCompletion = false;
        return seVarSet;
    }

    // 5. ARG = USED - INNER - EXTERN - CLASS_MEMBER 이 중에 LOCAL에 존재하는 이름.(만약 하나라도 없으면 FAIL)
    // USED 중 세 변수 집합에 존재하는 것 전부 빼고 나머지 중 LOCAL에 존재하는 이름 찾으면 됨.

    return seVarSet1;

}

vector< pair<string, string> > getVarSet(CloneData &c1, CloneData &c2, FtnType &f1, FtnType &f2, pair<int, int> &scope, bool &normalCompletion){

    vector< pair<string, string> > varSet;

    int lineOffset1, lineOffset2; // 파스트리 파일 라인과 실제 파일 라인 넘버가 상이할 경우 대비한 오프셋.
                                  // offset = 실제 파일 라인 - 파스 트리 파일 라인
    vector<NodeData> ndVec1;
    vector<NodeData> ndVec2;
    getFtnSubtree(c1.fileName, f1.ftnName, ndVec1);
    getFtnSubtree(c2.fileName, f2.ftnName, ndVec2);
    lineOffset1 = getLineOffset(ndVec1, f1.ftnName, c1.from);
    lineOffset2 = getLineOffset(ndVec2, f2.ftnName, c2.from);

    // 1. EXTERN & CLASS_MEMBER : 다른 함수에서 모은 import 객체, 클래스 멤버 변수
    // 2. FTN_ARG : 각 함수의 인자로 정의된 변수 모으기

    // 3. LOCAL : 함수 내 scope 구간 위 정의된 변수 모으기
    vector< pair<string, string> > varAboveScope1;
    vector< pair<string, string> > varAboveScope2;

    // 3.1. LOCAL 뽑을 범위 계산하기 (from : 함수 정의부 + 1, to : Scope.front - 1)
    // 파스 트리 파일 라인 = 실제 파일 라인 - offset
    int locScopeFrt1 = c1.from + 1 - lineOffset1;
    int locScopeRear1 = c1.from + scope.first - 1 - lineOffset1;
    pair<int, int> locScope1 = pair<int, int>(locScopeFrt1, locScopeRear1);
    varAboveScope1 = findLocVarInScope(ndVec1, locScope1);

    int locScopeFrt2 = c2.from + 1 - lineOffset2;
    int locScopeRear2 = c2.from + scope.first - 1 - lineOffset2;
    pair<int, int> locScope2 = pair<int, int>(locScopeFrt2, locScopeRear2);
    varAboveScope2 = findLocVarInScope(ndVec2, locScope2);

    // 3.2 merge ftn arg with local var above scope
    varAboveScope1.insert(varAboveScope1.end(), f1.ftnArgs.begin(), f1.ftnArgs.end());
    varAboveScope2.insert(varAboveScope2.end(), f2.ftnArgs.begin(), f2.ftnArgs.end());

    // 4. USED : 구간 내 사용된 변수 이름 모으기
    // TODO: refactor this and extract to function
    vector<string> usedVars1;
    int brktScopeFrt1 = c1.from + scope.first - lineOffset1;
    int brktScopeRear1 = c1.from + scope.second - lineOffset1;
    for(int i=0; i<ndVec1.size(); i++){
        if(ndVec1.at(i).nodeId == 39){
            if(i>5 && ndVec1.at(i-1).label != "." && ndVec1.at(i-5).nodeId != 123 && ndVec1.at(i+1).label != "Exception" 
                && ndVec1.at(i+1).isTerminal && !strVecExists(usedVars1, ndVec1.at(i+1).label)
                && ndVec1.at(i+1).lineNo >= brktScopeFrt1 && ndVec1.at(i+1).lineNo <= brktScopeRear1 ) usedVars1.push_back(ndVec1.at(i+1).label);
        }
    }
    vector< pair<string, string> > varSet1;
    for(int i=0; i<usedVars1.size(); i++){
        int idx = ssPairVecSndExists(varAboveScope1, usedVars1.at(i));
        if (idx != -1){
            varSet1.push_back(varAboveScope1.at(idx));
        }
    }
    
    vector<string> usedVars2;
    int brktScopeFrt2 = c2.from + scope.first - lineOffset2;
    int brktScopeRear2 = c2.from + scope.second - lineOffset2;
    for(int i=0; i<ndVec2.size(); i++){
        if(ndVec2.at(i).nodeId == 39){
            if(i>5 && ndVec2.at(i-1).label != "." && ndVec2.at(i-5).nodeId != 123 && ndVec2.at(i+1).label != "Exception" 
                && ndVec2.at(i+1).isTerminal && !strVecExists(usedVars2, ndVec2.at(i+1).label)
                && ndVec2.at(i+1).lineNo >= brktScopeFrt2 && ndVec2.at(i+1).lineNo <= brktScopeRear2 ) usedVars2.push_back(ndVec2.at(i+1).label);
        }
    }
    vector< pair<string, string> > varSet2;
    for(int i=0; i<usedVars2.size(); i++){
        int idx = ssPairVecSndExists(varAboveScope2, usedVars2.at(i));
        if (idx != -1){
            varSet2.push_back(varAboveScope2.at(idx));
        }
    }

    if(!cmpSsPairVec(varSet1, varSet2)) {
        cerr << "Error : em arguments doesn't match between two clone parts." << endl;
        normalCompletion = false;
        return varSet;
    }

    // 5. ARG = USED - INNER - EXTERN - CLASS_MEMBER 이 중에 LOCAL에 존재하는 이름.(만약 하나라도 없으면 FAIL)
    // USED 중 세 변수 집합에 존재하는 것 전부 빼고 나머지 중 LOCAL에 존재하는 이름 찾으면 됨.

    return varSet1;

}

void extractMethod(string fileName, CloneData &c1, CloneData &c2, FtnType &f1, FtnType &f2, pair<int, int> &scope, vector< pair<string, string> > &varSet, vector< pair<string, string> > &seVarSet){

    // 1. make new method name and decl line
    string newFtnName = f1.ftnName + f2.ftnName;

    int tabIdx = c1.cloneSnippet.front().find_first_not_of(" \t\r\n"); // this is for code formatting
    string tabStr = c1.cloneSnippet.front().substr(0, tabIdx);
    // TODO: seVarSet.front().first --> should be refactored.
    // this impl only accepts one/no seVarSet. but it should be expanded to accept multiple seVarSets using tuples. 
    string fstLine;
    if (seVarSet.empty()) fstLine = tabStr + "public void " + newFtnName + "(";
    else if (seVarSet.size()==1) fstLine = tabStr + "public " + seVarSet.front().first + " " + newFtnName + "(";
    else cerr << "AutoRefactor cannot refactor more than 1 SeVarSet now. It will be implemented soon." << endl;
    for(int i=0; i<varSet.size(); i++){
        fstLine += varSet.at(i).first + " " + varSet.at(i).second;
        if(i<varSet.size()-1) fstLine += ", ";
    }
    fstLine += ") {";
    tempClone.push_back(fstLine);

    // 2. insert bracket scope in the new method
    for(int i=scope.first; i<=scope.second; i++){
        tempClone.push_back(c1.cloneSnippet.at(i));    
    }    
    // 2-2 insert return statement to pass effected seVarSet
    int retTabIdx = c1.cloneSnippet.at(scope.second).find_first_not_of(" \t\r\n");
    string retTabStr = c1.cloneSnippet.at(scope.second).substr(0, retTabIdx);
    // TODO: seVarSet --> should be refactored.
    // this impl only accepts one/no seVarSet. but it should be expanded to accept multiple seVarSets using tuples. 
    string seVarSetRet;
    if (seVarSet.empty()) { // if empty. skip this stage. (inserting return statement)
    } else if (seVarSet.size()==1) seVarSetRet = retTabStr + "return " + seVarSet.front().second + ";";
    else cerr << "AutoRefactor cannot refactor more than 1 SeVarSet now. It will be implemented soon." << endl;
    tempClone.push_back(seVarSetRet);
    tempClone.push_back(tabStr + "}");

    if(runOption != COD){
        cout << "Patching clone..." << endl;
        cout << "Extracted method from clone part : " << newFtnName << "()" << endl << endl;
        testPrintCode(tempClone);
    }

    // 3. replace clone part with new function call
    bool inserted1 = false;
    for(int i=0; i<c1.cloneSnippet.size(); i++){
        if(i >= scope.first && i <= scope.second && !inserted1){
            int tabIdxIn = c1.cloneSnippet.at(scope.first).find_first_not_of(" \t\r\n"); // this is for code formatting
            string tabStrIn = c1.cloneSnippet.at(scope.first).substr(0, tabIdxIn);
            // TODO: seVarSet.front().second --> should be refactored.
            // this impl only accepts one/no seVarSet. but it should be expanded to accept multiple seVarSets using tuples. 
            string newFtnCall;
            if (seVarSet.empty()) newFtnCall = tabStrIn + newFtnName + "(";
            else if (seVarSet.size()==1) newFtnCall = tabStrIn + seVarSet.front().second + " = " + newFtnName + "(";
            else cerr << "AutoRefactor cannot refactor more than 1 SeVarSet now. It will be implemented soon." << endl;
            for(int i=0; i<varSet.size(); i++){
                newFtnCall += varSet.at(i).second;
                if (i<varSet.size()-1) newFtnCall += ", ";
            }
            newFtnCall += ");";
            orgClone1.push_back(newFtnCall);
            inserted1 = true;
        }
        else if (i < scope.first || i > scope.second) orgClone1.push_back(c1.cloneSnippet.at(i));
    }

    if(runOption != COD){
        cout << endl << "========================================" << endl;
        cout << "Patching clone..." << endl;
        cout << "Clone part 1 patched with ftn call." << endl << endl;
        testPrintCode(orgClone1);
    }

    // 3. replace clone part with new function call
    bool inserted2 = false;
    for(int i=0; i<c2.cloneSnippet.size(); i++){
        if(i >= scope.first && i <= scope.second && !inserted2){
            int tabIdxIn = c2.cloneSnippet.at(scope.first).find_first_not_of(" \t\r\n"); // this is for code formatting
            string tabStrIn = c2.cloneSnippet.at(scope.first).substr(0, tabIdxIn);
            // TODO: seVarSet.front().second --> should be refactored.
            // this impl only accepts one/no seVarSet. but it should be expanded to accept multiple seVarSets using tuples. 
            string newFtnCall;
            if (seVarSet.empty()) newFtnCall = tabStrIn + newFtnName + "(";
            else if (seVarSet.size()==1) newFtnCall = tabStrIn + seVarSet.front().second + " = " + newFtnName + "(";
            else cerr << "AutoRefactor cannot refactor more than 1 SeVarSet now. It will be implemented soon." << endl;
            for(int i=0; i<varSet.size(); i++){
                newFtnCall += varSet.at(i).second;
                if (i<varSet.size()-1) newFtnCall += ", ";
            }
            newFtnCall += ");";
            orgClone2.push_back(newFtnCall);
            inserted2 = true;
        }
        else if (i < scope.first || i > scope.second) orgClone2.push_back(c2.cloneSnippet.at(i));
    }

    if(runOption != COD){
        cout << endl << "========================================" << endl;
        cout << "Patching clone..." << endl;
        cout << "Clone part 2 patched with ftn call." << endl << endl;
        testPrintCode(orgClone2);
    }

    // patch code to the entire file
    ifstream pfile(c1.fileName.c_str());
    string line;

    int lineCnt = 1; // line counter
    while(getline(pfile, line)) {
        if(lineCnt == c1.from) { 
            patchCode.insert(patchCode.end(), tempClone.begin(), tempClone.end());
            patchCode.push_back("");
            patchCode.insert(patchCode.end(), orgClone1.begin(), orgClone1.end());
        } else if(lineCnt == c2.from){
            patchCode.insert(patchCode.end(), orgClone2.begin(), orgClone2.end());
        }
        if(lineCnt == c2.to + 1) {
            if(strOnlySpaces(line)) { lineCnt++; continue; }
        }
        if(!(lineCnt >= c1.from && lineCnt <= c1.to) && !(lineCnt >= c2.from && lineCnt <= c2.to)) patchCode.push_back(line);
        
        lineCnt++;
    }

    afterPatchLoc = patchCode.size();

    if(runOption != RST){
        cout << "Patching clones ...\n";
        cout << "(This will be replaced with actual file write operations)\n";
        testPrintCode(patchCode);
    }

}



/*
 * ====================================================
 * ======= FUNCTIONS FOR TYPE 2(MERGE METHOD) =========
 * ====================================================
 */

// TODO: finish caller patching. (in progress)
void getCallerInfo(string &cname, string &fname, vector<CallGraph> &cgVec, vector<Caller> &callerVec){
    // TODO: 3. 입력으로 Callee cname/fname을 주고 해당하는 Caller 정보 (call cnt, cname, fname) 모으기 
    // getCallerInfo : ( calleeCname * calleeFname * callGraph ) -> ( Caller[] )

    for(int i=0; i<cgVec.size(); i++){
        if(cgVec.at(i).callee_cname == cname && cgVec.at(i).callee_fname == fname) {
            Caller tmpCaller;
            tmpCaller.fileName = cgVec.at(i).caller_path;
            tmpCaller.callerObjectName = cgVec.at(i).caller_cname;
            tmpCaller.callerObjectFtnName = cgVec.at(i).caller_fname;
            tmpCaller.argNum = cgVec.at(i).caller_argcnt;
            callerVec.push_back(tmpCaller);
        }
    }

    // sort callerVec to count caller ftn invocation
    // TODO: sort(callerVec.begin(), callerVec.end(), compare_cg);

    /* vector<string> cname_lst;
    cname_lst.push_back("FasooMessageParser");
    
    vector<CallGraph> cg_lst;

    //getCallGraphData("/home/yang/Sources/AutoRefactor/casestudy/fasoo/eprint/callgraphGeneralPhase.dot", cg_lst, cname_lst);
    string cname = "FasooMessageParser";
    string fname = "parse2";
    getFtnCallerData("/home/yang/Sources/AutoRefactor/casestudy/fasoo/eprint/callgraphGeneralPhase.dot", cg_lst, cname, fname);
    
    sort(cg_lst.begin(), cg_lst.end(), compare_cg);
    
    // make unique (i think this should be deprecated)
    //vector<CallGraph>::iterator it;
    //it = unique(cg_lst.begin(), cg_lst.end(), same_cg);
    //cg_lst.resize(distance(cg_lst.begin(), it));

    cout << cg_lst.size() << endl;
    for(int i=0; i<cg_lst.size(); i++){
        cout << cg_lst.at(i).callee_cname << " " << cg_lst.at(i).callee_fname << " " << cg_lst.at(i).caller_path << " " << cg_lst.at(i).caller_cname << " " << cg_lst.at(i).caller_fname << endl;
    } */

}


DiffInfo getDiffInfo(vector<NodeData> &ndVec) {

    DiffInfo dinfo;
    bool fnd = false;

    for(int i=0; i<ndVec.size(); i++){
        if(!fnd && !ndVec.at(i).isTerminal && i<ndVec.size()-1){
            if(ndVec.at(i).nodeId == 162) {
                dinfo.diffType = 1; // return stmt
                fnd = true;
                break;
            }
            else if(ndVec.at(i).nodeId == 23 && ndVec.at(i+1).nodeId == 145) {
                dinfo.diffType = 2; // var decl
                fnd = true;
            }
            else if(ndVec.at(i).nodeId == 69){
                dinfo.diffType = 3; // assignment expr
                fnd = true;
            }
        } else if(fnd && dinfo.diffType == 2 && i<ndVec.size()-1) {
            if(ndVec.at(i).nodeId == 123 && ndVec.at(i+1).nodeId == 62) {
                dinfo.isRef = true; // var type is reference
                break;
            } else if(ndVec.at(i).nodeId == 123 && ndVec.at(i+1).nodeId == 117) {
                dinfo.isRef = false; // var type is primitive
                break;
            }
        }
    }
    if(!fnd) dinfo.diffType = 0; // others

    if(dinfo.diffType == 2){
        // if stmt type is var decl, parse type & var name
        vector<string> tnodeVec = getTnodeLabelInNdVec(ndVec);
        int assignIdx = 0;
        bool asnFnd = false;
        for(int i=0; i<tnodeVec.size(); i++){
            if(!asnFnd && tnodeVec.at(i) == "=") { 
                asnFnd = true;
                break;
            } else assignIdx++;
        }

        if(!asnFnd) cerr << "Error on DiffInfo parsing. Cannot parse stmt var types." << endl;
        else {
            string varType = "";
            for(int i=0; i<assignIdx-1; i++) varType += tnodeVec.at(i);
            string varName = tnodeVec.at(assignIdx-1);
            dinfo.typeName = varType;
            dinfo.varName = varName;
        }
    } else if(dinfo.diffType == 3){
        // stmt가 assign expr인 경우, lhs의 변수 이름 가져오기
        vector<string> tnodeVec = getTnodeLabelInNdVec(ndVec);
        int assignIdx = 0;
        bool asnFnd = false;
        for(int i=0; i<tnodeVec.size(); i++){
            if(!asnFnd && tnodeVec.at(i) == "=") { 
                asnFnd = true;
                break;
            } else assignIdx++;
        }

        if(!asnFnd) cerr << "Error on DiffInfo parsing. Cannot parse assign expr lhs." << endl;
        string varName = "";
        for(int i=0; i<assignIdx; i++) varName += tnodeVec.at(i);
        dinfo.varName = varName;
    }

    return dinfo;

}

vector<int> getDiff(CloneData &c1, CloneData &c2, FtnType &f1, FtnType &f2, vector<DiffInfo> &diffInfo, int patchType, bool &normalCompletion){
    // patchType; 2-T2 merge method:branching, 3-T3 merge method:arg pass
    // T3에서 L-value diff인 경우에도 일단 받아들일 수 있게 막지 않는다.

    // function for getting diff part of two clone datas
    vector<int> diffLine;

    // 1. compare two clone datas (function-wise)
    vector<string>::iterator it1 = c1.cloneSnippet.begin();
    vector<string>::iterator it2 = c2.cloneSnippet.begin();
    int idx = 0;

    // 2. put diff part offset line in the vector (this should except first/last line - b.c. ftn decl & closure)
    for(; it1 != c1.cloneSnippet.end() && it2 != c2.cloneSnippet.end(); ++it1, ++it2){
        if (!strAreSame((*it1), (*it2)) && idx != 0) diffLine.push_back(idx);
        idx++;
    }

    // <diff 알고리즘>
    // 1-1. 일단 syntatic하게 라인별로 비교
    // 1-2. 불일치 라인 트리 벡터로 찾아가 토큰 하나씩 비교
    
    // 1-2-a. 트리 벡터 이용시 사용할 라인 넘버 위한 라인 오프셋 계산.
    int lineOffset1, lineOffset2; // 파스트리 파일 라인과 실제 파일 라인 넘버가 상이할 경우 대비한 오프셋.
                                  // offset = 실제 파일 라인 - 파스 트리 파일 라인
    vector<NodeData> ndVec1;
    vector<NodeData> ndVec2;
    getFtnSubtree(c1.fileName, f1.ftnName, ndVec1);
    getFtnSubtree(c2.fileName, f2.ftnName, ndVec2);
    lineOffset1 = getLineOffset(ndVec1, f1.ftnName, c1.from);
    lineOffset2 = getLineOffset(ndVec2, f2.ftnName, c2.from);

    // 1-2-b. 불일치 라인 트리 벡터로 토큰 비교.
    bool hasLvalue = false;

    // 1-3. 비교해서 다른 토큰 각각 짚기
    // 1-4. 다른 토큰이 L-value인 경우 알고리즘 종료(찾는 방법은 nodeID를 보고)
    for(int i=0; i<diffLine.size(); i++){

        vector< pair<NodeData, int> > tmpVec1 = findNodeByLine(ndVec1, c1.from+diffLine.at(i)-lineOffset1);
        vector< pair<NodeData, int> > tmpVec2 = findNodeByLine(ndVec2, c2.from+diffLine.at(i)-lineOffset2);
        //cout << tmpVec1.size() << " " << tmpVec2.size() << endl;
        //cout << diffLine.at(i) << endl;

        // get same token (to except from diff token compare)
        vector<int> tokSame1;
        vector<int> tokSame2;
        for(int j=0; j<tmpVec1.size() && j<tmpVec2.size(); j++){
            if(tmpVec1.at(j).first.label == tmpVec2.at(j).first.label) {
                tokSame1.push_back(j);
                tokSame2.push_back(j);
            }
        }
        
        // testNdVec : 해당 라인에 해당하는 노드 벡터
        // testNdVec 이용해서 stmt 구분 먼저 
        // 23-145 : var_decl, 162 : return, 나머지 : others
        // 만약 var_decl 이면, var 타입 구하기
        // 123-62 : ref_type, 123-117: prmtv_type
        vector<NodeData> testNdVec = findNodeByLineWithNt(ndVec1, c1.from+diffLine.at(i)-lineOffset1);
        DiffInfo dinfo = getDiffInfo(testNdVec);
        diffInfo.push_back(dinfo);
        //testPrintDiffInfo(dinfo);

        vector<int> emptyVec;
        // Diff line Lvalue check part
        // Diff line Var Decl & Retur Stmt check part
        for(int j=0; j<tmpVec1.size(); j++){
            if(intVecContains(tokSame1, j)) continue;
            if(patchType==2 && isLvalueNode(ndVec1, tmpVec1.at(j).second)) {
                cerr << "Error : Var decl diff(Lvalue diff) found on vec1 diff line. Merging aborted." << endl;
                normalCompletion = false;
                hasLvalue |= isLvalueNode(ndVec1, tmpVec1.at(j).second);
            }
        }
        for(int j=0; j<tmpVec2.size(); j++){
            if(intVecContains(tokSame2, j)) continue;
            if(patchType==2 && isLvalueNode(ndVec2, tmpVec2.at(j).second)) {
                 cerr << "Error : Var decl diff(Lvalue diff) found on vec2 diff line. Merging aborted." << endl;
                 normalCompletion = false;
                 hasLvalue |= isLvalueNode(ndVec2, tmpVec2.at(j).second);
            }
        }
        if(hasLvalue) return emptyVec;

    }

    vector<int> tmpIntVec;

    for(int i=0; i<diffLine.size(); i++){
        if(lineParenthesisChk(ndVec1, c1.from+diffLine.at(i)-lineOffset1) == 1 && lineParenthesisChk(ndVec2, c2.from+diffLine.at(i)-lineOffset2) == 1){
            if(i<diffLine.size()-1 && diffLine.at(i+1) != diffLine.at(i)+1) continue;
            else{
                //tmpIntVec.push_back(diffLine.at(i)-1);
                //cout << diffLine.at(i) << endl;
                diffLine.insert(diffLine.begin()+i+1, diffLine.at(i)+1);
                i++;
            }
        }
        else if(lineParenthesisChk(ndVec1, c1.from+diffLine.at(i)-lineOffset1) == -1 && lineParenthesisChk(ndVec2, c2.from+diffLine.at(i)-lineOffset2) == -1){
            if(i>0 && diffLine.at(i-1) != diffLine.at(i)-1) continue;
            else{
                //tmpIntVec.push_back(diffLine.at(i)+1);
                //cout << "-1" << endl;
                diffLine.insert(diffLine.begin()+i, diffLine.at(i)-1);
                i++;
            }
        }
    }

    // 구현시 주의사항
    // * 라인 오프셋 주의하여 인자 전달
    // * 알고리즘 종료조건 함수 반환시 전달하여 정상 종료 될 수 있게.

    // return the vector
    return diffLine;
}

void mergeMethod(string fileName, CloneData &c1, CloneData &c2, FtnType &f1, FtnType &f2, bool &normalCompletion){
    
    string newFtnName = f1.ftnName + f2.ftnName;
    // 1. substitute caller function name with new one.

    vector<DiffInfo> diffInfo;

    vector<int> diffLine = getDiff(cloneDatas.front(), cloneDatas.back(), f1, f2, diffInfo, 2, normalCompletion);
    if(diffLine.empty()) {
        cerr << "Diff line empty. Merging method aborted." << endl;
        nc = false;
        return;
    }

    if(diffInfo.size() != diffLine.size()) {
        cerr << "Diff Info parsing error. Merging method aborted." << endl;
        nc = false;
        return;
    }

    // 2. insert procedure branches using if/else statements using flag.
    // use diffLine to get the diff lines
    int tabIdx = c1.cloneSnippet.front().find_first_not_of(" \t\r\n"); // this is for code formatting
    string tabStr = c1.cloneSnippet.front().substr(0, tabIdx);

    // 3. insert flag at the ftn decl.
    // use FtnType to not get new function name & arg name
    string ftnDecl = tabStr;
    for(int i=0; i<f1.modifiers.size(); i++){
        ftnDecl += (f1.modifiers[i] + " ");
    }

    ftnDecl += (f1.returnType + " " + newFtnName + "(");
    for(int i=0; i<f1.ftnArgs.size(); i++){
        ftnDecl += f1.ftnArgs[i].first;
        ftnDecl += " ";
        ftnDecl += f1.ftnArgs[i].second;
        ftnDecl += ", ";
    }
    ftnDecl += "int flag)";
    
    if(f1.exceptions.empty() && f1.bopenLine == 0) ftnDecl += " {";
    // else if(f1.exceptions.empty() && f1.bopenLine != 0) // skip b.c. bracket opener appear next line.
    else if(f1.exceptions.size() == 1 && f1.bopenLine == 0) ftnDecl += " throws " + f1.exceptions.front() + " {";
    else if(f1.exceptions.size() == 1 && f1.bopenLine != 0) ftnDecl += " throws " + f1.exceptions.front();
    else if(f1.exceptions.size() > 1  && f1.bopenLine == 0) {
        ftnDecl += " throws ";
        for(int i=0; i<f1.exceptions.size()-1; i++){
            ftnDecl += f1.exceptions.at(i) + ", ";
        }
        ftnDecl += f1.exceptions.back() + " {";
    } else if(f1.exceptions.size() > 1  && f1.bopenLine != 0) {
        ftnDecl += " throws ";
        for(int i=0; i<f1.exceptions.size()-1; i++){
            ftnDecl += f1.exceptions.at(i) + ", ";
        }
        ftnDecl += f1.exceptions.back();
    }

    // TODO: maybe need to refactor b.c. parenthesis not in first line?
    tempClone.push_back(ftnDecl);

    // check for adjacent clone lines;
    bool adjacent = false;
    bool asserted = false;
    vector<string> cloneDummy1; 
    vector<string> cloneDummy2; // clone dummy for adjacent clone snippets
    vector<string> dummyRear; // dummy to put return stmt on the rear
    string ifOpen;
    int dInfoIdx = 0;

    for(int i=1; i<c1.cloneSize; i++){
        if (!intVecContains(diffLine, i)) {
            // Flag 값에 대한 Assertion 삽입
            // Merge case가 2개인 경우에 대한 Flag Assertion
            if(!asserted && f1.bopenLine == 0) {
                bool strFnd = false;
                int strIdx = i;
                while(!strFnd && strIdx<c1.cloneSize){
                    if(strOnlySpaces(c1.cloneSnippet[strIdx])) strIdx++;
                    else strFnd = true;
                }
                if(!strFnd) { 
                    cerr << "Error : String parse error on processing assertion insertion." << endl;
                    return;
                }
                tabIdx = c1.cloneSnippet[strIdx].find_first_not_of(" \t\r\n"); // this is for code formatting
                tabStr = c1.cloneSnippet[strIdx].substr(0, tabIdx);
                string assertStr = tabStr + "assert flag >= 0 && flag <= 1;";
                tempClone.push_back(assertStr);
                asserted = true;
            } else if(!asserted && f1.bopenLine != 0 && i>1) {
                bool strFnd = false;
                int strIdx = i;
                while(!strFnd && strIdx<c1.cloneSize){
                    if(strOnlySpaces(c1.cloneSnippet[strIdx])) strIdx++;
                    else strFnd = true;
                }
                if(!strFnd) { 
                    cerr << "Error : String parse error on processing assertion insertion." << endl;
                    return;
                }
                tabIdx = c1.cloneSnippet[strIdx].find_first_not_of(" \t\r\n"); // this is for code formatting
                tabStr = c1.cloneSnippet[strIdx].substr(0, tabIdx);
                string assertStr = tabStr + "assert flag >= 0 && flag <= 1;";
                tempClone.push_back(assertStr);
                asserted = true;
            }

            tempClone.push_back(c1.cloneSnippet[i]);
        }
        else {
            tabIdx = c1.cloneSnippet[i].find_first_not_of(" \t\r\n"); // this is for code formatting
            tabStr = c1.cloneSnippet[i].substr(0, tabIdx);
            string retStr = tabStr;

            // NOTE
            // Statement 분기 알고리즘
            // 한 줄 분기 -> Var Decl 아닌 경우 - 그대로
            //          -> Var Decl 인 경우 - Ref 타입은 분기문 위로 변수 선언을 빼서 null로 초기화 후 assign은 분기에 각각
            //                             - Prmtv 타입은 bool일 때 false로, 나머지는 0으로 초기화 후 assign은 분기에 각각
            // 여러 줄 분기 -> 위와 상동. Var Decl 변수 선언 모두 모아서 분기문 위쪽으로 올리기.
            if (diffInfo.at(dInfoIdx).diffType == 2) {
                string declStr = tabStr;

                if (diffInfo.at(dInfoIdx).isRef) {
                    declStr += diffInfo.at(dInfoIdx).typeName + " " + diffInfo.at(dInfoIdx).varName + " = null;";
                } else {
                    if (diffInfo.at(dInfoIdx).typeName == "boolean") {
                        declStr += diffInfo.at(dInfoIdx).typeName + " " + diffInfo.at(dInfoIdx).varName + " = false;";
                    } else {
                        declStr += diffInfo.at(dInfoIdx).typeName + " " + diffInfo.at(dInfoIdx).varName + " = 0;";
                    }
                }

                dInfoIdx++;
                tempClone.push_back(declStr);
            } else if (diffInfo.at(dInfoIdx).diffType == 1){
                if (f1.rTypeRef) {
                    retStr += "else return null;";
                } else {
                    if (f1.returnType == "boolean") {
                        retStr += "else return false;";
                    } else {
                        retStr += "else return 0;";
                    }
                }

                dInfoIdx++;
            } else {
                dInfoIdx++;
            }

            // Return 문 분기 알고리즘
            // 위와 상동. Var Decl과 다르게, 함수의 반환 타입 보고 이건 분기 아래로 빼야 함.

            if(!adjacent){
            // 처음 중복 라인 찾아서 브랜치 나누는 경우
                if(i<c1.cloneSize-1 && intVecContains(diffLine, i+1)){
                // 마지막 라인이 아니면서 뒤에 인접한 중복 라인 존재시

                    // Statement 분기가 여러 줄인 경우
                    
                    if (diffInfo.at(dInfoIdx-1).diffType == 2){
                        cloneDummy1.push_back(tabStr + "if (flag == 0){ ");
                        cloneDummy2.push_back(tabStr + "else if (flag == 1){ ");
                        int varIdx1 = c1.cloneSnippet[i].find(diffInfo.at(dInfoIdx-1).varName, tabIdx+diffInfo.at(dInfoIdx-1).typeName.size());
                        int varIdx2 = c2.cloneSnippet[i].find(diffInfo.at(dInfoIdx-1).varName, tabIdx+diffInfo.at(dInfoIdx-1).typeName.size());
                        cloneDummy1.push_back(tabStr + c1.cloneSnippet[i].substr(varIdx1));
                        cloneDummy2.push_back(tabStr + c2.cloneSnippet[i].substr(varIdx2));
                    } else {
                        cloneDummy1.push_back(tabStr + "if (flag == 0){ ");
                        cloneDummy2.push_back(tabStr + "else if (flag == 1){ ");
                        cloneDummy1.push_back(tabStr + c1.cloneSnippet[i]);
                        cloneDummy2.push_back(tabStr + c2.cloneSnippet[i]);
                        if (diffInfo.at(dInfoIdx-1).diffType == 1) dummyRear.push_back(retStr);
                    }
                    ifOpen = tabStr;
                    adjacent = true;
                } else {

                    // Statement 분기가 한 줄인 경우

                    if (diffInfo.at(dInfoIdx-1).diffType == 2){
                        int varIdx1 = c1.cloneSnippet[i].find(diffInfo.at(dInfoIdx-1).varName, tabIdx+diffInfo.at(dInfoIdx-1).typeName.size());
                        int varIdx2 = c2.cloneSnippet[i].find(diffInfo.at(dInfoIdx-1).varName, tabIdx+diffInfo.at(dInfoIdx-1).typeName.size());
                        tempClone.push_back(tabStr + "if (flag == 0) " + c1.cloneSnippet[i].substr(varIdx1));
                        tempClone.push_back(tabStr + "else if (flag == 1) " + c2.cloneSnippet[i].substr(varIdx2));
                    } else {
                        tempClone.push_back(tabStr + "if (flag == 0) " + c1.cloneSnippet[i].substr(tabIdx));
                        tempClone.push_back(tabStr + "else if (flag == 1) " + c2.cloneSnippet[i].substr(tabIdx));                    
                        if (diffInfo.at(dInfoIdx-1).diffType == 1) tempClone.push_back(retStr);
                    }
                }

            } else {
            // 이미 인접한 중복 라인을 찾아서 브랜치 나누는 경우(parenthesis 안에 존재)
                if(i<c1.cloneSize-1 && intVecContains(diffLine, i+1)){
                // 마지막 라인이 아니면서 뒤에 인접한 중복 라인 존재시
                    if (diffInfo.at(dInfoIdx-1).diffType == 2) {
                        int varIdx1 = c1.cloneSnippet[i].find(diffInfo.at(dInfoIdx-1).varName, tabIdx+diffInfo.at(dInfoIdx-1).typeName.size());
                        int varIdx2 = c2.cloneSnippet[i].find(diffInfo.at(dInfoIdx-1).varName, tabIdx+diffInfo.at(dInfoIdx-1).typeName.size());
                        cloneDummy1.push_back(tabStr + c1.cloneSnippet[i].substr(varIdx1));
                        cloneDummy2.push_back(tabStr + c2.cloneSnippet[i].substr(varIdx2));
                    } else {
                        cloneDummy1.push_back(c1.cloneSnippet[i]);
                        cloneDummy2.push_back(c2.cloneSnippet[i]);
                        if (diffInfo.at(dInfoIdx-1).diffType == 1) dummyRear.push_back(retStr);                    
                    }
                } else {

                    if (diffInfo.at(dInfoIdx-1).diffType == 2) {
                        int varIdx1 = c1.cloneSnippet[i].find(diffInfo.at(dInfoIdx-1).varName, tabIdx+diffInfo.at(dInfoIdx-1).typeName.size());
                        int varIdx2 = c2.cloneSnippet[i].find(diffInfo.at(dInfoIdx-1).varName, tabIdx+diffInfo.at(dInfoIdx-1).typeName.size());
                        cloneDummy1.push_back(tabStr + c1.cloneSnippet[i].substr(varIdx1));
                        cloneDummy1.push_back(ifOpen + "}");
                        cloneDummy2.push_back(tabStr + c2.cloneSnippet[i].substr(varIdx2));
                        cloneDummy2.push_back(ifOpen + "}");
                    } else {
                        cloneDummy1.push_back(c1.cloneSnippet[i]);
                        cloneDummy1.push_back(ifOpen + "}");
                        cloneDummy2.push_back(c2.cloneSnippet[i]);
                        cloneDummy2.push_back(ifOpen + "}");
                        if (diffInfo.at(dInfoIdx-1).diffType == 1) dummyRear.push_back(retStr);
                    }

                    // vector1.insert( vector1.end(), vector2.begin(), vector2.end() );
                    tempClone.insert(tempClone.end(), cloneDummy1.begin(), cloneDummy1.end());
                    tempClone.insert(tempClone.end(), cloneDummy2.begin(), cloneDummy2.end());
                    tempClone.insert(tempClone.end(), dummyRear.begin(), dummyRear.end());

                    cloneDummy1.clear();
                    cloneDummy2.clear();      
                    dummyRear.clear();      
                    adjacent = false;              
                }
            }
        }
    }

    ifstream pfile(c1.fileName.c_str());
    string line;

    int lineCnt = 1; // line counter
    while(getline(pfile, line)) {
        if(lineCnt == c1.from) patchCode.insert(patchCode.end(), tempClone.begin(), tempClone.end());
        if(lineCnt == c2.to + 1) {
            if(strOnlySpaces(line)) { lineCnt++; continue; }
        }
        if(!(lineCnt >= c1.from && lineCnt <= c1.to) && !(lineCnt >= c2.from && lineCnt <= c2.to)) patchCode.push_back(line);
        
        lineCnt++;
    }

    afterPatchLoc = patchCode.size();
    
    if (runOption != COD){
        cout << "Merging clone..." << endl;
        cout << "Clone part 1,2 merged to one ftn." << endl << endl;
        testPrintCode(tempClone);
    }

    if (runOption != RST){
        cout << endl << "========================================" << endl;
        cout << "Patching clones ...\n";
        cout << "(This will be replaced with actual file write operations)\n";
        testPrintCode(patchCode); // TODO: need to replace this with file write operations
    }


    // Caller patch 부분
    // TODO: 옵션에 따라 실행되도록 분기 삽입

    string cname;
    fetchClassName(c1.fileName, cname);
    string fname1 = f1.ftnName;
    string fname2 = f2.ftnName;

    // TODO: 3. 입력으로 Callee cname/fname을 주고 해당하는 Caller 정보 (call cnt, cname, fname) 모으기 
    // getCallerInfo : ( calleeCname * calleeFname * callGraph ) -> ( Caller[] )
    vector<Caller> callerVec1, callerVec2;
    getCallerInfo(cname, fname1, callGraphVec, callerVec1);
    getCallerInfo(cname, fname2, callGraphVec, callerVec2);

    //for all callers.
    if(callerVec1.empty()) cout << "ftn1. No callers to patch." << endl;

    for(int i=0; i<callerVec1.size(); i++){
        cout << "ftn1." << callerVec1.size() << " Callers to patch." <<  endl;
        // 4. 2번의 맵을 이용하여 Caller의 실제 경로를 찾기
        int argCnt;
        if(mapFullPath(fpath2CnamePairVec, callerVec1.at(i).fileName, callerVec1.at(i).callerObjectName, callerVec1.at(i).realPath)) {
            cout << "Path found! : " << callerVec1.at(i).realPath << endl;
        }
        cout << callerVec1.at(i).argNum << endl;

        // TODO: 5. 찾은 Caller의 실제 파일위치와 Caller 정보 이용해서 Caller 패치해주기
        patchCaller(callerVec1.at(i), fname1, newFtnName, 0);
    }

    //for all callers.
    if(callerVec2.empty()) cout << "ftn2. No callers to patch." << endl;

    for(int i=0; i<callerVec2.size(); i++){
        cout << "ftn2." << callerVec2.size() << " Callers to patch." <<  endl;
        // 4. 2번의 맵을 이용하여 Caller의 실제 경로를 찾기
        int argCnt;
        if(mapFullPath(fpath2CnamePairVec, callerVec2.at(i).fileName, callerVec2.at(i).callerObjectName, callerVec2.at(i).realPath)) {
            cout << "Path found! : " << callerVec2.at(i).realPath << endl;
        }
        cout << callerVec2.at(i).argNum << endl;

        // TODO: 5. 찾은 Caller의 실제 파일위치와 Caller 정보 이용해서 Caller 패치해주기
        patchCaller(callerVec2.at(i), fname2, newFtnName, 1);
    }

}



/*
 * ====================================================
 * ======= FUNCTIONS FOR TYPE 3(PASS FTN ARG) =========
 * ====================================================
 */

void getPrmtv2ObjMap()
{
    // Boolean, Byte, Character, Double, Float, Integer, Long, Short, Void.
    // prmtv2ObjMap
    prmtv2ObjMap["boolean"] = "Boolean";
    prmtv2ObjMap["byte"] = "Byte";
    prmtv2ObjMap["char"] = "Character";
    prmtv2ObjMap["double"] = "Double";
    prmtv2ObjMap["float"] = "Float";
    prmtv2ObjMap["int"] = "Integer";
    prmtv2ObjMap["long"] = "Long";
    prmtv2ObjMap["short"] = "Short";
    prmtv2ObjMap["void"] = "Void";
}

bool isPrmtv(string tname){
    return (tname == "boolean" || tname == "byte" || tname == "char" || tname == "double" ||
            tname == "float" || tname == "int" || tname == "long" || tname == "short" || tname == "void");
}

bool errCheck(bool condition, bool &nc, string errMessage){
    // 에러 컨디션 체크 위한 함수.
    // condition이 true면 true 반환, 받아서 함수 종료.
    if(condition) {
        cerr << errMessage << endl;
        nc = false;
        return true; // return true if error.
    } else {
        return false;
    }
}

// TODO: rename function
// 이 함수는 함수 인자 전달하기 위한 토큰 확인용 함수
bool getDiffTok2Patch(CloneData &c1, CloneData &c2, vector<NodeData> &ndVec1, vector<NodeData> &ndVec2, int lineOffset1, int lineOffset2,
                    vector<FtnData> &fdVec, int diffLine, bool &normalCompletion, vector<string> &argTokVec, vector<string> &f1nameVec, vector<string> &f2nameVec){

    vector<NodeData> diffNdVec1 = findNodeByLineWithNt(ndVec1, c1.from - lineOffset1 + diffLine);
    vector<NodeData> diffNdVec2 = findNodeByLineWithNt(ndVec2, c2.from - lineOffset2 + diffLine);

    // 2-2. diff line에서 rhs nodeVec 토큰 빼기
    // Method invocation에 해당하는 노드 표기하기 (isFtnCall)
    // 알고리즘 제약 조건 : rhs 토큰 수 같아야, 함수 이름만 다르고 인자 등 다 같은 케이스만 발동.
    vector<NodeData> rhsNdVec1 = getRhsTnodeVec(diffNdVec1);
    vector<NodeData> rhsNdVec2 = getRhsTnodeVec(diffNdVec2);
    vector<NodeData> lhsNdVec1 = getLhsTnodeVec(diffNdVec1);
    vector<NodeData> lhsNdVec2 = getLhsTnodeVec(diffNdVec2);

    if(rhsNdVec1.size() != rhsNdVec2.size() && lhsNdVec1.size() != lhsNdVec2.size()) {
        cout << "T3 can only patch lhs or rhs code with same tok count" << endl;
        return false;
    }

    // rhs의 토큰들 비교
    int diffTok; 
    int diffTokCnt = 0;
    for(int i=0; i<rhsNdVec1.size(); i++){
        if(rhsNdVec1.at(i).label == rhsNdVec2.at(i).label) continue;
        else {
            diffTokCnt++;
            if(rhsNdVec1.at(i).isFtnCall == rhsNdVec2.at(i).isFtnCall) diffTok = i;
        }
    }
    if(diffTokCnt > 1) {
        cout << "T3 can only patch rhs code with one ftn call diff" << endl;
        return false;
    }

    // 3. 만약, 맞을 경우 rhs의 diff 토큰에 해당하는 diff 함수가 local 함수 call인지 찾는다.
    int f1idx = 0;
    int f2idx = 0;
    bool f1fnd = false;
    bool f2fnd = false;

    for(int i=0; i<fdVec.size(); i++){
        if(fdVec.at(i).ftnName == rhsNdVec1.at(diffTok).label) {
            f1fnd = true;
            f1idx = i;
            f1nameVec.push_back(rhsNdVec1.at(diffTok).label);
        }
        if(fdVec.at(i).ftnName == rhsNdVec2.at(diffTok).label) {
            f2fnd = true;
            f2idx = i;
            f2nameVec.push_back(rhsNdVec2.at(diffTok).label);
        }
    }

    if(!f1fnd || !f2fnd) {
        cout << "T3 patching error : T3 can only patch local ftn call diffs." << endl;
        return false;
    }

    FtnType f1type, f2type;
    vector<NodeData> fndVec1, fndVec2;
    getFtnSubtree(c1.fileName, f1nameVec.front(), fndVec1);
    parseFtnType(c1.fileName, f1nameVec.front(), f1type, fndVec1);
    getFtnSubtree(c1.fileName, f2nameVec.front(), fndVec2);
    parseFtnType(c1.fileName, f2nameVec.front(), f2type, fndVec2);

    // 4. 두 diff part에 해당하는 함수 (ex. hi1,hi2)가 타입이 같은 지 확인한다.
    // TODO: 수정필요 : compFtype() 함수는 어노테이션과 예외까지 비교, T3 알고리즘은 in/out 타입만 보기 때문에 문제 있을 수도.
    bool diffFtnTypeEq = compFtype(f1type, f2type);
    if(!diffFtnTypeEq) {
        cout << "T3 patching error : diff ftns must have same type." << endl;
        return false;
    }

    // 5. 해당 함수에 각각 전달되는 인자가 같은 지 확인한다.
    // 위에서 함수 diff외 인자 및 다른 요소는 같은 것으로 판단하고 진행.
    // 여기는 토큰 비교에서 이미 같은 것 확인하였으므로 인자 추출하는 것만 사용.

    // 5.1. rhsNdVec1에서 앞 인덱스부터 시작해서 bopen('(') 인덱스 찾기
    int bopenIdx = 0;
    bool bopenFnd = false;
    for(int i=0; i<rhsNdVec1.size(); i++){
        if(rhsNdVec1.at(i).label == "(") {
            bopenIdx = i;
            bopenFnd = true;
            break;
        }
    }
    // 5.2. rhsNdVec1에서 앞 인덱스부터 시작해서 bclose(')') 인덱스 찾기
    int bcloseIdx = 0;
    bool bcloseFnd = false;
    for(int i=rhsNdVec1.size()-1; i>=0; i--){
        if(rhsNdVec1.at(i).label == ")") { 
            bcloseIdx = i;
            bcloseFnd = true;
            break;    
        }
    }
    if(!bopenFnd || !bcloseFnd || (bopenIdx >= bcloseIdx)) {
        cout << "T3 patching error : cannot find args in diff ftn" << endl;
        return false;
    }

    // 5.3. bopen과 bclose 안에 들어있는 인자 토큰 뽑아내고 비교하기
    string argTok = "";
    for(int i=bopenIdx+1; i<bcloseIdx; i++){
        argTok += rhsNdVec1.at(i).label;
    }
    argTokVec.push_back(argTok);

    return true;
}

// TODO: rename function
void t3CodePatch(string fileName, CloneData &c1, CloneData &c2, FtnType &f1, FtnType &f2, bool &normalCompletion){

    // T3 함수 인자 전달식 패치 알고리즘 정리(초안)
    // 제약조건
    // * 여기서 hi1/hi2 : int -> int 로 같은 타입이어야 한다.
    // * T2와 마찬가지로 두 함수의 타입이 같을 때 발동, 인자로 함수 전달시 호출 객체의 이름을 Caller 패치시 줘야함.
    // * 함수 인자로 전달하는 함수는 Local(같은 파일 내 정의된 것) 함수이어야 한다.

    // 구현 알고리즘 추가 (18.10.25 - 제네릭 타입 diff에 대한 패치)
    // 구현 알고리즘 (case#1 단순 rhs 함수 인자 전달, case#2 rhs 함수와 lhs의 제네릭 타입 인자 전달)
    // 1. 파일을 파싱하여 파일 내 함수이름과 해당 함수의 타입을 전부 모은다.
    // 2-a. diff되는 부분이 var decl의 rhs에 있는 assignment인지 확인한다. (rhs diff)
    // 2-b. diff되는 부분이 var decl인데 변수의 이름이 같고 제네릭 타입 인자만 다르면서 rhs의 assignment만 다른지 확인.
    // 3. 만약, 맞을 경우 이 것에 해당하는 diff 함수가 local 함수 call인지 찾는다.(local 함수가 overload된 경우는 일단 고려하지 않는다.)
    // 4-a. 두 diff part에 해당하는 함수 (ex. hi1,hi2)가 타입이 같은 지 확인한다.
    // 4-b. 두 diff part에 해당하는 함수 (ex. hi1,hi2)가 리턴타입이 제네릭 타입의 인자와 같은 지 확인한다.
    // 5. 해당 함수에 각각 전달되는 인자가 같은 지 확인한다.
    //     - TODO: 인자가 달라도 상관없으나, 일단은 인자까지 같은 것으로 파악하여 구현하고 추후 확장.
    // 6. f,g를 합친 fg함수를 생성하고 중복 부분을 뽑아내고 함수의 인자는 람다 타입으로 준다.
    // 7. f,g의 중복부분을 fg call로 대치하고, 함수의 인자로 각각 hi1과 hi2를 준다.

    // T2 merge method와 병합된 알고리즘 
    string newFtnName = f1.ftnName + f2.ftnName; // 새 함수 이름
    
    // 코드 포맷 맞추기용 whitespace string
    int tabIdx = c1.cloneSnippet.front().find_first_not_of(" \t\r\n"); // this is for code formatting
    string tabStr = c1.cloneSnippet.front().substr(0, tabIdx);

    // 1. 파일을 파싱하여 파일 내 함수이름과 해당 함수의 타입을 전부 모은다.
    vector<FtnData> fdVec;    
    getAllFtnData(fileName, fdVec);

    // 2-a. diff되는 부분이 var decl의 rhs에 있는 assignment인지 확인한다. (일단 1개짜리만)
    // 2-b. diff되는 부분이 var decl인데 변수의 이름이 같고 제네릭 타입 인자만 다르면서 rhs의 assignment만 다른지 확인.
    vector<DiffInfo> diffInfo;
    vector<int> diffLine = getDiff(cloneDatas.front(), cloneDatas.back(), f1, f2, diffInfo, 3, normalCompletion);

    if(errCheck(diffLine.empty(), nc, "Diff line empty. T3 code patch aborted.")) return;
    if(errCheck(diffInfo.size() != diffLine.size(), nc, "Diff Info parsing error. Merging method aborted.")) return;    //if(errCheck(diffLine.size() > 1, nc, "T3 can only patch one line diff yet.")) return;
    bool allDiffAssign = true;
    for(int i=0; i<diffInfo.size(); i++) allDiffAssign &= ((diffInfo.at(i).diffType == 2) || (diffInfo.at(i).diffType == 3));
    if(errCheck(!allDiffAssign, nc, "T3 can only var decl && assign expr line diff")) return;

    // 2-1-a. rhs nodeVec 가져와서 비교하고 함수 호출부만 다른 경우인지 확인. 
    // 2-1-a. lhs의 변수의 이름이 같고 제네릭 타입 인자만 다르면서 rhs nodeVec 가져와서 비교하고 함수 호출부만 다른 경우인지 확인. 
    // 함수의 전달 인자는 같아야함. 
    // 호출 함수의 타입은 같아야함.
    vector<NodeData> ndVec1;
    vector<NodeData> ndVec2;
    getFtnSubtree(c1.fileName, f1.ftnName, ndVec1);
    getFtnSubtree(c1.fileName, f2.ftnName, ndVec2);
    int lineOffset1 = getLineOffset(ndVec1, f1.ftnName, c1.from);
    int lineOffset2 = getLineOffset(ndVec2, f2.ftnName, c2.from);    

    bool isMultiLinePatch = false;
    string argTok;
    int f1idx, f2idx;

    vector<string> argTokVec;
    vector<string> f1nameVec, f2nameVec;

    if(diffLine.size() == 1){
        // 라인 하나 패치하는 경우
        bool comp = getDiffTok2Patch(c1, c2, ndVec1, ndVec2, lineOffset1, lineOffset2, fdVec, 
                                    diffLine.front(), nc, argTokVec, f1nameVec, f2nameVec);
        if(!comp) return;
        argTok = argTokVec.front();
    } else{
        // 여러 라인 패치하는 경우
        bool comp = true;
        for(int i=0; i<diffLine.size(); i++){
            comp &= getDiffTok2Patch(c1, c2, ndVec1, ndVec2, lineOffset1, lineOffset2, fdVec, 
                                    diffLine.at(i), nc, argTokVec, f1nameVec, f2nameVec);
        }
        isMultiLinePatch = true;
        // TODO: 여기서 마저 함수 라인 보고 패치 재개하기
        // TODO: f1vec, f2vec은 같은 함수 이름이어야. 가드 넣을것
        // TODO: Local 함수 인 것들만 받아들이도록. 가드 넣을것
    }

    FtnType f1type, f2type;
    vector<NodeData> f1ndVec, f2ndVec;
    getFtnSubtree(c1.fileName, f1nameVec.front(), f1ndVec);
    parseFtnType(c1.fileName, f1nameVec.front(), f1type, f1ndVec);
    getFtnSubtree(c1.fileName, f2nameVec.front(), f2ndVec);
    parseFtnType(c1.fileName, f2nameVec.front(), f2type, f2ndVec);
    // f1type과 f2type은 같아야 한다.

    getPrmtv2ObjMap(); // fptr로 넘길 함수의 인자 타입을 Prmtv에서 Obj로 바꿀 맵 사용.
    string passArg;
    string asnStr;
    vector<string> asnStrVec; // 패치 라인이 여러개일 때 사용

    string argFtnRtype = f1type.returnType; // fptr로 넘길 ftn의 리턴 타입
    string argFtnRObjtype = f1type.returnType;
    if(isPrmtv(argFtnRtype)) argFtnRObjtype = prmtv2ObjMap[argFtnRtype];

    string argFtnAtype, argFtnAObjtype; // fptr로 넘길 ftn의 첫번째 인자 타입
    string argFtnAtype2, argFtnAObjtype2; // fptr로 넘길 ftn의 두번째 인자 타입

    if(f1type.ftnArgs.size() == 0){
        // 함수 인자가 0개인 경우 java.util.function.Function 사용
        passArg = "java.util.function.Function<Void, " + argFtnRObjtype + "> fptr";
    } else if(f1type.ftnArgs.size() == 1){
        // 함수 인자가 1개인 경우 java.util.function.Function 사용
        argFtnAtype = f1type.ftnArgs.front().first; // fptr로 넘길 ftn의 첫번째 인자 타입
        argFtnAObjtype = f1type.ftnArgs.front().first;
        if(isPrmtv(argFtnAtype)) argFtnAObjtype = prmtv2ObjMap[argFtnAtype];
        passArg = "java.util.function.Function<" + argFtnAObjtype + ", " + argFtnRObjtype + "> fptr";
    } else if(f1type.ftnArgs.size() == 2){
        // 함수 인자가 2개인 경우 java.util.function.BiFunction 사용
        argFtnAtype = f1type.ftnArgs.front().first; // fptr로 넘길 ftn의 첫번째 인자 타입
        argFtnAObjtype = f1type.ftnArgs.front().first;
        if(isPrmtv(argFtnAtype)) argFtnAObjtype = prmtv2ObjMap[argFtnAtype];
        argFtnAtype2 = f1type.ftnArgs.back().first; // fptr로 넘길 ftn의 첫번째 인자 타입
        argFtnAObjtype2 = f1type.ftnArgs.back().first;
        if(isPrmtv(argFtnAtype2)) argFtnAObjtype2 = prmtv2ObjMap[argFtnAtype];
        passArg = "java.util.function.BiFunction<" + argFtnAObjtype + ", " + argFtnAObjtype2 + ", " + argFtnRObjtype + "> fptr";
    } else {
        cerr << "T3 cannot patch diff line ftn with more than 2 args" << endl;
        nc = false;
        return;
    }

    if(!isMultiLinePatch) {
        // 한줄 패치를 할 경우

        // 6. f,g를 합친 fg함수를 생성하고 중복 부분을 뽑아내고 함수의 인자는 람다 타입으로 준다.
        // 6.1. 추출하는 함수의 타입을 판정하여 람다로 전달. 함수 선언부 구현
        if(diffInfo.front().diffType == 2){
            // diff line에 Var decl lhs에 해당하는 타입이 반환 타입이 된다.
            int tabIdx2 = c1.cloneSnippet.at(diffLine.front()).find_first_not_of(" \t\r\n");
            string tabStr2 = c1.cloneSnippet.at(diffLine.front()).substr(0, tabIdx2);
            if (f1type.ftnArgs.size() == 0) {
                asnStr = tabStr2 + diffInfo.front().typeName + " " + diffInfo.front().varName
                                + " = fptr.apply(null);";
            } else {
                asnStr = tabStr2 + diffInfo.front().typeName + " " + diffInfo.front().varName
                                + " = fptr.apply(" + argTok + ");";
            }
            
            // 해당 람다 함수 적용 라인 가지고 있다가 추후, 패치시 넣기
        } else if(diffInfo.front().diffType == 3){
            // diff line이 Assign Expr 일 경우
            int tabIdx2 = c1.cloneSnippet.at(diffLine.front()).find_first_not_of(" \t\r\n");
            string tabStr2 = c1.cloneSnippet.at(diffLine.front()).substr(0, tabIdx2);
            if (f1type.ftnArgs.size() == 0) {
                asnStr = tabStr2 + diffInfo.front().varName + " = fptr.apply(null);";
            } else {
                asnStr = tabStr2 + diffInfo.front().varName + " = fptr.apply(" + argTok + ");";
            }
            // 해당 람다 함수 적용 라인 가지고 있다가 추후, 패치시 넣기        
        } 
    } else {
        // 여러라인 패치를 할 경우
        asnStr = "";

        for(int i=0; i<diffInfo.size(); i++){
            // 6. f,g를 합친 fg함수를 생성하고 중복 부분을 뽑아내고 함수의 인자는 람다 타입으로 준다.
            // 6.1. 추출하는 함수의 타입을 판정하여 람다로 전달. 함수 선언부 구현
            if(diffInfo.at(i).diffType == 2){
                // diff line에 Var decl lhs에 해당하는 타입이 반환 타입이 된다.
                int tabIdx2 = c1.cloneSnippet.at(diffLine.at(i)).find_first_not_of(" \t\r\n");
                string tabStr2 = c1.cloneSnippet.at(diffLine.at(i)).substr(0, tabIdx2);
                if (f1type.ftnArgs.size() == 0) {
                    asnStr = tabStr2 + diffInfo.at(i).typeName + " " + diffInfo.at(i).varName
                                    + " = fptr.apply(null);";
                } else {
                    asnStr = tabStr2 + diffInfo.at(i).typeName + " " + diffInfo.at(i).varName
                                    + " = fptr.apply(" + argTokVec.at(i) + ");";
                }
                asnStrVec.push_back(asnStr);
                // 해당 람다 함수 적용 라인 가지고 있다가 추후, 패치시 넣기
            } else if(diffInfo.at(i).diffType == 3){
                // diff line이 Assign Expr 일 경우
                int tabIdx2 = c1.cloneSnippet.at(diffLine.at(i)).find_first_not_of(" \t\r\n");
                string tabStr2 = c1.cloneSnippet.at(diffLine.at(i)).substr(0, tabIdx2);
                if (f1type.ftnArgs.size() == 0) {
                    asnStr = tabStr2 + diffInfo.at(i).varName + " = fptr.apply(null);";
                } else {
                    asnStr = tabStr2 + diffInfo.at(i).varName + " = fptr.apply(" + argTokVec.at(i) + ");";
                }
                asnStrVec.push_back(asnStr);
                // 해당 람다 함수 적용 라인 가지고 있다가 추후, 패치시 넣기        
            } 
        }
    }

    // 함수 정의부 새로 선언
    string ftnDecl = tabStr;
    for(int i=0; i<f1.modifiers.size(); i++){
        ftnDecl += (f1.modifiers[i] + " ");
    }
    ftnDecl += (f1.returnType + " " + newFtnName + "(");
    for(int i=0; i<f1.ftnArgs.size(); i++){
        ftnDecl += f1.ftnArgs[i].first;
        ftnDecl += " ";
        ftnDecl += f1.ftnArgs[i].second;
        ftnDecl += ", ";
    }
    ftnDecl += passArg + ")"; 
    
    // 함수 정의부 뒤 Exception throw 부분
    if(f1.exceptions.empty() && f1.bopenLine == 0) ftnDecl += " {";
    // else if(f1.exceptions.empty() && f1.bopenLine != 0) // skip b.c. bracket opener appear next line.
    else if(f1.exceptions.size() == 1 && f1.bopenLine == 0) ftnDecl += " throws " + f1.exceptions.front() + " {";
    else if(f1.exceptions.size() == 1 && f1.bopenLine != 0) ftnDecl += " throws " + f1.exceptions.front();
    else if(f1.exceptions.size() > 1  && f1.bopenLine == 0) {
        ftnDecl += " throws ";
        for(int i=0; i<f1.exceptions.size()-1; i++){
            ftnDecl += f1.exceptions.at(i) + ", ";
        }
        ftnDecl += f1.exceptions.back() + " {";
    } else if(f1.exceptions.size() > 1  && f1.bopenLine != 0) {
        ftnDecl += " throws ";
        for(int i=0; i<f1.exceptions.size()-1; i++){
            ftnDecl += f1.exceptions.at(i) + ", ";
        }
        ftnDecl += f1.exceptions.back();
    }
    tempClone.push_back(ftnDecl);

    int asnCnt = 0;

    for(int i=1; i<c1.cloneSize; i++){
        if (!intVecContains(diffLine, i)) {
            // Diff 부분이 아닌 중복 부분
            if(i == f1.bopenLine && f1.bopenLine == 1) {
                tempClone.push_back(tabStr+"{");
                continue; // Bracket opener line 건너 뛰기
            }
            tempClone.push_back(c1.cloneSnippet[i]);
        } else {
            // TODO: T2에서는 분기 삽입부. T3에서 Lambda 함수 호출로 구분
            // TODO: 다른 값이 : 1) Ftn Call 2) Var Type 이 세개 잘 구분해서 구현하기
            // 일단 초기 버전으로는 1) Ftn Call이 다른 경우, 함수 인자 전달 방식으로 구현하기. 18.11.01
            if(!isMultiLinePatch) tempClone.push_back(asnStr);
            else { 
                tempClone.push_back(asnStrVec.at(asnCnt));
                asnCnt++;
            }

        }
    }

    testPrintCode(tempClone);

    string ftnArg1;
    string ftnArg2;

    if(f1type.ftnArgs.size() == 0){
        ftnArg1 = "((a) -> " + f1type.ftnName + "())";
        ftnArg2 = "((a) -> " + f2type.ftnName + "())";
    } else if(f1type.ftnArgs.size() == 1){
        ftnArg1 = "((a) -> " + f1type.ftnName + "(a))";
        ftnArg2 = "((a) -> " + f2type.ftnName + "(a))";
    } else if(f1type.ftnArgs.size() == 2){
        ftnArg1 = "((a, b) -> " + f1type.ftnName + "(a, b))";    
        ftnArg2 = "((a, b) -> " + f2type.ftnName + "(a, b))";
    }

    cout << endl;
    cout << " ===== Caller Ftn Args ===== " << endl;
    cout << " C#1 : " << ftnArg1 << endl;
    cout << " C#2 : " << ftnArg2 << endl;


    /* int patchtype; // 0 : rhs diff만 있는 경우. 1 : lhs diff가 있는데 제네릭 타입인 경우.

    // 구현 알고리즘

    // 2-a. diff되는 부분이 var decl의 rhs에 있는 assignment인지 확인한다. (일단 1개짜리만)
    // 2-b. diff되는 부분이 var decl인데 변수의 이름이 같고 제네릭 타입 인자만 다르면서 rhs의 assignment만 다른지 확인.
    //  - TODO: 추후 제네릭을 이용한 Lvalue 경우에 대한 패치도 확장 예정.
    vector<DiffInfo> diffInfo;
    vector<int> diffLine = getDiff(cloneDatas.front(), cloneDatas.back(), f1, f2, diffInfo, 3, normalCompletion); // TODO: refactor this?
    if(diffLine.empty()) {
        cerr << "Diff line empty. T3 code patch aborted." << endl;
        nc = false;
        return;
    }

    if(diffLine.size() > 1) {
        // TODO: 일단 현재 구현은 1라인 Diff만, 추후 구현 확장할 것.
        cerr << "T3 can only patch one line diff yet." << endl;
        nc = false;
        return;
    }

    if(diffInfo.front().diffType != 2) {
        cerr << "T3 can only var decl line diff" << endl;
        nc = false;
        return;
    }

    // 2-1-a. rhs nodeVec 가져와서 비교하고 함수 호출부만 다른 경우인지 확인. 
    // 2-1-a. lhs의 변수의 이름이 같고 제네릭 타입 인자만 다르면서 rhs nodeVec 가져와서 비교하고 함수 호출부만 다른 경우인지 확인. 
    // 함수의 전달 인자는 같아야함. 
    // 호출 함수의 타입은 같아야함.

    vector<NodeData> ndVec1;
    vector<NodeData> ndVec2;
    getFtnSubtree(c1.fileName, f1.ftnName, ndVec1);
    getFtnSubtree(c1.fileName, f2.ftnName, ndVec2);
    int lineOffset1 = getLineOffset(ndVec1, f1.ftnName, c1.from);
    int lineOffset2 = getLineOffset(ndVec2, f2.ftnName, c2.from);

    vector<NodeData> diffNdVec1 = findNodeByLineWithNt(ndVec1, c1.from - lineOffset1 + diffLine.front());
    vector<NodeData> diffNdVec2 = findNodeByLineWithNt(ndVec2, c2.from - lineOffset2 + diffLine.front());
    //printNodeVector(diffNdVec1);
    //printNodeVector(diffNdVec2);

    // 2-2. diff line에서 rhs nodeVec 토큰 빼기
    // Method invocation에 해당하는 노드 표기하기 (isFtnCall)
    // 알고리즘 제약 조건 : rhs 토큰 수 같아야, 함수 이름만 다르고 인자 등 다 같은 케이스만 발동.
    vector<NodeData> rhsNdVec1 = getRhsTnodeVec(diffNdVec1);
    vector<NodeData> rhsNdVec2 = getRhsTnodeVec(diffNdVec2);
    vector<NodeData> lhsNdVec1 = getLhsTnodeVec(diffNdVec1);
    vector<NodeData> lhsNdVec2 = getLhsTnodeVec(diffNdVec2);
    //printNodeVector(rhsNdVec1);
    //printNodeVector(rhsNdVec2);

    if(rhsNdVec1.size() != rhsNdVec2.size() && lhsNdVec1.size() != lhsNdVec2.size()){
        // TODO: 커버 케이스 확장하기
        cerr << "T3 can only patch lhs or rhs code with same tok count" << endl;
        nc = false;
        return;
    }

    // rhs의 토큰들 비교
    int diffTok; 
    int diffTokCnt = 0;
    for(int i=0; i<rhsNdVec1.size(); i++){
        if(rhsNdVec1.at(i).label == rhsNdVec2.at(i).label) continue;
        else {
            diffTokCnt++;
            if(rhsNdVec1.at(i).isFtnCall == rhsNdVec2.at(i).isFtnCall) diffTok = i;
        }
    }

    // lhs의 토큰들 비교
    int diffTypeTok = -1; // T3에서 제네릭 타입의 인자가 다른경우에 해당하는 타입 토큰
    int diffTypeTokCnt = 0;
    for(int i=0; i<lhsNdVec1.size(); i++){
        if(lhsNdVec1.at(i).label == lhsNdVec2.at(i).label) continue;
        else {
            diffTypeTokCnt++;
            if(lhsNdVec1.at(i).isGenericTypeArg == lhsNdVec2.at(i).isGenericTypeArg) diffTypeTok = i;
        }
    }

    if(diffTokCnt > 1 && diffTypeTokCnt > 1){
        // TODO: 커버 케이스 확장하기
        cerr << "T3 can only patch rhs code with one ftn call diff" << endl;
        nc = false;
        return;
    }

    if(diffTypeTok == -1) patchtype = 0;
    else patchtype = 1;
    // 0 : rhs diff만 있는 경우. 1 : lhs diff가 있는데 제네릭 타입인 경우.

    // 3. 만약, 맞을 경우 rhs의 diff 토큰에 해당하는 diff 함수가 local 함수 call인지 찾는다.
    // fdVec
    bool f1fnd = false;
    bool f2fnd = false;
    int f1idx = 0;
    int f2idx = 0;
    for(int i=0; i<ftVec.size(); i++){
        if(ftVec.at(i).ftnName == rhsNdVec1.at(diffTok).label) {
            f1fnd = true;
            f1idx = i;
        }
        if(ftVec.at(i).ftnName == rhsNdVec2.at(diffTok).label) {
            f2fnd = true;
            f2idx = i;
        }
    }

    if(!f1fnd || !f2fnd){
        cerr << "T3 patching error : T3 can only patch local ftn call diffs." << endl;
        nc = false;
        return;
    }

    // 4. 두 diff part에 해당하는 함수 (ex. hi1,hi2)가 타입이 같은 지 확인한다.
    // TODO: 수정필요 : compFtype() 함수는 어노테이션과 예외까지 비교, T3 알고리즘은 in/out 타입만 보기 때문에 문제 있을 수도.
    bool diffFtnTypeEq = compFtype(ftVec.at(f1idx), ftVec.at(f2idx));
    if(patchtype == 0 && !diffFtnTypeEq){
        cerr << "T3 patching error : diff ftns must have same type." << endl;
        nc = false;
        return;
    }

    // TODO: 여기서부터 패치 재개하기. patchType:0인 경우에는 원래대로 함수 포인터만 전달. 1인 경우에는 제네릭 타입과 함수 둘다 전달.

    // 5. 해당 함수에 각각 전달되는 인자가 같은 지 확인한다.
    // 위에서 함수 diff외 인자 및 다른 요소는 같은 것으로 판단하고 진행.
    // 여기는 토큰 비교에서 이미 같은 것 확인하였으므로 인자 추출하는 것만 사용.

    // 5.1. rhsNdVec1에서 앞 인덱스부터 시작해서 bopen('(') 인덱스 찾기
    int bopenIdx = 0;
    bool bopenFnd = false;
    for(int i=0; i<rhsNdVec1.size(); i++){
        if(rhsNdVec1.at(i).label == "(") {
            bopenIdx = i;
            bopenFnd = true;
            break;
        }
    }

    // 5.2. rhsNdVec1에서 앞 인덱스부터 시작해서 bclose(')') 인덱스 찾기
    int bcloseIdx = 0;
    bool bcloseFnd = false;
    for(int i=rhsNdVec1.size()-1; i>=0; i--){
        if(rhsNdVec1.at(i).label == ")") { 
            bcloseIdx = i;
            bcloseFnd = true;
            break;    
        }
    }

    if(!bopenFnd || !bcloseFnd || (bopenIdx >= bcloseIdx)){
        cerr << "T3 patching error : cannot find args in diff ftn" << endl;
        nc = false;
        return;
    }

    // 5.3. bopen과 bclose 안에 들어있는 인자 토큰 뽑아내고 비교하기
    string argTok = "";
    for(int i=bopenIdx+1; i<bcloseIdx; i++){
        argTok += rhsNdVec1.at(i).label;
    }

    // 6. f,g를 합친 fg함수를 생성하고 중복 부분을 뽑아내고 함수의 인자는 람다 타입으로 준다.
    int tabIdx = c1.cloneSnippet.front().find_first_not_of(" \t\r\n"); // this is for code formatting
    string tabStr = c1.cloneSnippet.front().substr(0, tabIdx);
    getPrmtv2ObjMap(); // fptr로 넘길 함수의 인자 타입을 Prmtv에서 Obj로 바꿀 맵 사용.

    // 6.1. 추출하는 함수의 타입을 판정하여 람다로 전달. 함수 선언부 구현

    // diff line에 Var decl lhs에 해당하는 타입이 반환 타입이 된다.
    string newFtnName = c1.ftnName + c2.ftnName;
    string argFtnRtype = diffInfo.front().typeName; // fptr로 넘길 ftn의 리턴 타입
    string argFtnRObjtype = diffInfo.front().typeName;
    if(isPrmtv(argFtnRtype)) argFtnRObjtype = prmtv2ObjMap[argFtnRtype];
    
    string argFtnAtype = ftVec.at(f1idx).ftnArgs.front().first; 
    // fptr로 넘길 ftn의 인자 타입(일단은 1개) TODO: 추후 여러개 확장 가능(BiFunction)
    string argFtnAObjtype = ftVec.at(f1idx).ftnArgs.front().first;
    if(isPrmtv(argFtnRtype)) argFtnAObjtype = prmtv2ObjMap[argFtnAtype];
    string declStr = tabStr + "public " + argFtnRtype + " " + newFtnName
                    + "(java.util.function.Function<" + argFtnAObjtype + ", " + argFtnRObjtype 
                    + "> fptr) {";
    tempClone.push_back(declStr);

    // 6.2. Var decl에서 함수 호출 diff부분 전까지 중복을 추출하고, 마지막에 계산된 값을 리턴하도록.
    for(int i=1; i<diffLine.front(); i++){
        tempClone.push_back(c1.cloneSnippet.at(i));
    }

    tabIdx = c1.cloneSnippet.at(diffLine.front()-1).find_first_not_of(" \t\r\n"); // this is for code formatting
    string tabStr2 = c1.cloneSnippet.at(diffLine.front()-1).substr(0, tabIdx);
    string asnStr = tabStr2 + diffInfo.front().typeName + " " + diffInfo.front().varName
                    + " = fptr.apply(" + argTok + ");";
    tempClone.push_back(asnStr);
    tempClone.push_back(tabStr2 + "return " + diffInfo.front().varName);
    tempClone.push_back(tabStr + "}");

    if(runOption != COD){
        cout << endl << "========================================" << endl;
        cout << "Extracting clone..." << endl;
        cout << "Clone part extracted to ftn arg." << endl << endl;
        testPrintCode(tempClone);
    }

    // 7. f,g의 중복부분을 fg call로 대치하고, 함수의 인자로 각각 hi3과 hi4를 준다.
    // 첫 번째 함수부분 패치 
    if(f1.bopenLine != 0){
        // TODO: 일단은 bopenLine 0인 경우만 처리. 그 이상은 나중에 휴리스틱 추가.
        cerr << "Error : f1 code pre-format error. bracket opener line not found." << endl;
        nc = false;
        return;
    }
        
    orgClone1.push_back(c1.cloneSnippet.front());
    for(int i=1; i<c1.cloneSnippet.size(); i++){
        if(i<diffLine.front()) continue;
        else if(i == diffLine.front()) {
            tabIdx = c1.cloneSnippet.at(i).find_first_not_of(" \t\r\n"); // this is for code formatting
            tabStr = c1.cloneSnippet.at(i).substr(0, tabIdx);
            // TODO: 람다 함수 패치는 일단 f: a->a 타입의 인자 하나, 리턴타입 하나인 경우만 먼저 구현. 추후 확장 예정
            string lmdCall = tabStr + diffInfo.front().typeName + " " + diffInfo.front().varName
                             + " = " + newFtnName + "((a) -> " + ftVec.at(f1idx).ftnName + "(a));";
            orgClone1.push_back(lmdCall);
        } else{
            orgClone1.push_back(c1.cloneSnippet.at(i));
        }
    }
    
    if(runOption != COD){
        cout << endl << "========================================" << endl;
        cout << "Patching clone..." << endl;
        cout << "Clone part 1 patched with ftn call." << endl << endl;
        testPrintCode(orgClone1);
    }

    // 두 번째 함수부분 패치
    if(f2.bopenLine != 0){
        // TODO: 일단은 bopenLine 0인 경우만 처리. 그 이상은 나중에 휴리스틱 추가.
        cerr << "Error : f2 code pre-format error. bracket opener line not found." << endl;
        nc = false;
        return;
    }
        
    orgClone2.push_back(c2.cloneSnippet.front());
    for(int i=1; i<c2.cloneSnippet.size(); i++){
        if(i<diffLine.front()) continue;
        else if(i == diffLine.front()) {
            tabIdx = c2.cloneSnippet.at(i).find_first_not_of(" \t\r\n"); // this is for code formatting
            tabStr = c2.cloneSnippet.at(i).substr(0, tabIdx);
            // TODO: 람다 함수 패치는 일단 f: a->a 타입의 인자 하나, 리턴타입 하나인 경우만 먼저 구현. 추후 확장 예정
            string lmdCall = tabStr + diffInfo.front().typeName + " " + diffInfo.front().varName
                             + " = " + newFtnName + "((a) -> " + ftVec.at(f2idx).ftnName + "(a));";
            orgClone2.push_back(lmdCall);
        } else{
            orgClone2.push_back(c2.cloneSnippet.at(i));
        }
    }

    if(runOption != COD){
        cout << endl << "========================================" << endl;
        cout << "Patching clone..." << endl;
        cout << "Clone part 2 patched with ftn call." << endl << endl;
        testPrintCode(orgClone2);
    }

    // patch code to the entire file
    ifstream pfile(c1.fileName.c_str());
    string line;

    int lineCnt = 1; // line counter
    while(getline(pfile, line)) {
        if(lineCnt == c1.from) { 
            patchCode.insert(patchCode.end(), tempClone.begin(), tempClone.end());
            patchCode.push_back("");
            patchCode.insert(patchCode.end(), orgClone1.begin(), orgClone1.end());
        } else if(lineCnt == c2.from){
            patchCode.insert(patchCode.end(), orgClone2.begin(), orgClone2.end());
        }
        if(lineCnt == c2.to + 1) {
            if(strOnlySpaces(line)) { lineCnt++; continue; }
        }
        if(!(lineCnt >= c1.from && lineCnt <= c1.to) && !(lineCnt >= c2.from && lineCnt <= c2.to)) patchCode.push_back(line);
        
        lineCnt++;
    }

    afterPatchLoc = patchCode.size();

    if(runOption != RST){
        cout << "Patching clones ...\n";
        cout << "(This will be replaced with actual file write operations)\n";
        testPrintCode(patchCode);
    } */

}





/*
 * ====================================================
 * ============= MAIN REFACTOR FUNCTIONS ==============
 * ====================================================
 */

void patchT1(){

    CloneData c1, c2;
    c1 = cloneDatas.front();
    c2 = cloneDatas.back();

    beforePatchLoc = getFileLine(c1.fileName);

    FtnType f1, f2;

    vector<NodeData> ndVec1;
    vector<NodeData> ndVec2;
    getFtnSubtree(c1.fileName, c1.ftnName, ndVec1);
    getFtnSubtree(c2.fileName, c2.ftnName, ndVec2);
    
    if(cloneFtnTypes.size() == 2){
        f1 = cloneFtnTypes.at(0);
        f2 = cloneFtnTypes.at(1);
    } else {
        cerr << "Error : Ftn Type not parsed. Code patch aborting..." << endl;
        return;
    }

    pair<int, int> p = getCommonPart(c1, c2, f1, f2, nc);
    if(!nc) {
        cerr << "Error getting common part. Aborting refactor..." << endl;
        return;
    }
    tempCodeLine = p.second - p.first + 1;
    
    if(p.first == 0 && p.second == 0) {
        cerr << "Error getting bracket scope. Aborting refactor..." << endl;
        return;
    }

    if(p.second - p.first < 10) {
        // this is heuristic. maybe need to improve this?
        cerr << "Bracket scope too small(less than 10 line). Aborting refactor..." << endl;
        return;
    }

    parseClassMemVars(c1.fileName);

    // a. 구간 내 인자로 뽑을 변수 선택하기; vector<pair<string, string>>로 반환
    vector< pair<string, string> > varSet = getVarSet(c1, c2, f1, f2, p, nc);
    if(!nc) {
        cerr << "Error getting var set from clone method. Aborting refactor..." << endl;
        return;
    }

    pair<int, int> scopeUp;
    scopeUp.first = p.second+1;
    scopeUp.second = c1.cloneSnippet.size();
    vector< pair<string, string> > seVarSet = getSeVarSet(c1, c2, f1, f2, scopeUp, nc);
    if(!nc) {
        cerr << "Error getting se var set from clone method. Aborting refactor..." << endl;
        return;
    }

    if(seVarSet.size()>1){
        cerr << "AutoRefactor cannot handle more than two seVarSet vars. It will be implemented soon." << endl;
        return;
    }

    // b. 뽑은 인자 사용해서 함수 정의부 만들고 중복부분 함수 호출 대치
    extractMethod(c1.fileName, c1, c2, f1, f2, p, varSet, seVarSet);

    reducedLoc = beforePatchLoc - afterPatchLoc;
    
    reportResult();

    // TODO: refactor below instruction
    // 1. EM 구간 정하기 (휴리스틱 - 구간 일정 크기보다 작으면 알고리즘 종료하기. ex 10라인 미만은 em 크게 의미 x)
    // 1.1. 함수 내 중복 부분 중 bracket(for문, if문) 큰 구간 찾고 적용 가능 한 구간 설정(이때 구간에 return문 제외)
    // 1.2. 앞 쪽 선언된 지역 변수가 있는데 구간 밖에서 사용되면 그 부분 제외
    // 2. EM 인자 모으기
    // 2.1. 일단 전역(클래스 멤버 변수), 지역(함수 내부, but 구간 외부), 함수 Arg 변수들 전부 <type, name>쌍의 Set으로 모으기
    // 2.2. 내부 구간에서 bracket 내(scope가 구간 내 사라지는 것) 변수 외에 사용된 변수들 중 지역과 Arg 인자들 모으기
    // 2.3. 해당 모아진 변수들은 함수 추출시 새로운 Arg로 전달 및 사용.
    // 3. 정의 만들고 중복 지운 후 Call로 대치.

}

void patchT2(){
    
    CloneData c1, c2;
    c1 = cloneDatas.front();
    c2 = cloneDatas.back();

    beforePatchLoc = getFileLine(c1.fileName);

    FtnType f1, f2;
    vector<NodeData> ndVec1;
    vector<NodeData> ndVec2;
    getFtnSubtree(c1.fileName, c1.ftnName, ndVec1);
    getFtnSubtree(c2.fileName, c2.ftnName, ndVec2);
    if(cloneFtnTypes.size() == 2){
        f1 = cloneFtnTypes.at(0);
        f2 = cloneFtnTypes.at(1);
    } else {
        cerr << "Error : Ftn Type not parsed. Code patch aborting..." << endl;
        return;
    }

    mergeMethod(c1.fileName, c1, c2, f1, f2, nc); // TODO: need to refactor?

    if(nc){
        reducedLoc = beforePatchLoc - afterPatchLoc;
        reportResult();
    } else {
        cout << "Patch completed abnormally. Couldn't patch this clone pair." << endl;
    }

    // TODO: refactor to below instruction
    // 1. diff 부분 확인하기. R-value만, L-value는 diff에 포함된 경우 알고리즘 중단. TODO: 이거를 타입 분류 앞쪽으로 빼기?
    // <diff 알고리즘>
    // 1-1. 일단 syntatic하게 라인별로 비교
    // 1-2. 불일치 라인 트리 벡터로 찾아가 토큰 하나씩 비교(여기서 토큰 일치시 불일치 아님)
    // 1-3. 비교해서 다른 토큰 각각 짚기
    // 1-4. 다른 토큰이 L-value인 경우 알고리즘 종료(찾는 방법은 nodeID를 보고)
    // 1-5. R-value인 경우 정상.
    // 2. caller 패칭하기.

}

void patchT3(){

    CloneData c1, c2;
    c1 = cloneDatas.front();
    c2 = cloneDatas.back();

    beforePatchLoc = getFileLine(c1.fileName);

    // TODO: 추후 타입 판정에 T3 추가하고 이 부분 T2_patch() 변경하기
    // 일단은 getCloneType() 결과와 상관없이 T3 타입으로 넣고 테스트
    FtnType f1, f2;

    vector<NodeData> ndVec1;
    vector<NodeData> ndVec2;
    getFtnSubtree(c1.fileName, c1.ftnName, ndVec1);
    getFtnSubtree(c2.fileName, c2.ftnName, ndVec2);
    if(cloneFtnTypes.size() == 2){
        f1 = cloneFtnTypes.at(0);
        f2 = cloneFtnTypes.at(1);
    } else {
        cerr << "Error : Ftn Type not parsed. Code patch aborting..." << endl;
        return;
    }

    t3CodePatch(c1.fileName, c1, c2, f1, f2, nc); // TODO: need to refactor?

    if(nc){
        reducedLoc = beforePatchLoc - afterPatchLoc;
        reportResult();
    } else {
        cout << "Patch completed abnormally. Couldn't patch this clone pair." << endl;
    }

}

void refactor(clone_type ct){

    switch(ct) {
        case T1:
            patchT1();
            break; 
        case T2:
            patchT2();
            break;
        case T3:
            patchT3();
            break;
        case ERR:
            cout << "Error : this clone data cannot be patched. procedure aborting..." << endl;
            break;
    }
    
}



/*
 * ====================================================
 * ================= TEST FUNCTIONS ===================
 * ====================================================
 */

void testPrintCloneData(){

    // test printer to check clone data read
    cout << "Number of clone pair : " << n << endl;

    int count = 1;
    for(vector<CloneData>::iterator it = cloneDatas.begin(); it!=cloneDatas.end(); ++it){
        cout << "Clone #" << count++ << " : " << it->fileName << "\t" << it->from << "\t" << it->to << endl;
        cout << "Clone fragment line : " << it->cloneSize << "\n=== Clone fragment ===\n";
        for(vector<string>::iterator cit = it->cloneSnippet.begin(); cit!=it->cloneSnippet.end(); ++cit){
            cout << cit->c_str() << endl;
        }
    }

}

void testPrintCaller(CloneData &cd){

    cout << "Number of callers : " << cd.callers.size() << endl;
    for(int i=0; i<cd.callers.size(); i++){
        cout << "Caller at : " << cd.callers[i].fileName << endl;
        cout << "Caller in : " << cd.callers[i].callerObjectName << "." << cd.callers[i].callerObjectFtnName << "()\n";
        cout << "Ftn called args : " << cd.callers[i].originalFtnName << "(";
        if(cd.callers[i].argNum == 0) cout << ")";
        for(int j=0; j<cd.callers[i].argNum; j++){
            cout << cd.callers[i].callArgs[j];
            if(j==cd.callers[i].argNum-1) cout << ")";
            else cout << ", ";
        }
        cout << "\nCalled line num : " << cd.callers[i].lineNum << endl;
    }

}

void testPrintCode(vector<string> code){
    for(vector<string>::iterator it = code.begin(); it != code.end(); ++it){
        cout << (*it) << endl;
    }
}

void testPrintFtnType(FtnType &f){
    cout << " ===== Function type ===== " << endl;
    cout << "annotations : ";
    for(int i=0; i<f.annotations.size(); i++){
        cout << f.annotations.at(i) << " ";
    }
    cout << "\nmodifiers : ";
    for(int p=0; p<f.modifiers.size(); p++){
        cout << f.modifiers.at(p) << " ";
    }
    cout << endl << f.ftnName << " : ";
    if (f.ftnArgs.size() > 0) {
        cout << "( ";
        for(int i=0; i<f.ftnArgs.size(); i++){
            if(i == f.ftnArgs.size()-1) {
                cout << f.ftnArgs.at(i).second << " : " << f.ftnArgs.at(i).first << " ) -> " << f.returnType << endl;
            } else {
                cout << f.ftnArgs.at(i).second << " : " << f.ftnArgs.at(i).first << " * ";
            }
        }
    } else {
        cout << "void -> " << f.returnType << endl;
    }
    cout << "exceptions : ";
    for(int i=0; i<f.exceptions.size(); i++){
        cout << f.exceptions.at(i) << " ";
    }
    cout << "\nBracket opener offset : " << f.bopenLine << endl;
    //cout << "Def line# : " << f.lineNum << endl; // TODO: remove this from ftnType?
}

void testPrintArgCalls(CloneData &cd){
    
    cout << "# of arg calls : " << cd.argCalls.size() << endl;
    vector< pair<string, int> >::iterator it = cd.argCalls.begin();
    for(; it!=cd.argCalls.end(); ++it){
        cout << (*it).first << " at line #" << (*it).second << endl;
    }

}

void testPrintClassNftnType(vector< pair< vector<string>, int > > &classNftnTypeDef){

    cout << " ===== Class Type Def ===== \n";
    cout << "Line#" << classNftnTypeDef.at(0).second << " | ";
    for(vector<string>::iterator it = classNftnTypeDef.at(0).first.begin(); it!=classNftnTypeDef.at(0).first.end(); ++it){
        cout << (*it) << " ";
    }
    cout << "\n\n";

    cout << " ===== Ftn Type Def ===== \n";
    for(int i=1; i<classNftnTypeDef.size(); i++){
        cout << "Line#" << classNftnTypeDef.at(i).second << " | ";
        for(vector<string>::iterator it = classNftnTypeDef.at(i).first.begin(); it!=classNftnTypeDef.at(i).first.end(); ++it){
            cout << (*it) << " ";
        }
        cout << "\n";
    }
    cout << "\n";

}

void testPrintClassType(ClassType &c){
    
    cout << " ===== Class Type ===== \n";
    cout << "modifiers : ";
    for(vector<string>::iterator it = c.modifiers.begin(); it!=c.modifiers.end(); ++it){
        cout << (*it) << " ";
    }
    cout << "\nClass Type : ";
    if (c.ctype == CLASS) cout << "class\n";
    else if (c.ctype == ABSTRACT_CLASS) cout << "abstract class\n";
    else if (c.ctype == INTERFACE) cout << "interface\n";
    cout << "Class Name : " << c.cname << endl;
    cout << "Def line# : " << c.lineNum << endl;

}

void testPrintFdVec(vector<FtnData> &fdVec){

    cout << " ===== FtnData Vector ===== \n";
    for(int i=0; i<fdVec.size(); i++){
        cout << fdVec.at(i).ftnName << "\t" << fdVec.at(i).from << " ~ " << fdVec.at(i).to << endl;
    }

}

void testPrintNdPairVec(vector< pair<NodeData, int> > &ndPairVec){

    cout << " ===== Pair of NodeData & Line Num Vector ===== \n";
    for(int i=0; i<ndPairVec.size(); i++){
        cout << "#" << ndPairVec.at(i).second << " | ";
        if (ndPairVec.at(i).first.isTerminal) cout << "T  | ";
        else cout << "NT | ";
        cout << ndPairVec.at(i).first.label << " | " << ndPairVec.at(i).first.nodeId << " | " << ndPairVec.at(i).first.lineNo << endl;
    }
    cout << endl;

}

void testPrintDiffInfo(DiffInfo &dInfo){

    cout << " ===== Diff Line Statement Info ===== \n";
    if(dInfo.diffType == 0) cout << "Others" << endl;
    else if(dInfo.diffType == 1) cout << "Return Stmt" << endl;
    else if(dInfo.diffType == 2) { 
        cout << "Var Decl | ";
        if (dInfo.isRef) cout << "Ref type | ";
        else cout << "Prmtv type | ";
        cout << dInfo.typeName << " | " << dInfo.varName << endl;
    }
    else if(dInfo.diffType == 1) cout << "Assignment Expr" << endl;

}

void testPrintPairVec(vector< pair<string, string> > &pairVec){

    cout << " ===== Print <str, str> pair vector ===== \n";
    for(int i=0; i<pairVec.size(); i++){
        cout << pairVec.at(i).first << " | " << pairVec.at(i).second << endl;
    }

}

void testPrintCallGraphVec(vector<CallGraph> &cgVec){

    cout << " ===== Print CallGraph Vector ===== \n";
    cout << " Total CallGraph Data : " << cgVec.size() << endl;
    for(int i=0; i<cgVec.size(); i++){
        cout << "[ " << cgVec.at(i).callee_cname << "." << cgVec.at(i).callee_fname << " " << cgVec.at(i).callee_argcnt
             << " <- " << cgVec.at(i).caller_cname << "." << cgVec.at(i).caller_fname << " " << cgVec.at(i).caller_argcnt
             << " (" << cgVec.at(i).caller_path << ") ]" << endl;
    }

}

void testPrintCallerVec(vector<Caller> &cVec){

    cout << " ===== Print Caller Info Vector ===== \n";
    cout << " Total Callers #" << cVec.size() << endl;
    for(int i=0; i<cVec.size(); i++){
        cout << "[ " << cVec.at(i).fileName << " | " << cVec.at(i).callerObjectName 
             << "." << cVec.at(i).callerObjectFtnName << " ]\n";
    }

}

/*
 * ====================================================
 * ================= MAIN FUNCTION ====================
 * ====================================================
 */

void init(string callGraphPath, string dirPath){

    // init 함수는 클론 알람별 중복 패치외, 디렉토리의 파일과 CallGraph를 읽어 
    // T2에서 함수 이름이 변경된 함수 호출자들의 이름을 바꿔주기 위한 선작업

    // CallGraph를 추출하여 전역 CallGraph 벡터를 생성
    getAllCallGraphData(callGraphPath, callGraphVec);
    
    // 디렉토리내 실제 파일경로와 클래스 이름 전역 맵을 생성
    // TODO: 디렉토리 명 제대로 확인할 수 있게 가드 만들기. -> read_file로
    fetchFname2CnameVec(dirPath, fpath2CnamePairVec);

}

int main(int argc, char** argv){

    string dotfile;
    string dirname;

    // USAGE :  ./autorefactor OPTION CLONEDATA [ DOTFILE DIRPATH ]
    if (argc < 3) {
        cerr << "Usage : " << argv[0] << " OPTION(-a, -r, -c) ALARMFILE [ DOTFILE DIRPATH ]" << endl;
        return 1;
    } else if (argc == 4) {
        cerr << "Usage : " << argv[0] << " OPTION(-a, -r, -c) ALARMFILE [ DOTFILE DIRPATH ]" << endl;
        cerr << "Only 3 arguments are passed. Need to pass directory path to trigger caller patch mode." << endl;
        return 1;
    } else if (argc == 5) {
        dotfile = string(argv[3]);
        dirname = string(argv[4]);
        if(dotfile.find(".dot") == string::npos) {
            cerr << "Usage : " << argv[0] << " OPTION(-a, -r, -c) ALARMFILE [ DOTFILE DIRPATH ]" << endl;
            cerr << "DOTFILE must be '.dot' format file." << endl;
            return 1;
        }
        callerPatchOn = true;
    } else if (argc > 5) {
        cerr << "Usage : " << argv[0] << " OPTION(-a, -r, -c) ALARMFILE [ DOTFILE DIRPATH ]" << endl;
        cerr << "Too many args passed." << endl;
        return 1;
    } else {
        callerPatchOn = false;
    }
     
    string opt = string(argv[1]);

    cout << opt << endl;

    if (opt.find("-a") != string::npos) runOption = ALL;
    else if (opt.find("-r") != string::npos) runOption = RST;
    else if (opt.find("-c") != string::npos) runOption = COD;
    else {
        cerr << "Error : run option not proper." << endl;
        return 1;
    }

    readFile(argv[2]); // 1. reads input data

    // TODO: 여기에 CallGraph 파싱 및 디렉토리 (파일명->클래스명) 맵 생성 함수 호출부 삽입하기
    // TODO: 알람에 따른 코드 패치는 인스턴스 여러번 수행하고 위 전체 디렉토리 정보 생성은 한번만 하도록

    clone_type ct = getCloneType();
    if(ct == T1){
        cout << "===== Clone patch type T1. Extract Method starting. =====" << endl << endl;
    } else if(ct == T2){
        cout << "===== Clone patch type T2. Merge Method starting. =====" << endl << endl;
    } else {
        cout << "===== Could not solve clone patch type. Abort refactor. =====" << endl << endl;
        return 0;
    }
    
    if(callerPatchOn) init(dotfile, dirname); // Caller 패치 모드가 켜진 경우 init()
    if(opt.find("3") != string::npos) refactor(T3); // 옵션을 -a|r|c|3 줄 경우 T3 Invoke
    else refactor(ct); // 2. refactor the code according to the clone datas

    //string fname = "/home/yang/Sources/os/jpcsp_java/DSPContext.java";
    //printss(fname);

    // test for callgraph patching
    // test with eprint/3/
    /* vector<string> cname_lst;
    cname_lst.push_back("FasooMessageParser");
    
    vector<CallGraph> cg_lst;

    //getCallGraphData("/home/yang/Sources/AutoRefactor/casestudy/fasoo/eprint/callgraphGeneralPhase.dot", cg_lst, cname_lst);
    string cname = "FasooMessageParser";
    string fname = "parse2";
    getFtnCallerData("/home/yang/Sources/AutoRefactor/casestudy/fasoo/eprint/callgraphGeneralPhase.dot", cg_lst, cname, fname);
    
    sort(cg_lst.begin(), cg_lst.end(), compare_cg);
    
    // make unique (i think this should be deprecated)
    //vector<CallGraph>::iterator it;
    //it = unique(cg_lst.begin(), cg_lst.end(), same_cg);
    //cg_lst.resize(distance(cg_lst.begin(), it));

    cout << cg_lst.size() << endl;
    for(int i=0; i<cg_lst.size(); i++){
        cout << cg_lst.at(i).callee_cname << " " << cg_lst.at(i).callee_fname << " " << cg_lst.at(i).caller_path << " " << cg_lst.at(i).caller_cname << " " << cg_lst.at(i).caller_fname << endl;
    } */

    // test for method invocation checking
    // method invocation : 122
    /* string fileName = "/home/yang/Sources/AutoRefactor/casestudy/fasoo/eprint/6/ePrint.com.fasoo.sqlclient.SqlClient.java";
    string ftnName = "queryForLong";

    vector<NodeData> ndVec;
    getFtnSubtree(fileName, ftnName, ndVec);
    printNodeVector(ndVec); */

    // TODO: 테스트에 해당 callee 이름 사용
    /* string cname = "FasooMessageParser";
    string fname = "parse";

    // TODO: 3. 입력으로 Callee cname/fname을 주고 해당하는 Caller 정보 (call cnt, cname, fname) 모으기 
    // getCallerInfo : ( calleeCname * calleeFname * callGraph ) -> ( Caller[] )
    vector<Caller> callerVec;
    // 해당 Callee에 대한 Caller 정보 모은 벡터. 추후 클론 인스턴스 별로 하나씩 생성하도록 리팩토링 할 것.
    getCallerInfo(cname, fname, callGraphVec, callerVec);
    testPrintCallerVec(callerVec);

    // 4. 2번의 맵을 이용하여 Caller의 실제 경로를 찾기
    string realPath;
    int argCnt;
    if(mapFullPath(fpath2CnamePairVec, callerVec.front().fileName, callerVec.front().callerObjectName, callerVec.front().realPath)) {
        cout << "Path found! : " << realPath << endl;
    }
    cout << callerVec.front().argNum << endl;

    // TODO: 5. 찾은 Caller의 실제 파일위치와 Caller 정보 이용해서 Caller 패치해주기
    vector<NodeData> ndVec;
    getPtreeVec(callerVec.front().realPath, ndVec);
    //printNodeVector(ndVec);

    //getConstSubtree(realPath, callerVec.front().callerObjectName, ndVec);
    //printNodeVector(ndVec);

    patchCaller(callerVec.front(), fname, "parseparse2", 1); */

    return 0;

} 