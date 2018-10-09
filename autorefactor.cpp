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

    // TODO: analyze call graph and insert caller data here!
    // 1. analyze call graph (fetch caller data for clone ftn 1 & 2)
    // 2. parse caller ftn tree and insert caller data (need to get caller's obj name, call args etc...)

    int callerNum;
    Caller tmpCaller;

    for(int i=0; i<n; i++){
        cfile >> callerNum;
        for(int j=0; j<callerNum; j++){
            cfile >> tmpCaller.fileName;
            cfile >> tmpCaller.callerObjectName >> tmpCaller.callerObjectFtnName >> tmpCaller.originalFtnName;
            cfile >> tmpCaller.argNum;
            for(int k=0; k<tmpCaller.argNum; k++){
                string tmpStr;
                cfile >> tmpStr;
                tmpCaller.callArgs.push_back(tmpStr);
            }
            cfile >> tmpCaller.lineNum;
            cloneDatas[i].callers.push_back(tmpCaller);
            tmpCaller.fileName = tmpCaller.callerObjectName = tmpCaller.callerObjectFtnName = "";
            tmpCaller.argNum = tmpCaller.lineNum = 0;
            tmpCaller.callArgs.clear();
        }
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

void patchCaller(Caller c, string newFname, int flag){
    // function for fetching caller datas
    // using data from the alarm file which are parsed from DOT file

    // Get the call site code line too. to use for caller patching
    ifstream pfile(c.fileName.c_str());
    string line;
    vector<string> tempCode;
    int callerLine = c.lineNum;
    int lineCnt = 0; // line counter
    while(getline(pfile, line)) {
        tempCode.push_back(line);
        lineCnt++;
    }

    string patchLine = tempCode[c.lineNum-1];
    bool found = false;
    int ftnFront, ftnRear;
    ftnFront = ftnRear = 0;

    while(!found){
        ftnFront = patchLine.find_first_of(c.originalFtnName, ftnFront);
        if (patchLine.at(ftnFront + c.originalFtnName.size()) == '(' && patchLine.at(ftnFront - 1) == '.') {
            found = true;
            ftnRear = patchLine.find_first_of(')', ftnFront);
        } else if (patchLine.at(ftnFront + c.originalFtnName.size()) == ' '){
            ftnFront += patchLine.substr(ftnFront).find_first_not_of(" \t\r\n");
            if (patchLine.at(ftnFront + c.originalFtnName.size()) == '(') {
                found = true;
                ftnRear = patchLine.find_first_of(')', ftnFront);
            }
        } else {
            ftnFront++;
        }
    }
    
    string strFront = patchLine.substr(0, ftnFront) + newFname + "(";
    string strRear = int2str(flag) + ")" + patchLine.substr(ftnRear + 1);

    patchLine = strFront;
    for(int i=0; i<c.argNum; i++){
        patchLine += c.callArgs[i] + ", ";
    }
    patchLine += strRear;
    tempCode[c.lineNum-1] = patchLine;    

    cout << "Patching callers ...\n";
    cout << "(This will be replaced with actual file write operations)\n";
    testPrintCode(tempCode); // TODO: need to replace this with file write operations

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
        } else if(fnd && dinfo.diffType == 2 && i<ndVec.size()-1) {
            if(ndVec.at(i).nodeId == 123 && ndVec.at(i).nodeId == 62) {
                dinfo.isRef = true; // var type is reference
                break;
            } else if(ndVec.at(i).nodeId == 123 && ndVec.at(i).nodeId == 117) {
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
    }

    return dinfo;

}

vector<int> getDiff(CloneData &c1, CloneData &c2, FtnType &f1, FtnType &f2, vector<DiffInfo> &diffInfo, bool &normalCompletion){
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
        //cout << tokSame1.size() << tokSame2.size() << endl;
        
        // TODO: diffInfo 채우기.
        // testNdVec : 해당 라인에 해당하는 노드 벡터
        // testNdVec 이용해서 stmt 구분 먼저 
        // 23-145 : var_decl, 162 : return, 나머지 : others
        // 만약 var_decl 이면, var 타입 구하기
        // 123-62 : ref_type, 123-117: prmtv_type
        vector<NodeData> testNdVec = findNodeByLineWithNt(ndVec1, c1.from+diffLine.at(i)-lineOffset1);
        DiffInfo dinfo = getDiffInfo(testNdVec);
        diffInfo.push_back(dinfo);
        testPrintDiffInfo(dinfo);

        vector<int> emptyVec;
        // Diff line Lvalue check part
        // Diff line Var Decl & Retur Stmt check part
        for(int j=0; j<tmpVec1.size(); j++){
            if(intVecContains(tokSame1, j)) continue;
            if(isLvalueNode(ndVec1, tmpVec1.at(j).second)) {
                cerr << "Error : Var decl diff(Lvalue diff) found on vec1 diff line. Merging aborted." << endl;
                normalCompletion = false;
                hasLvalue |= isLvalueNode(ndVec1, tmpVec1.at(j).second);
            }
        }
        for(int j=0; j<tmpVec2.size(); j++){
            if(intVecContains(tokSame2, j)) continue;
            if(isLvalueNode(ndVec2, tmpVec2.at(j).second)) {
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
    for(int i=0; i<c1.callers.size(); i++){
        patchCaller(c1.callers[i], newFtnName, 0);
    }
    for(int i=0; i<c2.callers.size(); i++){
        patchCaller(c2.callers[i], newFtnName, 1);
    }

    vector<DiffInfo> diffInfo;

    vector<int> diffLine = getDiff(cloneDatas.front(), cloneDatas.back(), f1, f2, diffInfo, normalCompletion); // TODO: refactor this?
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
                    retStr += "return null;";
                } else {
                    if (f1.returnType == "boolean") {
                        retStr += "return false;";
                    } else {
                        retStr += "return 0;";
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
                        cloneDummy1.push_back(tabStr + "if(flag == 0){ ");
                        cloneDummy2.push_back(tabStr + "else if(flag == 1){ ");
                        int varIdx1 = c1.cloneSnippet[i].find(diffInfo.at(dInfoIdx-1).varName, tabIdx+diffInfo.at(dInfoIdx-1).typeName.size());
                        int varIdx2 = c2.cloneSnippet[i].find(diffInfo.at(dInfoIdx-1).varName, tabIdx+diffInfo.at(dInfoIdx-1).typeName.size());
                        cloneDummy1.push_back(tabStr + c1.cloneSnippet[i].substr(varIdx1));
                        cloneDummy2.push_back(tabStr + c2.cloneSnippet[i].substr(varIdx2));
                    } else {
                        cloneDummy1.push_back(tabStr + "if(flag == 0){ ");
                        cloneDummy2.push_back(tabStr + "else if(flag == 1){ ");
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
                        tempClone.push_back(tabStr + "if(flag == 0) " + c1.cloneSnippet[i].substr(varIdx1));
                        tempClone.push_back(tabStr + "else if(flag == 1) " + c2.cloneSnippet[i].substr(varIdx2));
                    } else {
                        tempClone.push_back(tabStr + "if(flag == 0) " + c1.cloneSnippet[i].substr(tabIdx));
                        tempClone.push_back(tabStr + "else if(flag == 1) " + c2.cloneSnippet[i].substr(tabIdx));                    
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
    //parseFtype(ndVec1, f1);
    //parseFtype(ndVec2, f2);

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
    //parseFtype(ndVec1, f1);
    //parseFtype(ndVec2, f2);

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

void refactor(clone_type ct){

    switch(ct) {
        case T1:
            patchT1();
            break; 
        case T2:
            patchT2();
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

}

void testPrintPairVec(vector< pair<string, string> > &pairVec){

    cout << " ===== Print <str, str> pair vector ===== \n";
    for(int i=0; i<pairVec.size(); i++){
        cout << pairVec.at(i).first << " | " << pairVec.at(i).second << endl;
    }

}

/*
 * ====================================================
 * ================= MAIN FUNCTION ====================
 * ====================================================
 */

int main(int argc, char** argv){

    // USAGE :  ./autorefactor OPTION CLONEDATA
    /* if (argc < 2) {
        cerr << "Usage : " << argv[0] << " OPTION(-a, -r, -c) ALARMFILE" << endl;
        return 1;
    }

    string opt = string(argv[1]);

    if (opt == "-a") runOption = ALL;
    else if (opt == "-r") runOption = RST;
    else if (opt == "-c") runOption = COD;
    else {
        cerr << "Error : run option not proper." << endl;
        return 1;
    }

    readFile(argv[2]); // 1. reads input data

    clone_type ct = getCloneType();
    if(ct == T1){
        cout << "===== Clone patch type T1. Extract Method starting. =====" << endl << endl;
    } else if(ct == T2){
        cout << "===== Clone patch type T2. Merge Method starting. =====" << endl << endl;
    } else {
        cout << "===== Could not solve clone patch type. Abort refactor. =====" << endl << endl;
        return 0;
    }
    refactor(ct); */ // 2. refactor the code according to the clone datas

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

    fetchFname2CnameVec("/home/yang/Sources/Fasoo/bench/ePrint_java", fpath2CnamePairVec);
    testPrintPairVec(fpath2CnamePairVec);

    return 0;

} 