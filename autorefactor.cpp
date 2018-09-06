#include "autorefactor.h"

/*
 * ====================================================
 * =============== FILE I/O FUNCTIONS =================
 * ====================================================
 */

// maybe replace with merging the code to refactor_guide?
void read_file(char* alarmFile){

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

int get_file_line(string fileName){

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

bool are_same(string s1, string s2){

    if(only_spaces(s1) && only_spaces(s2)) return true;
    else if(only_spaces(s1) || only_spaces(s2)) return false;

    dtl::Diff< char, string > strDiff(s1, s2);
    strDiff.compose();
    return (strDiff.getEditDistance() == 0);

}

bool only_spaces(string str){
    // checks if certain string has only spaces
    // this function is for checking white space in the program code
    if(str.find_first_not_of(" \t\r\n") != std::string::npos) return false;
    else return true;
}

bool contains(string str, string word){
    // checks if str contains word
    return (str.find(word) < str.size() && str.find(word) >= 0);

}

int min_pos(int a, int b){
    if (a >= 0 && b >= 0) return a < b ? a : b;
    else return a > b ? a : b;
}

string int_to_str(int n){
    ostringstream ss;
    ss << n;
    return ss.str();
}

int str_to_int(const char *s)
{
    int i;
    i = 0;
    while(*s >= '0' && *s <= '9')
    {
        i = i * 10 + (*s - '0');
        s++;
    }
    return i;
}

int min_int(int a, int b){
    return a < b ? a : b;
}

bool str_vec_exists(vector<string> &sv, string s){
    for(int i=0; i<sv.size(); i++){
        if(sv.at(i) == s) return true;
    }
    return false;
}

int str_sec_vec_exists(vector< pair<string, string> > &sv, string s){
    // if found, return index. if not found, return -1
    for(int i=0; i<sv.size(); i++){
        if(sv.at(i).second == s) return i;
    }
    return -1;
}

bool comp_sp_vec(vector< pair<string, string> > &sv1, vector< pair<string, string> > &sv2){
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

void parse_ftn_type(string s, FtnType &ftype){
    
    if (s.find(')') == string::npos) { 
        cerr << "Error : parse_ftn_type() cannot parse \"" << s << "\" without parentheses closure" << endl;
        return;
    }

    vector<string> tokens;
    string ns = s.substr(s.find_first_not_of(" \t\r\n"));
    
    int prevPos = s.find_first_of(" \t\r\n");
    int emptyPoint = ns.find(' ');
    string token;

    // 1. parse ftn type and ftn name
    while(emptyPoint <= ns.find('(')){
        token = ns.substr(0, emptyPoint);
        tokens.push_back(token);
        ns = ns.substr(emptyPoint);
        ns = ns.substr(ns.find_first_not_of(" \t\r\n"));
        prevPos += (emptyPoint + 1);
        emptyPoint = ns.find(' ');
    }

    if (ns.find('(') > 0) {
        token = ns.substr(0, ns.find('('));
        tokens.push_back(token);
    }

    reverse(tokens.begin(), tokens.end());
    ftype.ftnName = tokens[0];
    ftype.returnType = tokens[1];

    if(tokens.size() > 2){
        for(int i=tokens.size()-1; i>=2; i--)
        ftype.keywords.push_back(tokens[i]);
    }

    ns = s.substr(s.find('(') + 1);
    ns = ns.substr(ns.find_first_not_of(" \t\r\n"));
    pair<string, string> argPair;

    // 2. parse arg type and arg name
    emptyPoint = ns.find(' ');
    while(emptyPoint <= ns.find(')') && ns.find_first_of('{') != 0){
        argPair.first = ns.substr(0, emptyPoint);
        ns = ns.substr(emptyPoint);
        ns = ns.substr(ns.find_first_not_of(" \t\r\n"));
        
        emptyPoint = min_pos(ns.find(' '), ns.find(','));
        emptyPoint = min_pos(emptyPoint, ns.find(')'));
        argPair.second = ns.substr(0, emptyPoint);
        ns = ns.substr(emptyPoint + 1);

        if(ns.find(',') > 0){
            ns = ns.substr(ns.find_first_not_of(" \t\r\n"));
            if(ns.find(',') == 0) {
                ns = ns.substr(1);
                if(ns.find_first_of(' ') == 0) ns = ns.substr(ns.find_first_not_of(" \t\r\n"));
            }
        } else {
            ns = ns.substr(1);
            ns = ns.substr(ns.find_first_not_of(" \t\r\n"));
        }

        ftype.ftnArgs.push_back(argPair);
        emptyPoint = ns.find(' ');
    }

}

void patch_callers(Caller c, string newFname, int flag){
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
    string strRear = int_to_str(flag) + ")" + patchLine.substr(ftnRear + 1);

    patchLine = strFront;
    for(int i=0; i<c.argNum; i++){
        patchLine += c.callArgs[i] + ", ";
    }
    patchLine += strRear;
    tempCode[c.lineNum-1] = patchLine;    

    cout << "Patching callers ...\n";
    cout << "(This will be replaced with actual file write operations)\n";
    print_code(tempCode); // TODO: need to replace this with file write operations

} 

int get_line_offset(vector<NodeData> &ndVec, string &ftnName, int from){

    int lineOffset;

    vector< pair<NodeData, int> > tempVec = find_node_by_label(ndVec, ftnName);
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

vector<int> get_diff(CloneData &c1, CloneData &c2, FtnType &f1, FtnType &f2){
    // function for getting diff part of two clone datas
    vector<int> diffLine;

    // 1. compare two clone datas (function-wise)
    vector<string>::iterator it1 = c1.cloneSnippet.begin();
    vector<string>::iterator it2 = c2.cloneSnippet.begin();
    int idx = 0;

    // 2. put diff part offset line in the vector (this should except first/last line - b.c. ftn decl & closure)
    for(; it1 != c1.cloneSnippet.end() && it2 != c2.cloneSnippet.end(); ++it1, ++it2){
        if (!are_same((*it1), (*it2)) && idx != 0) diffLine.push_back(idx);
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
    lineOffset1 = get_line_offset(ndVec1, f1.ftnName, c1.from);
    lineOffset2 = get_line_offset(ndVec2, f2.ftnName, c2.from);

    //if(!found1) cerr << "line offset1 not set. error might be caused." << endl;
    //if(!found2) cerr << "line offset2 not set. error might be caused." << endl;

    /* print_node_vector(ndVec1);
    print_node_vector(ndVec2); */

    // 1-2-b. 불일치 라인 트리 벡터로 토큰 비교.
    bool hasLvalue = false;

    // 1-3. 비교해서 다른 토큰 각각 짚기
    // 1-4. 다른 토큰이 L-value인 경우 알고리즘 종료(찾는 방법은 nodeID를 보고)
    for(int i=0; i<diffLine.size(); i++){

        vector< pair<NodeData, int> > tmpVec1 = find_node_by_line(ndVec1, c1.from+diffLine.at(i)-lineOffset1);
        vector< pair<NodeData, int> > tmpVec2 = find_node_by_line(ndVec2, c2.from+diffLine.at(i)-lineOffset2);
        //cout << tmpVec1.size() << " " << tmpVec2.size() << endl;
        //cout << diffLine.at(i) << endl;

        // get same token (to except from diff token compare)
        vector<int> tokSame1;
        vector<int> tokSame2;
        for(int j=0; j<tmpVec1.size() || j<tmpVec2.size(); j++){
            if(tmpVec1.at(j).first.label == tmpVec2.at(j).first.label) {
                tokSame1.push_back(j);
                tokSame2.push_back(j);
            }
        }
        //cout << tokSame1.size() << tokSame2.size() << endl;

        vector<int> emptyVec;
        // Diff line Lvalue check part
        for(int j=0; j<tmpVec1.size(); j++){
            if(int_vec_contains(tokSame1, j)) continue;
            if(is_lvalue_node(ndVec1, tmpVec1.at(j).second)) {
                cerr << "Error : lvalue found on vec1 diff line. merge should be aborted." << endl;
                hasLvalue |= is_lvalue_node(ndVec1, tmpVec1.at(j).second);
            }
        }
        for(int j=0; j<tmpVec2.size(); j++){
            if(int_vec_contains(tokSame2, j)) continue;
            if(is_lvalue_node(ndVec2, tmpVec2.at(j).second)) {
                 cerr << "Error : lvalue found on vec2 diff line. merge should be aborted." << endl;
                 hasLvalue |= is_lvalue_node(ndVec2, tmpVec2.at(j).second);
            }
        }
        if(hasLvalue) return emptyVec;

    }

    vector<int> tmpIntVec;

    for(int i=0; i<diffLine.size(); i++){
        if(line_parenthesis_check(ndVec1, c1.from+diffLine.at(i)-lineOffset1) == 1 && line_parenthesis_check(ndVec2, c2.from+diffLine.at(i)-lineOffset2) == 1){
            if(i<diffLine.size()-1 && diffLine.at(i+1) != diffLine.at(i)+1) continue;
            else{
                //tmpIntVec.push_back(diffLine.at(i)-1);
                //cout << diffLine.at(i) << endl;
                diffLine.insert(diffLine.begin()+i+1, diffLine.at(i)+1);
                i++;
            }
        }
        else if(line_parenthesis_check(ndVec1, c1.from+diffLine.at(i)-lineOffset1) == -1 && line_parenthesis_check(ndVec2, c2.from+diffLine.at(i)-lineOffset2) == -1){
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

    // 1-5. R-value인 경우 정상.
    // 3. return the vector
    return diffLine;
}

void parse_class_member_vars(string fileName){
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

void report_result(){

    cout << "\n======= Reporting Results =======" << endl;
    cout << "Original Loc : " << beforePatchLoc << endl;
    cout << "Patched Loc : " << afterPatchLoc << endl;
    cout << "Reduced Loc : " << reducedLoc << endl;
    cout << "Patched Ftn : " << endl; // TODO: fill this
    cout << "=================================" << endl;

}

/*
 * ====================================================
 * ======= FUNCTIONS FOR TYPE 1(EXTRACT METHOD) =======
 * ====================================================
 */


pair<int, int> get_common_part(CloneData &c1, CloneData &c2, FtnType &f1, FtnType &f2){

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
        if (!are_same((*it1), (*it2)) && idx != 0) diffInt.push_back(idx);
        ///cout << (*it1) << endl << (*it2) << endl;
        idx++;
    }

    int lineOffset1, lineOffset2; // 파스트리 파일 라인과 실제 파일 라인 넘버가 상이할 경우 대비한 오프셋.
                                  // offset = 실제 파일 라인 - 파스 트리 파일 라인
    vector<NodeData> ndVec1;
    vector<NodeData> ndVec2;
    getFtnSubtree(c1.fileName, f1.ftnName, ndVec1);
    getFtnSubtree(c2.fileName, f2.ftnName, ndVec2);
    lineOffset1 = get_line_offset(ndVec1, f1.ftnName, c1.from);
    lineOffset2 = get_line_offset(ndVec2, f2.ftnName, c2.from);

    vector< pair<NodeData, int> > returnVec1 = find_node_by_label(ndVec1, "return");
    vector< pair<NodeData, int> > returnVec2 = find_node_by_label(ndVec2, "return");
    
    int diffFrontRet1 = returnVec1.front().first.lineNo + lineOffset1 - c1.from;
    int diffFrontRet2 = returnVec2.front().first.lineNo + lineOffset2 - c1.from;
    //cout << returnVec1.size() << endl;
    //cout << returnVec2.size() << endl;

    if (diffInt.back() > diffFrontRet1 || diffInt.back() > diffFrontRet2) return pair<int, int>(0, 0);
    // error case

    int frt, rear;
    frt = diffInt.back();
    rear = min_int(diffFrontRet1, diffFrontRet2) - 1;
    //cout << frt << rear << endl;

    pair<int, int> tmpPair1 = pair<int, int>(frt + c1.from - lineOffset1, rear + c1.from - lineOffset1);
    pair<int, int> tmpPair2 = pair<int, int>(frt + c2.from - lineOffset2, rear + c2.from - lineOffset2);
    pair<int, int> scp1 = find_biggest_bracket_in_scope(ndVec1, tmpPair1);
    pair<int, int> scp2 = find_biggest_bracket_in_scope(ndVec2, tmpPair2);
    if (scp1.first == 0 && scp1.second == 0) return pair<int, int>(0, 0);
    if (scp2.first == 0 && scp2.second == 0) return pair<int, int>(0, 0);
    // if there is no bracket in the scope

    //cout << scp1.first + lineOffset1 << "~" << scp1.second + lineOffset1 << endl;
    //cout << scp2.first + lineOffset2 << "~" << scp2.second + lineOffset2 << endl;

    if (scp1.second - scp1.first != scp2.second - scp2.first) return pair<int, int>(0, 0);
    // error case : cannot find the scope

    //cout << f1.ftnName << " " << f2.ftnName << endl;
    //cout << diffInt.size();
 
    cp.first = scp1.first - c1.from + lineOffset1;
    cp.second = scp1.second - c1.from + lineOffset1;
    return cp;

}

vector< pair<string, string> > get_em_args(CloneData &c1, CloneData &c2, FtnType &f1, FtnType &f2, pair<int, int> &scope){

    vector< pair<string, string> > emArgs;

    int lineOffset1, lineOffset2; // 파스트리 파일 라인과 실제 파일 라인 넘버가 상이할 경우 대비한 오프셋.
                                  // offset = 실제 파일 라인 - 파스 트리 파일 라인
    vector<NodeData> ndVec1;
    vector<NodeData> ndVec2;
    getFtnSubtree(c1.fileName, f1.ftnName, ndVec1);
    getFtnSubtree(c2.fileName, f2.ftnName, ndVec2);
    lineOffset1 = get_line_offset(ndVec1, f1.ftnName, c1.from);
    lineOffset2 = get_line_offset(ndVec2, f2.ftnName, c2.from);

    //print_node_vector(ndVec1);

    // 1. EXTERN & CLASS_MEMBER : 다른 함수에서 모은 import 객체, 클래스 멤버 변수

    // 2. FTN_ARG : 각 함수의 인자로 정의된 변수 모으기
    /* for(int i=0; i<f1.ftnArgs.size(); i++){
        cout << f1.ftnArgs.at(i).first << " " << f1.ftnArgs.at(i).second << endl;
    }
    for(int i=0; i<f2.ftnArgs.size(); i++){
        cout << f2.ftnArgs.at(i).first << " " << f2.ftnArgs.at(i).second << endl;
    } */

    // 3. LOCAL : 함수 내 scope 구간 위 정의된 변수 모으기
    vector< pair<string, string> > varAboveScope1;
    vector< pair<string, string> > varAboveScope2;

    // 3.1. LOCAL 뽑을 범위 계산하기 (from : 함수 정의부 + 1, to : Scope.front - 1)
    // 파스 트리 파일 라인 = 실제 파일 라인 - offset
    int locScopeFrt1 = c1.from + 1 - lineOffset1;
    int locScopeRear1 = c1.from + scope.first - 1 - lineOffset1;
    pair<int, int> locScope1 = pair<int, int>(locScopeFrt1, locScopeRear1);
    varAboveScope1 = find_loc_var_in_scope(ndVec1, locScope1);

    int locScopeFrt2 = c2.from + 1 - lineOffset2;
    int locScopeRear2 = c2.from + scope.first - 1 - lineOffset2;
    pair<int, int> locScope2 = pair<int, int>(locScopeFrt2, locScopeRear2);
    varAboveScope2 = find_loc_var_in_scope(ndVec2, locScope2);

    // 3.2 merge ftn arg with local var above scope
    varAboveScope1.insert(varAboveScope1.end(), f1.ftnArgs.begin(), f1.ftnArgs.end());
    varAboveScope2.insert(varAboveScope2.end(), f2.ftnArgs.begin(), f2.ftnArgs.end());

    /* cout << endl << varAboveScope1.size() << endl;
    for(int i = 0; i<varAboveScope1.size(); i++){
        cout << varAboveScope1.at(i).first << " " << varAboveScope1.at(i).second << endl;
    }

    cout << varAboveScope2.size() << endl;
    for(int i = 0; i<varAboveScope2.size(); i++){
        cout << varAboveScope2.at(i).first << " " << varAboveScope2.at(i).second << endl;
    } */

    // 4. USED : 구간 내 사용된 변수 이름 모으기
    // TODO: refactor this and extract to function
    vector<string> usedVars1;
    int brktScopeFrt1 = c1.from + scope.first - lineOffset1;
    int brktScopeRear1 = c1.from + scope.second - lineOffset1;
    for(int i=0; i<ndVec1.size(); i++){
        if(ndVec1.at(i).nodeId == 39){
            if(i>5 && ndVec1.at(i-1).label != "." && ndVec1.at(i-5).nodeId != 123 && ndVec1.at(i+1).label != "Exception" 
                && ndVec1.at(i+1).isTerminal && !str_vec_exists(usedVars1, ndVec1.at(i+1).label)
                && ndVec1.at(i+1).lineNo >= brktScopeFrt1 && ndVec1.at(i+1).lineNo <= brktScopeRear1 ) usedVars1.push_back(ndVec1.at(i+1).label);
        }
    }
    vector< pair<string, string> > emArgs1;
    for(int i=0; i<usedVars1.size(); i++){
        int idx = str_sec_vec_exists(varAboveScope1, usedVars1.at(i));
        if (idx != -1){
            emArgs1.push_back(varAboveScope1.at(idx));
        }
    }
    
    vector<string> usedVars2;
    int brktScopeFrt2 = c2.from + scope.first - lineOffset2;
    int brktScopeRear2 = c2.from + scope.second - lineOffset2;
    for(int i=0; i<ndVec2.size(); i++){
        if(ndVec2.at(i).nodeId == 39){
            if(i>5 && ndVec2.at(i-1).label != "." && ndVec2.at(i-5).nodeId != 123 && ndVec2.at(i+1).label != "Exception" 
                && ndVec2.at(i+1).isTerminal && !str_vec_exists(usedVars2, ndVec2.at(i+1).label)
                && ndVec2.at(i+1).lineNo >= brktScopeFrt2 && ndVec2.at(i+1).lineNo <= brktScopeRear2 ) usedVars2.push_back(ndVec2.at(i+1).label);
        }
    }
    vector< pair<string, string> > emArgs2;
    for(int i=0; i<usedVars2.size(); i++){
        int idx = str_sec_vec_exists(varAboveScope2, usedVars2.at(i));
        if (idx != -1){
            emArgs2.push_back(varAboveScope2.at(idx));
        }
    }

    /* cout << endl << emArgs1.size() << endl;
    for(int i = 0; i<emArgs1.size(); i++){
        cout << emArgs1.at(i).first << " " << emArgs1.at(i).second << endl;
    }
    cout << endl << emArgs2.size() << endl;
    for(int i = 0; i<emArgs2.size(); i++){
        cout << emArgs2.at(i).first << " " << emArgs2.at(i).second << endl;
    } */

    /* cout << usedVars1.size() << endl;

    for(int i=0; i<usedVars1.size(); i++){
        cout << usedVars1.at(i) << endl;
    } */

    if(!comp_sp_vec(emArgs1, emArgs2)) {
        cerr << "Error : em arguments doesn't match between two clone parts." << endl;
        return emArgs;
    }

    // 5. ARG = USED - INNER - EXTERN - CLASS_MEMBER 이 중에 LOCAL에 존재하는 이름.(만약 하나라도 없으면 FAIL)
    // USED 중 세 변수 집합에 존재하는 것 전부 빼고 나머지 중 LOCAL에 존재하는 이름 찾으면 됨.

    return emArgs1;

}

string get_clone_ftn_name(){

    ostringstream ftnNum;
    ftnNum << cloneFtnNum;
    string ftnName = cloneFtnName + ftnNum.str() + "()";
    return ftnName;

}

void patch_code(string fileName, CloneData &c1, CloneData &c2, FtnType &f1, FtnType &f2, pair<int, int> &scope, vector< pair<string, string> > emArgs){

    //cout << scope.first << " " << scope.second << endl;

    // 1. make new method name and decl line
    string newFtnName = f1.ftnName + f2.ftnName;

    //cout << endl << "|" << newFtnName << "|" << endl;

    int tabIdx = c1.cloneSnippet.front().find_first_not_of(" \t\r\n"); // this is for code formatting
    string tabStr = c1.cloneSnippet.front().substr(0, tabIdx);
    string fstLine = tabStr + "public void " + newFtnName + "(";
    for(int i=0; i<emArgs.size(); i++){
        fstLine += emArgs.at(i).first + " " + emArgs.at(i).second;
        if(i<emArgs.size()-1) fstLine += ", ";
    }
    fstLine += ") {";
    tempClone.push_back(fstLine);
    //tempClone.push_back(""); // insert empty line to format

    // 2. insert bracket scope in the new method
    for(int i=scope.first; i<=scope.second; i++){
        tempClone.push_back(c1.cloneSnippet.at(i));    
    }
    
    //tempClone.push_back("");
    tempClone.push_back(tabStr + "}");

    //print_code(tempClone);

    // 3. replace clone part with new function call
    bool inserted = false;
    for(int i=0; i<c1.cloneSnippet.size(); i++){
        if(i >= scope.first && i <= scope.second && !inserted){
            int tabIdxIn = c1.cloneSnippet.at(scope.first).find_first_not_of(" \t\r\n"); // this is for code formatting
            string tabStrIn = c1.cloneSnippet.at(scope.first).substr(0, tabIdxIn);
            string newFtnCall = tabStrIn + newFtnName + "(";
            for(int i=0; i<emArgs.size(); i++){
                newFtnCall += emArgs.at(i).second;
                if (i<emArgs.size()-1) newFtnCall += ", ";
            }
            newFtnCall += ");";
            orgClone1.push_back(newFtnCall);
            inserted = true;
        }
        else if (i < scope.first || i > scope.second) orgClone1.push_back(c1.cloneSnippet.at(i));
    }

    print_code(orgClone1);


    // 3. insert flag at the ftn decl.
    // use FtnType to not get new function name & arg name
    /* string ftnDecl = tabStr;
    for(int i=0; i<f1.keywords.size(); i++){
        ftnDecl += (f1.keywords[i] + " ");
    }

    ftnDecl += (f1.returnType + " " + newFtnName + "(");
    for(int i=0; i<f1.ftnArgs.size(); i++){
        ftnDecl += f1.ftnArgs[i].first;
        ftnDecl += " ";
        ftnDecl += f1.ftnArgs[i].second;
        ftnDecl += ", ";
    }
    ftnDecl += "int flag) {"; // TODO: maybe need to refactor b.c. parenthesis not in first line?
    tempClone.push_back(ftnDecl);

    // check for adjacent clone lines;
    bool adjacent = false;
    vector<string> cloneDummy1; 
    vector<string> cloneDummy2; // clone dummy for adjacent clone snippets
    string ifOpen;

    for(int i=1; i<c1.cloneSize; i++){
        if (!int_vec_contains(diffLine, i)) tempClone.push_back(c1.cloneSnippet[i]);
        else {
            tabIdx = c1.cloneSnippet[i].find_first_not_of(" \t\r\n"); // this is for code formatting
            tabStr = c1.cloneSnippet[i].substr(0, tabIdx);

            if(!adjacent){
            // 처음 중복 라인 찾아서 브랜치 나누는 경우
                if(i<c1.cloneSize-1 && int_vec_contains(diffLine, i+1)){
                // 마지막 라인이 아니면서 뒤에 인접한 중복 라인 존재시
                    cloneDummy1.push_back(tabStr + "if(flag == 0){ ");
                    cloneDummy2.push_back(tabStr + "else if(flag == 1){ ");
                    cloneDummy1.push_back(c1.cloneSnippet[i]);
                    cloneDummy2.push_back(c2.cloneSnippet[i]);
                    ifOpen = tabStr;
                    adjacent = true;
                } else {
                    tempClone.push_back(tabStr + "if(flag == 0) " + c1.cloneSnippet[i].substr(tabIdx));
                    tempClone.push_back(tabStr + "else if(flag == 1) " + c2.cloneSnippet[i].substr(tabIdx));                    
                }

            } else {
            // 이미 인접한 중복 라인을 찾아서 브랜치 나누는 경우(parenthesis 안에 존재)
                if(i<c1.cloneSize-1 && int_vec_contains(diffLine, i+1)){
                // 마지막 라인이 아니면서 뒤에 인접한 중복 라인 존재시
                    cloneDummy1.push_back(c1.cloneSnippet[i]);
                    cloneDummy2.push_back(c2.cloneSnippet[i]);                    
                } else {
                    cloneDummy1.push_back(c1.cloneSnippet[i]);
                    cloneDummy1.push_back(ifOpen + "}");
                    cloneDummy2.push_back(c2.cloneSnippet[i]);
                    cloneDummy2.push_back(ifOpen + "}");

                    // vector1.insert( vector1.end(), vector2.begin(), vector2.end() );
                    tempClone.insert(tempClone.end(), cloneDummy1.begin(), cloneDummy1.end());
                    tempClone.insert(tempClone.end(), cloneDummy2.begin(), cloneDummy2.end());

                    cloneDummy1.clear();
                    cloneDummy2.clear();      
                    adjacent = false;              
                }
            }
        }
    }

    ifstream pfile(c1.fileName.c_str());
    string line;

    int lineCnt = 1; // line counter
    while(getline(pfile, line)) {
        //if (lineCnt >= c1.from && lineCnt <= c1.to) continue;
        //if (lineCnt >= c2.from && lineCnt <= c2.to) continue;
        //cout << line << endl;
        if(lineCnt == c1.from) patchCode.insert(patchCode.end(), tempClone.begin(), tempClone.end());
        if(lineCnt == c2.to + 1) {
            if(only_spaces(line)) { lineCnt++; continue; }
        }
        if(!(lineCnt >= c1.from && lineCnt <= c1.to) && !(lineCnt >= c2.from && lineCnt <= c2.to)) patchCode.push_back(line);
        
        lineCnt++;
    }

    cout << "Patching clones ...\n";
    cout << "(This will be replaced with actual file write operations)\n";
    afterPatchLoc = patchCode.size();
    print_code(tempClone); */
    //print_code(patchCode); // TODO: need to replace this with file write operations


}

/* void patch_code(string fileName){

    ifstream pfile(fileName.c_str());
    string line;
    int classLine; // line number of class declaration
    int lineCnt = 0; // line counter
    string ftnDef, ftnCls, ftnCall; // patch function code definition line & closure line
    ftnCall = "      " + get_clone_ftn_name() + ";";

    while(getline(pfile, line)) {
        lineCnt++;

        if (contains(line, "public") && contains(line, "class")) {
            patchCode.push_back(line);
            istringstream iss(line);
            string a, b;
            iss >> a >> b;
            if (!a.compare("public") && !b.compare("class")) {
                ftnDef = "    public void " + get_clone_ftn_name() + " {";
                ftnCls = "    }";
                patchCode.push_back("");
                patchCode.push_back(ftnDef);
                patchCode.insert(patchCode.end(), tempClone.begin(), tempClone.end());
                patchCode.push_back(ftnCls);
                classLine = lineCnt;
            }
        } else {

            if ((lineCnt >= cloneDatas.front().from && lineCnt < cloneDatas.front().to) 
               || (lineCnt >= cloneDatas.back().from && lineCnt < cloneDatas.back().to)) continue;
            else if (lineCnt == cloneDatas.front().to || lineCnt == cloneDatas.back().to) patchCode.push_back(ftnCall);
            else patchCode.push_back(line);

        }

    }
    cloneFtnNum++;

} */



/*
 * ====================================================
 * ======= FUNCTIONS FOR TYPE 2(MERGE METHOD) =========
 * ====================================================
 */

bool int_vec_contains(vector<int> &iv, int i){
// returns true if vector contains the element
    return ( find(iv.begin(), iv.end(), i) != iv.end() );
}

void merge_clone_ftn(string fileName, CloneData &c1, CloneData &c2, FtnType &f1, FtnType &f2){
    
    string newFtnName = f1.ftnName + f2.ftnName;
    // 1. substitute caller function name with new one.

    for(int i=0; i<c1.callers.size(); i++){
        patch_callers(c1.callers[i], newFtnName, 0);
    }

    for(int i=0; i<c2.callers.size(); i++){
        patch_callers(c2.callers[i], newFtnName, 1);
    }
    

    vector<int> diffLine = get_diff(cloneDatas.front(), cloneDatas.back(), f1, f2); // TODO: refactor this?
    if(diffLine.empty()) {
        cerr << "Diff line empty. Merging method aborted." << endl;
        return;
    }

    // 2. insert procedure branches using if/else statements using flag.
    // use diffLine to get the diff lines
    int tabIdx = c1.cloneSnippet.front().find_first_not_of(" \t\r\n"); // this is for code formatting
    string tabStr = c1.cloneSnippet.front().substr(0, tabIdx);


    // 3. insert flag at the ftn decl.
    // use FtnType to not get new function name & arg name
    string ftnDecl = tabStr;
    for(int i=0; i<f1.keywords.size(); i++){
        ftnDecl += (f1.keywords[i] + " ");
    }

    ftnDecl += (f1.returnType + " " + newFtnName + "(");
    for(int i=0; i<f1.ftnArgs.size(); i++){
        ftnDecl += f1.ftnArgs[i].first;
        ftnDecl += " ";
        ftnDecl += f1.ftnArgs[i].second;
        ftnDecl += ", ";
    }
    ftnDecl += "int flag) {"; // TODO: maybe need to refactor b.c. parenthesis not in first line?
    tempClone.push_back(ftnDecl);

    // check for adjacent clone lines;
    bool adjacent = false;
    vector<string> cloneDummy1; 
    vector<string> cloneDummy2; // clone dummy for adjacent clone snippets
    string ifOpen;

    for(int i=1; i<c1.cloneSize; i++){
        if (!int_vec_contains(diffLine, i)) tempClone.push_back(c1.cloneSnippet[i]);
        else {
            tabIdx = c1.cloneSnippet[i].find_first_not_of(" \t\r\n"); // this is for code formatting
            tabStr = c1.cloneSnippet[i].substr(0, tabIdx);

            if(!adjacent){
            // 처음 중복 라인 찾아서 브랜치 나누는 경우
                if(i<c1.cloneSize-1 && int_vec_contains(diffLine, i+1)){
                // 마지막 라인이 아니면서 뒤에 인접한 중복 라인 존재시
                    cloneDummy1.push_back(tabStr + "if(flag == 0){ ");
                    cloneDummy2.push_back(tabStr + "else if(flag == 1){ ");
                    cloneDummy1.push_back(c1.cloneSnippet[i]);
                    cloneDummy2.push_back(c2.cloneSnippet[i]);
                    ifOpen = tabStr;
                    adjacent = true;
                } else {
                    tempClone.push_back(tabStr + "if(flag == 0) " + c1.cloneSnippet[i].substr(tabIdx));
                    tempClone.push_back(tabStr + "else if(flag == 1) " + c2.cloneSnippet[i].substr(tabIdx));                    
                }

            } else {
            // 이미 인접한 중복 라인을 찾아서 브랜치 나누는 경우(parenthesis 안에 존재)
                if(i<c1.cloneSize-1 && int_vec_contains(diffLine, i+1)){
                // 마지막 라인이 아니면서 뒤에 인접한 중복 라인 존재시
                    cloneDummy1.push_back(c1.cloneSnippet[i]);
                    cloneDummy2.push_back(c2.cloneSnippet[i]);                    
                } else {
                    cloneDummy1.push_back(c1.cloneSnippet[i]);
                    cloneDummy1.push_back(ifOpen + "}");
                    cloneDummy2.push_back(c2.cloneSnippet[i]);
                    cloneDummy2.push_back(ifOpen + "}");

                    // vector1.insert( vector1.end(), vector2.begin(), vector2.end() );
                    tempClone.insert(tempClone.end(), cloneDummy1.begin(), cloneDummy1.end());
                    tempClone.insert(tempClone.end(), cloneDummy2.begin(), cloneDummy2.end());

                    cloneDummy1.clear();
                    cloneDummy2.clear();      
                    adjacent = false;              
                }
            }
        }
    }

    ifstream pfile(c1.fileName.c_str());
    string line;

    int lineCnt = 1; // line counter
    while(getline(pfile, line)) {
        //if (lineCnt >= c1.from && lineCnt <= c1.to) continue;
        //if (lineCnt >= c2.from && lineCnt <= c2.to) continue;
        //cout << line << endl;
        if(lineCnt == c1.from) patchCode.insert(patchCode.end(), tempClone.begin(), tempClone.end());
        if(lineCnt == c2.to + 1) {
            if(only_spaces(line)) { lineCnt++; continue; }
        }
        if(!(lineCnt >= c1.from && lineCnt <= c1.to) && !(lineCnt >= c2.from && lineCnt <= c2.to)) patchCode.push_back(line);
        
        lineCnt++;
    }

    cout << "Patching clones ...\n";
    cout << "(This will be replaced with actual file write operations)\n";
    afterPatchLoc = patchCode.size();
    print_code(tempClone);
    //print_code(patchCode); // TODO: need to replace this with file write operations

}




/*
 * ====================================================
 * ============= MAIN REFACTOR FUNCTIONS ==============
 * ====================================================
 */

void em_type1(){

    CloneData c1, c2;
    c1 = cloneDatas.front();
    c2 = cloneDatas.back();

    beforePatchLoc = get_file_line(c1.fileName);

    FtnType f1, f2;
    vector<NodeData> ndVec1;
    vector<NodeData> ndVec2;
    parse_ftn_type(c1.cloneSnippet.front(), f1);
    parse_ftn_type(c2.cloneSnippet.front(), f2);
    getFtnSubtree(c1.fileName, f1.ftnName, ndVec1);
    getFtnSubtree(c2.fileName, f2.ftnName, ndVec2);
    parse_ftype(ndVec1, f1);
    parse_ftype(ndVec2, f2);

    //print_ftn_type(f1);
    //print_ftn_type(f2);

    pair<int, int> p = get_common_part(c1, c2, f1, f2);
    tempCodeLine = p.second - p.first + 1;
    
    if(p.first == 0 && p.second == 0) {
        cerr << "Error getting bracket scope. Aborting refactor..." << endl;
        return;
    }

    parse_class_member_vars(c1.fileName);

    // a. 구간 내 인자로 뽑을 변수 선택하기; vector<pair<string, string>>로 반환

    vector< pair<string, string> > emArgs = get_em_args(c1, c2, f1, f2, p);

    /* cout << "\nEM args size : " << emArgs.size() << endl;
    for(int i=0; i<emArgs.size(); i++){
        cout << emArgs.at(i).first << " " << emArgs.at(i).second << endl;
    } */

    // b. 뽑은 인자 사용해서 함수 정의부 만들고 중복부분 함수 호출 대치
    patch_code(c1.fileName, c1, c2, f1, f2, p, emArgs);

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

void em_type2(){
    
    CloneData c1, c2;
    c1 = cloneDatas.front();
    c2 = cloneDatas.back();

    beforePatchLoc = get_file_line(c1.fileName);

    FtnType f1, f2;
    parse_ftn_type(c1.cloneSnippet.front(), f1);
    parse_ftn_type(c2.cloneSnippet.front(), f2);

    merge_clone_ftn(c1.fileName, c1, c2, f1, f2); // TODO: need to refactor?

    reducedLoc = beforePatchLoc - afterPatchLoc;
    report_result();

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
            em_type1();
            break; 
        case T2:
            em_type2();
            break;

    }
    
}





/*
 * ====================================================
 * ================= TEST FUNCTIONS ===================
 * ====================================================
 */

void test_print(){

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

void print_caller(CloneData &cd){

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

void print_code(vector<string> code){
    for(vector<string>::iterator it = code.begin(); it != code.end(); ++it){
        cout << (*it) << endl;
    }
}

void print_ftn_type(FtnType &f){
    cout << " ===== Function type ===== " << endl;
    cout << "Keywords : ";
    for(int p=0; p<f.keywords.size(); p++){
        cout << f.keywords[p] << " ";
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
    cout << "throws Exception : ";
    if(f.thrwExtn) cout << "O" << endl;
    else cout << "X" << endl;
    cout << "Bracket opener offset : " << f.bopenLine << endl;
    //cout << "Def line# : " << f.lineNum << endl; // TODO: remove this from ftnType?
}

void print_arg_calls(CloneData &cd){
    
    cout << "# of arg calls : " << cd.argCalls.size() << endl;
    vector< pair<string, int> >::iterator it = cd.argCalls.begin();
    for(; it!=cd.argCalls.end(); ++it){
        cout << (*it).first << " at line #" << (*it).second << endl;
    }

}

void print_class_n_ftn_type(vector< pair< vector<string>, int > > &classNftnTypeDef){

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

void print_class_type(ClassType &c){
    
    cout << " ===== Class Type ===== \n";
    cout << "Keywords : ";
    for(vector<string>::iterator it = c.keywords.begin(); it!=c.keywords.end(); ++it){
        cout << (*it) << " ";
    }
    cout << "\nClass Type : ";
    if (c.ctype == CLASS) cout << "class\n";
    else if (c.ctype == ABSTRACT_CLASS) cout << "abstract class\n";
    else if (c.ctype == INTERFACE) cout << "interface\n";
    cout << "Class Name : " << c.cname << endl;
    cout << "Def line# : " << c.lineNum << endl;

}



/*
 * ====================================================
 * ================= MAIN FUNCTION ====================
 * ====================================================
 */

int main(int argc, char** argv){

    // USAGE :  ./autorefactor CLONEDATA
    if (argc < 2) {
        cerr << "Usage : " << argv[0] << " ALARMFILE" << endl;
        return 1;
    }

    read_file(argv[1]); // 1. reads input data

    refactor(T1); // 2. refactor the code according to the clone datas
    //print_code(tempClone);

    // test for tree manipulation
    /* string fname = "/home/yang/Sources/AutoRefactor/casestudy/fasoo/dpserver/3/DigitalPage_Server.com.fasoo.note.api.service.MissionServiceImpl.java";
    string ftnname = "checkAchieveMission";
    vector<NodeData> ndVec;
    getFtnSubtree(fname, ftnname, ndVec);
    FtnType ftype;
    parse_ftype(ndVec, ftype);
    print_ftn_type(ftype); */
    //print_node_vector(ndVec);
    //printss(fname);
    //parse_class_member_vars(fname);
    //print_node_vector(ndvec);

    return 0;

} 