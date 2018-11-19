### AutoRefactor  

AutoRefactor is a tool which uses Deckard as a front-end to automatically refactor duplicates found in Java projects.

Please read the instructions below to use.

#### 1. Usage

##### 1.1 To Build

```
$ git clone https://github.com/Bloofer/AutoRefactor.git
$ make all
```

##### 1.2 To Prepare (Use Deckard Alarms)

**Alarm file format**
```
[Number of Clones]  
[Filename (including absolute path) of clone#1 from to]  
[Filename (including absolute path) of clone#2 from to]  
```

##### 1.3 To Patch
```
$ ./autorecfactor OPTIONS ALARMFILE [DOTFILE]
// OPTIONS : -a/-r/-c[3]
// ALARMFILE : Please read 1.2 and follow the format strictly
// DOTFILE : .dot file (CallGraph) from your project repository
```

##### 1.4 Restrictions
* TODO
* TODO

#### 2. Big Picture

##### 2.1 Auto-Refactoring for Function Unit Code Clones
TODO

##### 2.2 Implementation

**All directories/files in AutoRefactor**
```
└── AutoRefactor
    ├── ptgen               // for parse tree gen
    │   └── java
    ├── treeTra     
    ├── include             // headers
    ├── dtl                 // diff library
    ├── demo                // demos you can try
    │   ├── t1
    │   ├── t2
    │   └── t3
    ├── autorefactor.cpp    // main program of AutoRefactor
    ├── fileioutil.cpp      // file io utility
    ├── ptree.cc            
    ├── treeutil.cpp        // for tree manipulation
    └── Makefile
```

#### 3. In Practice

##### 3.1 Demos
TODO

##### 3.2 Real World Examples
TODO

#### 4. Trouble Shooting
TODO